#include <iostream>
#include <cstring>
#include <limits>
#include <iomanip>
#include <cmath>

// 자료형(Data Type)이 정의하는 것들

int main() {
    std::cout << "=== 자료형이 정의하는 4가지 핵심 요소 ===\n\n";
    
    // ========== 1. 크기 (Size) ==========
    std::cout << "1. 크기 (메모리 할당량):\n";
    std::cout << "   char:     " << sizeof(char) << " byte\n";
    std::cout << "   int:      " << sizeof(int) << " bytes\n";
    std::cout << "   float:    " << sizeof(float) << " bytes\n";
    std::cout << "   double:   " << sizeof(double) << " bytes\n\n";
    
    // ========== 2. 해석 방법 (Interpretation) ==========
    std::cout << "2. 비트 패턴의 해석 방법:\n";
    
    // 똑같은 4바이트 메모리 패턴을 다르게 해석
    union Memory {
        int asInt;
        float asFloat;
        unsigned int asUnsigned;
        char asBytes[4];
    };
    
    Memory mem;
    mem.asInt = -1;  // 모든 비트를 1로 설정
    
    std::cout << "   똑같은 메모리 패턴: ";
    for (int i = 0; i < 4; i++) {
        std::cout << std::hex << "0x" << (int)(unsigned char)mem.asBytes[i] << " ";
    }
    std::cout << std::dec << "\n";
    
    std::cout << "   - int로 해석:      " << mem.asInt << "\n";
    std::cout << "   - unsigned로 해석: " << mem.asUnsigned << "\n";
    std::cout << "   - float로 해석:    " << mem.asFloat << " (NaN)\n\n";
    
    // 더 명확한 예제
    mem.asInt = 1065353216;  // 특정 비트 패턴
    std::cout << "   비트 패턴 0x3F800000:\n";
    std::cout << "   - int로 해석:   " << mem.asInt << "\n";
    std::cout << "   - float로 해석: " << mem.asFloat << "\n\n";
    
    // ========== 3. 표현 범위 (Range) ==========
    std::cout << "3. 표현 가능한 값의 범위:\n";
    
    std::cout << "   signed char:   " 
              << (int)std::numeric_limits<signed char>::min() << " ~ " 
              << (int)std::numeric_limits<signed char>::max() << "\n";
    
    std::cout << "   unsigned char: " 
              << (int)std::numeric_limits<unsigned char>::min() << " ~ " 
              << (int)std::numeric_limits<unsigned char>::max() << "\n";
    
    std::cout << "   int:           " 
              << std::numeric_limits<int>::min() << " ~ " 
              << std::numeric_limits<int>::max() << "\n";
    
    std::cout << "   unsigned int:  " 
              << std::numeric_limits<unsigned int>::min() << " ~ " 
              << std::numeric_limits<unsigned int>::max() << "\n";
    
    std::cout << "   float:         " 
              << std::numeric_limits<float>::lowest() << " ~ " 
              << std::numeric_limits<float>::max() << "\n\n";
    
    // ========== 4. 허용 연산 (Operations) ==========
    std::cout << "4. 허용되는 연산:\n";
    
    // 정수 타입 연산
    int a = 10, b = 3;
    std::cout << "   정수(int) 연산:\n";
    std::cout << "   - 10 / 3 = " << (a / b) << " (정수 나눗셈)\n";
    std::cout << "   - 10 % 3 = " << (a % b) << " (나머지 연산 OK)\n";
    std::cout << "   - 10 << 2 = " << (a << 2) << " (비트 시프트 OK)\n";
    
    // 실수 타입 연산
    double x = 10.0, y = 3.0;
    std::cout << "\n   실수(double) 연산:\n";
    std::cout << "   - 10.0 / 3.0 = " << (x / y) << " (실수 나눗셈)\n";
    // std::cout << "   - 10.0 % 3.0 = 컴파일 에러! (% 연산 불가)\n";
    // std::cout << "   - 10.0 << 2 = 컴파일 에러! (비트 연산 불가)\n";
    
    // 포인터 타입 연산
    int arr[5] = {10, 20, 30, 40, 50};
    int* ptr = arr;
    std::cout << "\n   포인터(int*) 연산:\n";
    std::cout << "   - ptr 주소:     " << ptr << "\n";
    std::cout << "   - ptr + 1 주소: " << (ptr + 1) << " (4바이트 증가)\n";
    std::cout << "   - *ptr 값:      " << *ptr << "\n";
    std::cout << "   - *(ptr + 1):   " << *(ptr + 1) << "\n";
    // std::cout << "   - ptr * 2 = 컴파일 에러! (곱셈 불가)\n";
    
    // ========== 5. 타입 안정성 예제 ==========
    std::cout << "\n5. 타입 체크와 안정성:\n";
    
    // 암시적 변환 (위험할 수 있음)
    int bigNum = 300;
    char smallChar = bigNum;  // 경고: 데이터 손실
    std::cout << "   int 300 -> char: " << (int)smallChar << " (오버플로우 발생)\n";
    
    double precise = 3.14159;
    int truncated = precise;  // 소수점 잘림
    std::cout << "   double 3.14159 -> int: " << truncated << " (소수점 손실)\n";
    
    // ========== 6. 구조체/클래스 타입 ==========
    std::cout << "\n6. 사용자 정의 타입:\n";
    
    struct Point {
        double x, y;
        
        // 타입이 정의하는 연산
        Point operator+(const Point& other) const {
            return {x + other.x, y + other.y};
        }
        
        double distanceFromOrigin() const {
            return std::sqrt(x*x + y*y);
        }
    };
    
    Point p1{3.0, 4.0};
    Point p2{1.0, 2.0};
    Point p3 = p1 + p2;  // Point 타입만의 덧셈 연산
    
    std::cout << "   Point 타입:\n";
    std::cout << "   - 크기: " << sizeof(Point) << " bytes\n";
    std::cout << "   - p1 + p2 = (" << p3.x << ", " << p3.y << ")\n";
    std::cout << "   - 거리: " << p1.distanceFromOrigin() << "\n";
    
    // ========== 7. 타입의 의미 정리 ==========
    std::cout << "\n=== 자료형이 정의하는 것들 (요약) ===\n";
    std::cout << "1. 크기 (Size): 메모리를 얼마나 차지하는가?\n";
    std::cout << "2. 해석 (Interpretation): 비트 패턴을 어떻게 해석하는가?\n";
    std::cout << "3. 범위 (Range): 어떤 값들을 표현할 수 있는가?\n";
    std::cout << "4. 연산 (Operations): 어떤 연산이 가능한가?\n";
    std::cout << "5. 의미 (Semantics): 이 데이터가 무엇을 나타내는가?\n";
    std::cout << "6. 정렬 (Alignment): 메모리에 어떻게 배치되는가?\n";
    
    std::cout << "\n=== 핵심 ===\n";
    std::cout << "자료형 = 크기 + 해석방법 + 가능한 연산 + 의미\n";
    std::cout << "단순히 크기만 정하는 게 아니라,\n";
    std::cout << "그 메모리를 '어떻게 사용할 것인가'를 정의하는 것!\n";
    
    return 0;
}