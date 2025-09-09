# C 스타일 배열 환형 큐 구현 핵심 개념

## 1. 기본 개념

### C 스타일 배열
- **배열 이름 = 첫 번째 요소의 주소**: `arr == &arr[0]`
- **배열 접근**: `arr[i]` = `*(arr + i)` (동일한 표현)
- **sizeof 차이**: 
  - `sizeof(arr)`: 전체 배열 크기
  - `sizeof(ptr)`: 포인터 크기 (8바이트 in 64bit)
- **배열은 상수**: 재할당 불가 (`arr = arr2` 컴파일 에러)
- **포인터는 변수**: 재할당 가능 (`ptr = arr2` OK)

### 포인터 산술 연산
```cpp
int arr[5] = {10, 20, 30, 40, 50};
int* ptr = arr;
ptr++;  // 다음 요소를 가리킴 (4바이트 이동)
*(ptr + 2)  // ptr로부터 2개 뒤 요소 접근
```

## 2. 환형 큐의 핵심: 모듈러 연산

### 인덱스 순환
```cpp
next_index = (current_index + 1) % SIZE;  // 다음 인덱스
prev_index = (current_index - 1 + SIZE) % SIZE;  // 이전 인덱스
```

### 환형 특성
- 배열의 끝에서 다시 처음으로 순환
- 고정 크기 배열의 공간을 재사용
- 메모리 효율적인 큐 구현

## 3. 환형 큐 구조

### 핵심 멤버 변수
```cpp
struct CircularQueue {
    T* data;       // 데이터 배열
    int capacity;  // 최대 크기
    int front;     // 첫 번째 요소 인덱스
    int rear;      // 다음 삽입 위치 인덱스
    int count;     // 현재 요소 개수
};
```

### front와 rear의 관계
- **빈 큐**: `count == 0` (front와 rear 위치는 무관)
- **가득 찬 큐**: `count == capacity`
- **rear 이동**: `rear = (rear + 1) % capacity`
- **front 이동**: `front = (front + 1) % capacity`

## 4. 주요 연산

### Enqueue (삽입)
```cpp
bool enqueue(const T& value) {
    if(isFull()) return false;
    
    data[rear] = value;
    rear = (rear + 1) % capacity;  // 환형 증가
    count++;
    return true;
}
```

### Dequeue (제거)
```cpp
bool dequeue(T& value) {
    if(isEmpty()) return false;
    
    value = data[front];
    front = (front + 1) % capacity;  // 환형 증가
    count--;
    return true;
}
```

## 5. Full/Empty 판별 방법

### count 변수 사용 (권장)
- **장점**: 명확하고 간단한 판별
- **단점**: 추가 변수 필요
```cpp
bool isEmpty() { return count == 0; }
bool isFull() { return count == capacity; }
```

### front/rear만 사용
- **문제점**: front == rear일 때 빈 큐/가득 찬 큐 구분 불가
- **해결책**: 
  1. 한 칸 비워두기 (capacity-1개만 저장)
  2. flag 변수 추가 사용

## 6. 구현 시 주의사항

### 메모리 관리
- 동적 할당 시 소멸자에서 반드시 delete[]
- 복사 생성자와 대입 연산자 구현 필요
- 템플릿 사용 시 memset 대신 값 초기화 사용

### 크기 조정 (Resize)
```cpp
void resize(int newCapacity) {
    T* newData = new T[newCapacity];
    
    // 순서대로 복사
    int idx = front;
    for(int i = 0; i < count; i++) {
        newData[i] = data[idx];
        idx = (idx + 1) % capacity;
    }
    
    delete[] data;
    data = newData;
    front = 0;
    rear = count;
    capacity = newCapacity;
}
```

## 7. 시간 복잡도

| 연산 | 시간 복잡도 |
|------|------------|
| Enqueue | O(1) |
| Dequeue | O(1) |
| Peek | O(1) |
| isEmpty/isFull | O(1) |
| Resize | O(n) |

## 8. 환형 큐의 장점

1. **고정 크기 메모리**: 예측 가능한 메모리 사용
2. **O(1) 연산**: 빠른 삽입과 삭제
3. **공간 재사용**: 메모리 효율성
4. **간단한 구현**: 복잡한 포인터 연산 불필요

## 9. 실제 활용 예시

- **버퍼 관리**: 생산자-소비자 패턴
- **이벤트 큐**: 고정 크기 이벤트 처리
- **히스토리 관리**: 최근 N개 항목만 유지
- **스케줄링**: 라운드 로빈 스케줄러

## 10. 추가 학습 포인트

- **Thread-safe 구현**: mutex를 이용한 동기화
- **Lock-free 구현**: atomic 연산 활용
- **Double-ended queue**: 양방향 삽입/삭제
- **Priority queue**: 우선순위 기반 큐