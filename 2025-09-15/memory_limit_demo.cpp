#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    cout << "=== 32비트 시대의 4GB 메모리 한계 시뮬레이션 ===" << endl;
    
    // 현재 시스템에서 최대 메모리 주소
    size_t max_32bit_addr = static_cast<size_t>(0xFFFFFFFF);  // 32비트 최대값
    double gb_32bit = static_cast<double>(max_32bit_addr) / (1024.0 * 1024.0 * 1024.0);
    
    cout << "32비트 최대 주소: 0x" << hex << max_32bit_addr << endl;
    cout << "32비트 최대 메모리: " << fixed << setprecision(2) << gb_32bit << " GB" << endl;
    
    // 실제 문제 상황들 시뮬레이션
    cout << "\n=== 실제 발생했던 문제 상황들 ===" << endl;
    
    // 1. 대용량 이미지/비디오 처리
    cout << "\n[ 문제 1: 대용량 파일 처리 ]" << endl;
    size_t hd_video_size = 2ULL * 1024 * 1024 * 1024;  // 2GB HD 비디오
    size_t available_32bit = 3ULL * 1024 * 1024 * 1024; // 실제 사용 가능한 메모리 (~3GB)
    
    cout << "HD 비디오 파일 크기: " << hd_video_size / (1024*1024*1024) << " GB" << endl;
    cout << "32비트 실제 사용 가능 메모리: ~" << available_32bit / (1024*1024*1024) << " GB" << endl;
    cout << "동시 처리 가능한 HD 비디오: " << available_32bit / hd_video_size << "개" << endl;
    cout << "→ 비디오 편집 프로그램에서 심각한 제약!" << endl;
    
    // 2. 데이터베이스 캐시 문제
    cout << "\n[ 문제 2: 데이터베이스 메모리 캐시 ]" << endl;
    size_t db_record_size = 1024;  // 1KB per record
    size_t max_cache_32bit = available_32bit / db_record_size;
    size_t max_cache_64bit = 16ULL * 1024 * 1024 * 1024 / db_record_size;  // 16GB 가정
    
    cout << "레코드당 크기: " << db_record_size << " bytes" << endl;
    cout << "32비트 최대 캐시 레코드 수: " << dec << max_cache_32bit << "개" << endl;
    cout << "64비트 최대 캐시 레코드 수: " << max_cache_64bit << "개" << endl;
    cout << "성능 향상 배수: " << max_cache_64bit / max_cache_32bit << "배" << endl;
    
    // 3. 가상머신/컨테이너 한계
    cout << "\n[ 문제 3: 가상화 환경 ]" << endl;
    size_t vm_memory_each = 512ULL * 1024 * 1024;  // VM당 512MB
    size_t max_vms_32bit = available_32bit / vm_memory_each;
    size_t max_vms_64bit = (64ULL * 1024 * 1024 * 1024) / vm_memory_each;  // 64GB 가정
    
    cout << "VM당 메모리 할당: " << vm_memory_each / (1024*1024) << " MB" << endl;
    cout << "32비트 호스트 최대 VM 수: " << max_vms_32bit << "개" << endl;
    cout << "64비트 호스트 최대 VM 수: " << max_vms_64bit << "개" << endl;
    
    // 4. 과학 계산/빅데이터 처리
    cout << "\n[ 문제 4: 과학 계산 데이터 ]" << endl;
    size_t matrix_element_size = sizeof(double);  // 8바이트
    size_t max_elements_32bit = available_32bit / matrix_element_size;
    
    // 정사각 행렬 크기 계산 (N x N)
    size_t matrix_size_32bit = static_cast<size_t>(sqrt(max_elements_32bit));
    
    cout << "double 타입 원소 크기: " << matrix_element_size << " bytes" << endl;
    cout << "32비트에서 최대 행렬 크기: " << matrix_size_32bit << " x " << matrix_size_32bit << endl;
    cout << "총 원소 수: " << matrix_size_32bit * matrix_size_32bit << "개" << endl;
    cout << "→ 대규모 수치해석에서 심각한 제약!" << endl;
    
    // 5. 실제 시간대별 메모리 사용량 증가 트렌드
    cout << "\n=== 시간대별 메모리 사용량 증가 ===" << endl;
    struct YearData {
        int year;
        string typical_use;
        size_t typical_memory_gb;
    };
    
    vector<YearData> memory_trend = {
        {1990, "개인용 PC", 0},           // <1GB
        {1995, "멀티미디어 PC", 0},       // ~1GB  
        {2000, "인터넷 시대", 1},
        {2005, "게임/그래픽", 2},
        {2010, "HD비디오/가상화", 8},
        {2015, "4K영상/빅데이터", 16},
        {2020, "AI/머신러닝", 32},
        {2025, "현재", 64}
    };
    
    for (const auto& data : memory_trend) {
        cout << data.year << "년: " << setw(20) << left << data.typical_use;
        if (data.typical_memory_gb == 0) {
            cout << "<1GB";
        } else {
            cout << data.typical_memory_gb << "GB";
        }
        if (data.typical_memory_gb > 4) {
            cout << " ⚠️ 32비트 한계 초과!";
        }
        cout << endl;
    }
    
    return 0;
}