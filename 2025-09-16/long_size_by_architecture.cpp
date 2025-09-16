#include <iostream>
#include <climits>

int main() {
    std::cout << "=== long 타입 크기 분석 ===" << std::endl;
    std::cout << "현재 시스템에서 long의 크기: " << sizeof(long) << " bytes" << std::endl;
    std::cout << "long의 비트 수: " << sizeof(long) * 8 << " bits" << std::endl;
    std::cout << "LONG_MAX: " << LONG_MAX << std::endl;
    std::cout << "LONG_MIN: " << LONG_MIN << std::endl;
    
    std::cout << "\n=== 다른 정수 타입과의 비교 ===" << std::endl;
    std::cout << "int 크기: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "long long 크기: " << sizeof(long long) << " bytes" << std::endl;
    std::cout << "포인터 크기: " << sizeof(void*) << " bytes" << std::endl;
    std::cout << "size_t 크기: " << sizeof(size_t) << " bytes" << std::endl;
    
    std::cout << "\n=== 아키텍처별 long 크기 ===" << std::endl;
    std::cout << "32비트 시스템: long은 4바이트 (32비트)" << std::endl;
    std::cout << "64비트 시스템:" << std::endl;
    std::cout << "  - Windows (LLP64): long은 4바이트 (32비트)" << std::endl;
    std::cout << "  - Unix/Linux (LP64): long은 8바이트 (64비트)" << std::endl;
    
    return 0;
}