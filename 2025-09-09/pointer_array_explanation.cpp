#include <iostream>
#include <string>

// 포인터 배열(Pointer Array) 완전 정복

int main() {
    std::cout << "=== 포인터 배열(Pointer Array)이란? ===\n\n";
    
    // 1. 포인터 배열의 정의
    std::cout << "1. 포인터 배열의 정의:\n";
    std::cout << "   포인터 배열 = 포인터들을 저장하는 배열\n";
    std::cout << "   즉, 배열의 각 요소가 포인터인 배열\n\n";
    
    // 기본 예제
    int a = 10, b = 20, c = 30, d = 40, e = 50;
    
    // 이것이 포인터 배열!
    int* ptrArray[5] = {&a, &b, &c, &d, &e};
    
    std::cout << "   예시: int* ptrArray[5] = {&a, &b, &c, &d, &e};\n";
    std::cout << "   배열의 각 요소가 int* 포인터임!\n\n";
    
    // 2. 메모리 구조 시각화
    std::cout << "2. 메모리 구조:\n";
    std::cout << "   ptrArray 배열 (포인터들을 저장):\n";
    std::cout << "   ┌──────────────┬──────────────┬──────────────┬──────────────┬──────────────┐\n";
    std::cout << "   │   ptrArray[0]│   ptrArray[1]│   ptrArray[2]│   ptrArray[3]│   ptrArray[4]│\n";
    std::cout << "   │     (주소)   │     (주소)   │     (주소)   │     (주소)   │     (주소)   │\n";
    std::cout << "   └──────────────┴──────────────┴──────────────┴──────────────┴──────────────┘\n";
    
    for(int i = 0; i < 5; i++) {
        std::cout << "   ptrArray[" << i << "] = " << ptrArray[i] << " (주소를 저장)\n";
    }
    
    std::cout << "\n   이 주소들이 가리키는 실제 값들:\n";
    for(int i = 0; i < 5; i++) {
        std::cout << "   *ptrArray[" << i << "] = " << *ptrArray[i] << " (실제 값)\n";
    }
    std::cout << "\n";
    
    // 3. 다양한 포인터 배열 예제
    std::cout << "3. 다양한 포인터 배열 예제:\n\n";
    
    // char* 포인터 배열 (문자열 배열)
    const char* strArray[4] = {"Hello", "World", "from", "C++"};
    std::cout << "   문자열 포인터 배열: const char* strArray[4]\n";
    for(int i = 0; i < 4; i++) {
        std::cout << "   strArray[" << i << "] = \"" << strArray[i] << "\"\n";
    }
    std::cout << "\n";
    
    // double* 포인터 배열
    double x = 1.1, y = 2.2, z = 3.3;
    double* doubleArray[3] = {&x, &y, &z};
    std::cout << "   double 포인터 배열: double* doubleArray[3]\n";
    for(int i = 0; i < 3; i++) {
        std::cout << "   doubleArray[" << i << "] = " << doubleArray[i] 
                  << ", 값: " << *doubleArray[i] << "\n";
    }
    std::cout << "\n";
    
    // 4. 포인터 배열의 특징
    std::cout << "4. 포인터 배열의 특징:\n";
    std::cout << "   • 각 요소는 독립적인 포인터\n";
    std::cout << "   • 서로 다른 메모리 위치를 가리킬 수 있음\n";
    std::cout << "   • 포인터를 다른 주소로 변경 가능\n";
    std::cout << "   • 크기 = 포인터 크기 × 배열 크기\n\n";
    
    std::cout << "   sizeof(ptrArray) = " << sizeof(ptrArray) << " bytes (8 × 5 = 40)\n";
    std::cout << "   sizeof(ptrArray[0]) = " << sizeof(ptrArray[0]) << " bytes (하나의 포인터)\n\n";
    
    // 5. 포인터 재할당
    std::cout << "5. 포인터 재할당 가능:\n";
    int newValue = 999;
    std::cout << "   원래 ptrArray[0]이 가리키는 값: " << *ptrArray[0] << "\n";
    
    ptrArray[0] = &newValue;  // 포인터 재할당
    std::cout << "   ptrArray[0] = &newValue 후:\n";
    std::cout << "   *ptrArray[0] = " << *ptrArray[0] << " (새로운 값)\n\n";
    
    // 6. 실제 활용 예: 명령행 인수
    std::cout << "6. 실제 활용: main 함수의 argv는 포인터 배열!\n";
    std::cout << "   int main(int argc, char* argv[])\n";
    std::cout << "   argv는 char* 포인터들의 배열\n";
    std::cout << "   argv[0] = 프로그램 이름\n";
    std::cout << "   argv[1] = 첫 번째 인수\n";
    std::cout << "   argv[2] = 두 번째 인수\n";
    std::cout << "   ...\n\n";
    
    // 7. 함수 포인터 배열
    std::cout << "7. 함수 포인터 배열:\n";
    
    auto add = [](int a, int b) -> int { return a + b; };
    auto subtract = [](int a, int b) -> int { return a - b; };
    auto multiply = [](int a, int b) -> int { return a * b; };
    
    // 함수 포인터들의 배열
    int (*operations[3])(int, int) = {add, subtract, multiply};
    
    std::cout << "   함수 포인터 배열: int (*operations[3])(int, int)\n";
    const char* opNames[] = {"덧셈", "뺄셈", "곱셈"};
    
    for(int i = 0; i < 3; i++) {
        int result = operations[i](10, 5);
        std::cout << "   operations[" << i << "](10, 5) = " << result 
                  << " (" << opNames[i] << ")\n";
    }
    std::cout << "\n";
    
    // 8. 2차원 포인터 배열
    std::cout << "8. 2차원 포인터 배열 (이중 포인터 배열):\n";
    
    int val1 = 100, val2 = 200;
    int* ptr1 = &val1;
    int* ptr2 = &val2;
    
    // 포인터의 포인터 배열
    int** ptrPtrArray[2] = {&ptr1, &ptr2};
    
    std::cout << "   int** ptrPtrArray[2] = {&ptr1, &ptr2};\n";
    for(int i = 0; i < 2; i++) {
        std::cout << "   ptrPtrArray[" << i << "] = " << ptrPtrArray[i] 
                  << " (포인터의 주소)\n";
        std::cout << "   *ptrPtrArray[" << i << "] = " << *ptrPtrArray[i] 
                  << " (포인터가 가리키는 주소)\n";
        std::cout << "   **ptrPtrArray[" << i << "] = " << **ptrPtrArray[i] 
                  << " (최종 값)\n\n";
    }
    
    // 9. 포인터 배열 vs 배열 포인터 비교
    std::cout << "9. 포인터 배열 vs 배열 포인터 최종 비교:\n\n";
    
    // 포인터 배열
    int nums1 = 1, nums2 = 2, nums3 = 3;
    int* ptrArr[3] = {&nums1, &nums2, &nums3};  // 포인터 3개의 배열
    
    // 배열 포인터  
    int actualArr[3] = {1, 2, 3};
    int (*arrPtr)[3] = &actualArr;  // 배열 전체를 가리키는 포인터
    
    std::cout << "   포인터 배열 int* ptrArr[3]:\n";
    std::cout << "   • 포인터 3개가 각각 다른 변수를 가리킴\n";
    std::cout << "   • ptrArr[0], ptrArr[1], ptrArr[2] 모두 다른 주소\n";
    std::cout << "   • 크기: " << sizeof(ptrArr) << " bytes\n\n";
    
    std::cout << "   배열 포인터 int (*arrPtr)[3]:\n";
    std::cout << "   • 포인터 1개가 배열 전체를 가리킴\n";
    std::cout << "   • (*arrPtr)[0], (*arrPtr)[1], (*arrPtr)[2] 연속된 메모리\n";
    std::cout << "   • 크기: " << sizeof(arrPtr) << " bytes\n\n";
    
    // 10. 실제 메모리 위치 확인
    std::cout << "10. 실제 메모리 위치 비교:\n";
    std::cout << "    포인터 배열의 각 요소가 가리키는 곳:\n";
    for(int i = 0; i < 3; i++) {
        std::cout << "    ptrArr[" << i << "] = " << ptrArr[i] 
                  << " (분산된 위치)\n";
    }
    
    std::cout << "\n    배열 포인터가 가리키는 배열:\n";
    for(int i = 0; i < 3; i++) {
        std::cout << "    &(*arrPtr)[" << i << "] = " << &(*arrPtr)[i] 
                  << " (연속된 위치)\n";
    }
    
    std::cout << "\n=== 핵심 정리 ===\n";
    std::cout << "포인터 배열(int* arr[5]):\n";
    std::cout << "• 배열의 각 요소가 포인터\n";
    std::cout << "• 포인터 5개를 담는 배열\n";
    std::cout << "• 각 포인터는 서로 다른 곳을 가리킬 수 있음\n";
    std::cout << "• 주로 문자열 배열, 함수 포인터 배열 등에 사용\n";
    
    return 0;
}