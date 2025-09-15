#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

// 비트필드를 사용한 최적화
struct OptimizedFlags {
    bool flag1 : 1;  // 1비트만 사용
    bool flag2 : 1;  // 1비트만 사용
    bool flag3 : 1;  // 1비트만 사용
    bool flag4 : 1;  // 1비트만 사용
    bool flag5 : 1;  // 1비트만 사용
    bool flag6 : 1;  // 1비트만 사용
    bool flag7 : 1;  // 1비트만 사용
    bool flag8 : 1;  // 1비트만 사용
};

// 일반적인 방법
struct NormalFlags {
    bool flag1;
    bool flag2;
    bool flag3;
    bool flag4;
    bool flag5;
    bool flag6;
    bool flag7;
    bool flag8;
};

int main() {
    cout << "=== bool 메모리 최적화 방법들 ===" << endl;
    
    // 1. 일반 bool vs 비트필드 비교
    cout << "\n[ 방법 1: 비트필드 사용 ]" << endl;
    cout << "일반 struct (8개 bool): " << sizeof(NormalFlags) << " bytes" << endl;
    cout << "비트필드 struct: " << sizeof(OptimizedFlags) << " bytes" << endl;
    cout << "메모리 절약: " << sizeof(NormalFlags) - sizeof(OptimizedFlags) << " bytes" << endl;
    
    // 2. 수동 비트 마스킹
    cout << "\n[ 방법 2: 수동 비트마스킹 ]" << endl;
    unsigned char flags = 0;
    
    // 플래그 설정 (비트 OR 연산)
    flags |= (1 << 0);  // flag1 = true
    flags |= (1 << 2);  // flag3 = true
    flags |= (1 << 7);  // flag8 = true
    
    cout << "8개 플래그 상태: " << bitset<8>(flags) << endl;
    cout << "사용 메모리: " << sizeof(flags) << " byte" << endl;
    
    // 플래그 확인 (비트 AND 연산)
    bool flag1_value = (flags & (1 << 0)) != 0;
    bool flag3_value = (flags & (1 << 2)) != 0;
    bool flag5_value = (flags & (1 << 4)) != 0;
    
    cout << "flag1: " << flag1_value << endl;
    cout << "flag3: " << flag3_value << endl;
    cout << "flag5: " << flag5_value << endl;
    
    // 3. vector<bool>의 특수성
    cout << "\n[ 방법 3: vector<bool> 특수 최적화 ]" << endl;
    vector<bool> boolVec(64);  // 64개 bool
    vector<char> charVec(64);  // 64개 char (비교용)
    
    cout << "vector<bool> 64개: 실제로는 비트 패킹됨" << endl;
    cout << "vector<char> 64개: " << charVec.size() << " bytes" << endl;
    
    // vector<bool>의 문제점 시연
    cout << "\n[ vector<bool>의 특이한 점 ]" << endl;
    boolVec[0] = true;
    // auto& ref = boolVec[0];  // 컴파일 에러! 실제 bool&가 아님
    auto val = boolVec[0];      // 프록시 객체 반환
    cout << "vector<bool>은 실제 bool&를 반환하지 않습니다!" << endl;
    
    // 4. 성능 비교
    cout << "\n=== 성능 고려사항 ===" << endl;
    cout << "✅ 장점:" << endl;
    cout << "  - 메모리 사용량 최대 8배 절약" << endl;
    cout << "  - 캐시 효율성 향상" << endl;
    cout << "❌ 단점:" << endl;
    cout << "  - 비트 연산 오버헤드" << endl;
    cout << "  - 코드 복잡성 증가" << endl;
    cout << "  - 디버깅 어려움" << endl;
    
    return 0;
}