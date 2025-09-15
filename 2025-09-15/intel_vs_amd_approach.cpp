#include <iostream>
using namespace std;

int main() {
    cout << "=== Intel vs AMD: 서로 다른 설계 철학 ===" << endl;
    
    cout << "\n[ Intel의 보수적 접근법 ]" << endl;
    cout << "1990년대 Intel의 고민:" << endl;
    cout << "  💼 \"기존 x86 호환성을 절대 깨면 안 돼\"" << endl;
    cout << "  💼 \"시장 점유율 90% 잃을 수 없어\"" << endl;
    cout << "  💼 \"레지스터 늘리면 기존 소프트웨어 다 재컴파일해야 해\"" << endl;
    
    cout << "\nIntel의 해결책: Itanium (IA-64)" << endl;
    cout << "  - 완전히 새로운 아키텍처" << endl;
    cout << "  - 128개 레지스터(!)" << endl;
    cout << "  - VLIW (Very Long Instruction Word)" << endl;
    cout << "  - x86과 완전 단절" << endl;
    cout << "  결과: 시장에서 참패 💥" << endl;
    
    cout << "\n[ AMD의 혁신적 접근법 ]" << endl;
    cout << "1999년 AMD의 전략:" << endl;
    cout << "  🚀 \"어차피 우리는 도전자, 혁신해보자\"" << endl;
    cout << "  🚀 \"x86 호환성 + 새로운 기능\"" << endl;
    cout << "  🚀 \"64비트 만드는 김에 레지스터도 늘리자\"" << endl;
    
    cout << "\nAMD64 (x86-64)의 혁신:" << endl;
    cout << "  ✅ 기존 32비트 코드 그대로 실행" << endl;
    cout << "  ✅ 64비트 모드에서는 16개 레지스터" << endl;
    cout << "  ✅ 점진적 전환 가능" << endl;
    cout << "  결과: 시장에서 대성공 🎉" << endl;
    
    cout << "\n[ 왜 AMD 방식이 승리했을까? ]" << endl;
    
    cout << "\n1. 호환성 문제:" << endl;
    cout << "Intel Itanium:" << endl;
    cout << "  - 기존 x86 소프트웨어 못 돌림" << endl;
    cout << "  - 모든 프로그램 재작성 필요" << endl;
    cout << "  - 개발자들이 외면" << endl;
    
    cout << "\nAMD x86-64:" << endl;
    cout << "  - 기존 32비트 프로그램 그대로 실행" << endl;
    cout << "  - 새 프로그램만 64비트로 컴파일" << endl;
    cout << "  - 점진적 전환 가능" << endl;
    
    cout << "\n2. 시장 상황:" << endl;
    cout << "  - 1990년대 말 Intel 독주 시대" << endl;
    cout << "  - AMD는 도전자로서 혁신 필요" << endl;
    cout << "  - Intel은 안전한 길만 선택" << endl;
    cout << "  - 결과적으로 AMD가 시장을 선도" << endl;
    
    cout << "\n3. 기술적 우월성:" << endl;
    cout << "  - Itanium: 너무 복잡함" << endl;
    cout << "  - x86-64: 적절한 복잡성" << endl;
    cout << "  - 컴파일러가 최적화하기 쉬움" << endl;
    
    cout << "\n[ Intel의 굴복 ]" << endl;
    cout << "\n2004년 Intel의 선택:" << endl;
    cout << "  😅 \"AMD 방식을 따라가자...\"" << endl;
    cout << "  😅 \"Intel 64라고 브랜딩하자\"" << endl;
    cout << "  😅 \"사실상 AMD64와 동일\"" << endl;
    
    cout << "\n역사의 아이러니:" << endl;
    cout << "  - CPU 업계 1위 Intel이" << endl;
    cout << "  - CPU 업계 2위 AMD를 따라함" << endl;
    cout << "  - 현재 모든 64비트 x86 CPU는 'AMD64' 기반" << endl;
    
    cout << "\n[ 결론: 레지스터가 늘어난 진짜 이유 ]" << endl;
    
    cout << "\n기술적 이유:" << endl;
    cout << "  ✅ 40년된 x86의 8개 레지스터 제약 극복" << endl;
    cout << "  ✅ 다른 RISC 아키텍처 수준으로 현대화" << endl;
    cout << "  ✅ 컴파일러 최적화 공간 확보" << endl;
    
    cout << "\n역사적 이유:" << endl;
    cout << "  ✅ AMD의 도전정신과 혁신 의지" << endl;
    cout << "  ✅ Intel의 보수성이 만든 기회" << endl;
    cout << "  ✅ 64비트 전환 타이밍의 활용" << endl;
    
    cout << "\n시장 이유:" << endl;
    cout << "  ✅ 호환성과 혁신의 절묘한 균형" << endl;
    cout << "  ✅ 개발자 친화적 설계" << endl;
    cout << "  ✅ 점진적 전환 전략" << endl;
    
    cout << "\n💡 핵심 인사이트:" << endl;
    cout << "레지스터가 2배 늘어난 것은 '64비트의 부산물'이 아니라," << endl;
    cout << "'AMD가 x86의 오랜 한계를 해결한 혁신'이었다!" << endl;
    
    return 0;
}