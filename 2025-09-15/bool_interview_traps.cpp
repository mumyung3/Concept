#include <iostream>
#include <vector>
using namespace std;

void function_that_expects_bool_ref(bool& b) {
    b = !b;
    cout << "함수 내에서 bool 값 반전" << endl;
}

int main() {
    cout << "=== bool 관련 면접 함정 문제들 ===" << endl;
    
    // 함정 1: bool 크기 착각
    cout << "\n[ 함정 1: bool 크기 ]" << endl;
    cout << "Q: bool은 1비트인가요?" << endl;
    cout << "A: 아니요! " << sizeof(bool) << "바이트입니다." << endl;
    
    // 함정 2: bool 값 범위
    cout << "\n[ 함정 2: bool의 실제 값 ]" << endl;
    bool b1 = true;
    bool b2 = false;
    bool b3 = 2;        // 함정! 0이 아닌 모든 값은 true
    bool b4 = -1;       // 함정! 음수도 true
    bool b5 = 0;        // 오직 0만 false
    
    cout << "bool b3 = 2; 결과: " << b3 << endl;
    cout << "bool b4 = -1; 결과: " << b4 << endl;
    cout << "bool b5 = 0; 결과: " << b5 << endl;
    
    // 함정 3: 포인터 크기
    cout << "\n[ 함정 3: bool 포인터 크기 ]" << endl;
    bool* boolPtr = &b1;
    cout << "bool* 크기: " << sizeof(boolPtr) << " bytes" << endl;
    cout << "bool 크기: " << sizeof(bool) << " bytes" << endl;
    cout << "차이: " << sizeof(boolPtr) - sizeof(bool) << " bytes" << endl;
    
    // 함정 4: vector<bool>의 함정
    cout << "\n[ 함정 4: vector<bool> 함정 ]" << endl;
    vector<bool> boolVec = {true, false, true};
    vector<int> intVec = {1, 0, 1};
    
    cout << "일반 vector<int>:" << endl;
    for (auto& item : intVec) {
        cout << "주소: " << &item << ", 값: " << item << endl;
    }
    
    cout << "vector<bool>:" << endl;
    // 다음 코드는 컴파일 에러를 발생시킵니다!
    // for (auto& item : boolVec) {
    //     cout << "주소: " << &item << ", 값: " << item << endl;  // ERROR!
    // }
    
    cout << "vector<bool>은 실제 bool&를 반환하지 않습니다!" << endl;
    
    // 함정 5: 비트 연산과의 혼동
    cout << "\n[ 함정 5: bool과 비트 연산 ]" << endl;
    bool flag1 = true;
    bool flag2 = false;
    
    cout << "bool 논리 연산:" << endl;
    cout << "flag1 && flag2: " << (flag1 && flag2) << endl;
    cout << "flag1 || flag2: " << (flag1 || flag2) << endl;
    
    cout << "bool 비트 연산 (주의!):" << endl;
    cout << "flag1 & flag2: " << (flag1 & flag2) << endl;
    cout << "flag1 | flag2: " << (flag1 | flag2) << endl;
    
    // 함정 6: 메모리 정렬
    cout << "\n[ 함정 6: 구조체 내 bool의 메모리 정렬 ]" << endl;
    struct TestStruct {
        char c;     // 1바이트
        bool b;     // 1바이트
        int i;      // 4바이트
    };
    
    cout << "struct { char, bool, int } 크기: " << sizeof(TestStruct) << " bytes" << endl;
    cout << "예상 크기: 1 + 1 + 4 = 6 bytes" << endl;
    cout << "실제 크기가 다른 이유: 메모리 정렬(alignment)" << endl;
    
    // 함정 7: 함수 매개변수 문제
    cout << "\n[ 함정 7: vector<bool> 참조 전달 불가 ]" << endl;
    vector<bool> vecBool = {true, false};
    vector<int> vecInt = {1, 0};
    
    // 이건 가능
    function_that_expects_bool_ref(vecInt[0] ? *(new bool(true)) : *(new bool(false)));
    
    // 이건 불가능! 컴파일 에러
    // function_that_expects_bool_ref(vecBool[0]);  // ERROR!
    
    cout << "vector<bool>[i]는 bool&가 아닌 프록시 객체를 반환!" << endl;
    
    return 0;
}