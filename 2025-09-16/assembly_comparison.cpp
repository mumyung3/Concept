#include <iostream>

int main() {
    std::cout << "=== 범용 레지스터가 8개 → 16개로 늘어난 이유와 정의 ===" << std::endl;
    
    std::cout << "\n=== 범용 레지스터(General Purpose Register) 정의 ===" << std::endl;
    
    std::cout << "\n범용 레지스터란:" << std::endl;
    std::cout << "- 특정 용도가 정해지지 않은 레지스터" << std::endl;
    std::cout << "- 정수 연산, 주소 저장, 임시 데이터 보관 등에 자유롭게 사용" << std::endl;
    std::cout << "- 프로그래머/컴파일러가 필요에 따라 용도 결정" << std::endl;
    
    std::cout << "\n범용 레지스터 vs 특수 레지스터:" << std::endl;
    std::cout << "✓ 범용: EAX, EBX, ECX, EDX, ESI, EDI, EBP, ESP (32비트)" << std::endl;
    std::cout << "✗ 특수: " << std::endl;
    std::cout << "  - EIP (명령어 포인터) - 다음 실행할 명령어 주소" << std::endl;
    std::cout << "  - EFLAGS (플래그) - 연산 결과 상태" << std::endl;
    std::cout << "  - 세그먼트 레지스터 (CS, DS, ES, SS)" << std::endl;
    
    std::cout << "\n=== 32비트 x86에서 8개인 이유 ===" << std::endl;
    
    std::cout << "\n1. 역사적 제약:" << std::endl;
    std::cout << "   - 8086 (1978년): 16비트 레지스터 8개" << std::endl;
    std::cout << "   - 80386 (1985년): 32비트로 확장하되 개수 유지" << std::endl;
    std::cout << "   - 하위 호환성을 위해 기존 구조 유지" << std::endl;
    
    std::cout << "\n2. 명령어 인코딩 제약:" << std::endl;
    std::cout << "   - x86 명령어에서 레지스터 지정: 3비트 (2^3 = 8개)" << std::endl;
    std::cout << "   - 예: MOV EAX, EBX에서 EAX=000, EBX=011" << std::endl;
    std::cout << "   - 더 많은 레지스터 = 더 긴 명령어 = 호환성 문제" << std::endl;
    
    std::cout << "\n3. 실리콘 면적과 비용:" << std::endl;
    std::cout << "   - 1980년대 기술로는 레지스터도 비싸고 복잡" << std::endl;
    std::cout << "   - 8개면 대부분의 프로그램에 충분했음" << std::endl;
    std::cout << "   - 더 많은 레지스터 = 더 큰 다이 = 더 비싼 CPU" << std::endl;
    
    std::cout << "\n32비트 x86 범용 레지스터:" << std::endl;
    std::cout << "┌─────┬─────────────────────────────┐" << std::endl;
    std::cout << "│ 번호 │        레지스터 이름         │" << std::endl;
    std::cout << "├─────┼─────────────────────────────┤" << std::endl;
    std::cout << "│ 000 │ EAX (Accumulator)          │" << std::endl;
    std::cout << "│ 001 │ ECX (Counter)              │" << std::endl;
    std::cout << "│ 010 │ EDX (Data)                 │" << std::endl;
    std::cout << "│ 011 │ EBX (Base)                 │" << std::endl;
    std::cout << "│ 100 │ ESP (Stack Pointer) *특수   │" << std::endl;
    std::cout << "│ 101 │ EBP (Base Pointer) *반특수  │" << std::endl;
    std::cout << "│ 110 │ ESI (Source Index)         │" << std::endl;
    std::cout << "│ 111 │ EDI (Destination Index)    │" << std::endl;
    std::cout << "└─────┴─────────────────────────────┘" << std::endl;
    
    std::cout << "\n=== 64비트에서 16개로 늘어난 이유 ===" << std::endl;
    
    std::cout << "\n1. 성능 요구 증가:" << std::endl;
    std::cout << "   - 복잡한 64비트 연산" << std::endl;
    std::cout << "   - 더 큰 데이터 구조" << std::endl;
    std::cout << "   - 더 복잡한 알고리즘" << std::endl;
    std::cout << "   → 8개로는 부족!" << std::endl;
    
    std::cout << "\n2. 컴파일러 최적화 향상:" << std::endl;
    std::cout << "   - 더 많은 변수를 레지스터에 보관" << std::endl;
    std::cout << "   - 메모리 접근 횟수 감소" << std::endl;
    std::cout << "   - 레지스터 부족으로 인한 spill 현상 감소" << std::endl;
    
    std::cout << "\n3. 기술 발전:" << std::endl;
    std::cout << "   - 2000년대: 트랜지스터가 저렴해짐" << std::endl;
    std::cout << "   - 레지스터 추가 비용이 성능 향상 대비 미미" << std::endl;
    std::cout << "   - 다이 크기보다 성능이 더 중요해짐" << std::endl;
    
    std::cout << "\n4. 명령어 인코딩 확장:" << std::endl;
    std::cout << "   - REX prefix 도입으로 4비트 레지스터 지정 가능" << std::endl;
    std::cout << "   - 2^4 = 16개 레지스터 지원" << std::endl;
    std::cout << "   - 하위 호환성 유지하면서 확장" << std::endl;
    
    std::cout << "\n64비트 x86-64 범용 레지스터:" << std::endl;
    std::cout << "┌─────┬──────────────────┬──────────────────┐" << std::endl;
    std::cout << "│ 번호 │   기존 8개        │    새로 추가된 8개 │" << std::endl;
    std::cout << "├─────┼──────────────────┼──────────────────┤" << std::endl;
    std::cout << "│ 0000│ RAX (EAX 확장)   │                  │" << std::endl;
    std::cout << "│ 0001│ RCX (ECX 확장)   │                  │" << std::endl;
    std::cout << "│ 0010│ RDX (EDX 확장)   │                  │" << std::endl;
    std::cout << "│ 0011│ RBX (EBX 확장)   │                  │" << std::endl;
    std::cout << "│ 0100│ RSP (ESP 확장)   │                  │" << std::endl;
    std::cout << "│ 0101│ RBP (EBP 확장)   │                  │" << std::endl;
    std::cout << "│ 0110│ RSI (ESI 확장)   │                  │" << std::endl;
    std::cout << "│ 0111│ RDI (EDI 확장)   │                  │" << std::endl;
    std::cout << "├─────┼──────────────────┼──────────────────┤" << std::endl;
    std::cout << "│ 1000│                  │ R8               │" << std::endl;
    std::cout << "│ 1001│                  │ R9               │" << std::endl;
    std::cout << "│ 1010│                  │ R10              │" << std::endl;
    std::cout << "│ 1011│                  │ R11              │" << std::endl;
    std::cout << "│ 1100│                  │ R12              │" << std::endl;
    std::cout << "│ 1101│                  │ R13              │" << std::endl;
    std::cout << "│ 1110│                  │ R14              │" << std::endl;
    std::cout << "│ 1111│                  │ R15              │" << std::endl;
    std::cout << "└─────┴──────────────────┴──────────────────┘" << std::endl;
    
    std::cout << "\n=== 실제 성능 영향 ===" << std::endl;
    
    std::cout << "\n레지스터 부족 문제 (32비트):" << std::endl;
    std::cout << "int a=1, b=2, c=3, d=4, e=5, f=6, g=7, h=8, i=9;" << std::endl;
    std::cout << "→ 8개 초과하는 변수들은 메모리에 저장 (spill)" << std::endl;
    std::cout << "→ 메모리 접근으로 성능 저하" << std::endl;
    
    std::cout << "\n레지스터 충분 (64비트):" << std::endl;
    std::cout << "→ 더 많은 변수를 레지스터에 보관" << std::endl;
    std::cout << "→ 메모리 접근 감소" << std::endl;
    std::cout << "→ 성능 향상 (10-30%)" << std::endl;
    
    std::cout << "\n=== 다른 아키텍처와 비교 ===" << std::endl;
    
    std::cout << "\nARM64:" << std::endl;
    std::cout << "- 범용 레지스터: 31개 (X0-X30)" << std::endl;
    std::cout << "- 처음부터 많은 레지스터로 설계" << std::endl;
    
    std::cout << "\nRISC-V:" << std::endl;
    std::cout << "- 범용 레지스터: 31개 (X1-X31)" << std::endl;
    std::cout << "- 현대적 설계" << std::endl;
    
    std::cout << "\nPowerPC:" << std::endl;
    std::cout << "- 범용 레지스터: 32개" << std::endl;
    std::cout << "- IBM의 RISC 설계" << std::endl;
    
    std::cout << "\n=== 결론 ===" << std::endl;
    std::cout << "32비트 8개 → 64비트 16개인 이유:" << std::endl;
    
    std::cout << "\n32비트 8개 제약:" << std::endl;
    std::cout << "✗ 역사적 하위 호환성" << std::endl;
    std::cout << "✗ 명령어 인코딩 제약 (3비트)" << std::endl;
    std::cout << "✗ 1980년대 기술 제약" << std::endl;
    
    std::cout << "\n64비트 16개 확장:" << std::endl;
    std::cout << "✓ 성능 요구 증가" << std::endl;
    std::cout << "✓ 기술 발전 (트랜지스터 저렴)" << std::endl;
    std::cout << "✓ 명령어 확장 (REX prefix, 4비트)" << std::endl;
    std::cout << "✓ 컴파일러 최적화 향상" << std::endl;
    
    std::cout << "\n→ x86의 역사적 제약을 극복하면서" << std::endl;
    std::cout << "  현대적 성능 요구를 만족시키는 절충안!" << std::endl;
    
    return 0;
}