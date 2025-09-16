#include <iostream>

int main() {
    std::cout << "=== 하드웨어 아키텍처는 64비트에 맞춰 새로 설계되었나? ===" << std::endl;
    
    std::cout << "\n답: 부분적으로 맞습니다!" << std::endl;
    
    std::cout << "\n=== 새로 추가/확장된 하드웨어 요소들 ===" << std::endl;
    
    std::cout << "\n1. 레지스터 확장 및 추가:" << std::endl;
    std::cout << "   - 기존 8개 32비트 레지스터 → 64비트로 확장" << std::endl;
    std::cout << "   - 새로운 8개 64비트 레지스터 추가 (R8~R15)" << std::endl;
    std::cout << "   - 총 16개의 64비트 범용 레지스터" << std::endl;
    std::cout << "   - SSE 레지스터도 16개로 확장 (XMM0~XMM15)" << std::endl;
    
    std::cout << "\n2. 주소 버스 확장:" << std::endl;
    std::cout << "   - 32비트: 32개 주소선 (4GB 주소 공간)" << std::endl;
    std::cout << "   - 64비트: 실제로는 48개 주소선 사용 (256TB 주소 공간)" << std::endl;
    std::cout << "   - 하드웨어적으로 주소 디코딩 회로 확장" << std::endl;
    
    std::cout << "\n3. 데이터 버스:" << std::endl;
    std::cout << "   - 64비트 데이터 버스로 확장" << std::endl;
    std::cout << "   - 한 번에 8바이트 데이터 전송 가능" << std::endl;
    
    std::cout << "\n4. 메모리 관리 유닛(MMU):" << std::endl;
    std::cout << "   - 64비트 페이지 테이블 지원" << std::endl;
    std::cout << "   - 더 큰 가상 주소 공간 관리" << std::endl;
    std::cout << "   - 4단계 페이징 구조" << std::endl;
    
    std::cout << "\n=== 하지만 하위 호환성을 위해 유지된 것들 ===" << std::endl;
    
    std::cout << "\n1. 명령어 세트:" << std::endl;
    std::cout << "   - 기존 x86 명령어들 대부분 그대로 지원" << std::endl;
    std::cout << "   - 16비트, 32비트 모드도 여전히 지원" << std::endl;
    std::cout << "   - 실행 유닛들이 다양한 크기 처리" << std::endl;
    
    std::cout << "\n2. 인터럽트 시스템:" << std::endl;
    std::cout << "   - 기본 인터럽트 메커니즘 유지" << std::endl;
    std::cout << "   - 다만 인터럽트 핸들러는 64비트 주소 사용" << std::endl;
    
    std::cout << "\n3. I/O 시스템:" << std::endl;
    std::cout << "   - 기존 포트 I/O 방식 유지" << std::endl;
    std::cout << "   - PCI, USB 등 기존 버스 호환성 유지" << std::endl;
    
    std::cout << "\n=== 완전히 새로 설계된 부분들 ===" << std::endl;
    
    std::cout << "\n1. 캐시 서브시스템:" << std::endl;
    std::cout << "   - 64비트 주소를 효율적으로 처리하는 캐시 구조" << std::endl;
    std::cout << "   - 더 큰 캐시 크기 (L1, L2, L3)" << std::endl;
    std::cout << "   - 캐시 라인 크기 최적화" << std::endl;
    
    std::cout << "\n2. 분기 예측기:" << std::endl;
    std::cout << "   - 64비트 주소 공간의 분기 예측" << std::endl;
    std::cout << "   - 더 정교한 예측 알고리즘" << std::endl;
    
    std::cout << "\n3. 파이프라인:" << std::endl;
    std::cout << "   - 64비트 연산을 효율적으로 처리하는 실행 유닛" << std::endl;
    std::cout << "   - 더 많은 병렬 처리 능력" << std::endl;
    
    std::cout << "\n=== 실제 CPU 설계 전략 ===" << std::endl;
    
    std::cout << "\n1. Intel의 접근:" << std::endl;
    std::cout << "   - x86-64 (AMD64 기반) 라이선스" << std::endl;
    std::cout << "   - 기존 x86 코어에 64비트 확장 추가" << std::endl;
    std::cout << "   - 호환성을 최우선으로 고려" << std::endl;
    
    std::cout << "\n2. 실행 모드:" << std::endl;
    std::cout << "   - Real Mode (16비트)" << std::endl;
    std::cout << "   - Protected Mode (32비트)" << std::endl;
    std::cout << "   - Long Mode (64비트) - 새로 추가" << std::endl;
    std::cout << "   - 부팅 시에는 16비트로 시작해서 순차 전환" << std::endl;
    
    std::cout << "\n=== 결론 ===" << std::endl;
    std::cout << "64비트 하드웨어는:" << std::endl;
    std::cout << "✓ 새로 설계된 부분: 레지스터, 주소버스, MMU, 캐시" << std::endl;
    std::cout << "✓ 호환성 유지 부분: 명령어 세트, I/O, 인터럽트" << std::endl;
    std::cout << "✓ 전략: '확장'을 통한 진화, 혁명적 변화 아님" << std::endl;
    std::cout << "\n→ 완전히 새로운 아키텍처라기보다는" << std::endl;
    std::cout << "  '기존 아키텍처의 64비트 확장판'이 더 정확합니다!" << std::endl;
    
    return 0;
}