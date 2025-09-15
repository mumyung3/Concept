#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    cout << "=== 메모리 주소 지정 범위 분석 ===" << endl;
    
    // 32비트 주소 공간
    unsigned long addr_32bit = static_cast<unsigned long>(pow(2, 32));
    cout << "32비트 주소 개수: 2^32 = " << addr_32bit << endl;
    cout << "32비트 메모리 크기: " << addr_32bit / (1024*1024*1024) << " GB" << endl;
    
    // 64비트 주소 공간
    cout << "64비트 주소 개수: 2^64 = " << "18,446,744,073,709,551,616" << endl;
    
    // 실용적 계산
    double gb_64bit = pow(2, 64) / (1024.0 * 1024.0 * 1024.0);
    double tb_64bit = gb_64bit / 1024.0;
    double pb_64bit = tb_64bit / 1024.0;
    
    cout << "64비트 메모리 크기: " << fixed << setprecision(0) << gb_64bit << " GB" << endl;
    cout << "64비트 메모리 크기: " << fixed << setprecision(0) << tb_64bit << " TB" << endl;
    cout << "64비트 메모리 크기: " << fixed << setprecision(0) << pb_64bit << " PB" << endl;
    
    cout << "\n=== 실제 사용 가능한 주소 ===" << endl;
    
    // 실제 64비트 시스템에서는 모든 비트를 사용하지 않음
    cout << "실제 64비트 시스템 (48비트 주소):" << endl;
    unsigned long addr_48bit = static_cast<unsigned long>(pow(2, 48));
    double gb_48bit = addr_48bit / (1024.0 * 1024.0 * 1024.0);
    double tb_48bit = gb_48bit / 1024.0;
    
    cout << "48비트 주소 개수: 2^48 = " << addr_48bit << endl;
    cout << "48비트 메모리 크기: " << fixed << setprecision(0) << gb_48bit << " GB" << endl;
    cout << "48비트 메모리 크기: " << fixed << setprecision(0) << tb_48bit << " TB" << endl;
    
    cout << "\n=== 비교 결과 ===" << endl;
    cout << "32비트 대비 64비트 배수: " << fixed << setprecision(0) << (gb_64bit / 4) << "배" << endl;
    cout << "32비트 대비 48비트 배수: " << fixed << setprecision(0) << (gb_48bit / 4) << "배" << endl;
    
    // 포인터 주소 출력 예시
    cout << "\n=== 실제 주소 예시 ===" << endl;
    int variable = 42;
    int* ptr = &variable;
    
    cout << "변수 주소 (16진수): " << hex << ptr << endl;
    cout << "변수 주소 (10진수): " << dec << reinterpret_cast<uintptr_t>(ptr) << endl;
    
    return 0;
}