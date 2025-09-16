#include <iostream>

int main() {
    std::cout << "=== x86 레지스터 구조 설명 ===" << std::endl;
    
    std::cout << "\nRAX는 EAX의 '확장'이지 별개 레지스터가 아닙니다!" << std::endl;
    
    std::cout << "\n1. 16비트 시대 (8086):" << std::endl;
    std::cout << "   AX = 16비트 레지스터" << std::endl;
    std::cout << "   AH (상위 8비트) + AL (하위 8비트)" << std::endl;
    std::cout << "   [AH][AL] = AX (16비트)" << std::endl;
    
    std::cout << "\n2. 32비트 시대 (80386):" << std::endl;
    std::cout << "   EAX = Extended AX = 32비트" << std::endl;
    std::cout << "   기존 AX는 EAX의 하위 16비트가 됨" << std::endl;
    std::cout << "   [상위 16비트][AX] = EAX (32비트)" << std::endl;
    
    std::cout << "\n3. 64비트 시대 (x86-64):" << std::endl;
    std::cout << "   RAX = Register AX = 64비트" << std::endl;
    std::cout << "   기존 EAX는 RAX의 하위 32비트가 됨" << std::endl;
    std::cout << "   [상위 32비트][EAX] = RAX (64비트)" << std::endl;
    
    std::cout << "\n=== 실제 레지스터 계층 구조 ===" << std::endl;
    std::cout << "RAX (64비트): [63-32비트][31-16비트][15-8비트][7-0비트]" << std::endl;
    std::cout << "                      ↑            ↑         ↑        ↑" << std::endl;
    std::cout << "                  (확장부분)      EAX      AH       AL" << std::endl;
    std::cout << "                              (32비트)  (8비트)  (8비트)" << std::endl;
    std::cout << "                                  └─── AX (16비트) ──┘" << std::endl;
    
    std::cout << "\n=== 하나의 물리적 레지스터, 다른 접근 방식 ===" << std::endl;
    std::cout << "- AL: 8비트 접근 (하위 8비트)" << std::endl;
    std::cout << "- AH: 8비트 접근 (9-16비트)" << std::endl;
    std::cout << "- AX: 16비트 접근 (하위 16비트)" << std::endl;
    std::cout << "- EAX: 32비트 접근 (하위 32비트)" << std::endl;
    std::cout << "- RAX: 64비트 접근 (전체 64비트)" << std::endl;
    
    std::cout << "\n=== 중요한 점 ===" << std::endl;
    std::cout << "1. 물리적으로는 '하나'의 64비트 레지스터" << std::endl;
    std::cout << "2. 명령어에 따라 다른 부분에 접근" << std::endl;
    std::cout << "3. EAX에 값을 쓰면 RAX의 상위 32비트는 자동으로 0이 됨" << std::endl;
    std::cout << "4. AX에 값을 쓰면 EAX의 상위 16비트는 그대로 유지" << std::endl;
    
    std::cout << "\n=== 다른 레지스터들도 마찬가지 ===" << std::endl;
    std::cout << "RBX ⊃ EBX ⊃ BX ⊃ {BH, BL}" << std::endl;
    std::cout << "RCX ⊃ ECX ⊃ CX ⊃ {CH, CL}" << std::endl;
    std::cout << "RDX ⊃ EDX ⊃ DX ⊃ {DH, DL}" << std::endl;
    std::cout << "RSI ⊃ ESI ⊃ SI" << std::endl;
    std::cout << "RDI ⊃ EDI ⊃ DI" << std::endl;
    std::cout << "RBP ⊃ EBP ⊃ BP" << std::endl;
    std::cout << "RSP ⊃ ESP ⊃ SP" << std::endl;
    
    std::cout << "\n=== 새로 추가된 64비트 전용 레지스터들 ===" << std::endl;
    std::cout << "R8, R9, R10, R11, R12, R13, R14, R15" << std::endl;
    std::cout << "이들은 64비트에서만 사용 가능" << std::endl;
    std::cout << "R8D (32비트 부분), R8W (16비트 부분), R8B (8비트 부분)" << std::endl;
    
    return 0;
}