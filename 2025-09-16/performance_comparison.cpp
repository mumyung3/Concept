#include <iostream>

int main() {
    std::cout << "=== SIMD는 별도의 하드웨어 아키텍처인가? ===" << std::endl;
    
    std::cout << "\n답: 네! SIMD는 완전히 별도의 하드웨어입니다!" << std::endl;
    
    std::cout << "\n=== CPU 내부 구조 ===" << std::endl;
    
    std::cout << "\n현대 CPU의 실제 구성:" << std::endl;
    std::cout << "┌─────────────────────────────────────────────────┐" << std::endl;
    std::cout << "│                   CPU 다이                      │" << std::endl;
    std::cout << "├─────────────────────┬───────────────────────────┤" << std::endl;
    std::cout << "│   스칼라 유닛        │       SIMD 유닛            │" << std::endl;
    std::cout << "│ (일반 정수/부동소수점)│   (벡터 처리 전용)         │" << std::endl;
    std::cout << "├─────────────────────┼───────────────────────────┤" << std::endl;
    std::cout << "│ • RAX, RBX, RCX...  │ • XMM0~XMM15 (128비트)    │" << std::endl;
    std::cout << "│ • 64비트 ALU        │ • YMM0~YMM15 (256비트)    │" << std::endl;
    std::cout << "│ • 일반 연산         │ • ZMM0~ZMM15 (512비트)    │" << std::endl;
    std::cout << "└─────────────────────┴───────────────────────────┘" << std::endl;
    
    std::cout << "\n=== 별도의 하드웨어 구성요소들 ===" << std::endl;
    
    std::cout << "\n1. 별도의 레지스터 파일:" << std::endl;
    std::cout << "   - 일반 레지스터: RAX, RBX, RCX... (64비트 × 16개)" << std::endl;
    std::cout << "   - SIMD 레지스터: XMM, YMM, ZMM (최대 512비트 × 32개)" << std::endl;
    std::cout << "   - 물리적으로 완전히 분리된 저장공간" << std::endl;
    
    std::cout << "\n2. 별도의 실행 유닛:" << std::endl;
    std::cout << "   - 스칼라 ALU: 64비트 정수/부동소수점 연산" << std::endl;
    std::cout << "   - 벡터 ALU: 128/256/512비트 병렬 연산 전용" << std::endl;
    std::cout << "   - 각각 다른 실리콘 면적 사용" << std::endl;
    
    std::cout << "\n3. 별도의 디코더:" << std::endl;
    std::cout << "   - 일반 명령어: ADD, MOV, JMP 등" << std::endl;
    std::cout << "   - SIMD 명령어: PADDD, PMULL, VFMADD 등" << std::endl;
    std::cout << "   - 서로 다른 명령어 형식과 인코딩" << std::endl;
    
    std::cout << "\n=== 물리적 구현의 차이 ===" << std::endl;
    
    std::cout << "\n일반 64비트 ALU:" << std::endl;
    std::cout << "  [64비트 입력A] → [64비트 ALU] → [64비트 출력]" << std::endl;
    std::cout << "  - 하나의 큰 연산" << std::endl;
    std::cout << "  - 트랜지스터 수: 약 수천개" << std::endl;
    
    std::cout << "\n256비트 SIMD ALU (AVX):" << std::endl;
    std::cout << "  [32비트A1][32비트A2][32비트A3][32비트A4]" << std::endl;
    std::cout << "       ↓        ↓        ↓        ↓" << std::endl;
    std::cout << "  [ALU1]   [ALU2]   [ALU3]   [ALU4]    ← 4개 병렬" << std::endl;
    std::cout << "       ↓        ↓        ↓        ↓" << std::endl;
    std::cout << "  [32비트B1][32비트B2][32비트B3][32비트B4]" << std::endl;
    std::cout << "  - 4개의 독립적 연산" << std::endl;
    std::cout << "  - 트랜지스터 수: 약 수만개 (4배 이상)" << std::endl;
    
    std::cout << "\n=== 실제 칩 레이아웃 ===" << std::endl;
    
    std::cout << "\nIntel Core i7의 실제 구성:" << std::endl;
    std::cout << "- 스칼라 실행 유닛: 4-6개" << std::endl;
    std::cout << "- SIMD 실행 유닛: 2-4개" << std::endl;
    std::cout << "- 총 실리콘 면적의 약 20-30%가 SIMD 전용" << std::endl;
    
    std::cout << "\n면적 비교 (대략적):" << std::endl;
    std::cout << "- 64비트 ALU: 1 단위" << std::endl;
    std::cout << "- 256비트 SIMD ALU: 4-8 단위 (병렬 회로 + 제어 로직)" << std::endl;
    std::cout << "- 512비트 SIMD ALU: 10-16 단위" << std::endl;
    
    std::cout << "\n=== 독립적인 파이프라인 ===" << std::endl;
    
    std::cout << "\n스칼라 파이프라인:" << std::endl;
    std::cout << "  Fetch → Decode → Execute → Writeback" << std::endl;
    std::cout << "         (일반)    (64비트)   (RAX 등)" << std::endl;
    
    std::cout << "\nSIMD 파이프라인:" << std::endl;  
    std::cout << "  Fetch → Decode → Execute → Writeback" << std::endl;
    std::cout << "         (SIMD)   (256비트)  (YMM 등)" << std::endl;
    
    std::cout << "\n→ 두 파이프라인이 동시에 독립적으로 동작!" << std::endl;
    
    std::cout << "\n=== 전력 소비도 별도 ===" << std::endl;
    
    std::cout << "\n전력 소비 (대략적):" << std::endl;
    std::cout << "- 64비트 연산: 1W" << std::endl;
    std::cout << "- 128비트 SIMD: 2-3W" << std::endl;
    std::cout << "- 256비트 SIMD: 4-6W" << std::endl;
    std::cout << "- 512비트 SIMD: 8-15W" << std::endl;
    
    std::cout << "\n→ SIMD 사용 시 CPU 온도와 전력 소비 크게 증가" << std::endl;
    std::cout << "→ 따라서 필요할 때만 선택적으로 사용" << std::endl;
    
    std::cout << "\n=== 제조 비용도 증가 ===" << std::endl;
    
    std::cout << "\nCPU 제조 시:" << std::endl;
    std::cout << "- SIMD 유닛이 없으면: 더 작은 다이, 저렴한 제조비" << std::endl;
    std::cout << "- SIMD 유닛 포함: 다이 크기 20-30% 증가, 비용 증가" << std::endl;
    
    std::cout << "\n저전력 CPU들:" << std::endl;
    std::cout << "- ARM Cortex-A55: 기본 SIMD만" << std::endl;
    std::cout << "- Intel Atom: 제한적 SIMD" << std::endl;
    std::cout << "- 고성능 CPU: 풀 SIMD 지원" << std::endl;
    
    std::cout << "\n=== 결론 ===" << std::endl;
    std::cout << "SIMD는 별도의 하드웨어 아키텍처입니다:" << std::endl;
    
    std::cout << "\n✓ 물리적 분리:" << std::endl;
    std::cout << "  - 별도 레지스터 파일" << std::endl;
    std::cout << "  - 별도 실행 유닛" << std::endl;
    std::cout << "  - 별도 파이프라인" << std::endl;
    
    std::cout << "\n✓ 독립적 동작:" << std::endl;
    std::cout << "  - 일반 연산과 SIMD 연산 동시 실행 가능" << std::endl;
    std::cout << "  - 서로 다른 명령어 세트" << std::endl;
    
    std::cout << "\n✓ 추가 비용:" << std::endl;
    std::cout << "  - 실리콘 면적 증가" << std::endl;
    std::cout << "  - 전력 소비 증가" << std::endl;
    std::cout << "  - 제조 비용 증가" << std::endl;
    
    std::cout << "\n→ SIMD는 CPU 안의 '별도 컴퓨터'라고 볼 수 있습니다!" << std::endl;
    
    return 0;
}