#include <iostream>
#include <immintrin.h>  // SIMD 명령어용

int main() {
    std::cout << "=== \"32비트 두 개 동시 계산\" 가능한가? ===" << std::endl;
    
    std::cout << "\n답: 가능합니다! 그리고 실제로 사용되고 있습니다!" << std::endl;
    
    std::cout << "\n=== SIMD (Single Instruction, Multiple Data) ===" << std::endl;
    
    std::cout << "\n1. 64비트 레지스터로 32비트 2개 처리:" << std::endl;
    std::cout << "   64비트 레지스터: [32비트 A][32비트 B]" << std::endl;
    std::cout << "   한 명령어로 A와 B를 동시에 연산!" << std::endl;
    
    std::cout << "\n2. 더 큰 SIMD 레지스터들:" << std::endl;
    std::cout << "   - MMX: 64비트 (32비트 × 2개)" << std::endl;
    std::cout << "   - SSE: 128비트 (32비트 × 4개)" << std::endl;
    std::cout << "   - AVX: 256비트 (32비트 × 8개)" << std::endl;
    std::cout << "   - AVX-512: 512비트 (32비트 × 16개!)" << std::endl;
    
    std::cout << "\n=== 실제 예시 코드 ===" << std::endl;
    
    // 일반적인 32비트 연산 (순차적)
    int a1 = 10, b1 = 20;
    int a2 = 30, b2 = 40;
    
    std::cout << "\n일반적인 방법 (순차):" << std::endl;
    int result1 = a1 + b1;  // 첫 번째 계산
    int result2 = a2 + b2;  // 두 번째 계산
    std::cout << "결과1: " << result1 << ", 결과2: " << result2 << std::endl;
    
    std::cout << "\nSIMD 방법 (병렬):" << std::endl;
    // SSE를 사용한 32비트 4개 동시 처리
    __m128i vec_a = _mm_setr_epi32(10, 30, 50, 70);  // 4개 32비트 값
    __m128i vec_b = _mm_setr_epi32(20, 40, 60, 80);  // 4개 32비트 값
    __m128i vec_result = _mm_add_epi32(vec_a, vec_b); // 4개 동시 덧셈!
    
    // 결과 추출
    int results[4];
    _mm_storeu_si128((__m128i*)results, vec_result);
    
    std::cout << "SIMD 결과: ";
    for(int i = 0; i < 4; i++) {
        std::cout << results[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\n=== CPU가 실제로 지원하는 병렬 처리 ===" << std::endl;
    
    std::cout << "\n1. 정수 연산 병렬 처리:" << std::endl;
    std::cout << "   - 32비트 정수 4개를 128비트 레지스터에" << std::endl;
    std::cout << "   - 한 명령어로 4개 모두 덧셈/뺄셈" << std::endl;
    std::cout << "   - 게임, 그래픽, 과학 계산에 활용" << std::endl;
    
    std::cout << "\n2. 부동소수점 병렬 처리:" << std::endl;
    std::cout << "   - float 4개 (128비트) 또는 8개 (256비트)" << std::endl;
    std::cout << "   - 3D 벡터 연산에 최적" << std::endl;
    std::cout << "   - 머신러닝, AI 계산에 핵심" << std::endl;
    
    std::cout << "\n=== 실제 활용 사례들 ===" << std::endl;
    
    std::cout << "\n1. 이미지 처리:" << std::endl;
    std::cout << "   - 픽셀 4개를 동시에 처리" << std::endl;
    std::cout << "   - RGB 값 변환, 필터 적용" << std::endl;
    std::cout << "   - Photoshop, 동영상 인코딩" << std::endl;
    
    std::cout << "\n2. 게임 엔진:" << std::endl;
    std::cout << "   - 3D 좌표 4개 동시 변환" << std::endl;
    std::cout << "   - 물리 시뮬레이션 가속" << std::endl;
    std::cout << "   - 충돌 검사 병렬화" << std::endl;
    
    std::cout << "\n3. 암호화:" << std::endl;
    std::cout << "   - 블록 암호화 병렬 처리" << std::endl;
    std::cout << "   - 해시 계산 가속" << std::endl;
    
    std::cout << "\n=== 왜 항상 사용하지 않나? ===" << std::endl;
    
    std::cout << "\n1. 프로그래밍 복잡성:" << std::endl;
    std::cout << "   - 특수 명령어 사용 필요" << std::endl;
    std::cout << "   - 컴파일러 자동 최적화 한계" << std::endl;
    std::cout << "   - 개발자가 직접 최적화 필요" << std::endl;
    
    std::cout << "\n2. 적용 조건:" << std::endl;
    std::cout << "   - 같은 연산을 여러 데이터에 적용할 때만 유효" << std::endl;
    std::cout << "   - 데이터 의존성이 없어야 함" << std::endl;
    std::cout << "   - 메모리 정렬 조건 필요" << std::endl;
    
    std::cout << "\n3. 호환성 문제:" << std::endl;
    std::cout << "   - 모든 CPU가 같은 SIMD 지원하지 않음" << std::endl;
    std::cout << "   - 구형 CPU 호환성 고려 필요" << std::endl;
    
    std::cout << "\n=== 결론 ===" << std::endl;
    std::cout << "\"32비트 두 개 동시 계산\"은:" << std::endl;
    std::cout << "✓ 기술적으로 완전히 가능" << std::endl;
    std::cout << "✓ 실제로 많이 사용됨 (SIMD)" << std::endl;
    std::cout << "✓ 최대 16개까지도 가능 (AVX-512)" << std::endl;
    std::cout << "✓ 성능 향상 효과 큼" << std::endl;
    std::cout << "\n하지만 일반적인 프로그램에서는:" << std::endl;
    std::cout << "- 복잡성 때문에 선택적으로 사용" << std::endl;
    std::cout << "- 특수한 경우 (게임, 이미지처리, AI)에 집중 활용" << std::endl;
    
    return 0;
}