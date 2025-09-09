#include <iostream>
#include <typeinfo>

// int (*p)[5]에 arr vs &arr 할당 테스트

int main() {
    std::cout << "=== int (*p)[5]에 arr vs &arr 할당 테스트 ===\n\n";
    
    int arr[5] = {1, 2, 3, 4, 5};
    
    // 1. 타입 확인
    std::cout << "1. 타입 확인:\n";
    std::cout << "   arr의 타입:  " << typeid(arr).name() << " (int[5])\n";
    std::cout << "   &arr의 타입: " << typeid(&arr).name() << " (int(*)[5])\n\n";
    
    // 2. 배열 포인터 선언
    std::cout << "2. 배열 포인터 할당 시도:\n";
    
    // &arr로 할당 (정상)
    int (*p1)[5] = &arr;
    std::cout << "   int (*p1)[5] = &arr;  // ✅ OK\n";
    std::cout << "   p1 = " << p1 << "\n";
    std::cout << "   (*p1)[0] = " << (*p1)[0] << "\n\n";
    
    // arr로 할당 시도 (컴파일 에러!)
    std::cout << "   int (*p2)[5] = arr;   // ❌ 컴파일 에러!\n";
    // int (*p2)[5] = arr;  // 주석 처리 (컴파일 에러 방지)
    
    std::cout << "   에러 이유: 타입 불일치\n";
    std::cout << "   - arr은 int[5] → int*로 decay됨\n";
    std::cout << "   - int (*p)[5]는 int(*)[5] 타입 필요\n\n";
    
    // 3. 실제 컴파일러 에러 시뮬레이션
    std::cout << "3. 컴파일러 에러 메시지 (시뮬레이션):\n";
    std::cout << "   error: cannot convert 'int*' to 'int(*)[5]'\n";
    std::cout << "   note: array decays to pointer\n\n";
    
    // 4. 왜 안되는지 설명
    std::cout << "4. 왜 arr은 안되고 &arr만 되는가?\n\n";
    
    std::cout << "   arr (배열 이름):\n";
    std::cout << "   → 대부분 상황에서 int*로 자동 변환 (decay)\n";
    std::cout << "   → 첫 요소의 주소를 나타냄\n";
    std::cout << "   → 타입: int* (포인터)\n\n";
    
    std::cout << "   &arr (배열의 주소):\n";
    std::cout << "   → 배열 전체의 주소\n";
    std::cout << "   → decay 없이 원래 타입 유지\n";
    std::cout << "   → 타입: int(*)[5] (배열 포인터)\n\n";
    
    // 5. 포인터 값은 같지만 타입이 다름
    std::cout << "5. 주소 값은 같지만 타입이 다름:\n";
    std::cout << "   arr = " << arr << " (int*)\n";
    std::cout << "   &arr = " << &arr << " (int(*)[5])\n";
    std::cout << "   → 같은 주소이지만 타입이 달라서 할당 불가!\n\n";
    
    // 6. 강제 캐스팅으로 가능하긴 함 (권장하지 않음)
    std::cout << "6. 강제 캐스팅 (권장하지 않음):\n";
    int (*p3)[5] = (int(*)[5])arr;  // 강제 캐스팅
    std::cout << "   int (*p3)[5] = (int(*)[5])arr;  // 강제 캐스팅\n";
    std::cout << "   p3 = " << p3 << "\n";
    std::cout << "   (*p3)[2] = " << (*p3)[2] << "\n";
    std::cout << "   → 동작하지만 타입 안정성 위반!\n\n";
    
    // 7. 다른 예제로 확인
    std::cout << "7. 다른 크기 배열로 테스트:\n";
    int smallArr[3] = {10, 20, 30};
    
    // int (*p4)[5] = &smallArr;  // 컴파일 에러! 크기가 다름
    std::cout << "   int smallArr[3] = {10, 20, 30};\n";
    std::cout << "   int (*p4)[5] = &smallArr;  // ❌ 에러! 크기 다름\n";
    std::cout << "   → int(*)[3] ≠ int(*)[5]\n\n";
    
    // 8. 올바른 방법들
    std::cout << "8. 올바른 방법들:\n\n";
    
    std::cout << "   방법 1: &arr 사용 (정확한 타입)\n";
    int (*correct1)[5] = &arr;
    std::cout << "   int (*correct1)[5] = &arr;\n\n";
    
    std::cout << "   방법 2: auto 사용 (C++11+)\n";
    auto correct2 = &arr;
    std::cout << "   auto correct2 = &arr;  // 타입 자동 추론\n";
    std::cout << "   correct2 타입: " << typeid(correct2).name() << "\n\n";
    
    std::cout << "   방법 3: decltype 사용 (C++11+)\n";
    decltype(&arr) correct3 = &arr;
    std::cout << "   decltype(&arr) correct3 = &arr;\n\n";
    
    std::cout << "   방법 4: 일반 포인터로 받기 (크기 정보 잃음)\n";
    int* simplePtr = arr;  // OK, 하지만 크기 정보 손실
    std::cout << "   int* simplePtr = arr;  // OK, 하지만 크기 정보 손실\n\n";
    
    // 9. 함수 매개변수에서도 마찬가지
    std::cout << "9. 함수 매개변수에서도 동일한 규칙:\n";
    
    auto testFunc = [](int (*param)[5]) {
        std::cout << "   함수에서 받은 배열: (*param)[0] = " << (*param)[0] << "\n";
    };
    
    std::cout << "   void testFunc(int (*param)[5]);\n";
    std::cout << "   testFunc(&arr);  // ✅ OK\n";
    testFunc(&arr);
    std::cout << "   testFunc(arr);   // ❌ 컴파일 에러\n\n";
    
    std::cout << "=== 결론 ===\n";
    std::cout << "❌ int (*p)[5] = arr;   // 불가능 (타입 불일치)\n";
    std::cout << "✅ int (*p)[5] = &arr;  // 가능 (타입 일치)\n\n";
    
    std::cout << "이유:\n";
    std::cout << "• arr은 int*로 decay (첫 요소 포인터)\n";
    std::cout << "• &arr은 int(*)[5] (배열 전체 포인터)\n";
    std::cout << "• 주소는 같지만 타입이 달라서 직접 할당 불가\n";
    
    return 0;
}