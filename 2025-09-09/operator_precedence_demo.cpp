#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    
    // &arr[0]의 해석 순서
    cout << "arr[0]의 값: " << arr[0] << endl;
    cout << "&arr[0]의 주소: " << &arr[0] << endl;
    cout << "&(arr[0])의 주소: " << &(arr[0]) << endl;
    cout << "두 표현식은 동일: " << (&arr[0] == &(arr[0]) ? "true" : "false") << endl;
    
    // 비교: (&arr)[0]는 다른 의미
    cout << "\n(&arr)[0]의 주소: " << (&arr)[0] << endl;
    cout << "(&arr)의 타입은 int(*)[5]" << endl;
    
    return 0;
}