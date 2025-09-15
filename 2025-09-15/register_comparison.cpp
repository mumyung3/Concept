#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "=== 32비트 vs 64비트 레지스터 비교 ===" << endl;
    
    cout << "\n[ 1. 레지스터 크기 변화 ]" << endl;
    cout << "32비트 (x86):" << endl;
    cout << "  - 범용 레지스터: 32비트 (4바이트)" << endl;
    cout << "  - EAX, EBX, ECX, EDX, ESI, EDI, ESP, EBP" << endl;
    
    cout << "\n64비트 (x86-64):" << endl;
    cout << "  - 범용 레지스터: 64비트 (8바이트)" << endl;
    cout << "  - RAX, RBX, RCX, RDX, RSI, RDI, RSP, RBP" << endl;
    cout << "  - 기존 32비트 이름도 여전히 사용 가능 (호환성)" << endl;
    
    cout << "\n[ 2. 레지스터 개수 변화 ] ⭐ 중요!" << endl;
    cout << "32비트 (x86):" << endl;
    cout << "  - 범용 레지스터: 8개" << endl;
    cout << "  - 세그먼트 레지스터: 6개" << endl;
    cout << "  - 플래그 레지스터: 1개" << endl;
    cout << "  - 총 활용 가능한 범용: 8개 (제한적)" << endl;
    
    cout << "\n64비트 (x86-64):" << endl;
    cout << "  - 범용 레지스터: 16개 ⭐ (2배 증가!)" << endl;
    cout << "  - 새로 추가된 레지스터: R8, R9, R10, R11, R12, R13, R14, R15" << endl;
    cout << "  - 세그먼트 레지스터: 6개 (동일)" << endl;
    cout << "  - 플래그 레지스터: 1개 (64비트로 확장)" << endl;
    
    cout << "\n[ 3. 레지스터 명명 규칙 ]" << endl;
    cout << "64비트 레지스터는 계층적 접근 가능:" << endl;
    cout << "RAX (64비트) → EAX (하위 32비트) → AX (하위 16비트) → AL/AH (하위 8비트)" << endl;
    
    cout << "\n예시: RAX 레지스터" << endl;
    cout << "┌─ RAX (64비트) ─────────────────────────┐" << endl;
    cout << "│               │       EAX (32비트)    │" << endl;
    cout << "│               │         │    AX (16비트) │" << endl;
    cout << "│               │         │  AH │  AL  │" << endl;
    cout << "└───────────────┴─────────┴─────┴──────┘" << endl;
    cout << "63            31        15   8    0" << endl;
    
    cout << "\n[ 4. 성능에 미치는 영향 ]" << endl;
    
    cout << "\n✅ 레지스터 개수 증가의 장점:" << endl;
    cout << "  1. 함수 매개변수를 레지스터로 전달 가능" << endl;
    cout << "     - 32비트: 주로 스택 사용" << endl;
    cout << "     - 64비트: 처음 6개 매개변수는 레지스터" << endl;
    cout << "  2. 레지스터 스필링(spilling) 감소" << endl;
    cout << "     - 변수를 메모리에 저장할 필요 감소" << endl;
    cout << "  3. 루프 최적화 향상" << endl;
    cout << "     - 더 많은 임시변수를 레지스터에 보관" << endl;
    
    cout << "\n✅ 레지스터 크기 증가의 장점:" << endl;
    cout << "  1. 64비트 정수 연산이 네이티브" << endl;
    cout << "  2. 포인터 연산이 단일 명령어" << endl;
    cout << "  3. 더 큰 배열 인덱스 직접 처리" << endl;
    
    cout << "\n[ 5. 호출 규약(Calling Convention) 변화 ]" << endl;
    
    cout << "32비트 (stdcall/cdecl):" << endl;
    cout << "  - 매개변수: 스택으로 전달" << endl;
    cout << "  - 반환값: EAX 레지스터" << endl;
    cout << "  - 함수 호출 오버헤드: 스택 push/pop" << endl;
    
    cout << "\n64비트 (System V AMD64 ABI - Linux/macOS):" << endl;
    cout << "  - 매개변수: RDI, RSI, RDX, RCX, R8, R9 (6개)" << endl;
    cout << "  - 반환값: RAX 레지스터" << endl;
    cout << "  - 함수 호출 오버헤드: 대폭 감소!" << endl;
    
    cout << "\n64비트 (Microsoft x64 ABI - Windows):" << endl;
    cout << "  - 매개변수: RCX, RDX, R8, R9 (4개)" << endl;
    cout << "  - 반환값: RAX 레지스터" << endl;
    cout << "  - Shadow space: 32바이트 스택 공간 예약" << endl;
    
    cout << "\n[ 6. 실제 성능 향상 측정 ]" << endl;
    cout << "함수 호출 오버헤드 비교 (이론적):" << endl;
    cout << "32비트: 매개변수 6개 → 6번 스택 push" << endl;
    cout << "64비트: 매개변수 6개 → 6번 레지스터 설정 (Linux)" << endl;
    cout << "성능 향상: 약 50-300% (함수 호출 집약적 코드에서)" << endl;
    
    cout << "\n[ 7. 면접 함정 포인트 ]" << endl;
    cout << "❓ Q: 64비트는 32비트보다 항상 2배 빠른가?" << endl;
    cout << "❌ A: 아니다! 레지스터 크기가 2배가 된 것보다" << endl;
    cout << "      레지스터 개수가 2배가 된 것이 더 중요하다." << endl;
    
    cout << "\n❓ Q: 모든 연산이 64비트로 처리되는가?" << endl;
    cout << "❌ A: 아니다! int는 여전히 32비트이고," << endl;
    cout << "      필요한 경우에만 64비트 연산을 한다." << endl;
    
    return 0;
}