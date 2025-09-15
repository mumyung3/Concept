#include <iostream>
using namespace std;

int main() {
    cout << "=== 포인터 크기 분석 ===" << endl;
    
    // 다양한 타입의 포인터들
    int* intPtr;
    char* charPtr;
    double* doublePtr;
    void* voidPtr;
    
    cout << "int 포인터 크기: " << sizeof(intPtr) << " bytes" << endl;
    cout << "char 포인터 크기: " << sizeof(charPtr) << " bytes" << endl;
    cout << "double 포인터 크기: " << sizeof(doublePtr) << " bytes" << endl;
    cout << "void 포인터 크기: " << sizeof(voidPtr) << " bytes" << endl;
    
    // 다중 포인터
    int** doublePtrInt;
    int*** triplePtrInt;
    
    cout << "int** 포인터 크기: " << sizeof(doublePtrInt) << " bytes" << endl;
    cout << "int*** 포인터 크기: " << sizeof(triplePtrInt) << " bytes" << endl;
    
    // 실제 데이터 타입 크기와 비교
    cout << "\n=== 실제 데이터 타입 크기 ===" << endl;
    cout << "int 크기: " << sizeof(int) << " bytes" << endl;
    cout << "char 크기: " << sizeof(char) << " bytes" << endl;
    cout << "double 크기: " << sizeof(double) << " bytes" << endl;
    
    // 시스템 정보
    cout << "\n=== 시스템 정보 ===" << endl;
    cout << "long 크기: " << sizeof(long) << " bytes" << endl;
    cout << "size_t 크기: " << sizeof(size_t) << " bytes" << endl;
    cout << "주소 표현 가능 범위: " << sizeof(void*) * 8 << "비트" << endl;
    
    return 0;
}