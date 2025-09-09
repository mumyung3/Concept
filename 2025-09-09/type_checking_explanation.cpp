#include <iostream>
#include <typeinfo>

// 타입 체크: 컴파일러 vs OS 역할 구분

int main() {
    std::cout << "=== 타입 체크: 누가 언제 하는가? ===\n\n";
    
    // 1. 컴파일 시점 vs 런타임
    std::cout << "1. 컴파일 시점 vs 런타임:\n\n";
    
    std::cout << "   🔧 컴파일 시점 (Compile Time):\n";
    std::cout << "   • 컴파일러가 타입 체크\n";
    std::cout << "   • 문법 오류, 타입 불일치 검사\n";
    std::cout << "   • 코드를 기계어로 변환\n";
    std::cout << "   • 타입 정보는 대부분 제거됨\n\n";
    
    std::cout << "   🏃 런타임 (Runtime):\n";
    std::cout << "   • OS가 프로세스와 메모리 관리\n";
    std::cout << "   • 타입 정보는 거의 없음\n";
    std::cout << "   • 단순히 바이트 덩어리로 취급\n";
    std::cout << "   • 메모리 주소와 크기만 알고 있음\n\n";
    
    // 2. 실제 예제로 확인
    int arr[5] = {1, 2, 3, 4, 5};
    
    std::cout << "2. 컴파일 시점의 타입 체크:\n";
    std::cout << "   int arr[5] = {1, 2, 3, 4, 5};\n\n";
    
    // 컴파일러가 막는 코드들 (주석 처리)
    std::cout << "   컴파일러가 막는 코드들:\n";
    std::cout << "   // int (*p)[5] = arr;        // ❌ 타입 불일치\n";
    std::cout << "   // int (*p)[3] = &arr;       // ❌ 크기 다름\n";
    std::cout << "   // float* fp = arr;          // ❌ 타입 다름\n";
    std::cout << "   → 컴파일 단계에서 에러 발생!\n\n";
    
    // 3. 런타임에서 OS가 보는 것
    std::cout << "3. 런타임에서 OS가 보는 것:\n";
    
    int* ptr = arr;  // 컴파일러 허용
    void* voidPtr = arr;  // 컴파일러 허용
    
    std::cout << "   메모리 주소: " << ptr << "\n";
    std::cout << "   OS 관점에서는 그냥 '주소 " << ptr << "에 20바이트 할당'\n";
    std::cout << "   타입이 int든 float든 OS는 모름!\n\n";
    
    // 4. 메모리 덤프로 확인
    std::cout << "4. 메모리 내용 (OS 관점):\n";
    std::cout << "   주소        바이트 내용\n";
    std::cout << "   --------   ------------\n";
    
    unsigned char* bytePtr = (unsigned char*)arr;
    for(int i = 0; i < 20; i += 4) {
        std::cout << "   " << (void*)(bytePtr + i) << "   ";
        for(int j = 0; j < 4; j++) {
            printf("%02X ", bytePtr[i + j]);
        }
        std::cout << "(int 값: " << *(int*)(bytePtr + i) << ")\n";
    }
    std::cout << "   OS는 이것을 그냥 '바이트 덩어리'로만 봄\n\n";
    
    // 5. 타입 정보가 남아있는 경우 (예외적)
    std::cout << "5. 런타임에 타입 정보가 남아있는 경우:\n\n";
    
    std::cout << "   RTTI (Run-Time Type Information) - C++:\n";
    int x = 42;
    int* intPtr = &x;
    void* genericPtr = intPtr;
    
    std::cout << "   typeid(*intPtr).name() = " << typeid(*intPtr).name() << "\n";
    std::cout << "   → 컴파일러가 특별히 타입 정보를 남김\n\n";
    
    std::cout << "   가상 함수 테이블 (vtable) - 다형성:\n";
    std::cout << "   virtual 함수가 있는 클래스는 타입 정보 유지\n";
    std::cout << "   하지만 이것도 컴파일러가 만든 것!\n\n";
    
    // 6. 실제 시스템 관점
    std::cout << "6. 실제 시스템의 역할 분담:\n\n";
    
    std::cout << "   📝 컴파일러 (gcc, clang, MSVC):\n";
    std::cout << "   • 타입 체크와 변환\n";
    std::cout << "   • 메모리 레이아웃 결정\n";
    std::cout << "   • 최적화\n";
    std::cout << "   • 기계어 생성\n\n";
    
    std::cout << "   🖥️ OS (Linux, Windows, macOS):\n";
    std::cout << "   • 가상 메모리 관리\n";
    std::cout << "   • 프로세스 스케줄링\n";
    std::cout << "   • 시스템 콜 처리\n";
    std::cout << "   • 하드웨어 자원 관리\n\n";
    
    std::cout << "   💻 CPU:\n";
    std::cout << "   • 명령어 실행\n";
    std::cout << "   • 레지스터 관리\n";
    std::cout << "   • 메모리 액세스\n";
    std::cout << "   • 타입? 그게 뭐죠? 그냥 비트일 뿐\n\n";
    
    // 7. 포인터 타입 체크 실험
    std::cout << "7. 강제 캐스팅 실험 (런타임에는 문제없음):\n";
    
    int number = 0x41424344;  // ASCII 'ABCD'
    
    std::cout << "   int number = 0x41424344;\n";
    std::cout << "   int로 해석:    " << number << "\n";
    std::cout << "   char*로 해석:  ";
    
    char* charPtr = (char*)&number;
    for(int i = 0; i < 4; i++) {
        if(charPtr[i] >= 32 && charPtr[i] <= 126) {
            std::cout << charPtr[i];
        } else {
            std::cout << ".";
        }
    }
    std::cout << "\n";
    
    std::cout << "   float*로 해석: " << *(float*)&number << "\n";
    std::cout << "   → 런타임에는 모두 동작! OS는 신경 안씀\n\n";
    
    // 8. 디버거에서 보는 것
    std::cout << "8. 디버거 (gdb, lldb)는 어떻게 타입을 아는가?\n";
    std::cout << "   디버거는 컴파일러가 남긴 디버그 정보 사용:\n";
    std::cout << "   • -g 옵션으로 컴파일하면 DWARF 정보 포함\n";
    std::cout << "   • 변수명, 타입 정보, 소스 위치 등\n";
    std::cout << "   • 이것도 OS가 아닌 컴파일러가 만든 것!\n\n";
    
    std::cout << "=== 결론 ===\n";
    std::cout << "❌ OS가 타입을 계속 바라본다? NO!\n";
    std::cout << "✅ 컴파일러가 컴파일 시점에 타입 체크!\n\n";
    
    std::cout << "역할 분담:\n";
    std::cout << "• 컴파일러: 타입 안전성, 문법 체크\n";
    std::cout << "• OS: 메모리 관리, 프로세스 관리\n";
    std::cout << "• CPU: 명령어 실행 (타입 무관)\n\n";
    
    std::cout << "런타임에는 대부분 '그냥 바이트'일 뿐!\n";
    
    return 0;
}