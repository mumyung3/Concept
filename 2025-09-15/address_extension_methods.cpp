#include <iostream>
#include <iomanip>
using namespace std;

// 32비트 시스템에서 2워드 주소를 시뮬레이션
struct Extended64BitPointer {
    uint32_t low_word;   // 하위 32비트
    uint32_t high_word;  // 상위 32비트
    
    // 64비트 주소 생성
    uint64_t get_full_address() const {
        return (static_cast<uint64_t>(high_word) << 32) | low_word;
    }
    
    void set_address(uint64_t addr) {
        low_word = static_cast<uint32_t>(addr & 0xFFFFFFFF);
        high_word = static_cast<uint32_t>(addr >> 32);
    }
};

int main() {
    cout << "=== 32비트에서 2워드 주소 확장 방법들 ===" << endl;
    
    cout << "\n[ 방법 1: 소프트웨어적 2워드 포인터 ]" << endl;
    Extended64BitPointer ext_ptr;
    ext_ptr.set_address(0x123456789ABCDEF0ULL);
    
    cout << "64비트 주소: 0x" << hex << ext_ptr.get_full_address() << endl;
    cout << "상위 32비트: 0x" << ext_ptr.high_word << endl;
    cout << "하위 32비트: 0x" << ext_ptr.low_word << endl;
    cout << "총 포인터 크기: " << sizeof(ext_ptr) << " bytes" << endl;
    
    cout << "\n[ 실제 32비트 시대에 시도된 방법들 ]" << endl;
    
    cout << "\n1. Physical Address Extension (PAE) - Intel" << endl;
    cout << "   - 36비트 물리 주소 지원 (64GB까지)" << endl;
    cout << "   - 가상 주소는 여전히 32비트 (4GB 제한)" << endl;
    cout << "   - 프로세스별로는 4GB, 시스템 전체로는 64GB" << endl;
    
    cout << "\n2. Address Windowing Extensions (AWE) - Windows" << endl;
    cout << "   - 응용프로그램이 수동으로 메모리 윈도우 관리" << endl;
    cout << "   - 복잡한 프로그래밍 모델" << endl;
    cout << "   - 성능 오버헤드 상당함" << endl;
    
    cout << "\n3. Large Memory Model - 컴파일러 확장" << endl;
    cout << "   - far pointer, huge pointer 개념" << endl;
    cout << "   - 세그먼트:오프셋 방식" << endl;
    cout << "   - 16비트 시대의 연장선" << endl;
    
    cout << "\n[ 2워드 주소 방식의 문제점들 ]" << endl;
    
    // 성능 비교 시뮬레이션
    cout << "\n성능 오버헤드 분석:" << endl;
    
    // 일반 32비트 포인터 연산
    uint32_t* normal_ptr = nullptr;
    cout << "일반 32비트 포인터 연산:" << endl;
    cout << "  - 로드: 1 instruction" << endl;
    cout << "  - 스토어: 1 instruction" << endl;
    cout << "  - 포인터 산술: 1 instruction" << endl;
    
    // 확장 64비트 포인터 연산
    cout << "확장 64비트 포인터 연산:" << endl;
    cout << "  - 로드: 2+ instructions (상위+하위)" << endl;
    cout << "  - 스토어: 2+ instructions" << endl;
    cout << "  - 포인터 산술: 4+ instructions (캐리 처리)" << endl;
    cout << "  - 비교 연산: 3+ instructions" << endl;
    
    cout << "\n메모리 사용량 비교:" << endl;
    cout << "일반 포인터: " << sizeof(void*) << " bytes" << endl;
    cout << "확장 포인터: " << sizeof(Extended64BitPointer) << " bytes" << endl;
    cout << "메모리 오버헤드: " << (sizeof(Extended64BitPointer) * 100 / sizeof(void*)) - 100 << "%" << endl;
    
    cout << "\n[ 실제 구현의 복잡성 ]" << endl;
    cout << "❌ 하드웨어 지원 부족:" << endl;
    cout << "   - CPU 레지스터는 여전히 32비트" << endl;
    cout << "   - 메모리 컨트롤러 한계" << endl;
    cout << "   - 캐시 아키텍처 비효율성" << endl;
    
    cout << "\n❌ 소프트웨어 복잡성:" << endl;
    cout << "   - 기존 코드와 호환성 문제" << endl;
    cout << "   - 컴파일러 대대적 수정 필요" << endl;
    cout << "   - 라이브러리 전체 재작성" << endl;
    cout << "   - 디버깅 도구 문제" << endl;
    
    cout << "\n❌ 성능 문제:" << endl;
    cout << "   - 모든 포인터 연산이 2-4배 느려짐" << endl;
    cout << "   - 메모리 사용량 증가" << endl;
    cout << "   - 캐시 미스 증가" << endl;
    
    return 0;
}