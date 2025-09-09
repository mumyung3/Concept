#include <iostream>
#include <typeinfo>

// int[] vs int* 차이점 분석

void printArrayInfo(int arr[]) {  // 실제로는 int*로 받음
    std::cout << "함수 내부 sizeof(arr): " << sizeof(arr) << " bytes (포인터 크기)\n";
}

void printArrayInfo2(int arr[10]) {  // 여전히 int*로 받음
    std::cout << "함수 내부 sizeof(arr[10]): " << sizeof(arr) << " bytes (여전히 포인터)\n";
}

template<size_t N>
void printRealArray(int (&arr)[N]) {  // 진짜 배열 참조
    std::cout << "템플릿 함수 sizeof(arr): " << sizeof(arr) << " bytes (진짜 배열 크기)\n";
    std::cout << "배열 요소 개수: " << N << "\n";
}

int main() {
    std::cout << "=== int[] vs int* 차이점 ===\n\n";
    
    // 1. 선언과 초기화
    std::cout << "1. 선언과 초기화:\n";
    int array[5] = {1, 2, 3, 4, 5};  // 배열: 스택에 20바이트 할당
    int* pointer = new int[5];       // 포인터: 힙을 가리키는 8바이트 포인터
    
    std::cout << "   int array[5]:  실제 메모리 20바이트 할당 (스택)\n";
    std::cout << "   int* pointer:  8바이트 포인터 + 힙에 별도 메모리\n\n";
    
    // 2. sizeof 연산자 결과
    std::cout << "2. sizeof 연산자 차이:\n";
    std::cout << "   sizeof(array):   " << sizeof(array) << " bytes (5 * 4 = 20)\n";
    std::cout << "   sizeof(pointer): " << sizeof(pointer) << " bytes (포인터 크기)\n\n";
    
    // 3. 타입 정보
    std::cout << "3. 타입 정보:\n";
    std::cout << "   array의 타입:   " << typeid(array).name() << " (int[5])\n";
    std::cout << "   pointer의 타입: " << typeid(pointer).name() << " (int*)\n";
    
    auto& arrayRef = array;   // int(&)[5] 타입
    auto& pointerRef = pointer; // int*& 타입
    std::cout << "   array 참조 타입:   " << typeid(arrayRef).name() << "\n";
    std::cout << "   pointer 참조 타입: " << typeid(pointerRef).name() << "\n\n";
    
    // 4. 주소 연산
    std::cout << "4. 주소 연산의 차이:\n";
    std::cout << "   array 주소:    " << array << "\n";
    std::cout << "   &array 주소:   " << &array << " (같은 주소)\n";
    std::cout << "   &array[0]:     " << &array[0] << " (같은 주소)\n";
    
    std::cout << "\n   pointer 주소:  " << pointer << " (가리키는 곳)\n";
    std::cout << "   &pointer 주소: " << &pointer << " (포인터 변수 자체의 주소 - 다름!)\n";
    std::cout << "   &pointer[0]:   " << &pointer[0] << " (첫 요소 주소)\n\n";
    
    // 5. 배열 decay (배열이 포인터로 변환)
    std::cout << "5. 배열 Decay (함수 전달 시):\n";
    printArrayInfo(array);    // 배열이 포인터로 decay
    printArrayInfo2(array);   // 크기 명시해도 포인터로 decay
    printRealArray(array);    // 템플릿 참조는 진짜 배열 타입 유지
    std::cout << "\n";
    
    // 6. 재할당 가능 여부
    std::cout << "6. 재할당 가능 여부:\n";
    int other[3] = {7, 8, 9};
    
    // array = other;  // 컴파일 에러! 배열은 재할당 불가
    std::cout << "   array = other;   // 에러! 배열은 lvalue가 아님\n";
    
    int* tempPointer = pointer;  // 원래 주소 백업
    pointer = other;  // OK! 포인터는 다른 주소로 변경 가능
    std::cout << "   pointer = other; // OK! 포인터는 재할당 가능\n\n";
    pointer = tempPointer;  // 원래 주소로 복원 (나중에 delete를 위해)
    
    // 7. 메모리 위치
    std::cout << "7. 메모리 위치:\n";
    int localArray[3] = {10, 20, 30};
    int* heapPointer = new int[3]{10, 20, 30};
    
    std::cout << "   스택 배열 주소:  " << localArray << "\n";
    std::cout << "   힙 포인터 주소:  " << heapPointer << "\n";
    std::cout << "   주소 차이: " << ((char*)localArray - (char*)heapPointer) << " bytes\n\n";
    
    // 8. 다차원 배열
    std::cout << "8. 다차원 배열:\n";
    int array2D[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    int** pointer2D = new int*[3];
    for(int i = 0; i < 3; i++) {
        pointer2D[i] = new int[4];
    }
    
    std::cout << "   sizeof(array2D):   " << sizeof(array2D) << " bytes (연속된 메모리)\n";
    std::cout << "   sizeof(pointer2D): " << sizeof(pointer2D) << " bytes (포인터의 포인터)\n";
    
    // 메모리 레이아웃 차이
    std::cout << "\n   array2D 메모리 레이아웃 (연속):\n";
    for(int i = 0; i < 3; i++) {
        std::cout << "   행 " << i << " 주소: " << array2D[i] << " (간격: ";
        if(i > 0) std::cout << (char*)array2D[i] - (char*)array2D[i-1];
        else std::cout << "0";
        std::cout << " bytes)\n";
    }
    
    std::cout << "\n   pointer2D 메모리 레이아웃 (분산):\n";
    for(int i = 0; i < 3; i++) {
        std::cout << "   행 " << i << " 주소: " << pointer2D[i] << " (불연속적)\n";
    }
    
    // 9. 문자열 리터럴
    std::cout << "\n9. 문자열 리터럴의 경우:\n";
    char strArray[] = "Hello";      // char[6] 타입, 스택에 복사
    const char* strPointer = "World"; // const char* 타입, 문자열 리터럴 주소
    
    std::cout << "   sizeof(strArray):   " << sizeof(strArray) << " bytes (널 포함)\n";
    std::cout << "   sizeof(strPointer): " << sizeof(strPointer) << " bytes (포인터)\n";
    
    strArray[0] = 'h';  // OK! 수정 가능
    // strPointer[0] = 'w';  // 런타임 에러! 문자열 리터럴은 수정 불가
    std::cout << "   strArray 수정 가능: " << strArray << "\n";
    std::cout << "   strPointer는 리터럴 가리킴 (수정 불가)\n";
    
    // 10. 함수 매개변수로서의 차이
    std::cout << "\n10. 함수 매개변수 선언:\n";
    std::cout << "   void func(int arr[])   → 실제로는 void func(int* arr)\n";
    std::cout << "   void func(int arr[10]) → 실제로는 void func(int* arr)\n";
    std::cout << "   void func(int* arr)    → 그대로 void func(int* arr)\n";
    std::cout << "   void func(int (&arr)[5]) → 진짜 배열 참조 (크기 고정)\n";
    
    // 메모리 정리
    delete[] pointer;
    delete[] heapPointer;
    for(int i = 0; i < 3; i++) {
        delete[] pointer2D[i];
    }
    delete[] pointer2D;
    
    std::cout << "\n=== 핵심 차이점 정리 ===\n";
    std::cout << "1. 배열(int[]): 고정 크기, 연속 메모리, 재할당 불가\n";
    std::cout << "2. 포인터(int*): 가변 주소, 재할당 가능, 동적 할당\n";
    std::cout << "3. sizeof: 배열은 전체 크기, 포인터는 8바이트\n";
    std::cout << "4. 함수 전달 시 배열은 포인터로 decay\n";
    std::cout << "5. 배열 이름은 첫 요소의 주소로 암시적 변환 가능\n";
    
    return 0;
}