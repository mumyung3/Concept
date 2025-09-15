#include <iostream>
#include <climits>
using namespace std;

int main() {
    cout << "=== 32비트 vs 64비트 데이터 타입 크기 비교 ===" << endl;
    
    // 기본 정수 타입들
    cout << "\n[ 정수 타입 ]" << endl;
    cout << "char: " << sizeof(char) << " bytes (항상 1바이트 보장)" << endl;
    cout << "short: " << sizeof(short) << " bytes" << endl;
    cout << "int: " << sizeof(int) << " bytes" << endl;
    cout << "long: " << sizeof(long) << " bytes ⭐ (32/64비트에 따라 변할 수 있음)" << endl;
    cout << "long long: " << sizeof(long long) << " bytes (C++11, 항상 8바이트)" << endl;
    
    // 부동소수점 타입들
    cout << "\n[ 부동소수점 타입 ]" << endl;
    cout << "float: " << sizeof(float) << " bytes (IEEE 754 표준)" << endl;
    cout << "double: " << sizeof(double) << " bytes (IEEE 754 표준)" << endl;
    cout << "long double: " << sizeof(long double) << " bytes (컴파일러 의존적)" << endl;
    
    // 포인터 타입들
    cout << "\n[ 포인터 타입 ]" << endl;
    cout << "void*: " << sizeof(void*) << " bytes ⭐ (아키텍처에 따라 변함)" << endl;
    cout << "int*: " << sizeof(int*) << " bytes" << endl;
    cout << "char*: " << sizeof(char*) << " bytes" << endl;
    cout << "함수 포인터: " << sizeof(void(*)()) << " bytes" << endl;
    
    // 사이즈 관련 타입들
    cout << "\n[ 크기 관련 타입 ]" << endl;
    cout << "size_t: " << sizeof(size_t) << " bytes ⭐ (포인터와 같은 크기)" << endl;
    cout << "ptrdiff_t: " << sizeof(ptrdiff_t) << " bytes" << endl;
    cout << "intptr_t: " << sizeof(intptr_t) << " bytes" << endl;
    cout << "uintptr_t: " << sizeof(uintptr_t) << " bytes" << endl;
    
    // 실제 값 범위 확인
    cout << "\n=== 값 범위 분석 ===" << endl;
    cout << "int 최솟값: " << INT_MIN << endl;
    cout << "int 최댓값: " << INT_MAX << endl;
    cout << "long 최솟값: " << LONG_MIN << endl;
    cout << "long 최댓값: " << LONG_MAX << endl;
    
    // 중요한 관찰
    cout << "\n=== 핵심 포인트 ===" << endl;
    if (sizeof(int) == sizeof(long)) {
        cout << "🔍 이 시스템에서 int와 long은 같은 크기입니다!" << endl;
    } else {
        cout << "🔍 이 시스템에서 int와 long은 다른 크기입니다!" << endl;
    }
    
    if (sizeof(void*) == 8) {
        cout << "🔍 64비트 시스템입니다 (포인터 8바이트)" << endl;
    } else if (sizeof(void*) == 4) {
        cout << "🔍 32비트 시스템입니다 (포인터 4바이트)" << endl;
    }
    
    return 0;
}