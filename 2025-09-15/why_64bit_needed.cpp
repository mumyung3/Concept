#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "=== 왜 64비트가 필요했을까? ===" << endl;
    
    cout << "\n[ 핵심 이유 1: 메모리 한계 ]" << endl;
    cout << "32비트 최대 메모리: 4GB" << endl;
    cout << "2005년 일반적 RAM: 2-4GB" << endl;
    cout << "2010년 일반적 RAM: 8-16GB ⚠️ 32비트로 불가능!" << endl;
    cout << "현재 일반적 RAM: 16-64GB" << endl;
    
    cout << "\n[ 핵심 이유 2: 파일 크기 한계 ]" << endl;
    cout << "32비트 파일 포인터 최대: 4GB" << endl;
    cout << "HD 영화 파일: 4-8GB ⚠️" << endl;
    cout << "4K 영화 파일: 20-50GB ⚠️" << endl;
    cout << "데이터베이스 파일: 수십~수백GB ⚠️" << endl;
    
    cout << "\n[ 핵심 이유 3: 서버 확장성 ]" << endl;
    cout << "웹 서버 동시 접속자 수 증가" << endl;
    cout << "가상머신 기술 발전 → 더 많은 메모리 필요" << endl;
    cout << "클라우드 컴퓨팅 → 리소스 통합 필요" << endl;
    
    cout << "\n[ 실제 전환 시기 ]" << endl;
    cout << "AMD64 (x86-64) 출시: 2003년" << endl;
    cout << "Windows XP 64-bit: 2005년" << endl;
    cout << "macOS 64비트 전환: 2009년" << endl;
    cout << "일반 사용자 전환: 2010년대 초반" << endl;
    
    cout << "\n[ 64비트의 실제 장점들 ]" << endl;
    cout << "✅ 16EB 메모리 지원 (실질적으로 무제한)" << endl;
    cout << "✅ 큰 파일 처리 가능" << endl;
    cout << "✅ 더 많은 프로세스 동시 실행" << endl;
    cout << "✅ 암호화/보안 기능 강화" << endl;
    cout << "✅ 더 많은 레지스터 (x86-64에서 8→16개)" << endl;
    
    cout << "\n[ 전환 과정의 어려움들 ]" << endl;
    cout << "❌ 기존 32비트 프로그램 호환성" << endl;
    cout << "❌ 드라이버 재작성 필요" << endl;
    cout << "❌ 메모리 사용량 증가 (포인터 2배)" << endl;
    cout << "❌ 초기 성능 저하 (캐시 효율성)" << endl;
    
    return 0;
}