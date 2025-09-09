# C++ 메모리 관리 복잡성 - 심화 학습용

## 핵심 질문
> "포인터로 얕은 복사하면 되는데 왜 const&를 써야 하나? 그냥 잘 관리하면 되는 거 아닌가?"

## 1. 기본 개념
- **배열 멤버**: 항상 깊은 복사 (전체 데이터 복사)
- **포인터 멤버**: 얕은 복사 (주소만 복사)

```cpp
struct ArrayData {
    int arr[1000];  // 4KB 전체 복사
};

struct PointerData {
    int* ptr;       // 8바이트만 복사 (주소)
};
```

## 2. 메모리 관리가 복잡한 이유들

### 2.1 소유권 문제
```cpp
struct Data {
    int* ptr;
};

Data createData() {
    Data d;
    d.ptr = new int[1000];  // 누가 delete 해야 할까?
    return d;
}

Data d1 = createData();
Data d2 = d1;              // 두 객체가 같은 메모리를 가리킴
// 프로그램 끝날 때 누가 delete[] 할까? 둘 다 하면 double-free 에러!
```

### 2.2 예외 안전성
```cpp
void process() {
    int* data = new int[1000];
    
    someFunction();  // 만약 여기서 예외 발생하면?
    
    delete[] data;   // 이 줄이 실행되지 않음 → 메모리 누수!
}
```

### 2.3 필수 함수들 (Rule of Three/Five)
```cpp
struct Buffer {
    int* data;
    int size;
    
    Buffer(int s) : size(s) {
        data = new int[size];
    }
    
    // 소멸자 - 빼먹으면 메모리 누수
    ~Buffer() {
        delete[] data;
    }
    
    // 복사 생성자 - 빼먹으면 얕은 복사 문제
    Buffer(const Buffer& other) {
        size = other.size;
        data = new int[size];  
        memcpy(data, other.data, size * sizeof(int));
    }
    
    // 복사 대입 연산자 - 빼먹으면 대입 시 문제
    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data;                    // 기존 메모리 해제
            size = other.size;
            data = new int[size];             // 새로 할당
            memcpy(data, other.data, size * sizeof(int)); // 복사
        }
        return *this;
    }
};
```

### 2.4 복잡한 객체 관계
```cpp
class Node {
public:
    int* data;
    Node* children;
    int childCount;
    
    // 이 Node가 삭제될 때:
    // - data를 해제해야 하나?
    // - children들도 삭제해야 하나?
    // - children이 다른 곳에서도 참조되면?
};
```

### 2.5 멀티스레딩 환경
```cpp
void thread1() {
    shared_ptr<Buffer> buf = getSharedBuffer();
    // 다른 스레드에서 buf가 삭제될 수도...
}

void thread2() {
    // 같은 Buffer 사용 중
}
```

### 2.6 실제 현업 코드 예시
```cpp
class Manager {
    Buffer* buffers[100];
    int count;
    
    void addBuffer(Buffer* b) {
        buffers[count++] = b;  // 이 Buffer는 누가 관리?
    }
    
    void removeBuffer(int index) {
        // delete 해야 하나? 다른 곳에서 쓰고 있나?
        buffers[index] = nullptr;
    }
    
    ~Manager() {
        // 모든 Buffer를 delete 해야 하나?
        // 일부는 이미 삭제됐을 수도?
    }
};
```

## 3. 현실적 해결책

### 3.1 RAII + 스마트 포인터
```cpp
struct ModernData {
    std::vector<int> data;           // 자동 메모리 관리
    std::unique_ptr<int[]> ptr;      // 스마트 포인터
    
    // 복사, 소멸자 자동으로 올바르게 처리됨
};
```

### 3.2 const& 사용으로 복사 자체 회피
```cpp
void process(const ModernData& data) {
    // 메모리 관리 걱정 없음
    // 복사도 없음
}
```

## 4. 학습 포인트

### 현재 이해 수준
- ✅ 배열 vs 포인터 복사 차이
- ✅ 얕은 복사의 기본 개념
- ❓ 복사 생성자, 대입 연산자의 필요성
- ❓ 소유권과 메모리 관리의 복잡성

### 추후 학습 계획
1. **Rule of Three/Five** 개념 정리
2. **RAII (Resource Acquisition Is Initialization)** 패턴
3. **스마트 포인터** (unique_ptr, shared_ptr)
4. **예외 안전성** 프로그래밍
5. **멀티스레딩**과 메모리 관리

## 5. 결론
> "잘 관리하면 된다"는 이론적으로 맞지만, 실제로는:
> - 작은 프로그램: 가능 ✅  
> - 대규모 프로젝트: 실수 필연적 ❌
> 
> 그래서 C++은 이런 복잡성을 "피하는" 방향으로 발전 (const&, 스마트 포인터, RAII 등)

---
*이 내용은 나중에 C++ 메모리 관리를 깊이 학습할 때 다시 참고할 예정*