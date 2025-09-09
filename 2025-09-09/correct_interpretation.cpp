#include <iostream>

// int (*p)[5] 올바른 해석 방법

int main() {
    std::cout << "=== int (*p)[5] 올바른 해석 방법 ===\n\n";
    
    // 잘못된 해석 vs 올바른 해석
    std::cout << "❌ 잘못된 해석:\n";
    std::cout << "   (*p)     → 포인터 변수\n";
    std::cout << "   [5]      → 포인터 변수의 배열 5개\n";
    std::cout << "   결론: 포인터 5개의 배열? (틀렸음!)\n\n";
    
    std::cout << "✅ 올바른 해석:\n";
    std::cout << "   전체를 하나의 타입으로 봐야 함!\n";
    std::cout << "   int (*p)[5] → p는 'int[5] 배열'을 가리키는 포인터\n\n";
    
    // 1. 단계별 올바른 해석
    std::cout << "1. 단계별 올바른 해석:\n";
    std::cout << "   Step 1: (*p)  → p는 포인터다\n";
    std::cout << "   Step 2: [5]   → 5개 요소를 가진 배열을 가리킨다\n";
    std::cout << "   Step 3: int   → 그 배열의 요소는 int 타입이다\n";
    std::cout << "   결론: p는 '5개의 int를 담은 배열 전체'를 가리키는 포인터\n\n";
    
    // 2. 실제 예제로 확인
    std::cout << "2. 실제 예제로 차이 확인:\n\n";
    
    // 포인터 배열 (잘못된 해석의 실제 모습)
    int a = 10, b = 20, c = 30, d = 40, e = 50;
    int* pointerArray[5] = {&a, &b, &c, &d, &e};  // 포인터 5개의 배열
    
    std::cout << "   포인터 배열: int* pointerArray[5]\n";
    std::cout << "   메모리 구조:\n";
    std::cout << "   pointerArray[0] → " << pointerArray[0] << " (주소를 저장)\n";
    std::cout << "   pointerArray[1] → " << pointerArray[1] << " (주소를 저장)\n";
    std::cout << "   pointerArray[2] → " << pointerArray[2] << " (주소를 저장)\n";
    std::cout << "   ...\n";
    std::cout << "   크기: " << sizeof(pointerArray) << " bytes (포인터 5개 = 8*5)\n\n";
    
    // 배열 포인터 (올바른 해석)
    int actualArray[5] = {10, 20, 30, 40, 50};
    int (*arrayPointer)[5] = &actualArray;  // 배열 전체를 가리키는 포인터 1개
    
    std::cout << "   배열 포인터: int (*arrayPointer)[5]\n";
    std::cout << "   메모리 구조:\n";
    std::cout << "   arrayPointer → " << arrayPointer << " (배열 전체의 주소)\n";
    std::cout << "   실제 배열:  [10][20][30][40][50] (연속된 메모리)\n";
    std::cout << "   크기: " << sizeof(arrayPointer) << " bytes (포인터 1개 = 8)\n\n";
    
    // 3. 사용법 차이
    std::cout << "3. 사용법 차이:\n\n";
    
    std::cout << "   포인터 배열 사용:\n";
    std::cout << "   pointerArray[0] = " << pointerArray[0] << " (주소)\n";
    std::cout << "   *pointerArray[0] = " << *pointerArray[0] << " (값)\n";
    std::cout << "   pointerArray[2] = " << pointerArray[2] << " (주소)\n";
    std::cout << "   *pointerArray[2] = " << *pointerArray[2] << " (값)\n\n";
    
    std::cout << "   배열 포인터 사용:\n";
    std::cout << "   arrayPointer = " << arrayPointer << " (배열 주소)\n";
    std::cout << "   *arrayPointer = " << *arrayPointer << " (배열 자체)\n";
    std::cout << "   (*arrayPointer)[0] = " << (*arrayPointer)[0] << " (첫 요소)\n";
    std::cout << "   (*arrayPointer)[2] = " << (*arrayPointer)[2] << " (세번째 요소)\n\n";
    
    // 4. 메모리 레이아웃 시각화
    std::cout << "4. 메모리 레이아웃 시각화:\n\n";
    
    std::cout << "   포인터 배열 int* arr[5]:\n";
    std::cout << "   ┌─────────┬─────────┬─────────┬─────────┬─────────┐\n";
    std::cout << "   │ ptr to a│ ptr to b│ ptr to c│ ptr to d│ ptr to e│\n";
    std::cout << "   └─────────┴─────────┴─────────┴─────────┴─────────┘\n";
    std::cout << "        ↓        ↓        ↓        ↓        ↓\n";
    std::cout << "       [10]     [20]     [30]     [40]     [50]\n";
    std::cout << "   (각각 다른 메모리 위치에 분산되어 있음)\n\n";
    
    std::cout << "   배열 포인터 int (*p)[5]:\n";
    std::cout << "   p → ┌─────┬─────┬─────┬─────┬─────┐\n";
    std::cout << "       │ 10  │ 20  │ 30  │ 40  │ 50  │\n";
    std::cout << "       └─────┴─────┴─────┴─────┴─────┘\n";
    std::cout << "   (하나의 연속된 배열을 통째로 가리킴)\n\n";
    
    // 5. 문법 우선순위 설명
    std::cout << "5. 문법 우선순위가 중요한 이유:\n\n";
    
    std::cout << "   만약 괄호가 없다면:\n";
    std::cout << "   int *p[5]  →  int *(p[5])  →  p[5] 먼저 해석\n";
    std::cout << "                               →  배열이 먼저, 그 요소가 int*\n";
    std::cout << "                               →  포인터들의 배열\n\n";
    
    std::cout << "   괄호가 있으면:\n";
    std::cout << "   int (*p)[5]  →  (*p) 먼저 해석\n";
    std::cout << "                   →  p는 포인터, 그것이 가리키는 것은 int[5]\n";
    std::cout << "                   →  배열을 가리키는 포인터\n\n";
    
    // 6. 실제 활용 예제
    std::cout << "6. 실제 활용 예제:\n\n";
    
    // 2차원 배열과 배열 포인터
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}, 
        {9, 10, 11, 12}
    };
    
    int (*row)[4];  // 4개 int 배열을 가리키는 포인터
    
    std::cout << "   2차원 배열의 각 행을 순회:\n";
    for(int i = 0; i < 3; i++) {
        row = &matrix[i];  // i번째 행의 주소
        std::cout << "   행 " << i << ": ";
        for(int j = 0; j < 4; j++) {
            std::cout << (*row)[j] << " ";
        }
        std::cout << "\n";
    }
    
    std::cout << "\n=== 핵심 정리 ===\n";
    std::cout << "❌ 틀린 해석: (*p) + [5] = 포인터 변수의 배열\n";
    std::cout << "✅ 맞는 해석: int (*p)[5] = int[5] 배열을 가리키는 포인터\n\n";
    
    std::cout << "기억하세요:\n";
    std::cout << "• int *p[5]   - 포인터 5개를 담는 배열\n";
    std::cout << "• int (*p)[5] - 5개 요소 배열을 가리키는 포인터 1개\n";
    std::cout << "• 괄호가 의미를 완전히 바꿈!\n";
    
    return 0;
}