#include <iostream>
#include <typeinfo>

// int(*)[5] 문법 완전 정복

int main() {
    std::cout << "=== 배열 포인터 문법: int(*)[5] 이해하기 ===\n\n";
    
    // 1. 기본 포인터 vs 배열 포인터
    std::cout << "1. 포인터 선언 문법 비교:\n";
    
    int x = 10;
    int* p1 = &x;           // 일반 int 포인터
    std::cout << "   int* p1;          // int를 가리키는 포인터\n";
    
    int arr[5] = {1,2,3,4,5};
    int (*p2)[5] = &arr;    // 배열 포인터
    std::cout << "   int (*p2)[5];     // int[5] 배열을 가리키는 포인터\n\n";
    
    // 2. 괄호가 중요한 이유
    std::cout << "2. 괄호의 중요성:\n";
    
    // int *p3[5];   // 이것은 포인터의 배열 (5개의 int* 포인터)
    // int (*p4)[5]; // 이것은 배열의 포인터 (int[5]를 가리키는 포인터)
    
    std::cout << "   int *p3[5];       // 포인터의 배열 (int* 5개)\n";
    std::cout << "                     // = {ptr0, ptr1, ptr2, ptr3, ptr4}\n\n";
    
    std::cout << "   int (*p4)[5];     // 배열의 포인터 (int[5]를 가리킴)\n";
    std::cout << "                     // = 하나의 포인터가 5개짜리 배열 전체를 가리킴\n\n";
    
    // 3. 문법 분해
    std::cout << "3. int (*ptr)[5] 문법 분해:\n";
    std::cout << "   int          // 기본 타입\n";
    std::cout << "   (*ptr)       // ptr은 포인터다\n";
    std::cout << "   [5]          // 5개 요소를 가진 배열을\n";
    std::cout << "   → 'ptr은 int[5] 배열을 가리키는 포인터'\n\n";
    
    // 4. 실제 사용 예제
    std::cout << "4. 실제 사용 예제:\n";
    
    int array[5] = {10, 20, 30, 40, 50};
    int (*arrayPtr)[5] = &array;
    
    std::cout << "   int array[5] = {10, 20, 30, 40, 50};\n";
    std::cout << "   int (*arrayPtr)[5] = &array;\n\n";
    
    std::cout << "   arrayPtr = " << arrayPtr << "\n";
    std::cout << "   *arrayPtr = " << *arrayPtr << " (배열로 역참조)\n";
    std::cout << "   (*arrayPtr)[0] = " << (*arrayPtr)[0] << "\n";
    std::cout << "   (*arrayPtr)[2] = " << (*arrayPtr)[2] << "\n\n";
    
    // 5. 포인터 배열 vs 배열 포인터
    std::cout << "5. 포인터 배열 vs 배열 포인터 비교:\n\n";
    
    // 포인터 배열
    int a = 10, b = 20, c = 30;
    int* ptrArray[3] = {&a, &b, &c};  // 3개의 포인터를 담는 배열
    
    std::cout << "   포인터 배열: int* ptrArray[3]\n";
    std::cout << "   크기: " << sizeof(ptrArray) << " bytes (8 * 3 = 24)\n";
    for(int i = 0; i < 3; i++) {
        std::cout << "   ptrArray[" << i << "] = " << ptrArray[i] 
                  << ", 값: " << *ptrArray[i] << "\n";
    }
    
    // 배열 포인터
    int nums[3] = {100, 200, 300};
    int (*arrPtr)[3] = &nums;  // 배열 전체를 가리키는 포인터 1개
    
    std::cout << "\n   배열 포인터: int (*arrPtr)[3]\n";
    std::cout << "   크기: " << sizeof(arrPtr) << " bytes (포인터 1개)\n";
    std::cout << "   arrPtr = " << arrPtr << "\n";
    std::cout << "   (*arrPtr)[0] = " << (*arrPtr)[0] << "\n";
    std::cout << "   (*arrPtr)[1] = " << (*arrPtr)[1] << "\n";
    std::cout << "   (*arrPtr)[2] = " << (*arrPtr)[2] << "\n\n";
    
    // 6. 2차원 배열과 배열 포인터
    std::cout << "6. 2차원 배열에서 활용:\n";
    
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    // matrix는 int[4]를 가리키는 포인터로 decay
    int (*rowPtr)[4] = matrix;  // 첫 번째 행을 가리킴
    
    std::cout << "   int matrix[3][4];\n";
    std::cout << "   int (*rowPtr)[4] = matrix;\n\n";
    
    std::cout << "   rowPtr가 가리키는 행: ";
    for(int i = 0; i < 4; i++) {
        std::cout << (*rowPtr)[i] << " ";
    }
    std::cout << "\n";
    
    rowPtr++;  // 다음 행으로 이동 (16바이트 점프)
    std::cout << "   rowPtr++ 후 행: ";
    for(int i = 0; i < 4; i++) {
        std::cout << (*rowPtr)[i] << " ";
    }
    std::cout << "\n\n";
    
    // 7. 함수 매개변수로 사용
    std::cout << "7. 함수 매개변수로 배열 포인터 사용:\n";
    
    auto processArray = [](int (*arr)[5]) {
        std::cout << "   받은 배열: ";
        for(int i = 0; i < 5; i++) {
            std::cout << (*arr)[i] << " ";
        }
        std::cout << "\n";
        
        // 배열 수정 가능
        (*arr)[0] = 999;
    };
    
    int testArr[5] = {1, 2, 3, 4, 5};
    std::cout << "   원본 배열: ";
    for(int i = 0; i < 5; i++) {
        std::cout << testArr[i] << " ";
    }
    std::cout << "\n";
    
    processArray(&testArr);  // 배열의 주소 전달
    
    std::cout << "   수정 후: ";
    for(int i = 0; i < 5; i++) {
        std::cout << testArr[i] << " ";
    }
    std::cout << "\n\n";
    
    // 8. typedef로 단순화
    std::cout << "8. typedef로 가독성 향상:\n";
    
    typedef int ArrayType[5];  // int[5]를 ArrayType으로 정의
    typedef int (*ArrayPtrType)[5];  // int(*)[5]를 ArrayPtrType으로 정의
    
    ArrayType myArray = {11, 22, 33, 44, 55};
    ArrayPtrType myPtr = &myArray;
    
    std::cout << "   typedef int ArrayType[5];\n";
    std::cout << "   typedef int (*ArrayPtrType)[5];\n\n";
    std::cout << "   ArrayType myArray = {11, 22, 33, 44, 55};\n";
    std::cout << "   ArrayPtrType myPtr = &myArray;\n";
    std::cout << "   (*myPtr)[2] = " << (*myPtr)[2] << "\n\n";
    
    // 9. C++11 using 문법
    std::cout << "9. C++11 using 문법 (더 명확):\n";
    
    using Array5 = int[5];
    using Array5Ptr = int(*)[5];
    
    Array5 modernArray = {111, 222, 333, 444, 555};
    Array5Ptr modernPtr = &modernArray;
    
    std::cout << "   using Array5 = int[5];\n";
    std::cout << "   using Array5Ptr = int(*)[5];\n";
    std::cout << "   (*modernPtr)[3] = " << (*modernPtr)[3] << "\n\n";
    
    // 10. 정리
    std::cout << "=== 핵심 정리 ===\n";
    std::cout << "int (*ptr)[5] 읽는 법:\n";
    std::cout << "1. 안에서 밖으로 읽기\n";
    std::cout << "2. (*ptr) → ptr은 포인터\n";
    std::cout << "3. [5] → 5개 요소 배열을\n";
    std::cout << "4. int → int 타입의\n";
    std::cout << "→ 'ptr은 5개의 int를 가진 배열을 가리키는 포인터'\n\n";
    
    std::cout << "기억할 점:\n";
    std::cout << "• int *p[5]   = 포인터들의 배열 (포인터 5개)\n";
    std::cout << "• int (*p)[5] = 배열의 포인터 (배열 전체를 가리키는 포인터 1개)\n";
    std::cout << "• 괄호가 우선순위를 결정!\n";
    
    return 0;
}