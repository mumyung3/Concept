#include <iostream>
#include <cstring>
#include <iomanip>

template<typename T>
class CircularQueue {
private:
    T* data;           // 동적 할당 배열
    int capacity;      // 큐의 최대 크기
    int front;         // 첫 번째 요소 인덱스
    int rear;          // 다음 삽입 위치 인덱스
    int count;         // 현재 요소 개수
    
public:
    // 생성자
    CircularQueue(int size = 10) : capacity(size), front(0), rear(0), count(0) {
        data = new T[capacity]();  // 값 초기화 사용
    }
    
    // 소멸자
    ~CircularQueue() {
        delete[] data;
    }
    
    // 복사 생성자
    CircularQueue(const CircularQueue& other) 
        : capacity(other.capacity), front(other.front), rear(other.rear), count(other.count) {
        data = new T[capacity];
        memcpy(data, other.data, sizeof(T) * capacity);
    }
    
    // 대입 연산자
    CircularQueue& operator=(const CircularQueue& other) {
        if(this != &other) {
            delete[] data;
            capacity = other.capacity;
            front = other.front;
            rear = other.rear;
            count = other.count;
            data = new T[capacity];
            memcpy(data, other.data, sizeof(T) * capacity);
        }
        return *this;
    }
    
    // 큐가 비어있는지 확인
    bool isEmpty() const {
        return count == 0;
    }
    
    // 큐가 가득 찼는지 확인
    bool isFull() const {
        return count == capacity;
    }
    
    // 현재 요소 개수 반환
    int size() const {
        return count;
    }
    
    // 큐의 최대 용량 반환
    int getCapacity() const {
        return capacity;
    }
    
    // 요소 추가 (큐의 뒤에)
    bool enqueue(const T& value) {
        if(isFull()) {
            return false;
        }
        
        data[rear] = value;
        rear = (rear + 1) % capacity;  // 환형 증가
        count++;
        return true;
    }
    
    // 요소 제거 (큐의 앞에서)
    bool dequeue(T& value) {
        if(isEmpty()) {
            return false;
        }
        
        value = data[front];
        front = (front + 1) % capacity;  // 환형 증가
        count--;
        return true;
    }
    
    // 요소 제거 (반환값 버전)
    T dequeue() {
        if(isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        
        T value = data[front];
        front = (front + 1) % capacity;
        count--;
        return value;
    }
    
    // 맨 앞 요소 확인 (제거하지 않음)
    bool peek(T& value) const {
        if(isEmpty()) {
            return false;
        }
        value = data[front];
        return true;
    }
    
    // 맨 앞 요소 확인 (반환값 버전)
    T& getFront() {
        if(isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        return data[front];
    }
    
    // 맨 뒤 요소 확인
    T& getRear() {
        if(isEmpty()) {
            throw std::runtime_error("Queue is empty");
        }
        int lastIndex = (rear - 1 + capacity) % capacity;
        return data[lastIndex];
    }
    
    // 큐 초기화
    void clear() {
        front = 0;
        rear = 0;
        count = 0;
        // 요소들을 기본값으로 재초기화
        for(int i = 0; i < capacity; i++) {
            data[i] = T();
        }
    }
    
    // 큐 크기 조정
    void resize(int newCapacity) {
        if(newCapacity <= count) {
            throw std::invalid_argument("New capacity must be larger than current element count");
        }
        
        T* newData = new T[newCapacity];
        
        // 기존 데이터 복사 (순서대로)
        int idx = front;
        for(int i = 0; i < count; i++) {
            newData[i] = data[idx];
            idx = (idx + 1) % capacity;
        }
        
        delete[] data;
        data = newData;
        capacity = newCapacity;
        front = 0;
        rear = count;
    }
    
    // 큐 내용 출력
    void display() const {
        std::cout << "Queue[" << count << "/" << capacity << "]: ";
        
        if(isEmpty()) {
            std::cout << "Empty";
        } else {
            int idx = front;
            std::cout << "[";
            for(int i = 0; i < count; i++) {
                std::cout << data[idx];
                if(i < count - 1) std::cout << ", ";
                idx = (idx + 1) % capacity;
            }
            std::cout << "]";
        }
        
        std::cout << " (front=" << front << ", rear=" << rear << ")" << std::endl;
    }
    
    // 내부 배열 상태 출력 (디버깅용)
    void displayInternal() const {
        std::cout << "Internal array: [";
        for(int i = 0; i < capacity; i++) {
            if(i == front && i == rear && !isEmpty()) {
                std::cout << "F/R:";
            } else if(i == front && !isEmpty()) {
                std::cout << "F:";
            } else if(i == rear) {
                std::cout << "R:";
            }
            
            std::cout << std::setw(3) << data[i];
            
            if(i < capacity - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
};

// 테스트 함수들
void testBasicOperations() {
    std::cout << "\n=== Basic Operations Test ===" << std::endl;
    
    CircularQueue<int> queue(5);
    
    std::cout << "Initial state: ";
    queue.display();
    
    // Enqueue 테스트
    std::cout << "\nEnqueue operations:" << std::endl;
    for(int i = 1; i <= 6; i++) {
        if(queue.enqueue(i * 10)) {
            std::cout << "Enqueued " << i * 10 << ": ";
        } else {
            std::cout << "Failed to enqueue " << i * 10 << " (full): ";
        }
        queue.display();
    }
    
    // Dequeue 테스트
    std::cout << "\nDequeue operations:" << std::endl;
    int value;
    for(int i = 0; i < 3; i++) {
        if(queue.dequeue(value)) {
            std::cout << "Dequeued " << value << ": ";
            queue.display();
        }
    }
    
    // 환형 특성 테스트
    std::cout << "\nCircular property test:" << std::endl;
    queue.enqueue(60);
    queue.enqueue(70);
    queue.enqueue(80);
    queue.display();
    queue.displayInternal();
}

void testResize() {
    std::cout << "\n=== Resize Test ===" << std::endl;
    
    CircularQueue<int> queue(3);
    
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    
    std::cout << "Before resize: ";
    queue.display();
    queue.displayInternal();
    
    queue.resize(6);
    
    std::cout << "After resize to 6: ";
    queue.display();
    queue.displayInternal();
    
    queue.enqueue(40);
    queue.enqueue(50);
    std::cout << "After adding more elements: ";
    queue.display();
}

void testStringQueue() {
    std::cout << "\n=== String Queue Test ===" << std::endl;
    
    CircularQueue<std::string> queue(4);
    
    queue.enqueue("Hello");
    queue.enqueue("World");
    queue.enqueue("Circular");
    queue.enqueue("Queue");
    
    queue.display();
    
    std::cout << "Front element: " << queue.getFront() << std::endl;
    std::cout << "Rear element: " << queue.getRear() << std::endl;
    
    std::string str;
    queue.dequeue(str);
    std::cout << "Dequeued: " << str << std::endl;
    queue.display();
}

void testEdgeCases() {
    std::cout << "\n=== Edge Cases Test ===" << std::endl;
    
    CircularQueue<int> queue(2);
    
    // 빈 큐에서 dequeue 시도
    int value;
    if(!queue.dequeue(value)) {
        std::cout << "Cannot dequeue from empty queue" << std::endl;
    }
    
    // 가득 찬 큐 테스트
    queue.enqueue(1);
    queue.enqueue(2);
    if(!queue.enqueue(3)) {
        std::cout << "Cannot enqueue to full queue" << std::endl;
    }
    
    // Clear 테스트
    queue.clear();
    std::cout << "After clear: ";
    queue.display();
    
    // 복사 생성자 테스트
    CircularQueue<int> queue2(3);
    queue2.enqueue(100);
    queue2.enqueue(200);
    
    CircularQueue<int> queue3(queue2);
    std::cout << "Original queue: ";
    queue2.display();
    std::cout << "Copied queue: ";
    queue3.display();
}

void performanceDemo() {
    std::cout << "\n=== Performance Demo ===" << std::endl;
    
    const int SIZE = 1000000;
    CircularQueue<int> queue(SIZE);
    
    std::cout << "Adding " << SIZE << " elements..." << std::endl;
    for(int i = 0; i < SIZE; i++) {
        queue.enqueue(i);
    }
    std::cout << "Size: " << queue.size() << "/" << queue.getCapacity() << std::endl;
    
    std::cout << "Removing half elements..." << std::endl;
    int value;
    for(int i = 0; i < SIZE/2; i++) {
        queue.dequeue(value);
    }
    std::cout << "Size: " << queue.size() << "/" << queue.getCapacity() << std::endl;
    
    std::cout << "Adding more elements (reusing space)..." << std::endl;
    for(int i = SIZE; i < SIZE + SIZE/2; i++) {
        queue.enqueue(i);
    }
    std::cout << "Final size: " << queue.size() << "/" << queue.getCapacity() << std::endl;
}

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "    C++ Circular Queue Implementation   " << std::endl;
    std::cout << "========================================" << std::endl;
    
    testBasicOperations();
    testResize();
    testStringQueue();
    testEdgeCases();
    performanceDemo();
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "환형 큐 구현 특징:" << std::endl;
    std::cout << "1. 템플릿으로 다양한 타입 지원" << std::endl;
    std::cout << "2. 동적 메모리 할당 및 크기 조정 가능" << std::endl;
    std::cout << "3. 복사 생성자와 대입 연산자 구현" << std::endl;
    std::cout << "4. 예외 처리 및 에러 핸들링" << std::endl;
    std::cout << "5. O(1) 시간 복잡도의 enqueue/dequeue" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}