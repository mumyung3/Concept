#include <iostream>
#include <iomanip>
#include <typeinfo>

// 배열에서 arr과 &arr의 차이점 심층 분석

int main() {
    std::cout << "=== 배열에서 arr과 &arr의 의미 ===\n\n";
    
    int arr[5] = {10, 20, 30, 40, 50};
    
    // 1. 주소값은 같지만...
    std::cout << "1. 주소값 비교:\n";
    std::cout << "   arr   = " << arr << "\n";
    std::cout << "   &arr  = " << &arr << "\n";
    std::cout << "   &arr[0] = " << &arr[0] << "\n";
    std::cout << "   → 모두 같은 주소를 출력!\n\n";
    
    // 2. 하지만 타입이 다르다!
    std::cout << "2. 타입이 완전히 다름:\n";
    std::cout << "   arr의 타입:   " << typeid(arr).name() << " → int[5] (배열)\n";
    std::cout << "   &arr의 타입:  " << typeid(&arr).name() << " → int(*)[5] (배열 포인터)\n";
    std::cout << "   &arr[0]의 타입: " << typeid(&arr[0]).name() << " → int* (정수 포인터)\n\n";
    
    // 3. 포인터 연산 시 차이 (핵심!)
    std::cout << "3. 포인터 연산의 차이 (중요!):\n";
    
    int* p1 = arr;      // arr은 첫 요소의 포인터로 decay
    int (*p2)[5] = &arr; // 배열 전체를 가리키는 포인터
    
    std::cout << "   int* p1 = arr;\n";
    std::cout << "   int (*p2)[5] = &arr;\n\n";
    
    std::cout << "   p1     = " << p1 << "\n";
    std::cout << "   p1 + 1 = " << (p1 + 1) << " (+" << sizeof(int) << " bytes)\n";
    std::cout << "   *(p1 + 1) = " << *(p1 + 1) << " (다음 요소: 20)\n\n";
    
    std::cout << "   p2     = " << p2 << "\n";
    std::cout << "   p2 + 1 = " << (p2 + 1) << " (+" << sizeof(arr) << " bytes!)\n";
    std::cout << "   차이: " << (char*)(p2 + 1) - (char*)p2 << " bytes\n\n";
    
    // 4. 메모리 레이아웃 시각화
    std::cout << "4. 메모리 레이아웃 시각화:\n";
    std::cout << "   메모리 주소        값\n";
    std::cout << "   ------------      ---\n";
    for (int i = 0; i < 5; i++) {
        std::cout << "   " << &arr[i] << "  " << arr[i];
        if (i == 0) {
            std::cout << "  ← arr, &arr, &arr[0] 모두 여기를 가리킴";
        }
        std::cout << "\n";
    }
    std::cout << "   " << &arr + 1 << "     ?  ← &arr + 1은 여기! (배열 전체 크기만큼 점프)\n\n";
    
    // 5. 왜 같은 주소인가?
    std::cout << "5. 왜 arr과 &arr이 같은 주소인가?\n";
    std::cout << "   배열은 메모리에 연속적으로 저장됨\n";
    std::cout << "   → 배열의 시작 주소 = 첫 요소의 주소\n";
    std::cout << "   → 하지만 '의미'가 다름!\n\n";
    
    std::cout << "   arr:  '첫 요소'를 가리킴 (int*로 decay)\n";
    std::cout << "   &arr: '배열 전체'를 가리킴 (int(*)[5])\n\n";
    
    // 6. 실제 사용 예제
    std::cout << "6. 실제 사용 차이:\n";
    
    // arr 사용 (첫 요소 포인터로 decay)
    int* ptr = arr;  // OK
    std::cout << "   int* ptr = arr;  // OK (배열이 포인터로 decay)\n";
    std::cout << "   ptr[2] = " << ptr[2] << "\n";
    
    // &arr 사용 (배열 포인터)
    int (*arrPtr)[5] = &arr;  // 배열 전체 포인터
    std::cout << "\n   int (*arrPtr)[5] = &arr;  // 배열 포인터\n";
    std::cout << "   (*arrPtr)[2] = " << (*arrPtr)[2] << "\n";
    std::cout << "   arrPtr는 배열 전체를 가리키므로 *를 써야 배열에 접근\n\n";
    
    // 7. 2차원 배열에서 더 명확한 차이
    std::cout << "7. 2차원 배열에서의 차이:\n";
    int arr2D[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};
    
    std::cout << "   int arr2D[3][4];\n";
    std::cout << "   arr2D      = " << arr2D << " (첫 행을 가리킴)\n";
    std::cout << "   arr2D + 1  = " << arr2D + 1 << " (다음 행, +" << sizeof(arr2D[0]) << " bytes)\n";
    std::cout << "   &arr2D     = " << &arr2D << " (2차원 배열 전체)\n";
    std::cout << "   &arr2D + 1 = " << &arr2D + 1 << " (+" << sizeof(arr2D) << " bytes!)\n\n";
    
    // 8. sizeof 연산자와의 관계
    std::cout << "8. sizeof 연산자 적용:\n";
    std::cout << "   sizeof(arr)     = " << sizeof(arr) << " bytes (배열 전체)\n";
    std::cout << "   sizeof(&arr)    = " << sizeof(&arr) << " bytes (포인터 크기)\n";
    std::cout << "   sizeof(*&arr)   = " << sizeof(*&arr) << " bytes (다시 배열 전체)\n\n";
    
    // 9. 함수 전달 시 차이
    auto takePointer = [](int* p) {
        std::cout << "   받은 포인터: " << p << ", 첫 값: " << *p << "\n";
    };
    
    auto takeArrayPointer = [](int (*p)[5]) {
        std::cout << "   받은 배열 포인터: " << p << ", 첫 값: " << (*p)[0] << "\n";
    };
    
    std::cout << "9. 함수 전달 시:\n";
    takePointer(arr);        // arr은 int*로 decay
    // takePointer(&arr);    // 컴파일 에러! &arr은 int(*)[5] 타입
    takeArrayPointer(&arr);  // &arr은 int(*)[5] 타입
    // takeArrayPointer(arr); // 컴파일 에러! arr은 int*로 decay
    
    std::cout << "\n=== 핵심 정리 ===\n";
    std::cout << "arr과 &arr이 같은 주소를 출력하는 이유:\n";
    std::cout << "→ 배열의 시작 위치가 곧 첫 요소의 위치이기 때문\n\n";
    
    std::cout << "하지만 의미가 다름:\n";
    std::cout << "• arr:  첫 요소를 가리킴 (단위: int)\n";
    std::cout << "• &arr: 배열 전체를 가리킴 (단위: int[5])\n\n";
    
    std::cout << "포인터 연산 시:\n";
    std::cout << "• arr + 1:  다음 요소 (+" << sizeof(int) << " bytes)\n";
    std::cout << "• &arr + 1: 다음 배열 (+" << sizeof(arr) << " bytes)\n";
    
    return 0;
}