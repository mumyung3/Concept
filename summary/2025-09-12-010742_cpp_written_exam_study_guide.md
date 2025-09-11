# C++ 필기 시험 대비 종합 정리

## 목표: 70% 이상 정답률 달성

### 1. 문법적 지식 (Grammar Knowledge)

#### 기본 문법 요소
- **변수 선언과 초기화**
  ```cpp
  int a = 10;          // 초기화
  int b(20);           // 생성자 스타일
  int c{30};           // 유니폼 초기화 (C++11)
  ```

- **배열과 포인터 관계**
  - 배열명은 첫 번째 요소의 주소를 나타내는 상수 포인터
  - `int arr[5]` → `arr`은 `&arr[0]`와 동일
  - Array decay: 함수 매개변수로 전달 시 포인터로 변환

- **참조(Reference) vs 포인터(Pointer)**
  ```cpp
  int x = 10;
  int& ref = x;        // 참조: 별명, 반드시 초기화 필요
  int* ptr = &x;       // 포인터: 주소 저장, null 가능
  ```

#### 연산자 우선순위
- `[]` (배열 첨자) > `*` (역참조) > `&` (주소 연산자)
- `++`, `--` 전위/후위 연산자 차이

### 2. 코드 해석 능력 (Code Interpretation)

#### 복잡한 선언문 해석
```cpp
int *p[10];          // 포인터 배열: int를 가리키는 포인터 10개
int (*p)[10];        // 배열 포인터: 크기 10인 int 배열을 가리키는 포인터
int *(*p)[10];       // 포인터 배열을 가리키는 포인터
```

#### 함수 포인터
```cpp
int (*func)(int, int);           // 함수 포인터 선언
int (*arr[10])(int);             // 함수 포인터 배열
```

#### 타입 변환과 캐스팅
- 암시적 변환: `int → double`
- 명시적 변환: `static_cast<int>(3.14)`
- void 포인터 캐스팅

### 3. 포인터 사용법 (Pointer Usage)

#### 포인터 기본 개념
- **포인터 크기**: 시스템 아키텍처에 따라 결정 (32bit: 4바이트, 64bit: 8바이트)
- **void 포인터**: 타입 정보 없는 범용 포인터
  ```cpp
  void* vptr;
  int* iptr = static_cast<int*>(vptr);  // 명시적 캐스팅 필요
  ```

#### 다중 포인터
```cpp
int x = 10;
int* p1 = &x;        // 1단계 포인터
int** p2 = &p1;      // 2단계 포인터
int*** p3 = &p2;     // 3단계 포인터
```

#### 포인터 연산
- 주소 연산: `ptr + 1` (타입 크기만큼 증가)
- 포인터 차이: `ptr2 - ptr1` (요소 개수 반환)

### 4. 동적 메모리 사용법 (Dynamic Memory)

#### new/delete 연산자
```cpp
// 단일 객체
int* ptr = new int(10);
delete ptr;

// 배열
int* arr = new int[10];
delete[] arr;

// 클래스 객체
MyClass* obj = new MyClass();
delete obj;
```

#### 메모리 누수 방지
- **RAII** (Resource Acquisition Is Initialization)
- **스마트 포인터** (C++11)
  ```cpp
  std::unique_ptr<int> ptr(new int(10));
  std::shared_ptr<int> sptr = std::make_shared<int>(20);
  ```

#### 메모리 할당/해제 과정
1. new → 메모리 할당 → 생성자 호출
2. delete → 소멸자 호출 → 메모리 해제

### 5. 컴파일러 이론적 지식 (Compiler Theory)

#### 컴파일 과정
1. **전처리(Preprocessing)**: `#include`, `#define` 처리
2. **컴파일(Compilation)**: 소스코드 → 어셈블리어
3. **어셈블(Assembly)**: 어셈블리어 → 기계어 오브젝트 파일
4. **링킹(Linking)**: 오브젝트 파일들을 실행 파일로 결합

#### 타입 체킹
- **정적 타입 체킹**: 컴파일 타임에 타입 검사
- **강타입 언어**: 타입 불일치 시 컴파일 에러
- **타입 추론**: `auto` 키워드 (C++11)

#### 최적화
- **Zero Overhead Principle**: 사용하지 않는 기능에 대한 비용 없음
- **인라인 함수**: 함수 호출 오버헤드 제거
- **컴파일러 최적화 플래그**: `-O1`, `-O2`, `-O3`

#### 링커와 심볼 테이블
- **외부 링크**: 다른 파일에서 접근 가능
- **내부 링크**: 같은 파일 내에서만 접근
- **심볼 해결**: 함수/변수 참조를 실제 주소로 변환

### 6. 퀵 정렬 알고리즘 (Quick Sort Algorithm)

#### 알고리즘 개념
- **분할 정복(Divide and Conquer)** 방식
- **피벗(Pivot)** 선택 → 분할 → 재귀적 정렬

#### 구현 단계
```cpp
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // 분할
        quickSort(arr, low, pi - 1);         // 왼쪽 부분 정렬
        quickSort(arr, pi + 1, high);        // 오른쪽 부분 정렬
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];    // 마지막 요소를 피벗으로 선택
    int i = low - 1;          // 작은 요소의 인덱스
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
```

#### 시간/공간 복잡도
- **평균 시간 복잡도**: O(n log n)
- **최악 시간 복잡도**: O(n²) - 이미 정렬된 배열
- **공간 복잡도**: O(log n) - 재귀 호출 스택

#### 최적화 기법
- **피벗 선택**: 랜덤 피벗, 중간값 피벗
- **작은 부분배열**: 삽입 정렬로 전환
- **3-way 파티셔닝**: 중복값 처리

## 시험 대비 핵심 포인트

### 자주 출제되는 함정 문제
1. **배열과 포인터 혼동**
2. **연산자 우선순위 실수**
3. **메모리 누수 관련 문제**
4. **타입 변환 오류**
5. **포인터 산술 연산 실수**

### 실전 팁
- 복잡한 선언문은 오른쪽에서 왼쪽으로 해석
- 포인터 연산 시 타입 크기 고려
- 동적 메모리는 항상 delete와 쌍으로
- 컴파일 에러와 런타임 에러 구분
- 알고리즘의 시간 복잡도 분석 능력

### 마지막 점검 사항
- [ ] 기본 문법 숙지
- [ ] 포인터와 배열 관계 이해
- [ ] 동적 메모리 관리 방법
- [ ] 컴파일 과정 이해
- [ ] 퀵 정렬 구현과 분석
- [ ] 예상 문제 풀이 연습