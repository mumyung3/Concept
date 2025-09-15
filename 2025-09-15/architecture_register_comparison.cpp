#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct ArchitectureInfo {
    string name;
    string company;
    int year_introduced;
    int bit_width_32bit_era;
    int registers_32bit;
    int bit_width_64bit_era;
    int registers_64bit;
    string design_philosophy;
};

int main() {
    cout << "=== 32비트 시대 아키텍처별 레지스터 개수 비교 ===" << endl;
    
    vector<ArchitectureInfo> architectures = {
        {"x86", "Intel", 1985, 32, 8, 64, 16, "CISC, 호환성 우선"},
        {"MIPS", "MIPS/SGI", 1985, 32, 32, 64, 32, "RISC, 많은 레지스터"},
        {"SPARC", "Sun", 1987, 32, 32, 64, 32, "RISC, 레지스터 윈도우"},
        {"PowerPC", "IBM/Motorola", 1992, 32, 32, 64, 32, "RISC, 균형 잡힌 설계"},
        {"ARM", "Acorn/ARM", 1985, 32, 16, 64, 32, "RISC, 저전력 최적화"},
        {"Alpha", "DEC", 1992, 64, 32, 64, 32, "순수 64비트 설계"}
    };
    
    cout << "\n[ 32비트 시대 (1980년대~2000년대) 레지스터 개수 ]" << endl;
    cout << left << setw(12) << "아키텍처" 
         << setw(12) << "회사" 
         << setw(6) << "연도"
         << setw(12) << "32비트 레지스터"
         << "설계 철학" << endl;
    cout << string(70, '-') << endl;
    
    for (const auto& arch : architectures) {
        cout << left << setw(12) << arch.name
             << setw(12) << arch.company
             << setw(6) << arch.year_introduced
             << setw(12) << arch.registers_32bit
             << arch.design_philosophy << endl;
    }
    
    cout << "\n[ 놀라운 사실 ] ⚠️" << endl;
    cout << "32비트 시대에도 대부분 아키텍처가 16-32개 레지스터를 가지고 있었습니다!" << endl;
    cout << "x86만 유독 8개로 40년간 버틴 것이 특이한 상황이었습니다." << endl;
    
    cout << "\n[ 왜 x86만 8개였을까? ]" << endl;
    
    cout << "\n1. 역사적 짐:" << endl;
    cout << "   - 1978년 8086 (16비트) 설계의 유산" << endl;
    cout << "   - 80286, 80386으로 발전하면서도 호환성 유지" << endl;
    cout << "   - '이미 너무 많은 소프트웨어가 8개에 의존'" << endl;
    
    cout << "\n2. CISC vs RISC 철학 차이:" << endl;
    cout << "   CISC (x86): \"복잡한 명령어로 메모리 접근 줄이자\"" << endl;
    cout << "   RISC (MIPS, SPARC): \"단순한 명령어 + 많은 레지스터\"" << endl;
    
    cout << "\n3. 시장 지배력의 함정:" << endl;
    cout << "   - Intel이 시장을 독점하면서 변화 동기 부족" << endl;
    cout << "   - \"이미 잘 팔리는데 왜 바꿔?\"" << endl;
    cout << "   - 개발자들도 8개에 익숙해짐" << endl;
    
    cout << "\n[ 다른 아키텍처들의 접근법 ]" << endl;
    
    cout << "\n🔥 MIPS (32개 레지스터):" << endl;
    cout << "   - $0~$31까지 32개 범용 레지스터" << endl;
    cout << "   - $0은 항상 0 (상수)" << endl;
    cout << "   - 컴파일러 최적화에 매우 유리" << endl;
    cout << "   - 함수 매개변수 4-8개까지 레지스터로 전달" << endl;
    
    cout << "\n🔥 SPARC (32개 + 레지스터 윈도우):" << endl;
    cout << "   - 실제로는 100개 이상의 레지스터" << endl;
    cout << "   - 함수 호출 시 윈도우 슬라이딩" << endl;
    cout << "   - 함수 호출 오버헤드 거의 0" << endl;
    
    cout << "\n🔥 PowerPC (32개):" << endl;
    cout << "   - GPR0~GPR31 (32개 범용)" << endl;
    cout << "   - 별도로 FPR0~FPR31 (32개 부동소수점)" << endl;
    cout << "   - RISC와 성능의 균형점" << endl;
    
    cout << "\n🔥 ARM (16개, 하지만 효율적):" << endl;
    cout << "   - R0~R15 (16개)" << endl;
    cout << "   - 하지만 conditional execution으로 효율성 확보" << endl;
    cout << "   - 저전력에 특화된 설계" << endl;
    
    cout << "\n[ x86의 성능 문제 ]" << endl;
    
    cout << "\n32비트 시대 x86의 고질적 문제들:" << endl;
    cout << "❌ 함수 매개변수 → 항상 스택 사용 (느림)" << endl;
    cout << "❌ 복잡한 계산 → 메모리 spill 빈발 (느림)" << endl;
    cout << "❌ 루프 최적화 → 레지스터 부족으로 제한" << endl;
    cout << "❌ 컴파일러 → 최적화 포기하는 경우 많음" << endl;
    
    cout << "\n다른 RISC들의 장점:" << endl;
    cout << "✅ 함수 매개변수 → 레지스터로 전달 (빠름)" << endl;
    cout << "✅ 복잡한 계산 → 충분한 레지스터 활용" << endl;
    cout << "✅ 루프 최적화 → 적극적 최적화 가능" << endl;
    cout << "✅ 컴파일러 → 다양한 최적화 기법 적용" << endl;
    
    cout << "\n[ 성능 비교 (1990년대) ]" << endl;
    cout << "동일한 클럭에서의 성능 (추정치):" << endl;
    cout << "   MIPS R4000 (32 regs):     기준 성능" << endl;
    cout << "   SPARC (32 regs):          기준의 95-105%" << endl;
    cout << "   PowerPC (32 regs):        기준의 100-110%" << endl;
    cout << "   x86 Pentium (8 regs):     기준의 70-85% 😱" << endl;
    
    cout << "\n[ 그럼 왜 x86이 살아남았을까? ]" << endl;
    
    cout << "\n1. 소프트웨어 생태계:" << endl;
    cout << "   - DOS, Windows의 압도적 점유율" << endl;
    cout << "   - 개발자들이 이미 x86에 익숙" << endl;
    cout << "   - 기존 프로그램들의 호환성" << endl;
    
    cout << "\n2. 마케팅과 가격:" << endl;
    cout << "   - Intel의 강력한 마케팅" << endl;
    cout << "   - 대량 생산으로 인한 가격 경쟁력" << endl;
    cout << "   - PC 시장의 폭발적 성장" << endl;
    
    cout << "\n3. 슈퍼스칼라와 파이프라인:" << endl;
    cout << "   - Pentium Pro부터 내부적으로 RISC화" << endl;
    cout << "   - 마이크로 명령어로 변환" << endl;
    cout << "   - 하드웨어적으로 성능 격차 축소" << endl;
    
    cout << "\n[ 결론 ]" << endl;
    cout << "\n네, 맞습니다! 32비트 시대에도 대부분 아키텍처는 16-32개 레지스터를 가지고 있었습니다." << endl;
    cout << "x86-64에서 레지스터가 8개→16개로 늘어난 것은" << endl;
    cout << "'64비트의 자연스러운 결과'가 아니라" << endl;
    cout << "'다른 아키텍처 수준으로 따라잡은 것'이었습니다!" << endl;
    
    return 0;
}