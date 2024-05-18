#include <iostream>
#include <chrono>

using namespace std;



int main()
{

#pragma region �ð� ��� ����
    {
        // ���� �ð� ���
        auto start = std::chrono::high_resolution_clock::now();

        // ���� �۾�: 1�� ���� ���
        std::this_thread::sleep_for(std::chrono::seconds(1));

        // ���� �ð� ���
        auto end = std::chrono::high_resolution_clock::now();

        // �ð� ���� ���
        std::chrono::duration<double> duration = end - start;

        // �� ������ ǥ�� (�ε� �Ҽ���)
        std::cout << "Elapsed time (seconds): " << duration.count() << std::endl;

        // �и��� ������ ��ȯ
        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration);

        // �и��� ������ ǥ�� (����)
        std::cout << "Elapsed time (milliseconds): " << milliseconds.count() << " ms" << std::endl;
    }
#pragma endregion

#pragma region Ư�� �ð� ����Ʈ �ٷ��
    {
        // ���� �ý��� �ð� ��������
        auto now = std::chrono::system_clock::now();

        // ���� �ð� ��� (�ð� ����Ʈ�� �ð�_t�� ��ȯ�Ͽ� ���)
        std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
        std::cout << "Current time: " << std::ctime(&now_time_t);

        // 24�ð� ���� �ð� ���
        auto tomorrow = now + std::chrono::hours(24);
        std::time_t tomorrow_time_t = std::chrono::system_clock::to_time_t(tomorrow);
        std::cout << "Same time tomorrow: " << std::ctime(&tomorrow_time_t);
    }
#pragma endregion

#pragma region �ð� ���� �ٷ��
    {
        // 1���� �ʷ� ��ȯ
        std::chrono::minutes one_minute(1);
        std::chrono::seconds one_minute_in_seconds = std::chrono::duration_cast<std::chrono::seconds>(one_minute);

        std::cout << "1 minute is " << one_minute_in_seconds.count() << " seconds" << std::endl;

        // 1000�и��ʸ� �ʷ� ��ȯ
        std::chrono::milliseconds one_thousand_milliseconds(1000);
        std::chrono::seconds one_thousand_milliseconds_in_seconds = std::chrono::duration_cast<std::chrono::seconds>(one_thousand_milliseconds);

        std::cout << "1000 milliseconds is " << one_thousand_milliseconds_in_seconds.count() << " seconds" << std::endl;
    }
#pragma endregion

    return 0;
}