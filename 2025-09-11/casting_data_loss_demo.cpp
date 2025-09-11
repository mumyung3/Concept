#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // 원본 4바이트 데이터
    int original = 0x12345678;
    
    cout << "원본 데이터: 0x" << hex << original << endl;
    cout << "원본 크기: " << sizeof(original) << " bytes" << endl;
    
    // 1바이트로 캐스팅 후 값 읽기
    char byte_value = (char)original;
    cout << "\n1바이트로 캐스팅: 0x" << hex << (int)(unsigned char)byte_value << endl;
    cout << "1바이트 크기: " << sizeof(byte_value) << " bytes" << endl;
    
    // 다시 4바이트로 확장
    int restored = (int)byte_value;
    cout << "\n다시 4바이트로 확장: 0x" << hex << restored << endl;
    cout << "복원된 크기: " << sizeof(restored) << " bytes" << endl;
    
    cout << "\n원본과 복원된 값이 같은가? " 
         << (original == restored ? "Yes" : "No") << endl;
    
    // 부호 없는 캐스팅으로도 테스트
    cout << "\n--- 부호 없는 캐스팅 테스트 ---" << endl;
    unsigned char ubyte_value = (unsigned char)original;
    int urestoredm = (int)ubyte_value;
    cout << "unsigned char로 캐스팅: 0x" << hex << (int)ubyte_value << endl;
    cout << "다시 int로 확장: 0x" << hex << urestoredm << endl;
    
    // 포인터를 통한 접근 (메모리 직접 접근)
    cout << "\n--- 포인터를 통한 메모리 접근 ---" << endl;
    char* ptr = (char*)&original;
    cout << "첫 번째 바이트: 0x" << hex << (int)(unsigned char)ptr[0] << endl;
    cout << "두 번째 바이트: 0x" << hex << (int)(unsigned char)ptr[1] << endl;
    cout << "세 번째 바이트: 0x" << hex << (int)(unsigned char)ptr[2] << endl;
    cout << "네 번째 바이트: 0x" << hex << (int)(unsigned char)ptr[3] << endl;
    
    return 0;
}