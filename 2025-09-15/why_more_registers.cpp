#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "=== 왜 레지스터 개수가 2배로 늘어났을까? ===" << endl;
    
    cout << "\n[ 1. x86의 역사적 제약 ]" << endl;
    cout << "x86 아키텍처의 탄생 (1978년 8086):" << endl;
    cout << "  - 16비트 시대에 설계됨" << endl;
    cout << "  - 당시 기준으로는 충분했던 8개 레지스터" << endl;
    cout << "  - 하지만 40년 후에도 8개만 사용하는 것은 비효율적" << endl;
    
    cout << "\n8086 → 80386 → Pentium 과정에서:" << endl;
    cout << "  ✅ 레지스터 크기: 16비트 → 32비트 ✅" << endl;
    cout << "  ❌ 레지스터 개수: 8개 → 8개 (변화 없음) ❌" << endl;
    cout << "  이유: 기존 소프트웨어와의 호환성 때문" << endl;
    
    cout << "\n[ 2. 왜 8개로는 부족했을까? ]" << endl;
    
    cout << "\n실제 32비트 시대의 문제점들:" << endl;
    cout << "  - ESP, EBP는 스택 관리용 (실질적으로 6개만 사용)" << endl;
    cout << "  - 복잡한 함수에서 변수들이 메모리로 spill" << endl;
    cout << "  - 함수 매개변수를 스택으로만 전달" << endl;
    cout << "  - 레지스터 부족으로 인한 성능 저하" << endl;
    
    cout << "\n컴파일러 개발자들의 고민:" << endl;
    cout << "  \"최적화를 하고 싶은데 레지스터가 부족해...\"" << endl;
    cout << "  \"변수를 레지스터에 할당하고 싶은데 자리가 없어...\"" << endl;
    cout << "  \"함수 호출할 때마다 스택 써야 해서 느려...\"" << endl;
    
    cout << "\n[ 3. AMD의 혁신적 결정 ]" << endl;
    
    cout << "AMD가 x86-64 설계할 때 (1999-2003년):" << endl;
    cout << "  🤔 \"어차피 새로운 명령어 인코딩을 만드는 김에...\"" << endl;
    cout << "  💡 \"레지스터도 늘려버리자!\"" << endl;
    cout << "  🎯 \"8개 → 16개로 2배 증가\"" << endl;
    
    cout << "\n왜 정확히 16개로?" << endl;
    cout << "  1. 명령어 인코딩에서 4비트면 충분 (2^4 = 16)" << endl;
    cout << "  2. 하드웨어 복잡도와 성능의 균형점" << endl;
    cout << "  3. 컴파일러 최적화에 충분한 수" << endl;
    cout << "  4. 다른 RISC 아키텍처들도 16-32개 사용" << endl;
    
    cout << "\n[ 4. 기술적 근거 분석 ]" << endl;
    
    cout << "\n명령어 인코딩 공간:" << endl;
    cout << "32비트 x86: 3비트로 레지스터 지정 (2^3 = 8개)" << endl;
    cout << "  명령어 예: MOV EAX, EBX" << endl;
    cout << "  │     │" << endl;
    cout << "  3비트 3비트 → 총 8개만 가능" << endl;
    
    cout << "\n64비트 x86-64: 4비트로 레지스터 지정 (2^4 = 16개)" << endl;
    cout << "  새로운 REX prefix 도입" << endl;
    cout << "  │         │" << endl;
    cout << "  4비트     4비트 → 총 16개 가능" << endl;
    
    cout << "\n하드웨어 비용 분석:" << endl;
    cout << "  레지스터 8개 → 16개:" << endl;
    cout << "  - 트랜지스터 수: 약 2배 증가" << endl;
    cout << "  - 다이 면적: 전체 CPU의 5% 미만 증가" << endl;
    cout << "  - 성능 향상: 20-50% (충분히 가치 있음)" << endl;
    
    cout << "\n[ 5. 다른 아키텍처와의 비교 ]" << endl;
    
    struct ArchInfo {
        string name;
        string period;
        int registers;
        string note;
    };
    
    ArchInfo archs[] = {
        {"x86 (8086)", "1978년", 8, "16비트 시대 설계"},
        {"MIPS", "1985년", 32, "RISC 철학, 많은 레지스터"},
        {"ARM", "1985년", 16, "임베디드 최적화"},
        {"SPARC", "1987년", 32, "Sun의 워크스테이션용"},
        {"PowerPC", "1991년", 32, "IBM/Motorola 협업"},
        {"x86-64", "2003년", 16, "호환성과 성능의 균형"}
    };
    
    cout << left << setw(12) << "아키텍처" << setw(8) << "연도" 
         << setw(10) << "레지스터" << "특징" << endl;
    cout << string(50, '-') << endl;
    
    for (const auto& arch : archs) {
        cout << left << setw(12) << arch.name << setw(8) << arch.period 
             << setw(10) << arch.registers << arch.note << endl;
    }
    
    cout << "\n관찰 포인트:" << endl;
    cout << "  - 1980년대 RISC들은 이미 16-32개 사용" << endl;
    cout << "  - x86만 8개로 40년간 버텨온 것이 특이함" << endl;
    cout << "  - x86-64는 뒤늦게 현실적 수준으로 맞춘 것" << endl;
    
    cout << "\n[ 6. 왜 32개가 아니라 16개? ]" << endl;
    
    cout << "\n연구 결과에 따르면:" << endl;
    cout << "  - 8개 → 16개: 성능 향상 매우 큼" << endl;
    cout << "  - 16개 → 32개: 성능 향상 미미함" << endl;
    cout << "  - 32개 이상: 거의 효과 없음" << endl;
    
    cout << "\n이유:" << endl;
    cout << "  1. 함수 호출 시 레지스터 저장/복원 비용 증가" << endl;
    cout << "  2. 컴파일러가 효율적으로 사용하기 어려움" << endl;
    cout << "  3. 하드웨어 복잡도 증가" << endl;
    cout << "  4. 컨텍스트 스위칭 비용 증가" << endl;
    
    cout << "\n[ 7. 결론 ]" << endl;
    cout << "\n레지스터 개수가 2배 늘어난 이유:" << endl;
    cout << "  ✅ x86의 40년된 제약을 극복하기 위해" << endl;
    cout << "  ✅ 다른 아키텍처 수준으로 현대화" << endl;
    cout << "  ✅ 컴파일러 최적화 여유 공간 확보" << endl;
    cout << "  ✅ 함수 호출 성능 대폭 개선" << endl;
    cout << "  ✅ 64비트 전환 기회에 함께 개선" << endl;
    
    cout << "\n핵심: '64비트라서 2배'가 아니라," << endl;
    cout << "      '64비트 설계 기회에 오래된 제약을 해결'" << endl;
    
    return 0;
}