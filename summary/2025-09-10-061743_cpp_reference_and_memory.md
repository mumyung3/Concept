# C++ 참조(Reference)와 메모리 관리 심화 학습

## 1. lvalue와 rvalue 개념

### 기본 정의
- **lvalue (left value)**: 메모리 주소를 가지는 표현식, 이름이 있는 객체
- **rvalue (right value)**: 임시값, 메모리 주소를 얻을 수 없는 표현식

### 판별 방법
```cpp
// & 연산자를 적용할 수 있으면 lvalue
int x = 10;
&x;        // ✅ OK → x는 lvalue
&10;       // ❌ 에러 → 10은 rvalue
&(x + 5);  // ❌ 에러 → (x + 5)는 rvalue
```

### 중요한 통찰
- **언어 수준**: rvalue는 "주소 없음" (추상화)
- **구현 수준**: 모든 값은 실제로 메모리/레지스터 어딘가에 존재
- **리터럴 = rvalue** (문자열 리터럴 제외)

## 2. const 참조 (const T&)

### const int& ref = 10의 실제 동작
```cpp
const int& ref = 10;
// 컴파일러가 하는 일:
// 1. int temp = 10;        // 임시 변수 생성 (스택에)
// 2. const int& ref = temp; // ref는 temp를 가리킴
```

### 함수에서의 const 참조
```cpp
void func(const int& param);

func(10);    // rvalue 전달
func(x);     // lvalue 전달
// 둘 다 동일하게 작동! caller 스택의 객체 주소를 바인딩
```

### 사용 시기
- **함수 매개변수**로 읽기 전용 전달
- **큰 객체**를 복사 없이 전달
- **범위 기반 for문**에서 효율적 순회
- **임시 객체**도 받을 수 있어야 할 때

## 3. rvalue 참조 (T&&)와 이동 의미론

### Move Semantics 핵심
```cpp
class BigObject {
    int* data;
    int size;
public:
    // 복사 생성자 (비싼 연산)
    BigObject(const BigObject& other) {
        data = new int[size];
        memcpy(data, other.data, size * sizeof(int));  // 전체 복사
    }
    
    // 이동 생성자 (빠른 연산)
    BigObject(BigObject&& other) {
        data = other.data;      // 포인터만 훔쳐옴
        other.data = nullptr;   // 원본 무효화
    }
};
```

### std::move의 실제 의미
```cpp
BigObject obj1;
BigObject obj2 = std::move(obj1);
```
- **obj1 객체는 여전히 존재** (스택에)
- **데이터만 이동** (포인터, 리소스 등)
- **obj1은 "빈 껍데기" 상태**가 됨 (moved-from state)
- `std::move`는 "데이터 소유권 이전"

### 오버로드 해상도
| 전달값 타입 | 이동 생성자 있음 | 이동 생성자 없음 |
|------------|----------------|-----------------|
| lvalue     | 복사 생성자     | 복사 생성자      |
| rvalue     | **이동 생성자** | 복사 생성자      |

## 4. 배열과 포인터의 차이

### 배열이 "상수"인 이유
<details>
<summary>📚 상세 설명 (클릭하여 펼치기)</summary>

#### 배열 이름의 특성
- **재할당 불가능**: `arr1 = arr2;` ❌ 컴파일 에러
- **non-modifiable lvalue**: 컴파일 시점에 고정된 주소
- 배열의 **요소**는 변경 가능: `arr[0] = 100;` ✅
- 배열 **이름이 가리키는 주소**는 변경 불가

#### 컴파일러 관점
```cpp
int arr[5];  // "arr이라는 이름으로 20바이트 공간 확보"
// 이 공간의 시작 주소는 프로그램 실행 중 절대 변경 불가
```

</details>

### 구조체 내 배열 복사
```cpp
struct BigData {
    int array[10000];  // 배열: 전체 복사됨 (깊은 복사)
    int* ptr;          // 포인터: 주소만 복사됨 (얕은 복사)
};
```
- C++ 구조체의 **배열 멤버는 깊은 복사**가 기본
- 그래서 큰 배열을 가진 구조체는 `const&`로 전달하는 게 효율적

## 5. 기본 생성 함수들

### 컴파일러가 자동 생성하는 것들
1. **기본 생성자** (매개변수 없으면)
2. **소멸자**
3. **복사 생성자**
4. **복사 대입 연산자** (멤버별 얕은 복사)
5. **이동 생성자** (C++11)
6. **이동 대입 연산자** (C++11)

### 기본 대입 연산자의 동작
```cpp
class MyClass {
    int a;
    double b;
    // 대입 연산자 정의 안 함
};

// 컴파일러가 자동 생성:
MyClass& operator=(const MyClass& other) {
    a = other.a;  // 멤버별 복사
    b = other.b;
    return *this;
}
```

### 포인터 멤버의 위험성
```cpp
class Dangerous {
    int* ptr;
};
// 기본 대입 = 얕은 복사 → double-free 위험!
```

## 6. 메모리 레이아웃과 리터럴

### 리터럴 값의 실제 위치
- **작은 정수 리터럴** (10 등): 명령어 자체에 포함 (즉시값)
- **문자열 리터럴**: 읽기 전용 데이터 섹션(.rodata)에 저장

### const int& ref = 10의 과정
1. 명령어에서 10을 읽음 (코드 영역)
2. 스택에 임시 변수 생성
3. 10을 임시 변수에 복사
4. ref가 임시 변수 가리킴

## 7. 핵심 개념 정리

### 참조의 본질
- **모든 참조는 주소를 바인딩**
- lvalue든 rvalue든 const 참조는 항상 **caller 스택의 어떤 객체 주소**를 바인딩
- 참조는 별명(alias)이지만, 내부적으로는 주소를 통해 구현

### 성능 최적화 전략
1. **const&**: 복사 비용 절약, 읽기 전용
2. **&&**: 임시 객체 재활용, 이동 의미론
3. **RVO/NRVO**: 컴파일러 최적화로 불필요한 복사/이동 제거

### Rule of Three/Five/Zero
- **Rule of Three**: 소멸자, 복사 생성자, 복사 대입 연산자
- **Rule of Five**: + 이동 생성자, 이동 대입 연산자
- **Rule of Zero**: RAII 클래스 사용으로 자동 관리

## 8. 주요 학습 포인트

### 이해한 내용
- ✅ lvalue/rvalue 구분
- ✅ const 참조의 동작 원리
- ✅ 배열과 포인터의 복사 차이
- ✅ std::move와 이동 의미론
- ✅ 기본 대입 연산자 동작

### 추후 학습 필요
- ❓ RAII 패턴 심화
- ❓ 스마트 포인터 활용
- ❓ 예외 안전성
- ❓ Perfect Forwarding

## 9. 실용적 가이드라인

1. **작은 타입** (int, double): 값으로 전달
2. **큰 객체**: const& 또는 이동 의미론 활용
3. **동적 메모리**: 스마트 포인터 사용
4. **컨테이너**: STL 컨테이너 활용 (자동 메모리 관리)
5. **의심되면**: const&가 안전한 기본 선택

---
*이 문서는 C++ 참조와 메모리 관리에 대한 심화 학습 내용을 정리한 것입니다.*