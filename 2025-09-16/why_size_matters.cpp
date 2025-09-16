#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

// 실제 문제 상황들을 시뮬레이션

struct GameSaveData32 {
    int player_id;      // 4바이트
    char* player_name;  // 32비트: 4바이트, 64비트: 8바이트
    int level;          // 4바이트
    int score;          // 4바이트
};

void problem1_file_corruption() {
    std::cout << "=== 실제 문제 1: 게임 세이브 파일 호환성 ===" << std::endl;
    
    GameSaveData32 save_data;
    save_data.player_id = 12345;
    save_data.player_name = nullptr;  // 실제로는 문자열 포인터
    save_data.level = 50;
    save_data.score = 999999;
    
    std::cout << "32비트에서 저장된 구조체 크기: 16바이트 (예상)" << std::endl;
    std::cout << "64비트에서 읽는 구조체 크기: " << sizeof(GameSaveData32) << "바이트" << std::endl;
    
    std::cout << "\n문제 상황:" << std::endl;
    std::cout << "- 32비트 게임으로 만든 세이브 파일" << std::endl;
    std::cout << "- 64비트로 업그레이드 후 세이브 파일 로드" << std::endl;
    std::cout << "- 구조체 크기 불일치로 데이터 깨짐!" << std::endl;
    std::cout << "- 플레이어들의 수백시간 진행상황 사라짐" << std::endl;
}

void problem2_network_protocol() {
    std::cout << "\n=== 실제 문제 2: 네트워크 프로토콜 깨짐 ===" << std::endl;
    
    struct NetworkPacket {
        int packet_type;    // 4바이트
        void* data_ptr;     // 32비트: 4바이트, 64비트: 8바이트
        int data_size;      // 4바이트
    };
    
    std::cout << "네트워크 패킷 크기: " << sizeof(NetworkPacket) << "바이트" << std::endl;
    
    std::cout << "\n문제 상황:" << std::endl;
    std::cout << "- 32비트 서버 ↔ 64비트 클라이언트 통신" << std::endl;
    std::cout << "- 패킷 크기 불일치로 데이터 파싱 실패" << std::endl;
    std::cout << "- 서버 전체 다운 또는 클라이언트 연결 끊김" << std::endl;
    std::cout << "- 실시간 서비스에서는 치명적!" << std::endl;
}

void problem3_memory_corruption() {
    std::cout << "\n=== 실제 문제 3: 메모리 구조 오해 ===" << std::endl;
    
    // 32비트에서 작성된 코드를 시뮬레이션
    struct DataBlock {
        int header;         // 4바이트
        char* content;      // 32비트: 4바이트, 64비트: 8바이트
        int footer;         // 4바이트
    };
    
    std::vector<DataBlock> blocks(1000);
    
    std::cout << "DataBlock 하나 크기: " << sizeof(DataBlock) << "바이트" << std::endl;
    std::cout << "1000개 배열 크기: " << sizeof(DataBlock) * 1000 << "바이트" << std::endl;
    
    std::cout << "\n문제 상황:" << std::endl;
    std::cout << "- 32비트 기준으로 메모리 할당 계산" << std::endl;
    std::cout << "- 64비트에서 실제 필요한 메모리가 더 큼" << std::endl;
    std::cout << "- 메모리 부족으로 프로그램 크래시" << std::endl;
    std::cout << "- 특히 임베디드 시스템에서 심각" << std::endl;
}

void problem4_hash_table_disaster() {
    std::cout << "\n=== 실제 문제 4: 해시 테이블 무너짐 ===" << std::endl;
    
    // 포인터 값을 해시로 사용하는 경우
    int value1 = 100, value2 = 200;
    int* ptr1 = &value1;
    int* ptr2 = &value2;
    
    // 32비트에서는 포인터를 int로 캐스팅해서 해시로 사용
    uintptr_t addr1 = (uintptr_t)ptr1;
    uintptr_t addr2 = (uintptr_t)ptr2;
    
    std::cout << "포인터 주소들:" << std::endl;
    std::cout << "ptr1: 0x" << std::hex << addr1 << std::dec << std::endl;
    std::cout << "ptr2: 0x" << std::hex << addr2 << std::dec << std::endl;
    
    std::cout << "\n문제 상황:" << std::endl;
    std::cout << "- 32비트: 포인터를 int로 캐스팅해서 해시키 생성" << std::endl;
    std::cout << "- 64비트: 포인터 상위 4바이트 손실" << std::endl;
    std::cout << "- 다른 포인터들이 같은 해시값 가짐" << std::endl;
    std::cout << "- 해시 테이블 성능 극악화, 무한 충돌" << std::endl;
}

void problem5_database_chaos() {
    std::cout << "\n=== 실제 문제 5: 데이터베이스 인덱스 파괴 ===" << std::endl;
    
    struct DBRecord {
        int record_id;      // 4바이트
        char* table_name;   // 32비트: 4바이트, 64비트: 8바이트  
        long timestamp;     // 32비트: 4바이트, 64비트: 8바이트
        int data_size;      // 4바이트
    };
    
    std::cout << "DB 레코드 크기: " << sizeof(DBRecord) << "바이트" << std::endl;
    
    std::cout << "\n문제 상황:" << std::endl;
    std::cout << "- 32비트 DB 엔진으로 생성된 인덱스 파일" << std::endl;  
    std::cout << "- 64비트로 업그레이드 후 인덱스 읽기 실패" << std::endl;
    std::cout << "- 수천만 건 데이터의 인덱스 전체 재구축 필요" << std::endl;
    std::cout << "- 서비스 수십시간 중단, 막대한 손실" << std::endl;
}

void real_world_examples() {
    std::cout << "\n=== 실제 발생한 사건들 ===" << std::endl;
    
    std::cout << "\n1. MySQL 32→64비트 마이그레이션:" << std::endl;
    std::cout << "   - 테이블 구조 변경으로 덤프/복원 필수" << std::endl;
    std::cout << "   - 대용량 DB는 수일간 서비스 중단" << std::endl;
    
    std::cout << "\n2. Adobe Photoshop CS 시리즈:" << std::endl;
    std::cout << "   - 플러그인 API 변경으로 기존 플러그인 사용 불가" << std::endl;
    std::cout << "   - 서드파티 개발사들 재개발 강요" << std::endl;
    
    std::cout << "\n3. Windows Vista/7 64비트 초기:" << std::endl;
    std::cout << "   - 32비트 드라이버 호환성 문제" << std::endl;
    std::cout << "   - 많은 하드웨어 사용 불가" << std::endl;
    
    std::cout << "\n4. 게임 업계:" << std::endl;
    std::cout << "   - 세이브 파일, 리플레이 파일 호환성 깨짐" << std::endl;
    std::cout << "   - 온라인 게임 프로토콜 재설계" << std::endl;
}

int main() {
    std::cout << "=== 크기 변화가 왜 그렇게 심각한 문제인가? ===" << std::endl;
    
    problem1_file_corruption();
    problem2_network_protocol();
    problem3_memory_corruption();  
    problem4_hash_table_disaster();
    problem5_database_chaos();
    real_world_examples();
    
    std::cout << "\n=== 결론 ===" << std::endl;
    std::cout << "단순히 '크기가 바뀌는 것'이 아니라:" << std::endl;
    std::cout << "- 데이터 호환성 파괴" << std::endl;
    std::cout << "- 시스템 간 통신 장애" << std::endl;
    std::cout << "- 성능 치명적 저하" << std::endl;
    std::cout << "- 서비스 장시간 중단" << std::endl;
    std::cout << "- 막대한 경제적 손실" << std::endl;
    std::cout << "\n그래서 32→64비트 포팅은 매우 신중하게 접근해야 합니다!" << std::endl;
    
    return 0;
}