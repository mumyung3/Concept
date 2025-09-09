#include <iostream>
#include <iomanip>

// 모든 포인터의 크기는 동일하다는 것을 증명

struct BigStruct {
    int array[1000];
    double matrix[100][100];
    char buffer[10000];
};

class ComplexClass {
    virtual void func1() {}
    virtual void func2() {}
    int data[500];
};

int main() {
    std::cout << "=== 포인터 크기 비교 ===\n\n";
    
    // 1. 다양한 타입의 포인터 크기
    std::cout << "1. 기본 타입 포인터들의 크기:\n";
    std::cout << "   sizeof(char*)       = " << sizeof(char*) << " bytes\n";
    std::cout << "   sizeof(short*)      = " << sizeof(short*) << " bytes\n";
    std::cout << "   sizeof(int*)        = " << sizeof(int*) << " bytes\n";
    std::cout << "   sizeof(long*)       = " << sizeof(long*) << " bytes\n";
    std::cout << "   sizeof(long long*)  = " << sizeof(long long*) << " bytes\n";
    std::cout << "   sizeof(float*)      = " << sizeof(float*) << " bytes\n";
    std::cout << "   sizeof(double*)     = " << sizeof(double*) << " bytes\n";
    std::cout << "   sizeof(void*)       = " << sizeof(void*) << " bytes ← 똑같다!\n";
    
    std::cout << "\n2. 복잡한 타입 포인터들의 크기:\n";
    std::cout << "   sizeof(BigStruct*)    = " << sizeof(BigStruct*) << " bytes\n";
    std::cout << "   sizeof(ComplexClass*) = " << sizeof(ComplexClass*) << " bytes\n";
    std::cout << "   sizeof(int***)        = " << sizeof(int***) << " bytes (삼중 포인터)\n";
    
    std::cout << "\n3. 함수 포인터의 크기:\n";
    std::cout << "   sizeof(void(*)())     = " << sizeof(void(*)()) << " bytes\n";
    std::cout << "   sizeof(int(*)(int))   = " << sizeof(int(*)(int)) << " bytes\n";
    
    // 2. 실제 객체 크기 vs 포인터 크기
    std::cout << "\n4. 실제 객체 크기 vs 포인터 크기 비교:\n";
    std::cout << std::setw(25) << std::left << "   타입" 
              << std::setw(15) << "객체 크기" 
              << std::setw(15) << "포인터 크기" << "\n";
    std::cout << "   " << std::string(55, '-') << "\n";
    
    std::cout << std::setw(25) << std::left << "   char" 
              << std::setw(15) << sizeof(char) 
              << std::setw(15) << sizeof(char*) << "\n";
    
    std::cout << std::setw(25) << std::left << "   int" 
              << std::setw(15) << sizeof(int) 
              << std::setw(15) << sizeof(int*) << "\n";
    
    std::cout << std::setw(25) << std::left << "   double" 
              << std::setw(15) << sizeof(double) 
              << std::setw(15) << sizeof(double*) << "\n";
    
    std::cout << std::setw(25) << std::left << "   BigStruct" 
              << std::setw(15) << sizeof(BigStruct) 
              << std::setw(15) << sizeof(BigStruct*) << "\n";
    
    // 3. 왜 모든 포인터 크기가 같은가?
    std::cout << "\n5. 포인터가 실제로 저장하는 것 (메모리 주소):\n";
    
    int x = 42;
    double y = 3.14;
    BigStruct big;
    
    int* pInt = &x;
    double* pDouble = &y;
    BigStruct* pBig = &big;
    void* pVoid = &x;
    
    std::cout << "   int 변수 주소:        " << pInt << "\n";
    std::cout << "   double 변수 주소:     " << pDouble << "\n";
    std::cout << "   BigStruct 변수 주소:  " << pBig << "\n";
    std::cout << "   void* 에 저장된 주소: " << pVoid << "\n";
    
    // 4. void* 변환 시연
    std::cout << "\n6. void* 포인터 변환 (크기가 같아서 가능):\n";
    
    void* genericPtr;
    
    // 어떤 포인터든 void*에 저장 가능 (크기가 같으므로)
    genericPtr = pInt;
    std::cout << "   int* -> void*:    " << genericPtr << "\n";
    
    genericPtr = pDouble;
    std::cout << "   double* -> void*: " << genericPtr << "\n";
    
    genericPtr = pBig;
    std::cout << "   BigStruct* -> void*: " << genericPtr << "\n";
    
    // 5. 시스템 정보
    std::cout << "\n7. 시스템 아키텍처 정보:\n";
    if (sizeof(void*) == 8) {
        std::cout << "   64비트 시스템 (포인터 크기: 8 bytes = 64 bits)\n";
        std::cout << "   주소 공간: 0x0000000000000000 ~ 0xFFFFFFFFFFFFFFFF\n";
        std::cout << "   이론적 최대 메모리: 2^64 bytes = 16 EB (엑사바이트)\n";
    } else if (sizeof(void*) == 4) {
        std::cout << "   32비트 시스템 (포인터 크기: 4 bytes = 32 bits)\n";
        std::cout << "   주소 공간: 0x00000000 ~ 0xFFFFFFFF\n";
        std::cout << "   이론적 최대 메모리: 2^32 bytes = 4 GB\n";
    }
    
    // 6. void* 사용 이유
    std::cout << "\n=== void* 를 사용하는 이유 ===\n";
    std::cout << "1. 모든 포인터는 크기가 같음 (메모리 주소를 저장하므로)\n";
    std::cout << "2. void*는 '타입 정보 없이' 주소만 저장\n";
    std::cout << "3. 따라서 어떤 타입의 포인터든 void*로 변환 가능\n";
    std::cout << "4. malloc() 같은 함수가 void*를 반환하는 이유:\n";
    std::cout << "   - 메모리만 할당하고 타입은 사용자가 결정\n";
    std::cout << "   - 어떤 타입으로든 캐스팅 가능\n";
    
    std::cout << "\n=== 핵심 개념 ===\n";
    std::cout << "포인터 = 메모리 주소를 저장하는 변수\n";
    std::cout << "포인터 크기 = 주소를 표현하는데 필요한 비트 수\n";
    std::cout << "             (32비트 시스템: 4바이트, 64비트 시스템: 8바이트)\n";
    std::cout << "void* = 타입 정보 없이 순수한 주소만 저장\n";
    
    return 0;
}