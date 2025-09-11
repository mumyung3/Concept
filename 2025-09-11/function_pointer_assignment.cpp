#include <iostream>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    // 함수 포인터 선언
    int (*fun_ptr)(int, int);
    
    cout << "함수 주소들:" << endl;
    cout << "add 함수 주소: " << (void*)add << endl;
    cout << "&add 주소: " << (void*)&add << endl;
    cout << "*add 주소: " << (void*)*add << endl;
    cout << "**add 주소: " << (void*)**add << endl;
    
    cout << "\n각각의 할당 방식:" << endl;
    
    // 방식 1: &fun (명시적 주소 연산자)
    fun_ptr = &add;
    cout << "fun_ptr = &add: " << (void*)fun_ptr << endl;
    cout << "결과: " << fun_ptr(3, 4) << endl;
    
    // 방식 2: fun (함수명 자동 변환)
    fun_ptr = add;
    cout << "fun_ptr = add: " << (void*)fun_ptr << endl;
    cout << "결과: " << fun_ptr(3, 4) << endl;
    
    // 방식 3: *fun (역참조 후 다시 주소)
    fun_ptr = *add;
    cout << "fun_ptr = *add: " << (void*)fun_ptr << endl;
    cout << "결과: " << fun_ptr(3, 4) << endl;
    
    // 방식 4: **fun (이중 역참조 후 다시 주소)
    fun_ptr = **add;
    cout << "fun_ptr = **add: " << (void*)fun_ptr << endl;
    cout << "결과: " << fun_ptr(3, 4) << endl;
    
    cout << "\n모든 방식이 같은 주소를 가리키는가? " 
         << ((void*)&add == (void*)add && 
             (void*)add == (void*)*add && 
             (void*)*add == (void*)**add ? "Yes" : "No") << endl;
    
    return 0;
}