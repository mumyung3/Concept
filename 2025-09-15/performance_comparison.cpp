#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace chrono;

// 32비트 확장 포인터 시뮬레이션
struct Extended32Pointer {
    uint32_t high;
    uint32_t low;
    
    // 포인터 산술 연산 (느림)
    Extended32Pointer operator+(int offset) const {
        uint64_t full_addr = (static_cast<uint64_t>(high) << 32) | low;
        full_addr += offset;
        return {static_cast<uint32_t>(full_addr >> 32), 
                static_cast<uint32_t>(full_addr & 0xFFFFFFFF)};
    }
    
    // 비교 연산 (느림)
    bool operator<(const Extended32Pointer& other) const {
        if (high != other.high) return high < other.high;
        return low < other.low;
    }
};

int main() {
    cout << "=== 32비트 확장 vs 64비트 네이티브 성능 비교 ===" << endl;
    
    const int ITERATIONS = 1000000;
    
    cout << "\n[ 테스트 1: 포인터 산술 연산 ]" << endl;
    
    // 64비트 네이티브 포인터 연산
    auto start = high_resolution_clock::now();
    uint64_t* native_ptr = reinterpret_cast<uint64_t*>(0x100000000ULL);
    for (int i = 0; i < ITERATIONS; i++) {
        native_ptr = native_ptr + 1;
    }
    auto end = high_resolution_clock::now();
    auto native_time = duration_cast<microseconds>(end - start).count();
    
    // 32비트 확장 포인터 연산
    start = high_resolution_clock::now();
    Extended32Pointer ext_ptr = {0x1, 0x0};
    for (int i = 0; i < ITERATIONS; i++) {
        ext_ptr = ext_ptr + 1;
    }
    end = high_resolution_clock::now();
    auto extended_time = duration_cast<microseconds>(end - start).count();
    
    cout << "64비트 네이티브: " << native_time << " μs" << endl;
    cout << "32비트 확장: " << extended_time << " μs" << endl;
    cout << "성능 차이: " << (double)extended_time / native_time << "배 느림" << endl;
    
    cout << "\n[ 테스트 2: 메모리 사용량 비교 ]" << endl;
    
    vector<void*> native_pointers(1000);
    vector<Extended32Pointer> extended_pointers(1000);
    
    cout << "1000개 포인터 메모리 사용량:" << endl;
    cout << "64비트 네이티브: " << sizeof(void*) * 1000 << " bytes" << endl;
    cout << "32비트 확장: " << sizeof(Extended32Pointer) * 1000 << " bytes" << endl;
    cout << "메모리 차이: " << ((sizeof(Extended32Pointer) * 1000) - (sizeof(void*) * 1000)) << " bytes" << endl;
    
    cout << "\n[ 실제 CPU 명령어 수 비교 ]" << endl;
    
    cout << "\n포인터 로드 연산:" << endl;
    cout << "64비트 네이티브: MOV reg, [ptr]           (1 instruction)" << endl;
    cout << "32비트 확장:    MOV reg1, [ptr+0]        (1 instruction)" << endl;
    cout << "               MOV reg2, [ptr+4]        (1 instruction)" << endl;
    cout << "               총 2 instructions → 2배 느림" << endl;
    
    cout << "\n포인터 덧셈 연산:" << endl;
    cout << "64비트 네이티브: ADD reg, offset          (1 instruction)" << endl;
    cout << "32비트 확장:    ADD low_reg, offset      (1 instruction)" << endl;
    cout << "               ADC high_reg, 0          (1 instruction, 캐리)" << endl;
    cout << "               총 2 instructions → 2배 느림" << endl;
    
    cout << "\n포인터 비교 연산:" << endl;
    cout << "64비트 네이티브: CMP reg1, reg2           (1 instruction)" << endl;
    cout << "32비트 확장:    CMP high1, high2         (1 instruction)" << endl;
    cout << "               JNE done                 (1 instruction)" << endl;
    cout << "               CMP low1, low2           (1 instruction)" << endl;
    cout << "               총 3 instructions → 3배 느림" << endl;
    
    cout << "\n[ 캐시 효율성 분석 ]" << endl;
    
    cout << "\n64비트 네이티브:" << endl;
    cout << "- 포인터 1개당 8바이트" << endl;
    cout << "- 캐시 라인(64바이트)에 8개 포인터" << endl;
    cout << "- 연속 접근 시 캐시 히트율 높음" << endl;
    
    cout << "\n32비트 확장:" << endl;
    cout << "- 포인터 1개당 8바이트 (동일)" << endl;
    cout << "- 하지만 2번의 로드 연산 필요" << endl;
    cout << "- 명령어 캐시 사용량 증가" << endl;
    cout << "- 분기 예측 실패 가능성 증가" << endl;
    
    cout << "\n=== 결론 ====" << endl;
    cout << "\n32비트에서 2워드 확장이 이론적으로는 가능하지만," << endl;
    cout << "실제로는 다음과 같은 이유로 비현실적입니다:" << endl;
    cout << "\n1. 성능: 2-4배 느린 포인터 연산" << endl;
    cout << "2. 복잡성: 모든 소프트웨어 스택 재작성 필요" << endl;
    cout << "3. 호환성: 기존 코드와의 호환성 지옥" << endl;
    cout << "4. 하드웨어: 근본적 아키텍처 제약" << endl;
    cout << "\n따라서 64비트 네이티브 전환이 유일한 현실적 해답이었습니다." << endl;
    
    return 0;
}