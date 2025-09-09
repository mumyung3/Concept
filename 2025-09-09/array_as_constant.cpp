#include <iostream>
using namespace std;

int main() {
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {6, 7, 8, 9, 10};
    int* ptr = arr1;  // OK: 배열 이름을 포인터에 할당
    
    // 1. 배열의 요소는 변경 가능
    arr1[0] = 100;  // OK
    cout << "arr1[0] = " << arr1[0] << endl;
    
    // 2. 배열 이름은 재할당 불가 (상수처럼 동작)
    // arr1 = arr2;     // 컴파일 에러: 배열은 할당 불가
    // arr1 = ptr;      // 컴파일 에러: 배열은 재할당 불가
    // arr1 = nullptr;  // 컴파일 에러
    
    // 3. 포인터는 재할당 가능
    ptr = arr2;  // OK: 포인터는 다른 주소로 변경 가능
    cout << "ptr이 가리키는 값: " << *ptr << endl;
    
    // 4. 배열 이름의 타입
    cout << "\n타입 정보:" << endl;
    cout << "sizeof(arr1) = " << sizeof(arr1) << " bytes (전체 배열)" << endl;
    cout << "sizeof(ptr) = " << sizeof(ptr) << " bytes (포인터)" << endl;
    
    // 5. 배열은 rvalue (수정 불가능한 값)
    // &arr1 = ...;  // 불가능: 배열 이름은 lvalue가 아님
    
    // 6. const 배열과의 차이
    const int constArr[3] = {1, 2, 3};
    // constArr[0] = 10;  // 에러: const 배열의 요소도 수정 불가
    
    cout << "\n배열 이름의 특징:" << endl;
    cout << "- 배열 이름은 첫 번째 요소의 주소로 변환됨" << endl;
    cout << "- 하지만 재할당 불가능 (non-modifiable lvalue)" << endl;
    cout << "- sizeof와 &연산자 사용 시 배열 전체를 의미" << endl;
    
    return 0;
}