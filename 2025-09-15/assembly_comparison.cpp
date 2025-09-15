#include <iostream>
using namespace std;

// 간단한 함수: 6개 매개변수 더하기
int add_six_numbers(int a, int b, int c, int d, int e, int f) {
    return a + b + c + d + e + f;
}

// 64비트 포인터 연산
void pointer_arithmetic_demo() {
    long long* ptr = reinterpret_cast<long long*>(0x123456789ABCDEF0ULL);
    ptr++;  // 64비트에서는 단일 명령어
    cout << "포인터 연산 완료" << endl;
}

int main() {
    cout << "=== 레지스터 확장의 실제 어셈블리 비교 ===" << endl;
    
    cout << "\n[ 함수 호출 비교 ]" << endl;
    cout << "함수: add_six_numbers(1, 2, 3, 4, 5, 6)" << endl;
    
    cout << "\n32비트 x86 어셈블리 (이론적):" << endl;
    cout << "    push 6        ; 6번째 매개변수" << endl;
    cout << "    push 5        ; 5번째 매개변수" << endl;
    cout << "    push 4        ; 4번째 매개변수" << endl;
    cout << "    push 3        ; 3번째 매개변수" << endl;
    cout << "    push 2        ; 2번째 매개변수" << endl;
    cout << "    push 1        ; 1번째 매개변수" << endl;
    cout << "    call add_six_numbers" << endl;
    cout << "    add esp, 24   ; 스택 정리 (6 * 4bytes)" << endl;
    cout << "→ 총 8개 명령어, 스택 메모리 6번 접근" << endl;
    
    cout << "\n64비트 x86-64 어셈블리 (이론적):" << endl;
    cout << "    mov edi, 1    ; RDI = 1번째 매개변수" << endl;
    cout << "    mov esi, 2    ; RSI = 2번째 매개변수" << endl;
    cout << "    mov edx, 3    ; RDX = 3번째 매개변수" << endl;
    cout << "    mov ecx, 4    ; RCX = 4번째 매개변수" << endl;
    cout << "    mov r8d, 5    ; R8 = 5번째 매개변수" << endl;
    cout << "    mov r9d, 6    ; R9 = 6번째 매개변수" << endl;
    cout << "    call add_six_numbers" << endl;
    cout << "→ 총 7개 명령어, 메모리 접근 0번!" << endl;
    
    // 실제 함수 호출
    int result = add_six_numbers(1, 2, 3, 4, 5, 6);
    cout << "결과: " << result << endl;
    
    cout << "\n[ 포인터 연산 비교 ]" << endl;
    cout << "연산: 64비트 포인터++;" << endl;
    
    cout << "\n32비트에서 64비트 포인터 (가정):" << endl;
    cout << "    mov eax, [ptr_low]     ; 하위 32비트 로드" << endl;
    cout << "    mov edx, [ptr_high]    ; 상위 32비트 로드" << endl;
    cout << "    add eax, 8             ; 하위에 8 더하기" << endl;
    cout << "    adc edx, 0             ; 상위에 캐리 더하기" << endl;
    cout << "    mov [ptr_low], eax     ; 하위 32비트 저장" << endl;
    cout << "    mov [ptr_high], edx    ; 상위 32비트 저장" << endl;
    cout << "→ 총 6개 명령어, 메모리 접근 4번" << endl;
    
    cout << "\n64비트에서 64비트 포인터:" << endl;
    cout << "    add qword ptr [ptr], 8 ; 64비트 직접 더하기" << endl;
    cout << "→ 총 1개 명령어, 메모리 접근 1번" << endl;
    
    pointer_arithmetic_demo();
    
    cout << "\n[ 레지스터 사용 패턴 비교 ]" << endl;
    
    cout << "\n복잡한 계산 함수에서:" << endl;
    cout << "32비트 (8개 레지스터):" << endl;
    cout << "  - 변수 많으면 자주 메모리에 spill" << endl;
    cout << "  - 임시값들을 스택에 저장" << endl;
    cout << "  - 레지스터 압박으로 비효율적 코드" << endl;
    
    cout << "\n64비트 (16개 레지스터):" << endl;
    cout << "  - 더 많은 변수를 레지스터에 유지" << endl;
    cout << "  - 메모리 접근 횟수 감소" << endl;
    cout << "  - 루프 최적화 효율성 증가" << endl;
    
    cout << "\n[ 실제 성능 차이 ]" << endl;
    cout << "벤치마크 결과 (일반적):" << endl;
    cout << "  - 함수 호출 집약적: 50-200% 향상" << endl;
    cout << "  - 포인터 연산 집약적: 100-300% 향상" << endl;
    cout << "  - 일반 정수 연산: 10-50% 향상" << endl;
    cout << "  - I/O 집약적: 거의 차이 없음" << endl;
    
    return 0;
}