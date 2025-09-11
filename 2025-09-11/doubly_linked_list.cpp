#include <iostream>
using namespace std;

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        
        Node(int value) : data(value), next(nullptr), prev(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    int size;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    ~DoublyLinkedList() {
        clear();
    }
    
    void push_front(int value);
    void push_back(int value);
    bool remove(int value);
    void display();
    void displayReverse();
    bool empty() const { return size == 0; }
    int getSize() const { return size; }
    void clear();
};

void DoublyLinkedList::push_front(int value) {
    Node* newNode = new Node(value);
    
    if (empty()) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

void DoublyLinkedList::push_back(int value) {
    Node* newNode = new Node(value);
    
    if (empty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

bool DoublyLinkedList::remove(int value) {
    Node* current = head;
    
    while (current != nullptr) {
        if (current->data == value) {
            if (current == head && current == tail) {
                head = tail = nullptr;
            } else if (current == head) {
                head = current->next;
                head->prev = nullptr;
            } else if (current == tail) {
                tail = current->prev;
                tail->next = nullptr;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            
            delete current;
            size--;
            return true;
        }
        current = current->next;
    }
    return false;
}

void DoublyLinkedList::display() {
    Node* current = head;
    cout << "List: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void DoublyLinkedList::displayReverse() {
    Node* current = tail;
    cout << "Reverse: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

void DoublyLinkedList::clear() {
    while (!empty()) {
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }
    tail = nullptr;
}

int main() {
    DoublyLinkedList list;
    
    cout << "=== Doubly Linked List Test ===" << endl;
    
    cout << "\n1. 앞쪽 삽입 테스트" << endl;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.display();
    list.displayReverse();
    
    cout << "\n2. 끝쪽 삽입 테스트" << endl;
    list.push_back(40);
    list.push_back(50);
    list.display();
    list.displayReverse();
    
    cout << "\n3. 특정값 삭제 테스트" << endl;
    cout << "20 삭제: " << (list.remove(20) ? "성공" : "실패") << endl;
    list.display();
    
    cout << "100 삭제 시도: " << (list.remove(100) ? "성공" : "실패") << endl;
    
    cout << "30 삭제: " << (list.remove(30) ? "성공" : "실패") << endl;
    list.display();
    
    cout << "\n4. 크기 정보" << endl;
    cout << "현재 크기: " << list.getSize() << endl;
    
    return 0;
}