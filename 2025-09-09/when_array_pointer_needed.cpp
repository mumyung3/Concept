#include <iostream>

// 언제 배열 포인터가 실제로 필요한가?

void printArray(int* arr, int size) {
    // 일반적인 방법: 배열이 포인터로 decay되어 전달
    std::cout << "일반적인 함수 (int* arr): ";
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

void printFixedArray(int (*arr)[5]) {
    // 배열 포인터: 정확히 5개 요소 배열만 받음
    std::cout << "배열 포인터 함수 (int (*arr)[5]): ";
    for(int i = 0; i < 5; i++) {
        std::cout << (*arr)[i] << " ";
    }
    std::cout << "\n";
    std::cout << "함수 내에서 배열 크기 알 수 있음: " << sizeof(*arr) << " bytes\n";
}

template<size_t N>
void printTemplateArray(int (&arr)[N]) {
    // 템플릿 참조: 더 좋은 방법 (C++에서 권장)
    std::cout << "템플릿 함수 (int (&arr)[" << N << "]): ";
    for(size_t i = 0; i < N; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cout << "=== 배열 포인터가 실제로 필요한 경우 ===\n\n";
    
    int arr[5] = {1, 2, 3, 4, 5};
    
    std::cout << "1. 일반적인 경우 - 배열 이름만으로 충분:\n";
    std::cout << "   int arr[5] = {1, 2, 3, 4, 5};\n";
    std::cout << "   printArray(arr, 5);  // arr이 int*로 자동 변환\n";
    printArray(arr, 5);
    std::cout << "\n";
    
    std::cout << "2. 배열 포인터가 필요한 경우들:\n\n";
    
    // Case 1: 함수에서 배열 크기를 정확히 알아야 할 때
    std::cout << "   Case 1: 함수에서 배열 크기를 보존해야 할 때\n";
    printFixedArray(&arr);  // 배열 전체의 주소 전달
    std::cout << "\n";
    
    // Case 2: 2차원 배열의 행을 순회할 때
    std::cout << "   Case 2: 2차원 배열의 행 순회\n";
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    int (*rowPtr)[4];  // 4개 int 배열을 가리키는 포인터
    std::cout << "   int (*rowPtr)[4];\n";
    
    for(int i = 0; i < 3; i++) {
        rowPtr = &matrix[i];  // i번째 행의 주소
        std::cout << "   행 " << i << ": ";
        for(int j = 0; j < 4; j++) {
            std::cout << (*rowPtr)[j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    
    // Case 3: 포인터 연산에서 배열 단위로 점프해야 할 때
    std::cout << "   Case 3: 배열 단위로 포인터 연산\n";
    int arrays[3][4] = {
        {10, 20, 30, 40},
        {50, 60, 70, 80},
        {90, 100, 110, 120}
    };
    
    int (*arrPtr)[4] = arrays;  // 첫 번째 배열을 가리킴
    std::cout << "   int (*arrPtr)[4] = arrays;\n";
    
    for(int i = 0; i < 3; i++) {
        std::cout << "   배열 " << i << ": ";
        for(int j = 0; j < 4; j++) {
            std::cout << (*arrPtr)[j] << " ";
        }
        std::cout << "\n";
        arrPtr++;  // 다음 배열로 이동 (16바이트 점프)
    }
    std::cout << "\n";
    
    // Case 4: 배열의 배열을 다룰 때
    std::cout << "   Case 4: 배열들의 배열\n";
    int arr1[3] = {1, 2, 3};
    int arr2[3] = {4, 5, 6};
    int arr3[3] = {7, 8, 9};
    
    // 배열 포인터들의 배열
    int (*arrayPtrs[3])[3] = {&arr1, &arr2, &arr3};
    std::cout << "   int (*arrayPtrs[3])[3] = {&arr1, &arr2, &arr3};\n";
    
    for(int i = 0; i < 3; i++) {
        std::cout << "   배열 " << i << ": ";
        for(int j = 0; j < 3; j++) {
            std::cout << (*arrayPtrs[i])[j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    
    // Case 5: 함수 포인터에서 배열을 반환할 때
    std::cout << "   Case 5: 함수가 배열 포인터를 반환\n";
    
    auto getArrayPtr = []() -> int(*)[5] {
        static int result[5] = {11, 22, 33, 44, 55};
        return &result;
    };
    
    int (*returnedPtr)[5] = getArrayPtr();
    std::cout << "   함수에서 반환된 배열: ";
    for(int i = 0; i < 5; i++) {
        std::cout << (*returnedPtr)[i] << " ";
    }
    std::cout << "\n\n";
    
    // 실제로는 대부분의 경우 더 나은 방법이 있음
    std::cout << "3. 더 나은 C++ 방법들:\n\n";
    
    std::cout << "   대신 템플릿 참조 사용 (권장):\n";
    printTemplateArray(arr);
    std::cout << "\n";
    
    std::cout << "   또는 std::array 사용 (C++11+):\n";
    std::cout << "   std::array<int, 5> modernArray = {1, 2, 3, 4, 5};\n";
    std::cout << "   크기 정보 보존, 더 안전함\n\n";
    
    std::cout << "=== 결론 ===\n";
    std::cout << "질문이 맞습니다! 대부분의 경우 배열 이름으로 충분함\n\n";
    
    std::cout << "배열 포인터가 정말 필요한 경우:\n";
    std::cout << "✓ 2차원 배열의 행 단위 조작\n";
    std::cout << "✓ 배열 단위로 포인터 연산\n";
    std::cout << "✓ 함수에서 정확한 배열 크기 보존 필요\n";
    std::cout << "✓ 배열들의 배열 관리\n\n";
    
    std::cout << "하지만 현대 C++에서는:\n";
    std::cout << "• 템플릿 참조: template<size_t N> func(int (&arr)[N])\n";
    std::cout << "• std::array: std::array<int, 5>\n";
    std::cout << "• std::vector: 동적 크기\n";
    std::cout << "이 더 안전하고 편리합니다!\n";
    
    return 0;
}