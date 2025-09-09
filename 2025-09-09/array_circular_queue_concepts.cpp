#include <iostream>
#include <cstring>

void basicArrayConcepts() {
    std::cout << "\n=== 1. C 스타일 배열 기본 개념 ===" << std::endl;
    
    // 배열 선언과 초기화
    int arr[5] = {10, 20, 30, 40, 50};
    
    // 배열 이름은 첫 번째 요소의 주소
    std::cout << "배열 이름 arr: " << arr << std::endl;
    std::cout << "첫 번째 요소 주소 &arr[0]: " << &arr[0] << std::endl;
    std::cout << "두 값이 같음: " << (arr == &arr[0] ? "true" : "false") << std::endl;
    
    // 배열 인덱싱과 포인터 산술
    std::cout << "\n배열 접근 방법:" << std::endl;
    std::cout << "arr[2] = " << arr[2] << std::endl;
    std::cout << "*(arr + 2) = " << *(arr + 2) << std::endl;
    
    // 배열 크기 계산
    std::cout << "\n배열 크기:" << std::endl;
    std::cout << "sizeof(arr) = " << sizeof(arr) << " bytes" << std::endl;
    std::cout << "요소 개수 = " << sizeof(arr)/sizeof(arr[0]) << std::endl;
}

void pointerArithmetic() {
    std::cout << "\n=== 2. 포인터 산술 연산 ===" << std::endl;
    
    int arr[5] = {10, 20, 30, 40, 50};
    int* ptr = arr;
    
    std::cout << "초기 ptr 주소: " << ptr << ", 값: " << *ptr << std::endl;
    
    // 포인터 증가
    ptr++;
    std::cout << "ptr++ 후 주소: " << ptr << ", 값: " << *ptr << std::endl;
    
    // 포인터로 배열 순회
    std::cout << "\n포인터로 배열 순회:" << std::endl;
    ptr = arr;  // 초기화
    for(int i = 0; i < 5; i++) {
        std::cout << "ptr[" << i << "] = " << *(ptr + i) << std::endl;
    }
}

void modularArithmetic() {
    std::cout << "\n=== 3. 모듈러 연산 (환형 구조의 핵심) ===" << std::endl;
    
    const int SIZE = 5;
    
    std::cout << "배열 크기: " << SIZE << std::endl;
    std::cout << "\n인덱스 순환 예시:" << std::endl;
    
    for(int i = 0; i < 10; i++) {
        int circularIndex = i % SIZE;
        std::cout << "i = " << i << " -> 환형 인덱스 = " << circularIndex << std::endl;
    }
    
    std::cout << "\n음수 처리 (역방향):" << std::endl;
    for(int i = -1; i >= -5; i--) {
        int circularIndex = (i % SIZE + SIZE) % SIZE;
        std::cout << "i = " << i << " -> 환형 인덱스 = " << circularIndex << std::endl;
    }
}

// 간단한 환형 큐 구조체
struct CircularQueue {
    static const int MAX_SIZE = 5;
    int data[MAX_SIZE];
    int front;
    int rear;
    int count;
    
    CircularQueue() : front(0), rear(0), count(0) {
        memset(data, 0, sizeof(data));
    }
    
    bool isEmpty() { return count == 0; }
    bool isFull() { return count == MAX_SIZE; }
    
    bool enqueue(int value) {
        if(isFull()) {
            std::cout << "큐가 가득 참!" << std::endl;
            return false;
        }
        
        data[rear] = value;
        rear = (rear + 1) % MAX_SIZE;  // 환형 증가
        count++;
        return true;
    }
    
    bool dequeue(int& value) {
        if(isEmpty()) {
            std::cout << "큐가 비어있음!" << std::endl;
            return false;
        }
        
        value = data[front];
        front = (front + 1) % MAX_SIZE;  // 환형 증가
        count--;
        return true;
    }
    
    void display() {
        std::cout << "큐 상태: ";
        if(isEmpty()) {
            std::cout << "비어있음";
        } else {
            int idx = front;
            for(int i = 0; i < count; i++) {
                std::cout << data[idx] << " ";
                idx = (idx + 1) % MAX_SIZE;
            }
        }
        std::cout << " [front=" << front << ", rear=" << rear 
                  << ", count=" << count << "]" << std::endl;
    }
};

void circularQueueDemo() {
    std::cout << "\n=== 4. 환형 큐 동작 원리 ===" << std::endl;
    
    CircularQueue queue;
    
    std::cout << "\n1) 요소 추가 (Enqueue):" << std::endl;
    for(int i = 1; i <= 6; i++) {
        std::cout << "Enqueue(" << i*10 << "): ";
        queue.enqueue(i*10);
        queue.display();
    }
    
    std::cout << "\n2) 요소 제거 (Dequeue):" << std::endl;
    int value;
    for(int i = 0; i < 3; i++) {
        if(queue.dequeue(value)) {
            std::cout << "Dequeue() = " << value << ": ";
            queue.display();
        }
    }
    
    std::cout << "\n3) 환형 특성 테스트 (재사용):" << std::endl;
    for(int i = 7; i <= 9; i++) {
        std::cout << "Enqueue(" << i*10 << "): ";
        queue.enqueue(i*10);
        queue.display();
    }
    
    std::cout << "\n4) 모든 요소 제거:" << std::endl;
    while(!queue.isEmpty()) {
        if(queue.dequeue(value)) {
            std::cout << "Dequeue() = " << value << ": ";
            queue.display();
        }
    }
}

void arrayVsPointerDifference() {
    std::cout << "\n=== 5. 배열과 포인터의 차이 ===" << std::endl;
    
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr;
    
    std::cout << "sizeof(arr) = " << sizeof(arr) << " bytes (전체 배열)" << std::endl;
    std::cout << "sizeof(ptr) = " << sizeof(ptr) << " bytes (포인터 크기)" << std::endl;
    
    // 배열은 상수, 포인터는 변수
    std::cout << "\n포인터는 재할당 가능:" << std::endl;
    int arr2[3] = {10, 20, 30};
    ptr = arr2;  // OK
    std::cout << "ptr이 arr2를 가리킴: " << *ptr << std::endl;
    
    // arr = arr2;  // 컴파일 에러! 배열 이름은 상수
}

int main() {
    std::cout << "=====================================" << std::endl;
    std::cout << "   C 스타일 배열 환형 큐 핵심 개념   " << std::endl;
    std::cout << "=====================================" << std::endl;
    
    basicArrayConcepts();
    pointerArithmetic();
    modularArithmetic();
    circularQueueDemo();
    arrayVsPointerDifference();
    
    std::cout << "\n=====================================" << std::endl;
    std::cout << "환형 큐의 핵심 포인트:" << std::endl;
    std::cout << "1. 고정 크기 배열 사용" << std::endl;
    std::cout << "2. front와 rear 인덱스로 큐 관리" << std::endl;
    std::cout << "3. 모듈러 연산(%)으로 인덱스 순환" << std::endl;
    std::cout << "4. 배열 공간 재사용으로 메모리 효율성" << std::endl;
    std::cout << "5. count 변수로 full/empty 상태 구분" << std::endl;
    std::cout << "=====================================" << std::endl;
    
    return 0;
}