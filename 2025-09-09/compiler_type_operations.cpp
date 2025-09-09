#include <iostream>
#include <bitset>

// 컴파일러의 타입별 연산 규칙과 캐스팅의 진실

int main() {
    std::cout << "=== 컴파일러의 타입별 연산 규칙과 캐스팅 ===\n\n";
    
    // 1. 컴파일러가 미리 정해놓은 타입별 연산들
    std::cout << "1. 컴파일러가 각 타입에 대해 미리 정의한 연산들:\n\n";
    
    int a = 10, b = 3;
    float x = 10.5f, y = 3.2f;
    
    std::cout << "   정수 타입 (int):\n";
    std::cout << "   ✅ a + b = " << (a + b) << " (덧셈)\n";
    std::cout << "   ✅ a / b = " << (a / b) << " (정수 나눗셈)\n";
    std::cout << "   ✅ a % b = " << (a % b) << " (나머지)\n";
    std::cout << "   ✅ a << 2 = " << (a << 2) << " (비트 시프트)\n";
    std::cout << "   ✅ a & 7 = " << (a & 7) << " (비트 AND)\n\n";
    
    std::cout << "   실수 타입 (float):\n";
    std::cout << "   ✅ x + y = " << (x + y) << " (덧셈)\n";
    std::cout << "   ✅ x / y = " << (x / y) << " (실수 나눗셈)\n";
    std::cout << "   ❌ x % y     (컴파일 에러! 실수는 나머지 연산 불가)\n";
    std::cout << "   ❌ x << 2    (컴파일 에러! 실수는 비트 연산 불가)\n";
    std::cout << "   ❌ x & 7     (컴파일 에러! 실수는 비트 연산 불가)\n\n";
    
    // 2. 같은 메모리, 다른 해석
    std::cout << "2. 캐스팅 = 같은 메모리의 다른 해석:\n\n";
    
    int intValue = 1078530011;  // 특정 비트 패턴
    
    std::cout << "   같은 메모리 (4바이트): ";
    unsigned char* bytes = (unsigned char*)&intValue;
    for(int i = 0; i < 4; i++) {
        printf("%02X ", bytes[i]);
    }
    std::cout << "\n\n";
    
    std::cout << "   int로 해석:    " << intValue << "\n";
    std::cout << "   float로 해석:  " << *(float*)&intValue << "\n";
    std::cout << "   unsigned로 해석: " << *(unsigned*)&intValue << "\n";
    
    char* charPtr = (char*)&intValue;
    std::cout << "   char[4]로 해석: {" << (int)charPtr[0] << ", " 
              << (int)charPtr[1] << ", " << (int)charPtr[2] << ", " 
              << (int)charPtr[3] << "}\n\n";
    
    std::cout << "   → 같은 메모리, 다른 해석 = 다른 의미!\n\n";
    
    // 3. 캐스팅의 종류와 의미
    std::cout << "3. 캐스팅의 종류:\n\n";
    
    std::cout << "   📝 재해석 캐스팅 (메모리 내용 그대로):\n";
    int original = 42;
    float* floatView = (float*)&original;
    std::cout << "   int 42를 float*로 보기: " << *floatView << " (쓰레기값)\n";
    std::cout << "   → 메모리 내용 안바뀜, 해석만 바뀜\n\n";
    
    std::cout << "   🔄 변환 캐스팅 (메모리 내용 바뀜):\n";
    int intNum = 42;
    float floatNum = (float)intNum;  // 실제 변환
    std::cout << "   int 42를 float로 변환: " << floatNum << "\n";
    std::cout << "   → 새로운 float 값 생성 (메모리 내용 변환)\n\n";
    
    // 4. 컴파일러의 연산 생성 과정
    std::cout << "4. 컴파일러가 연산을 어떻게 처리하는가:\n\n";
    
    std::cout << "   C++ 코드:     int result = a + b;\n";
    std::cout << "   컴파일러 판단: '+'는 int 타입에 대해 정의됨\n";
    std::cout << "   어셈블리:     ADD EAX, EBX  (정수 덧셈 명령어)\n\n";
    
    std::cout << "   C++ 코드:     float result = x + y;\n";
    std::cout << "   컴파일러 판단: '+'는 float 타입에 대해 정의됨\n";
    std::cout << "   어셈블리:     ADDSS XMM0, XMM1  (실수 덧셈 명령어)\n\n";
    
    std::cout << "   C++ 코드:     int result = x + y;  // float + float\n";
    std::cout << "   컴파일러 판단: float을 int로 변환 필요\n";
    std::cout << "   어셈블리:     ADDSS → CVTSS2SI  (실수 덧셈 후 정수 변환)\n\n";
    
    // 5. 비트 레벨에서 확인
    std::cout << "5. 비트 레벨에서 확인:\n\n";
    
    int num1 = 5;   // 0101
    int num2 = 3;   // 0011
    
    std::cout << "   " << num1 << " (이진): " << std::bitset<8>(num1) << "\n";
    std::cout << "   " << num2 << " (이진): " << std::bitset<8>(num2) << "\n\n";
    
    std::cout << "   정수 연산들 (컴파일러가 허용):\n";
    std::cout << "   " << num1 << " + " << num2 << " = " << (num1 + num2) 
              << " (" << std::bitset<8>(num1 + num2) << ")\n";
    std::cout << "   " << num1 << " & " << num2 << " = " << (num1 & num2)
              << " (" << std::bitset<8>(num1 & num2) << ")\n";
    std::cout << "   " << num1 << " << 1 = " << (num1 << 1)
              << " (" << std::bitset<8>(num1 << 1) << ")\n\n";
    
    // 6. 포인터 연산도 마찬가지
    std::cout << "6. 포인터 연산도 타입에 따라 다름:\n\n";
    
    int intArray[5] = {10, 20, 30, 40, 50};
    int* intPtr = intArray;
    char* charPtr2 = (char*)intArray;
    
    std::cout << "   int* 포인터 연산:\n";
    std::cout << "   intPtr     = " << intPtr << "\n";
    std::cout << "   intPtr + 1 = " << (intPtr + 1) << " (+" << sizeof(int) << " bytes)\n";
    std::cout << "   *(intPtr + 1) = " << *(intPtr + 1) << "\n\n";
    
    std::cout << "   char* 포인터 연산 (같은 메모리):\n";
    std::cout << "   charPtr2     = " << (void*)charPtr2 << "\n";
    std::cout << "   charPtr2 + 1 = " << (void*)(charPtr2 + 1) << " (+" << sizeof(char) << " byte)\n";
    std::cout << "   *(charPtr2 + 1) = " << (int)*(charPtr2 + 1) << " (바이트 값)\n\n";
    
    // 7. 컴파일러의 타입 테이블 (개념적)
    std::cout << "7. 컴파일러 내부의 타입 테이블 (개념적):\n\n";
    std::cout << "   타입     크기   허용연산           포인터연산단위\n";
    std::cout << "   ----     ----   --------           --------------\n";
    std::cout << "   char     1      +,-,*,/,%,&,|      1 byte\n";
    std::cout << "   int      4      +,-,*,/,%,&,|      4 bytes\n";
    std::cout << "   float    4      +,-,*,/ (no %)     4 bytes\n";
    std::cout << "   double   8      +,-,*,/ (no %)     8 bytes\n";
    std::cout << "   void*    8      비교만 가능         1 byte\n\n";
    
    // 8. 실제 어셈블리 차이 (개념적 설명)
    std::cout << "8. 같은 '+' 연산이 다른 기계어로 번역됨:\n\n";
    
    int ia = 10, ib = 20;
    float fa = 10.0f, fb = 20.0f;
    
    std::cout << "   int 덧셈:   " << ia << " + " << ib << " = " << (ia + ib) << "\n";
    std::cout << "   → 기계어: ADD (정수 덧셈 명령어)\n\n";
    
    std::cout << "   float 덧셈: " << fa << " + " << fb << " = " << (fa + fb) << "\n";
    std::cout << "   → 기계어: FADD (부동소수점 덧셈 명령어)\n\n";
    
    std::cout << "=== 핵심 정리 ===\n";
    std::cout << "✅ 맞습니다! 컴파일러가 타입별로 연산을 미리 정의\n";
    std::cout << "✅ 캐스팅 = 같은 메모리를 다른 방식으로 해석\n\n";
    
    std::cout << "컴파일러의 역할:\n";
    std::cout << "1. 타입별 허용 연산 체크\n";
    std::cout << "2. 적절한 기계어 명령어 선택\n";
    std::cout << "3. 타입 변환 규칙 적용\n";
    std::cout << "4. 메모리 레이아웃 결정\n\n";
    
    std::cout << "런타임에는:\n";
    std::cout << "• CPU는 그냥 기계어 명령어만 실행\n";
    std::cout << "• 타입 정보 없음, 순수 비트 연산\n";
    std::cout << "• ADD면 정수 덧셈, FADD면 실수 덧셈\n";
    
    return 0;
}