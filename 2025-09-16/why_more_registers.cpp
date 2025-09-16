#include <iostream>

int main() {
    std::cout << "=== \"32비트 한 워드씩만 올리면 되는거 아닌가?\"에 대한 답변 ===" << std::endl;
    
    std::cout << "\n아니요! 그것보다 훨씬 복잡합니다!" << std::endl;
    
    std::cout << "\n=== 단순히 32비트 워드만 처리하면 안 되는 이유들 ===" << std::endl;
    
    std::cout << "\n1. 주소 공간의 근본적 차이:" << std::endl;
    std::cout << "   - 32비트: 4GB 주소 공간 (2^32)" << std::endl;
    std::cout << "   - 64비트: 256TB 주소 공간 (2^48)" << std::endl;
    std::cout << "   → 포인터 자체가 8바이트로 커져야 함" << std::endl;
    
    std::cout << "\n2. 메모리 접근 방식:" << std::endl;
    std::cout << "   32비트에서 int* ptr = 0x12345678;" << std::endl;
    std::cout << "   64비트에서 int* ptr = 0x12345678ABCD1234;" << std::endl;
    std::cout << "   → 주소 계산 자체가 64비트 연산 필요" << std::endl;
    
    void* ptr = nullptr;
    std::cout << "\n   현재 포인터 크기: " << sizeof(ptr) << " 바이트" << std::endl;
    std::cout << "   → 32비트 워드 2개가 필요!" << std::endl;
    
    std::cout << "\n=== 실제 CPU가 해야 하는 일들 ===" << std::endl;
    
    std::cout << "\n1. 레지스터 관리:" << std::endl;
    std::cout << "   - 64비트 레지스터에서 32비트 부분만 사용" << std::endl;
    std::cout << "   - 하지만 주소 계산은 전체 64비트 사용" << std::endl;
    std::cout << "   - 레지스터 간 데이터 이동 시 크기 고려" << std::endl;
    
    std::cout << "\n2. 메모리 주소 변환:" << std::endl;
    std::cout << "   - 가상 주소 → 물리 주소 변환" << std::endl;
    std::cout << "   - 64비트 주소 공간의 페이지 테이블 탐색" << std::endl;
    std::cout << "   - 4단계 페이징 구조 (32비트는 2단계)" << std::endl;
    
    std::cout << "\n3. 캐시 관리:" << std::endl;
    std::cout << "   - 64비트 주소로 캐시 태그 관리" << std::endl;
    std::cout << "   - 더 큰 주소 공간으로 인한 캐시 미스 패턴 변화" << std::endl;
    
    std::cout << "\n=== 성능 최적화가 필요한 이유 ===" << std::endl;
    
    std::cout << "\n1. 만약 정말로 '32비트씩만' 처리한다면:" << std::endl;
    std::cout << "   - 64비트 주소 접근 시 2번의 메모리 액세스" << std::endl;
    std::cout << "   - 64비트 연산 시 2개 명령어로 분할" << std::endl;
    std::cout << "   - 성능이 현저히 떨어짐" << std::endl;
    
    std::cout << "\n2. 실제 64비트 CPU의 최적화:" << std::endl;
    std::cout << "   - 64비트 데이터를 한 번에 처리" << std::endl;
    std::cout << "   - 64비트 ALU (Arithmetic Logic Unit)" << std::endl;
    std::cout << "   - 64비트 데이터 경로 (data path)" << std::endl;
    
    std::cout << "\n=== 호환성 vs 성능 ===" << std::endl;
    
    std::cout << "\n32비트 호환성을 위해:" << std::endl;
    std::cout << "✓ 32비트 명령어들 지원" << std::endl;
    std::cout << "✓ 32비트 레지스터 이름들 유지 (EAX 등)" << std::endl;
    std::cout << "✓ 32비트 모드로 실행 가능" << std::endl;
    
    std::cout << "\n64비트 성능을 위해:" << std::endl;
    std::cout << "✓ 64비트 데이터 경로" << std::endl;
    std::cout << "✓ 64비트 ALU" << std::endl;
    std::cout << "✓ 더 많은 레지스터 (R8-R15)" << std::endl;
    std::cout << "✓ 64비트 주소 계산 유닛" << std::endl;
    
    std::cout << "\n=== 실제 예시 ===" << std::endl;
    
    long long big_number = 0x123456789ABCDEF0LL;
    std::cout << "\n64비트 수: 0x" << std::hex << big_number << std::dec << std::endl;
    
    std::cout << "\n만약 32비트씩 처리한다면:" << std::endl;
    std::cout << "1. 하위 32비트: 0x9ABCDEF0 로드" << std::endl;
    std::cout << "2. 상위 32비트: 0x12345678 로드" << std::endl;
    std::cout << "3. 두 부분을 조합해서 연산" << std::endl;
    std::cout << "→ 비효율적!" << std::endl;
    
    std::cout << "\n실제 64비트 CPU:" << std::endl;
    std::cout << "1. 전체 64비트를 한 번에 로드" << std::endl;
    std::cout << "2. 64비트 연산 직접 수행" << std::endl;
    std::cout << "→ 효율적!" << std::endl;
    
    std::cout << "\n=== 결론 ===" << std::endl;
    std::cout << "64비트 CPU는:" << std::endl;
    std::cout << "✗ 단순히 '32비트 워드만 처리'하지 않음" << std::endl;
    std::cout << "✓ 32비트 호환성 + 64비트 최적화를 동시에 지원" << std::endl;
    std::cout << "✓ 상황에 따라 32비트/64비트 처리를 선택적으로 사용" << std::endl;
    std::cout << "✓ 하드웨어 설계가 훨씬 복잡하고 정교함" << std::endl;
    
    return 0;
}