#include <iostream>
#include <cstdint>
#include <climits>

// 문제 1: 포인터와 int 크기 차이
void problem1_pointer_int_casting() {
    std::cout << "=== 문제 1: 포인터 ↔ int 캐스팅 ===" << std::endl;
    
    int value = 42;
    int* ptr = &value;
    
    std::cout << "포인터 크기: " << sizeof(ptr) << " bytes" << std::endl;
    std::cout << "int 크기: " << sizeof(int) << " bytes" << std::endl;
    
    // 32비트에서는 문제없던 코드
    std::cout << "\n32비트에서 괜찮던 코드:" << std::endl;
    std::cout << "int handle = (int)ptr;  // 32비트: 4바이트 → 4바이트" << std::endl;
    std::cout << "int* restored = (int*)handle;" << std::endl;
    
    std::cout << "\n64비트에서 문제:" << std::endl;
    // 이 코드는 64비트에서 경고/오류 발생
    // int handle = (int)ptr;  // 64비트: 8바이트 → 4바이트 (데이터 손실!)
    
    std::cout << "포인터(8바이트)를 int(4바이트)에 저장하면 상위 4바이트 손실!" << std::endl;
    std::cout << "해결책: uintptr_t 또는 intptr_t 사용" << std::endl;
    
    uintptr_t safe_handle = (uintptr_t)ptr;
    int* safe_restored = (int*)safe_handle;
    std::cout << "안전한 방법: uintptr_t handle = (uintptr_t)ptr;" << std::endl;
}

// 문제 2: 구조체 패딩 변화
struct Problem2_32bit {
    int id;        // 4바이트
    char* name;    // 32비트에서 4바이트
    int count;     // 4바이트
};  // 32비트 총 크기: 12바이트

struct Problem2_64bit {
    int id;        // 4바이트
    char* name;    // 64비트에서 8바이트  
    int count;     // 4바이트
};  // 64비트 총 크기: 16바이트 (패딩 포함)

void problem2_struct_padding() {
    std::cout << "\n=== 문제 2: 구조체 크기 및 패딩 변화 ===" << std::endl;
    
    std::cout << "구조체 크기 변화:" << std::endl;
    std::cout << "Problem2_64bit 크기: " << sizeof(Problem2_64bit) << " bytes" << std::endl;
    std::cout << "각 멤버 크기:" << std::endl;
    std::cout << "  int id: " << sizeof(int) << " bytes" << std::endl;
    std::cout << "  char* name: " << sizeof(char*) << " bytes" << std::endl;
    std::cout << "  int count: " << sizeof(int) << " bytes" << std::endl;
    
    std::cout << "\n문제점:" << std::endl;
    std::cout << "- 파일 저장/로드 시 크기 불일치" << std::endl;
    std::cout << "- 네트워크 프로토콜에서 구조체 직접 전송 문제" << std::endl;
    std::cout << "- 32비트와 64비트 간 데이터 호환성 문제" << std::endl;
}

// 문제 3: 정수 오버플로우
void problem3_integer_overflow() {
    std::cout << "\n=== 문제 3: 정수 크기 관련 문제 ===" << std::endl;
    
    // 32비트에서는 long이 4바이트, 64비트 Unix에서는 8바이트
    std::cout << "long 크기: " << sizeof(long) << " bytes" << std::endl;
    
    // 파일 크기나 메모리 크기 계산 시 문제
    std::cout << "\n파일 크기 계산 예시:" << std::endl;
    
    // 32비트에서 문제없던 코드
    long file_size = 3000000000L;  // 약 3GB
    std::cout << "파일 크기: " << file_size << " bytes" << std::endl;
    
    if (sizeof(long) == 4) {
        std::cout << "32비트에서: long으로 3GB 표현 불가 (오버플로우)" << std::endl;
    } else {
        std::cout << "64비트에서: long으로 3GB 표현 가능" << std::endl;
    }
    
    std::cout << "해결책: 명시적 크기 타입 사용 (int64_t, size_t)" << std::endl;
}

// 문제 4: 포인터 산술 연산
void problem4_pointer_arithmetic() {
    std::cout << "\n=== 문제 4: 포인터 산술 연산 ===" << std::endl;
    
    int arr[10];
    int* start = arr;
    int* end = arr + 10;
    
    // 포인터 차이 계산
    ptrdiff_t diff = end - start;
    std::cout << "포인터 차이: " << diff << std::endl;
    std::cout << "ptrdiff_t 크기: " << sizeof(ptrdiff_t) << " bytes" << std::endl;
    
    std::cout << "\n문제점:" << std::endl;
    std::cout << "- 32비트: ptrdiff_t가 4바이트" << std::endl;
    std::cout << "- 64비트: ptrdiff_t가 8바이트" << std::endl;
    std::cout << "- 포인터 차이를 int에 저장하면 64비트에서 오버플로우 가능" << std::endl;
}

// 문제 5: 시간 관련 타입
void problem5_time_types() {
    std::cout << "\n=== 문제 5: 시간 관련 타입 문제 ===" << std::endl;
    
    std::cout << "time_t 크기: " << sizeof(time_t) << " bytes" << std::endl;
    
    std::cout << "\n문제점:" << std::endl;
    std::cout << "- 32비트 시스템: time_t가 4바이트 (2038년 문제)" << std::endl;
    std::cout << "- 64비트 시스템: time_t가 8바이트" << std::endl;
    std::cout << "- 시간 데이터 저장/로드 시 호환성 문제" << std::endl;
}

int main() {
    std::cout << "=== 32비트 → 64비트 포팅의 주요 문제들 ===" << std::endl;
    
    problem1_pointer_int_casting();
    problem2_struct_padding();
    problem3_integer_overflow();
    problem4_pointer_arithmetic();
    problem5_time_types();
    
    std::cout << "\n=== 포팅 시 주의사항 요약 ===" << std::endl;
    std::cout << "1. 포인터를 int에 저장하지 말고 uintptr_t 사용" << std::endl;
    std::cout << "2. 구조체 직렬화 시 명시적 크기 지정" << std::endl;
    std::cout << "3. long 대신 int32_t, int64_t 같은 명시적 타입 사용" << std::endl;
    std::cout << "4. 포인터 산술 결과를 적절한 타입에 저장" << std::endl;
    std::cout << "5. 시간, 크기 관련 타입들 재검토" << std::endl;
    
    return 0;
}