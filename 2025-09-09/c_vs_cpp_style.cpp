// C 스타일 vs C++ 스타일 비교

#include <iostream>
#include <vector>
#include <memory>
#include <cstdlib>  // malloc, free
#include <cstring>  // memcpy

// ========== C 스타일 ==========

// 1. C 스타일 배열
void c_style_array() {
    // 정적 배열
    int arr1[10];  // 스택에 할당, 크기 고정
    
    // 동적 배열 (malloc/free 사용)
    int* arr2 = (int*)malloc(10 * sizeof(int));
    if (arr2 == NULL) {
        // 에러 처리
    }
    
    // 사용
    for (int i = 0; i < 10; i++) {
        arr2[i] = i;
    }
    
    // 메모리 해제 필수
    free(arr2);
}

// 2. C 스타일 구조체
typedef struct {
    int x;
    int y;
} Point_C;

// 3. C 스타일 함수
int add_c(int a, int b) {
    return a + b;
}

// 4. C 스타일 문자열
void c_style_string() {
    char str1[100] = "Hello";  // 고정 크기
    char* str2 = (char*)malloc(100 * sizeof(char));
    strcpy(str2, "World");
    
    // 문자열 연결
    strcat(str1, " ");
    strcat(str1, str2);
    
    free(str2);
}

// 5. C 스타일 환형 큐 예제
typedef struct {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} CircularQueue_C;

CircularQueue_C* createQueue(int capacity) {
    CircularQueue_C* queue = (CircularQueue_C*)malloc(sizeof(CircularQueue_C));
    queue->data = (int*)malloc(capacity * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    queue->capacity = capacity;
    return queue;
}

void enqueue_c(CircularQueue_C* queue, int value) {
    if (queue->size == queue->capacity) {
        printf("Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = value;
    queue->size++;
}

void destroyQueue(CircularQueue_C* queue) {
    free(queue->data);
    free(queue);
}

// ========== C++ 스타일 ==========

// 1. C++ 스타일 배열/컨테이너
void cpp_style_array() {
    // 정적 배열 (C++11 std::array)
    std::array<int, 10> arr1;
    
    // 동적 배열 (vector)
    std::vector<int> arr2(10);
    
    // 자동 메모리 관리
    for (int i = 0; i < 10; i++) {
        arr2[i] = i;
    }
    
    // 크기 변경 가능
    arr2.push_back(11);
    arr2.resize(20);
    
    // 소멸자에서 자동으로 메모리 해제
}

// 2. C++ 스타일 클래스
class Point_CPP {
private:
    int x, y;
    
public:
    Point_CPP(int x = 0, int y = 0) : x(x), y(y) {}
    
    // 메서드
    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }
    
    // getter/setter
    int getX() const { return x; }
    int getY() const { return y; }
};

// 3. C++ 스타일 함수 (템플릿, 오버로딩)
template<typename T>
T add_cpp(T a, T b) {
    return a + b;
}

// 함수 오버로딩
int add_cpp(int a, int b, int c) {
    return a + b + c;
}

// 4. C++ 스타일 문자열
void cpp_style_string() {
    std::string str1 = "Hello";
    std::string str2 = "World";
    
    // 간단한 연결
    std::string result = str1 + " " + str2;
    
    // 자동 메모리 관리
}

// 5. C++ 스타일 환형 큐 클래스
template<typename T>
class CircularQueue_CPP {
private:
    std::vector<T> data;
    int front;
    int rear;
    int size;
    int capacity;
    
public:
    CircularQueue_CPP(int cap) : data(cap), front(0), rear(-1), size(0), capacity(cap) {}
    
    void enqueue(const T& value) {
        if (size == capacity) {
            std::cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % capacity;
        data[rear] = value;
        size++;
    }
    
    T dequeue() {
        if (size == 0) {
            throw std::runtime_error("Queue is empty");
        }
        T value = data[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }
    
    bool isEmpty() const { return size == 0; }
    bool isFull() const { return size == capacity; }
    
    // 소멸자 불필요 (vector가 자동 관리)
};

// ========== 주요 차이점 정리 ==========
/*
1. 메모리 관리:
   - C: malloc/free 수동 관리
   - C++: new/delete 또는 스마트 포인터, RAII

2. 데이터 구조:
   - C: 구조체(struct), 함수 포인터
   - C++: 클래스, 상속, 다형성, 캡슐화

3. 타입 안정성:
   - C: void* 캐스팅, 타입 체크 약함
   - C++: 템플릿, 강한 타입 체크

4. 에러 처리:
   - C: 반환값 체크, errno
   - C++: 예외 처리(exception)

5. 표준 라이브러리:
   - C: 제한적 (stdio.h, stdlib.h 등)
   - C++: STL (vector, string, map 등)

6. 코드 재사용:
   - C: 함수, 매크로
   - C++: 템플릿, 상속, 오버로딩
*/

int main() {
    std::cout << "=== C 스타일 환형 큐 ===" << std::endl;
    CircularQueue_C* cQueue = createQueue(5);
    enqueue_c(cQueue, 10);
    enqueue_c(cQueue, 20);
    destroyQueue(cQueue);
    
    std::cout << "\n=== C++ 스타일 환형 큐 ===" << std::endl;
    CircularQueue_CPP<int> cppQueue(5);
    cppQueue.enqueue(10);
    cppQueue.enqueue(20);
    // 자동으로 메모리 해제
    
    return 0;
}