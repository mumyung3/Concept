#include <iostream>

int main() {
    // 1. 컴파일 타임 상수 - OK
    const int SIZE1 = 10;
    int arr1[SIZE1];  // OK: const 상수
    
    constexpr int SIZE2 = 20;
    int arr2[SIZE2];  // OK: constexpr 상수
    
    #define SIZE3 30
    int arr3[SIZE3];  // OK: 매크로 상수
    
    // 2. 런타임 변수 - 에러
    int n = 10;
    // int arr4[n];  // 에러: 변수는 사용 불가 (C99 VLA는 C++에서 비표준)
    
    // 3. const지만 런타임에 결정되는 값 - 에러
    int input;
    std::cin >> input;
    const int SIZE4 = input;
    // int arr5[SIZE4];  // 에러: 런타임에 결정되는 const
    
    // 4. 해결 방법: 동적 할당
    int* arr6 = new int[n];     // OK: new 사용
    int* arr7 = new int[input]; // OK: 런타임 크기 가능
    
    std::cout << "정적 배열은 컴파일 타임에 크기가 확정되어야 함\n";
    std::cout << "변수 크기가 필요하면 동적 할당 사용\n";
    
    delete[] arr6;
    delete[] arr7;
    
    return 0;
}