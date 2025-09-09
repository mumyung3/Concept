#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

class CircularQueue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;
    int count;

public:
    CircularQueue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX_SIZE;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "큐가 가득 찼습니다! " << value << "를 추가할 수 없습니다." << endl;
            return;
        }
        
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = value;
        count++;
        cout << value << " 삽입됨" << endl;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "큐가 비어있습니다!" << endl;
            return -1;
        }
        
        int value = arr[front];
        front = (front + 1) % MAX_SIZE;
        count--;
        return value;
    }

    int peek() {
        if (isEmpty()) {
            cout << "큐가 비어있습니다!" << endl;
            return -1;
        }
        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "큐가 비어있습니다!" << endl;
            return;
        }
        
        cout << "큐 내용: ";
        int i = front;
        for (int j = 0; j < count; j++) {
            cout << arr[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
        cout << "Front 인덱스: " << front << ", Rear 인덱스: " << rear << ", 요소 개수: " << count << endl;
    }
};

int main() {
    CircularQueue queue;
    
    cout << "=== 환형 큐 테스트 ===" << endl;
    cout << "큐 크기: " << MAX_SIZE << endl << endl;
    
    cout << "1. 요소 삽입 테스트" << endl;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.display();
    
    cout << "\n2. 큐가 가득 찬 상태에서 삽입 시도" << endl;
    queue.enqueue(60);
    
    cout << "\n3. 요소 제거 테스트" << endl;
    cout << "제거된 요소: " << queue.dequeue() << endl;
    cout << "제거된 요소: " << queue.dequeue() << endl;
    queue.display();
    
    cout << "\n4. 환형 특성 테스트 (rear가 다시 앞으로)" << endl;
    queue.enqueue(60);
    queue.enqueue(70);
    queue.display();
    
    cout << "\n5. Peek 테스트" << endl;
    cout << "Front 요소 (제거하지 않고 확인): " << queue.peek() << endl;
    
    cout << "\n6. 모든 요소 제거" << endl;
    while (!queue.isEmpty()) {
        cout << "제거된 요소: " << queue.dequeue() << endl;
    }
    queue.display();
    
    cout << "\n7. 빈 큐에서 제거 시도" << endl;
    queue.dequeue();
    
    return 0;
}