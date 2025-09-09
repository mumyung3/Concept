#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

// void* 그 자체의 실제 사용법들

// 1. 제네릭 함수: qsort 스타일
int compareInts(const void* a, const void* b) {
    int intA = *(const int*)a;
    int intB = *(const int*)b;
    return (intA > intB) - (intA < intB);
}

int compareFloats(const void* a, const void* b) {
    float floatA = *(const float*)a;
    float floatB = *(const float*)b;
    return (floatA > floatB) - (floatA < floatB);
}

// 2. 제네릭 스왑 함수
void genericSwap(void* a, void* b, size_t size) {
    void* temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

// 3. 제네릭 메모리 풀
struct MemoryPool {
    void* memory;
    size_t size;
    size_t used;
    
    MemoryPool(size_t poolSize) : size(poolSize), used(0) {
        memory = malloc(poolSize);
    }
    
    ~MemoryPool() {
        free(memory);
    }
    
    void* allocate(size_t bytes) {
        if (used + bytes > size) return nullptr;
        void* result = (char*)memory + used;
        used += bytes;
        return result;
    }
};

// 4. 콜백 함수에서 사용자 데이터 전달
void processCallback(void (*callback)(void* data), void* userData) {
    std::cout << "콜백 실행 전 작업...\n";
    callback(userData);
    std::cout << "콜백 실행 후 정리...\n";
}

void intCallback(void* data) {
    int* intData = (int*)data;
    std::cout << "정수 데이터: " << *intData << "\n";
}

void stringCallback(void* data) {
    const char* strData = (const char*)data;
    std::cout << "문자열 데이터: " << strData << "\n";
}

// 5. 이벤트 시스템
enum EventType {
    INT_EVENT,
    FLOAT_EVENT,
    STRING_EVENT
};

struct Event {
    EventType type;
    void* data;
    size_t dataSize;
    
    Event(EventType t, void* d, size_t s) : type(t), dataSize(s) {
        data = malloc(s);
        memcpy(data, d, s);
    }
    
    ~Event() {
        free(data);
    }
};

void handleEvent(const Event& event) {
    switch(event.type) {
        case INT_EVENT:
            std::cout << "정수 이벤트: " << *(int*)event.data << "\n";
            break;
        case FLOAT_EVENT:
            std::cout << "실수 이벤트: " << *(float*)event.data << "\n";
            break;
        case STRING_EVENT:
            std::cout << "문자열 이벤트: " << (char*)event.data << "\n";
            break;
    }
}

int main() {
    std::cout << "=== void* 그 자체의 실제 사용법들 ===\n\n";
    
    // 1. C 표준 라이브러리 스타일 제네릭 정렬
    std::cout << "1. 제네릭 정렬 (qsort 스타일):\n";
    
    int intArray[] = {5, 2, 8, 1, 9};
    float floatArray[] = {3.14f, 1.5f, 2.7f, 0.5f};
    
    std::cout << "   정렬 전 int 배열: ";
    for(int i = 0; i < 5; i++) std::cout << intArray[i] << " ";
    std::cout << "\n";
    
    qsort(intArray, 5, sizeof(int), compareInts);
    
    std::cout << "   정렬 후 int 배열: ";
    for(int i = 0; i < 5; i++) std::cout << intArray[i] << " ";
    std::cout << "\n\n";
    
    std::cout << "   정렬 전 float 배열: ";
    for(int i = 0; i < 4; i++) std::cout << floatArray[i] << " ";
    std::cout << "\n";
    
    qsort(floatArray, 4, sizeof(float), compareFloats);
    
    std::cout << "   정렬 후 float 배열: ";
    for(int i = 0; i < 4; i++) std::cout << floatArray[i] << " ";
    std::cout << "\n\n";
    
    // 2. 제네릭 스왑
    std::cout << "2. 제네릭 스왑 함수:\n";
    
    int a = 100, b = 200;
    std::cout << "   int 교환 전: a=" << a << ", b=" << b << "\n";
    genericSwap(&a, &b, sizeof(int));
    std::cout << "   int 교환 후: a=" << a << ", b=" << b << "\n";
    
    double x = 3.14, y = 2.71;
    std::cout << "   double 교환 전: x=" << x << ", y=" << y << "\n";
    genericSwap(&x, &y, sizeof(double));
    std::cout << "   double 교환 후: x=" << x << ", y=" << y << "\n\n";
    
    // 3. 메모리 풀 사용
    std::cout << "3. 제네릭 메모리 풀:\n";
    
    MemoryPool pool(1024);
    
    int* intPtr = (int*)pool.allocate(sizeof(int));
    float* floatPtr = (float*)pool.allocate(sizeof(float));
    char* stringPtr = (char*)pool.allocate(20);
    
    if(intPtr && floatPtr && stringPtr) {
        *intPtr = 42;
        *floatPtr = 3.14f;
        strcpy(stringPtr, "Hello Pool");
        
        std::cout << "   메모리 풀에서 할당:\n";
        std::cout << "   int: " << *intPtr << "\n";
        std::cout << "   float: " << *floatPtr << "\n";
        std::cout << "   string: " << stringPtr << "\n";
    }
    std::cout << "   사용된 메모리: " << pool.used << " bytes\n\n";
    
    // 4. 콜백에서 void* 사용
    std::cout << "4. 콜백 함수에서 사용자 데이터 전달:\n";
    
    int callbackInt = 777;
    const char* callbackStr = "Callback Data";
    
    processCallback(intCallback, &callbackInt);
    processCallback(stringCallback, (void*)callbackStr);
    std::cout << "\n";
    
    // 5. 간단한 이벤트 시스템
    std::cout << "5. 이벤트 시스템에서 void* 활용:\n";
    
    int eventInt = 123;
    float eventFloat = 99.9f;
    const char* eventString = "이벤트 발생!";
    
    Event intEvent(INT_EVENT, &eventInt, sizeof(int));
    Event floatEvent(FLOAT_EVENT, &eventFloat, sizeof(float));
    Event stringEvent(STRING_EVENT, (void*)eventString, strlen(eventString) + 1);
    
    handleEvent(intEvent);
    handleEvent(floatEvent);
    handleEvent(stringEvent);
    std::cout << "\n";
    
    // 6. void* 포인터 연산 (제한적)
    std::cout << "6. void* 포인터 연산의 제한:\n";
    
    char buffer[10] = "abcdefghi";
    void* voidPtr = buffer;
    
    std::cout << "   void* 직접 연산 불가:\n";
    std::cout << "   // voidPtr + 1  // 컴파일 에러!\n";
    std::cout << "   // *voidPtr     // 컴파일 에러!\n\n";
    
    std::cout << "   char*로 캐스팅 후 연산:\n";
    char* charPtr = (char*)voidPtr;
    std::cout << "   charPtr[0] = " << charPtr[0] << "\n";
    std::cout << "   charPtr[3] = " << charPtr[3] << "\n\n";
    
    // 7. memcpy, memset 등에서 활용
    std::cout << "7. 메모리 함수에서 void* 활용:\n";
    
    int source[3] = {10, 20, 30};
    int dest[3];
    
    memcpy(dest, source, sizeof(source));  // void*를 받음
    
    std::cout << "   memcpy 결과: ";
    for(int i = 0; i < 3; i++) {
        std::cout << dest[i] << " ";
    }
    std::cout << "\n";
    
    memset(dest, 0, sizeof(dest));  // void*를 받음
    
    std::cout << "   memset 후: ";
    for(int i = 0; i < 3; i++) {
        std::cout << dest[i] << " ";
    }
    std::cout << "\n\n";
    
    // 8. 함수 포인터에서 void* 반환
    std::cout << "8. 동적 타입 시스템 구현:\n";
    
    auto createInt = []() -> void* {
        int* ptr = new int(999);
        return ptr;
    };
    
    auto createFloat = []() -> void* {
        float* ptr = new float(7.77f);
        return ptr;
    };
    
    void* data1 = createInt();
    void* data2 = createFloat();
    
    std::cout << "   동적 생성 int: " << *(int*)data1 << "\n";
    std::cout << "   동적 생성 float: " << *(float*)data2 << "\n";
    
    delete (int*)data1;
    delete (float*)data2;
    
    std::cout << "\n=== void* 사용법 정리 ===\n";
    std::cout << "✅ 제네릭 함수 (qsort, memcpy 등)\n";
    std::cout << "✅ 콜백 함수의 사용자 데이터 전달\n";
    std::cout << "✅ 이벤트/메시지 시스템\n";
    std::cout << "✅ 메모리 풀, 할당자\n";
    std::cout << "✅ 플러그인 시스템\n";
    std::cout << "✅ C API에서 언어 바인딩\n\n";
    
    std::cout << "❌ void* 자체로는 할 수 없는 것들:\n";
    std::cout << "• 직접 역참조 (*voidPtr)\n";
    std::cout << "• 포인터 연산 (voidPtr + 1)\n";
    std::cout << "• sizeof(*voidPtr)\n";
    std::cout << "→ 반드시 적절한 타입으로 캐스팅 필요!\n";
    
    return 0;
}