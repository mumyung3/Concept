#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

// void 키워드의 일반적인 사용 사례

// ========== 1. 반환값이 없는 함수 ==========
void printMessage(const std::string& msg) {
    std::cout << msg << std::endl;
    // return 생략 가능 (또는 return; 만 작성)
}

void updateCounter(int& counter) {
    counter++;
    // 값을 반환하지 않고 참조로 전달된 변수만 수정
}

// ========== 2. 매개변수가 없음을 명시 (C 스타일) ==========
void noParameters(void) {  // C에서는 void를 명시
    std::cout << "매개변수가 없는 함수\n";
}
// C++에서는 그냥 () 만 써도 됨
void noParametersCpp() {
    std::cout << "C++에서는 void 생략 가능\n";
}

// ========== 3. void 포인터 (이미 학습함) ==========
void demonstrateVoidPointer() {
    int x = 10;
    void* ptr = &x;  // 어떤 타입의 주소든 저장
    int* intPtr = static_cast<int*>(ptr);
    std::cout << "void* 사용: " << *intPtr << "\n";
}

// ========== 4. 함수 포인터에서 void 반환 ==========
void actionA() {
    std::cout << "Action A 실행\n";
}

void actionB() {
    std::cout << "Action B 실행\n";
}

void executeFunctionPointer() {
    // void를 반환하는 함수 포인터
    void (*funcPtr)() = nullptr;
    
    funcPtr = actionA;
    funcPtr();  // Action A 실행
    
    funcPtr = actionB;
    funcPtr();  // Action B 실행
}

// ========== 5. 콜백 함수 ==========
void processData(int data, void (*callback)(int)) {
    std::cout << "데이터 처리 중: " << data << "\n";
    callback(data * 2);  // 콜백 실행
}

void onComplete(int result) {
    std::cout << "처리 완료! 결과: " << result << "\n";
}

// ========== 6. 클래스 멤버 함수 ==========
class Logger {
private:
    std::vector<std::string> logs;
    
public:
    // void 반환 멤버 함수들
    void addLog(const std::string& message) {
        logs.push_back(message);
    }
    
    void clearLogs() {
        logs.clear();
    }
    
    void printAllLogs() const {
        for (const auto& log : logs) {
            std::cout << "[LOG] " << log << "\n";
        }
    }
};

// ========== 7. 소멸자는 항상 void ==========
class Resource {
private:
    int* data;
    
public:
    Resource(int size) {
        data = new int[size];
        std::cout << "리소스 할당\n";
    }
    
    ~Resource() {  // 소멸자는 반환 타입이 없음 (암묵적으로 void)
        delete[] data;
        std::cout << "리소스 해제\n";
    }
};

// ========== 8. 스레드 함수 ==========
void threadFunction(int id) {
    std::cout << "스레드 " << id << " 실행 중\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout << "스레드 " << id << " 완료\n";
}

// ========== 9. 이벤트 핸들러 ==========
class Button {
private:
    void (*onClick)();
    
public:
    void setClickHandler(void (*handler)()) {
        onClick = handler;
    }
    
    void click() {
        if (onClick) {
            onClick();
        }
    }
};

void onButtonClick() {
    std::cout << "버튼이 클릭되었습니다!\n";
}

// ========== 10. void 사용 시 주의사항 ==========
// void 타입 변수는 선언 불가능
// void x;  // 에러! void 타입 변수는 불가능

// void 배열도 불가능
// void arr[10];  // 에러!

// 하지만 void 포인터는 가능
// void* ptr;  // OK!

int main() {
    std::cout << "=== void 키워드 사용 사례 ===\n\n";
    
    // 1. 반환값 없는 함수
    std::cout << "1. 반환값 없는 함수:\n";
    printMessage("Hello, void!");
    int counter = 0;
    updateCounter(counter);
    std::cout << "카운터 값: " << counter << "\n\n";
    
    // 2. 매개변수 없는 함수
    std::cout << "2. 매개변수 없는 함수:\n";
    noParameters();
    noParametersCpp();
    std::cout << "\n";
    
    // 3. void 포인터
    std::cout << "3. void 포인터:\n";
    demonstrateVoidPointer();
    std::cout << "\n";
    
    // 4. 함수 포인터
    std::cout << "4. 함수 포인터:\n";
    executeFunctionPointer();
    std::cout << "\n";
    
    // 5. 콜백 함수
    std::cout << "5. 콜백 함수:\n";
    processData(10, onComplete);
    std::cout << "\n";
    
    // 6. 클래스 멤버 함수
    std::cout << "6. 클래스 멤버 함수:\n";
    Logger logger;
    logger.addLog("시스템 시작");
    logger.addLog("작업 진행 중");
    logger.addLog("작업 완료");
    logger.printAllLogs();
    std::cout << "\n";
    
    // 7. 생성자/소멸자
    std::cout << "7. 생성자/소멸자:\n";
    {
        Resource res(100);
        // 스코프를 벗어나면 자동으로 소멸자 호출
    }
    std::cout << "\n";
    
    // 8. 스레드 함수
    std::cout << "8. 스레드 함수:\n";
    std::thread t1(threadFunction, 1);
    std::thread t2(threadFunction, 2);
    t1.join();
    t2.join();
    std::cout << "\n";
    
    // 9. 이벤트 핸들러
    std::cout << "9. 이벤트 핸들러:\n";
    Button btn;
    btn.setClickHandler(onButtonClick);
    btn.click();
    
    std::cout << "\n=== void 사용 요약 ===\n";
    std::cout << "1. 함수가 값을 반환하지 않을 때: void function()\n";
    std::cout << "2. 매개변수가 없음을 명시할 때: function(void) - C 스타일\n";
    std::cout << "3. 제네릭 포인터가 필요할 때: void* ptr\n";
    std::cout << "4. 콜백, 이벤트 핸들러 등에서 반환값이 불필요할 때\n";
    std::cout << "5. 소멸자는 항상 void (명시하지 않음)\n";
    
    return 0;
}