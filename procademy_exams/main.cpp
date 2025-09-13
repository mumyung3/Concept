#include <iostream>
#define MAX 100
struct Queue{
    int ar[MAX];
    int front;
    int rear;
};
// 배열 원소 하나는 없도록 빌때는 front == rear
// 배열 원소 하나는 꽉차게 할때는 (rear + 1)

bool IsEmpty(Queue &q){
    return q.front == q.rear;
}
bool IsFull(Queue &q){
    return (q.rear + 1) % MAX == q.front;
}

void Dequque(Queue &q){

    if(IsEmpty(q)){
        return;
    }
    //뺀다
    printf("Deque : %d\n", q.ar[q.front]);
    q.ar[q.front] = 0;
    q.front = (q.front + 1) % MAX;
}

void Enqueue(Queue &q, int val){
    if(IsFull(q)){
        return;
    }
    //넣는다
    q.ar[q.rear] = val;
    q.rear = (q.rear + 1) % MAX;
}

// list cpp 스타일
class Node{
public:
    int data;
    Node *next =nullptr;
    Node *prev =nullptr;
};

class LinkedList{
public:
    Node *head = nullptr;
    Node *tail = nullptr;
    void AddNodeHeader(int data){
        Node * newNode = new Node();
        newNode->data = data;
        if(/*아무것도 없을때*/ head == nullptr && tail == nullptr){
            head = newNode;
            tail = newNode;
            return;
        }
        else {
            // newnode -
            // ㅁㅡㅁ
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }
    }
    void AddNodeTail(int data){
        Node * newNode = new Node();
        newNode->data = data;
        if(/*아무것도 없을때*/ head == nullptr && tail == nullptr){
            head = newNode;
            tail = newNode;
            return;
        }
        else {
            // ㅁㅡㅁ -
            //       newnode
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            return;
        }
    }

    Node* RemoveNode(int data){
        Node *cur = head;
        while(cur!=nullptr){
            if(cur->data == data){
                // head 노드 처리
                if(cur->prev == nullptr) head = cur->next;
                else cur->prev->next = cur->next;

                // tail 노드 처리  
                if(cur->next == nullptr) tail = cur->prev;
                else cur->next->prev = cur->prev;

                cur->next = nullptr;
                cur->prev = nullptr;
                return cur;
            }
            cur = cur->next;

        }
        return nullptr;

    }
};
/*

ㅁㅁㅁㅁ
ㅁㅁㅁ
ㅁㅁ

*/
void bubbleSort(int ar[], int size){
    for(int i = 0 ; i< size - 1; i++){
        for(int j=0;j<size - i - 1;j++){
            if(ar[j] > ar[j+1]){
                int temp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = temp;
            }
        }
    }
}

void bubbleSortList(LinkedList &list){
    if(list.head == nullptr) return;
    
    bool swapped;
    do {
        swapped = false;
        Node *cur = list.head;
        
        while(cur != nullptr && cur->next != nullptr){
            if(cur->data > cur->next->data){
                int temp = cur->data;
                cur->data = cur->next->data;
                cur->next->data = temp;
                swapped = true;
            }
            cur = cur->next;
        }
    } while(swapped);
}

int main() {



    return 0;
}