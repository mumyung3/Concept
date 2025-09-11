#include <iostream>

void testArrayDecay(int arr[]) {
    std::cout << "함수 내부에서 sizeof(arr): " << sizeof(arr) << " (포인터 크기)" << std::endl;
    std::cout << "함수 내부에서 arr의 주소: " << arr << std::endl;
}

void testArrayDecayWithSize(int arr[5]) {  
    std::cout << "크기 명시해도 sizeof(arr): " << sizeof(arr) << " (여전히 포인터)" << std::endl;
}

void testPointer(int* ptr) {
    std::cout << "포인터로 받을 때 sizeof(ptr): " << sizeof(ptr) << std::endl;
}

// C++에서는 참조로 배열을 받을 수 있음 (크기 고정)
void testArrayReference(int (&arr)[5]) {
    std::cout << "참조로 받을 때 sizeof(arr): " << sizeof(arr) << " (실제 배열 크기)" << std::endl;
}

// 템플릿으로 배열 크기를 유지하는 방법
template<size_t N>
void testArrayTemplate(int (&arr)[N]) {
    std::cout << "템플릿 참조 sizeof(arr): " << sizeof(arr) << " (크기: " << N << ")" << std::endl;
}

int main() {
    int myArray[5] = {1, 2, 3, 4, 5};
    
    std::cout << "=== 배열 정보 ===" << std::endl;
    std::cout << "main에서 sizeof(myArray): " << sizeof(myArray) << " (실제 배열 크기)" << std::endl;
    std::cout << "main에서 myArray 주소: " << myArray << std::endl;
    std::cout << "배열 원소 개수: " << sizeof(myArray)/sizeof(myArray[0]) << std::endl;
    
    std::cout << "\n=== 함수 호출 테스트 ===" << std::endl;
    
    // 이 세 가지는 모두 동일하게 작동 (포인터로 decay)
    testArrayDecay(myArray);
    testArrayDecayWithSize(myArray);
    testPointer(myArray);
    
    std::cout << "\n=== C++ 참조 방식 ===" << std::endl;
    testArrayReference(myArray);
    testArrayTemplate(myArray);
    
    std::cout << "\n=== Decay 증명 ===" << std::endl;
    // 다음은 컴파일 에러가 발생함을 보여주는 예제들
    
    // 1. 크기가 다른 배열을 같은 함수에 넘길 수 있음 (decay 때문)
    int bigArray[10] = {0};
    testArrayDecayWithSize(bigArray);  // 컴파일 됨! (크기 무시됨)
    
    // 2. 실제로는 이 모든 선언이 동일함
    std::cout << "이 함수 시그니처들은 모두 동일함:" << std::endl;
    std::cout << "void func(int arr[])" << std::endl;
    std::cout << "void func(int arr[5])" << std::endl;  
    std::cout << "void func(int arr[100])" << std::endl;
    std::cout << "void func(int* arr)" << std::endl;
    
    return 0;
}