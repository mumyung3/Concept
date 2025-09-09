#include <iostream>
#include <cstdlib>  // malloc, free
#include <cstring>  // memcpy

// void* 포인터 캐스팅 설명

int main() {
    std::cout << "=== void* 포인터 캐스팅 이해하기 ===\n\n";
    
    // 1. void* 란?
    // - "타입이 없는 포인터" 또는 "제네릭 포인터"
    // - 어떤 타입의 주소든 저장 가능
    // - 하지만 직접 역참조(dereference) 불가능
    
    int num = 42;
    double pi = 3.14;
    char ch = 'A';
    
    void* voidPtr;  // void 포인터 선언
    
    // 어떤 타입의 주소든 저장 가능
    voidPtr = &num;  // int* -> void* (암시적 변환 OK)
    voidPtr = &pi;   // double* -> void*
    voidPtr = &ch;   // char* -> void*
    
    // 2. malloc이 void*를 반환하는 이유
    std::cout << "2. malloc과 void* 캐스팅:\n";
    
    // C 스타일 (명시적 캐스팅 필요)
    int* arr_c = (int*)malloc(5 * sizeof(int));  // void* -> int* 캐스팅
    
    // malloc은 void*를 반환 (어떤 타입으로든 변환 가능하도록)
    // 사용하려면 원하는 타입으로 캐스팅 필요
    
    if (arr_c != NULL) {
        for (int i = 0; i < 5; i++) {
            arr_c[i] = i * 10;
            std::cout << "arr_c[" << i << "] = " << arr_c[i] << "\n";
        }
    }
    
    // 3. void* 사용시 주의사항
    std::cout << "\n3. void* 사용시 주의사항:\n";
    
    int value = 100;
    void* vPtr = &value;
    
    // 직접 역참조 불가능 (컴파일 에러)
    // int x = *vPtr;  // 에러! void*는 역참조 불가
    
    // 반드시 적절한 타입으로 캐스팅 후 사용
    int* intPtr = (int*)vPtr;  // void* -> int* 캐스팅
    int x = *intPtr;  // OK! int*는 역참조 가능
    std::cout << "캐스팅 후 값: " << x << "\n";
    
    // 4. 잘못된 캐스팅의 위험
    std::cout << "\n4. 잘못된 캐스팅의 위험:\n";
    
    double doubleValue = 3.14159;
    void* genericPtr = &doubleValue;
    
    // 위험! double을 int*로 잘못 캐스팅
    int* wrongPtr = (int*)genericPtr;
    std::cout << "원래 double 값: " << doubleValue << "\n";
    std::cout << "잘못 캐스팅된 int 값: " << *wrongPtr << " (쓰레기 값)\n";
    
    // 5. 제네릭 함수에서 void* 활용
    std::cout << "\n5. 제네릭 함수 예제:\n";
    
    // memcpy 같은 함수가 void*를 사용하는 예
    int src[] = {1, 2, 3, 4, 5};
    int dest[5];
    
    // memcpy(void* dest, const void* src, size_t n)
    memcpy(dest, src, 5 * sizeof(int));  // int* -> void* 자동 변환
    
    std::cout << "복사된 배열: ";
    for (int i = 0; i < 5; i++) {
        std::cout << dest[i] << " ";
    }
    std::cout << "\n";
    
    // 6. C vs C++ 차이
    std::cout << "\n6. C vs C++ 캐스팅 차이:\n";
    
    // C에서는 void*를 다른 포인터로 암시적 변환 가능
    // C++에서는 명시적 캐스팅 필요
    
    void* voidMem = malloc(sizeof(int));
    
    // C 스타일 캐스팅
    int* cStylePtr = (int*)voidMem;  // C/C++ 모두 OK
    
    // C++ 스타일 캐스팅 (더 안전)
    int* cppStylePtr = static_cast<int*>(voidMem);
    
    *cppStylePtr = 999;
    std::cout << "C++ 스타일 캐스팅 결과: " << *cppStylePtr << "\n";
    
    // 7. 실제 사용 예: 제네릭 스왑 함수
    std::cout << "\n7. 제네릭 스왑 함수 예제:\n";
    
    auto genericSwap = [](void* a, void* b, size_t size) {
        void* temp = malloc(size);
        memcpy(temp, a, size);     // a -> temp
        memcpy(a, b, size);        // b -> a  
        memcpy(b, temp, size);     // temp -> b
        free(temp);
    };
    
    int x1 = 10, y1 = 20;
    std::cout << "교환 전: x1=" << x1 << ", y1=" << y1 << "\n";
    genericSwap(&x1, &y1, sizeof(int));
    std::cout << "교환 후: x1=" << x1 << ", y1=" << y1 << "\n";
    
    double x2 = 1.5, y2 = 2.5;
    std::cout << "교환 전: x2=" << x2 << ", y2=" << y2 << "\n";
    genericSwap(&x2, &y2, sizeof(double));
    std::cout << "교환 후: x2=" << x2 << ", y2=" << y2 << "\n";
    
    // 메모리 해제
    free(arr_c);
    free(voidMem);
    
    std::cout << "\n=== 요약 ===\n";
    std::cout << "1. void*는 '타입 없는 포인터'로 어떤 타입의 주소든 저장 가능\n";
    std::cout << "2. 사용하려면 반드시 원하는 타입으로 캐스팅 필요\n";
    std::cout << "3. malloc()이 void*를 반환하므로 (int*)malloc() 형태로 캐스팅\n";
    std::cout << "4. 잘못된 캐스팅은 위험하므로 주의 필요\n";
    std::cout << "5. C++에서는 static_cast를 사용하는 것이 더 안전\n";
    
    return 0;
}