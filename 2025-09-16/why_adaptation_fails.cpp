#include <iostream>
#include <fstream>
#include <vector>

struct GameSave {
    int player_id;      // 4바이트
    char* player_name;  // 32비트: 4바이트, 64비트: 8바이트
    int level;          // 4바이트
    int score;          // 4바이트
};

void problem1_existing_files() {
    std::cout << "=== 문제 1: 기존 파일들은 어떻게 할까? ===" << std::endl;
    
    std::cout << "현재 GameSave 크기: " << sizeof(GameSave) << "바이트" << std::endl;
    
    std::cout << "\n상황:" << std::endl;
    std::cout << "- 이미 출시된 게임에 세이브 파일 수천만개 존재" << std::endl;
    std::cout << "- 플레이어들이 32비트 버전으로 만든 세이브 파일들" << std::endl;
    std::cout << "- 64비트 업데이트 후에도 기존 세이브 파일 읽어야 함" << std::endl;
    
    std::cout << "\n\"그냥 맞춰서 저장하면 된다\"고? 하지만..." << std::endl;
    std::cout << "- 기존 파일: 16바이트 구조체" << std::endl;
    std::cout << "- 새 파일: 24바이트 구조체" << std::endl;
    std::cout << "- 둘 다 읽을 수 있는 코드 작성해야 함 (복잡!)" << std::endl;
    std::cout << "- 버전 체크, 변환 로직, 오류 처리 필요" << std::endl;
}

void problem2_network_compatibility() {
    std::cout << "\n=== 문제 2: 네트워크에서는 불가능 ===" << std::endl;
    
    struct NetworkPacket {
        int msg_type;       // 4바이트
        void* data_ptr;     // 32비트: 4바이트, 64비트: 8바이트
        int data_size;      // 4바이트
    };
    
    std::cout << "NetworkPacket 크기: " << sizeof(NetworkPacket) << "바이트" << std::endl;
    
    std::cout << "\n상황:" << std::endl;
    std::cout << "- 32비트 서버가 운영중" << std::endl;
    std::cout << "- 64비트 클라이언트 접속 시도" << std::endl;
    std::cout << "- 둘이 다른 크기의 패킷 주고받음" << std::endl;
    
    std::cout << "\n\"맞춰서 저장하면 된다\"고? 하지만..." << std::endl;
    std::cout << "- 누가 누구에게 맞춰야 하나?" << std::endl;
    std::cout << "- 실시간으로 패킷 크기 협상? (오버헤드 엄청남)" << std::endl;
    std::cout << "- 기존 32비트 클라이언트들은 어떻게?" << std::endl;
    std::cout << "- 서버 코드 대대적 수정 필요" << std::endl;
}

void problem3_third_party_dependency() {
    std::cout << "\n=== 문제 3: 외부 라이브러리 의존성 ===" << std::endl;
    
    std::cout << "상황:" << std::endl;
    std::cout << "- 내가 만든 게임이지만..." << std::endl;
    std::cout << "- 물리엔진: 외부 라이브러리 (32비트 전용)" << std::endl;
    std::cout << "- 사운드엔진: 다른 회사 제품 (32비트 전용)" << std::endl;
    std::cout << "- 네트워크 라이브러리: 또 다른 업체" << std::endl;
    
    std::cout << "\n\"맞춰서 저장하면 된다\"고? 하지만..." << std::endl;
    std::cout << "- 라이브러리들이 내부적으로 구조체 크기 가정" << std::endl;
    std::cout << "- 소스코드 없어서 수정 불가능" << std::endl;
    std::cout << "- 업체가 망해서 지원 중단된 라이브러리들" << std::endl;
    std::cout << "- 전체 시스템 다시 설계해야 함" << std::endl;
}

void problem4_performance_disaster() {
    std::cout << "\n=== 문제 4: 성능 재앙 ===" << std::endl;
    
    struct DataRecord {
        int id;             // 4바이트
        char* content;      // 32비트: 4바이트, 64비트: 8바이트
        int size;           // 4바이트
    };
    
    std::cout << "DataRecord 하나: " << sizeof(DataRecord) << "바이트" << std::endl;
    
    // 대량 데이터 시뮬레이션
    const int COUNT = 1000000;
    std::vector<DataRecord> records(COUNT);
    
    std::cout << "100만개 레코드 메모리: " << sizeof(DataRecord) * COUNT / 1024 / 1024 << "MB" << std::endl;
    
    std::cout << "\n\"맞춰서 저장하면 된다\"고? 하지만..." << std::endl;
    std::cout << "- 32비트 버전: 16MB 사용" << std::endl;
    std::cout << "- 64비트 버전: 24MB 사용 (50% 증가!)" << std::endl;
    std::cout << "- 캐시 미스 증가, 성능 저하" << std::endl;
    std::cout << "- 메모리 부족한 시스템에서 문제" << std::endl;
}

void problem5_development_cost() {
    std::cout << "\n=== 문제 5: 개발 비용 폭발 ===" << std::endl;
    
    std::cout << "\"그냥 맞춰서 저장\"하려면 해야 할 일들:" << std::endl;
    std::cout << "\n1. 버전 관리 시스템 구축:" << std::endl;
    std::cout << "   - 파일 헤더에 버전 정보 추가" << std::endl;
    std::cout << "   - 32비트/64비트 구분 로직" << std::endl;
    std::cout << "   - 변환 함수들 작성" << std::endl;
    
    std::cout << "\n2. 호환성 계층 개발:" << std::endl;
    std::cout << "   - 구 버전 읽기 함수" << std::endl;
    std::cout << "   - 신 버전 쓰기 함수" << std::endl;
    std::cout << "   - 에러 처리 로직" << std::endl;
    
    std::cout << "\n3. 테스트 케이스 폭증:" << std::endl;
    std::cout << "   - 32비트→64비트 변환 테스트" << std::endl;
    std::cout << "   - 64비트→32비트 변환 테스트" << std::endl;
    std::cout << "   - 버전 혼재 환경 테스트" << std::endl;
    
    std::cout << "\n4. 문서화 및 유지보수:" << std::endl;
    std::cout << "   - 개발자 가이드 업데이트" << std::endl;
    std::cout << "   - 사용자 매뉴얼 수정" << std::endl;
    std::cout << "   - 지원팀 교육" << std::endl;
    
    std::cout << "\n결과: 개발 기간 2-3배 증가, 비용 폭증!" << std::endl;
}

void problem6_maintenance_nightmare() {
    std::cout << "\n=== 문제 6: 유지보수 악몽 ===" << std::endl;
    
    std::cout << "5년 후 상황:" << std::endl;
    std::cout << "- 버그 리포트: \"32비트 세이브 파일이 안 열려요\"" << std::endl;
    std::cout << "- 개발자: \"그 코드 누가 짰더라...\"" << std::endl;
    std::cout << "- 복잡한 변환 로직에서 버그 찾기 지옥" << std::endl;
    std::cout << "- 새 기능 추가할 때마다 호환성 체크" << std::endl;
    
    std::cout << "\n10년 후:" << std::endl;
    std::cout << "- 128비트 시스템 나오면 또 변환 로직 추가?" << std::endl;
    std::cout << "- 32비트/64비트/128비트 모두 지원?" << std::endl;
    std::cout << "- 코드 복잡도 기하급수적 증가" << std::endl;
    std::cout << "- 아무도 건드리고 싶어하지 않는 레거시 코드" << std::endl;
}

int main() {
    std::cout << "=== \"그냥 맞춰서 저장하면 될 일\"이라고? ===" << std::endl;
    std::cout << "이론적으로는 맞지만 현실은..." << std::endl;
    
    problem1_existing_files();
    problem2_network_compatibility();
    problem3_third_party_dependency();
    problem4_performance_disaster();
    problem5_development_cost();
    problem6_maintenance_nightmare();
    
    std::cout << "\n=== 결론 ===" << std::endl;
    std::cout << "\"맞춰서 저장하면 된다\"는 것은:" << std::endl;
    std::cout << "✓ 기술적으로 가능하다" << std::endl;
    std::cout << "✗ 하지만 현실적으로는..." << std::endl;
    std::cout << "  - 개발 비용 폭증" << std::endl;
    std::cout << "  - 성능 저하" << std::endl;
    std::cout << "  - 복잡도 증가" << std::endl;
    std::cout << "  - 유지보수 악몽" << std::endl;
    std::cout << "  - 호환성 지옥" << std::endl;
    
    std::cout << "\n그래서 처음부터 이식성 있게 설계하는 것이 중요!" << std::endl;
    
    return 0;
}