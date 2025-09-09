#include <iostream>

int main() {
    // 1. 일반 배열 선언 - 크기 필수
    int arr1[5];  // OK: 크기 5 명시
    // int arr2[];  // 컴파일 에러: 크기 없음
    
    // 2. 초기화와 함께 선언 - 크기 생략 가능
    int arr3[] = {1, 2, 3, 4, 5};  // OK: 컴파일러가 크기 5로 추론
    int arr4[10] = {1, 2, 3};      // OK: 나머지는 0으로 초기화
    
    // 3. 문자열 - 크기 생략 가능
    char str1[] = "Hello";     // OK: 크기 6 (널 문자 포함)
    char str2[10] = "Hello";   // OK: 크기 10 명시
    
    // 4. 함수 매개변수 - 첫 번째 차원만 생략 가능
    // void func(int arr[]);    // OK: 실제로는 int* arr
    // void func(int arr[10]);  // OK: 하지만 10은 무시됨
    
    // 5. 동적 크기가 필요한 경우
    int n = 5;
    // int arr5[n];  // C99 VLA (Variable Length Array) - C++에서는 비표준
    int* arr6 = new int[n];  // OK: 동적 할당 사용
    
    std::cout << "arr3 크기: " << sizeof(arr3)/sizeof(arr3[0]) << std::endl;
    std::cout << "str1 크기: " << sizeof(str1) << std::endl;
    
    delete[] arr6;
    return 0;
}