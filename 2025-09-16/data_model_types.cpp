#include <iostream>
#include <climits>

int main() {
    std::cout << "=== 데이터 모델 타입들 ===" << std::endl;
    
    std::cout << "\n현재 시스템의 타입 크기:" << std::endl;
    std::cout << "int: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "long: " << sizeof(long) << " bytes" << std::endl;
    std::cout << "pointer: " << sizeof(void*) << " bytes" << std::endl;
    std::cout << "long long: " << sizeof(long long) << " bytes" << std::endl;
    
    std::cout << "\n=== 주요 데이터 모델들 ===" << std::endl;
    
    std::cout << "\n1. IP16L32 (16비트 시스템)" << std::endl;
    std::cout << "   - int: 2바이트, pointer: 2바이트, long: 4바이트" << std::endl;
    std::cout << "   - 사용: 초기 16비트 시스템 (8086, MS-DOS)" << std::endl;
    
    std::cout << "\n2. I16LP32 (16비트 int, 32비트 long/pointer)" << std::endl;
    std::cout << "   - int: 2바이트, long: 4바이트, pointer: 4바이트" << std::endl;
    std::cout << "   - 사용: 초기 32비트 시스템 전환기" << std::endl;
    
    std::cout << "\n3. ILP32 (32비트 표준)" << std::endl;
    std::cout << "   - int: 4바이트, long: 4바이트, pointer: 4바이트" << std::endl;
    std::cout << "   - 사용: 32비트 시스템 (x86, ARM32)" << std::endl;
    
    std::cout << "\n4. LLP64 (Windows 64비트)" << std::endl;
    std::cout << "   - int: 4바이트, long: 4바이트, long long: 8바이트, pointer: 8바이트" << std::endl;
    std::cout << "   - 사용: Windows x64, Visual C++" << std::endl;
    
    std::cout << "\n5. LP64 (Unix/Linux 64비트)" << std::endl;
    std::cout << "   - int: 4바이트, long: 8바이트, pointer: 8바이트" << std::endl;
    std::cout << "   - 사용: Unix, Linux, macOS (x64, ARM64)" << std::endl;
    
    std::cout << "\n6. ILP64 (이론적)" << std::endl;
    std::cout << "   - int: 8바이트, long: 8바이트, pointer: 8바이트" << std::endl;
    std::cout << "   - 사용: 거의 사용되지 않음 (호환성 문제)" << std::endl;
    
    std::cout << "\n7. SILP64 (특수 목적)" << std::endl;
    std::cout << "   - short: 8바이트, int: 8바이트, long: 8바이트, pointer: 8바이트" << std::endl;
    std::cout << "   - 사용: 일부 특수 목적 시스템" << std::endl;
    
    std::cout << "\n=== 현재 시스템 판단 ===" << std::endl;
    if (sizeof(int) == 4 && sizeof(long) == 4 && sizeof(void*) == 8) {
        std::cout << "현재 시스템: LLP64 (Windows 스타일)" << std::endl;
    } else if (sizeof(int) == 4 && sizeof(long) == 8 && sizeof(void*) == 8) {
        std::cout << "현재 시스템: LP64 (Unix/Linux 스타일)" << std::endl;
    } else if (sizeof(int) == 4 && sizeof(long) == 4 && sizeof(void*) == 4) {
        std::cout << "현재 시스템: ILP32 (32비트)" << std::endl;
    } else {
        std::cout << "현재 시스템: 기타 또는 특수 모델" << std::endl;
    }
    
    return 0;
}