#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main() {
    cout << "=== bool 타입 크기 분석 ===" << endl;
    
    // bool 기본 크기
    bool flag = true;
    cout << "bool 크기: " << sizeof(bool) << " bytes" << endl;
    cout << "bool 값 (true): " << flag << endl;
    cout << "bool 값 (false): " << !flag << endl;
    
    // bool 배열 메모리 사용량
    cout << "\n=== bool 배열 메모리 효율성 ===" << endl;
    bool boolArray[8];
    cout << "bool[8] 크기: " << sizeof(boolArray) << " bytes" << endl;
    cout << "예상했던 크기: 1 bit × 8 = 1 byte" << endl;
    cout << "실제 크기: " << sizeof(boolArray) << " bytes (8배 낭비!)" << endl;
    
    // char와 비교
    char charArray[8];
    cout << "char[8] 크기: " << sizeof(charArray) << " bytes" << endl;
    
    // vector<bool>의 특별한 최적화
    cout << "\n=== vector<bool>의 특수 최적화 ===" << endl;
    vector<bool> boolVector(8);
    cout << "vector<bool> 8개 원소 실제 메모리 사용량 확인..." << endl;
    
    // 개별 bool 변수들
    cout << "\n=== 개별 bool 변수들 ===" << endl;
    bool b1 = true;
    bool b2 = false; 
    bool b3 = true;
    bool b4 = false;
    
    cout << "bool b1 주소: " << &b1 << endl;
    cout << "bool b2 주소: " << &b2 << endl;
    cout << "bool b3 주소: " << &b3 << endl;
    cout << "bool b4 주소: " << &b4 << endl;
    
    // 주소 차이 계산
    intptr_t addr1 = reinterpret_cast<intptr_t>(&b1);
    intptr_t addr2 = reinterpret_cast<intptr_t>(&b2);
    cout << "b1과 b2 주소 차이: " << abs(addr2 - addr1) << " bytes" << endl;
    
    // 비트 조작으로 8개 bool을 1바이트에 저장하는 예시
    cout << "\n=== 수동 비트 패킹 예시 ===" << endl;
    unsigned char packed = 0;  // 8개 bool을 1바이트에 저장
    
    // 8개 bool 값 설정 (비트마스크 사용)
    packed |= (1 << 0);  // 첫 번째 비트를 1로
    packed |= (1 << 2);  // 세 번째 비트를 1로
    packed |= (1 << 7);  // 여덟 번째 비트를 1로
    
    cout << "8개 bool을 1바이트로 패킹: " << bitset<8>(packed) << endl;
    cout << "패킹된 데이터 크기: " << sizeof(packed) << " byte" << endl;
    cout << "일반 bool[8] 크기: " << sizeof(boolArray) << " bytes" << endl;
    cout << "메모리 절약: " << sizeof(boolArray) - sizeof(packed) << " bytes" << endl;
    
    return 0;
}