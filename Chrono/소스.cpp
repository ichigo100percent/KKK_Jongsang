#include <iostream>
#include <chrono>

using namespace std;



int main()
{

#pragma region 시간 기록 측정
    {
        // 시작 시간 기록
        auto start = std::chrono::high_resolution_clock::now();

        // 예시 작업: 1초 동안 대기
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // 종료 시간 기록
        auto end = std::chrono::high_resolution_clock::now();

        // 시간 간격 계산
        std::chrono::duration<double> duration = end - start;

        // 초 단위로 표시 (부동 소수점)
        std::cout << "Elapsed time (seconds): " << duration.count() << std::endl;

        // 밀리초 단위로 변환
        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration);

        // 밀리초 단위로 표시 (정수)
        std::cout << "Elapsed time (milliseconds): " << milliseconds.count() << " ms" << std::endl;
    }
#pragma endregion

#pragma region 특정 시간 포인트 다루기
    {
        // 현재 시스템 시간 가져오기
        auto now = std::chrono::system_clock::now();

        // 현재 시간 출력 (시간 포인트를 시간_t로 변환하여 출력)
        std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
        std::cout << "Current time: " << std::ctime(&now_time_t);

        // 24시간 후의 시간 계산
        auto tomorrow = now + std::chrono::hours(24);
        std::time_t tomorrow_time_t = std::chrono::system_clock::to_time_t(tomorrow);
        std::cout << "Same time tomorrow: " << std::ctime(&tomorrow_time_t);
    }
#pragma endregion

#pragma region 시간 간격 다루기
    {
        // 1분을 초로 변환
        std::chrono::minutes one_minute(1);
        std::chrono::seconds one_minute_in_seconds = std::chrono::duration_cast<std::chrono::seconds>(one_minute);

        std::cout << "1 minute is " << one_minute_in_seconds.count() << " seconds" << std::endl;

        // 1000밀리초를 초로 변환
        std::chrono::milliseconds one_thousand_milliseconds(1000);
        std::chrono::seconds one_thousand_milliseconds_in_seconds = std::chrono::duration_cast<std::chrono::seconds>(one_thousand_milliseconds);

        std::cout << "1000 milliseconds is " << one_thousand_milliseconds_in_seconds.count() << " seconds" << std::endl;
    }
#pragma endregion

    return 0;
}