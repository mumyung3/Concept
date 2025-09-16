#include <iostream>
#include <iomanip>
#include <cmath>

void printAddressInfo() {
    std::cout << "=== Intel x86-64 주소 공간 설명 ===" << std::endl;
    
    std::cout << "\n1. 이론적 64비트 주소 공간:" << std::endl;
    std::cout << "   - 64비트 = 2^64 = " << std::pow(2, 64) << " bytes" << std::endl;
    std::cout << "   - 약 18.4 엑사바이트 (18,446,744,073,709,551,616 bytes)" << std::endl;
    
    std::cout << "\n2. 실제 Intel x86-64 구현:" << std::endl;
    std::cout << "   - 물리 주소: 40비트 사용" << std::endl;
    std::cout << "   - 가상 주소: 48비트 사용" << std::endl;
    std::cout << "   - 나머지 비트는 미래 확장을 위해 예약" << std::endl;
    
    std::cout << "\n3. 40비트 물리 주소 공간:" << std::endl;
    long long physical_max = 1LL << 40;
    std::cout << "   - 2^40 = " << physical_max << " bytes" << std::endl;
    std::cout << "   - " << physical_max / (1024 * 1024 * 1024) << " GB = " 
              << physical_max / (1024LL * 1024 * 1024 * 1024) << " TB" << std::endl;
    std::cout << "   - 실제 RAM 용량 제한" << std::endl;
    
    std::cout << "\n4. 48비트 가상 주소 공간:" << std::endl;
    long long virtual_max = 1LL << 48;
    std::cout << "   - 2^48 = " << virtual_max << " bytes" << std::endl;
    std::cout << "   - " << virtual_max / (1024LL * 1024 * 1024 * 1024) << " TB" << std::endl;
    std::cout << "   - 각 프로세스가 사용할 수 있는 가상 메모리 공간" << std::endl;
    
    std::cout << "\n5. 왜 이렇게 설계했을까?" << std::endl;
    std::cout << "   a) 하드웨어 복잡성 감소:" << std::endl;
    std::cout << "      - 64비트 전체를 구현하면 회로가 복잡해짐" << std::endl;
    std::cout << "      - 40비트로도 현재는 충분한 물리 메모리" << std::endl;
    
    std::cout << "\n   b) 가상 주소는 더 크게:" << std::endl;
    std::cout << "      - 프로세스별로 독립적인 가상 공간 필요" << std::endl;
    std::cout << "      - MMU가 가상→물리 주소 변환 담당" << std::endl;
    
    std::cout << "\n   c) 점진적 확장 가능:" << std::endl;
    std::cout << "      - 미래에 필요하면 물리 주소 비트 확장" << std::endl;
    std::cout << "      - 소프트웨어 호환성 유지" << std::endl;
}

void demonstrateAddressing() {
    std::cout << "\n=== 실제 포인터 크기 확인 ===" << std::endl;
    
    int variable = 42;
    void* ptr = &variable;
    
    std::cout << "포인터 크기: " << sizeof(ptr) << " bytes = " 
              << sizeof(ptr) * 8 << " bits" << std::endl;
    std::cout << "포인터 주소: 0x" << std::hex << (uintptr_t)ptr << std::dec << std::endl;
    
    // 주소의 상위 비트들 확인
    uintptr_t addr = (uintptr_t)ptr;
    std::cout << "주소 분석:" << std::endl;
    std::cout << "  - 전체 64비트 중 상위 16비트: 0x" 
              << std::hex << (addr >> 48) << std::dec << std::endl;
    std::cout << "  - 실제 사용되는 48비트 부분: 0x" 
              << std::hex << (addr & 0xFFFFFFFFFFFFLL) << std::dec << std::endl;
}

int main() {
    printAddressInfo();
    demonstrateAddressing();
    
    std::cout << "\n=== 요약 ===" << std::endl;
    std::cout << "Intel 64비트 CPU는 효율성을 위해:" << std::endl;
    std::cout << "- 물리 주소: 40비트 (1TB RAM 지원)" << std::endl;
    std::cout << "- 가상 주소: 48비트 (256TB 가상 공간)" << std::endl;
    std::cout << "- 포인터는 여전히 64비트지만 일부 비트만 실제 사용" << std::endl;
    
    return 0;
}