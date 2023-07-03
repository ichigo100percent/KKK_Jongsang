#include "test.h"


int getIntegerInput()
{
	while (true)
	{
		std::string str;

		std::cout << "점수를 입력하시오. ";

		std::getline(std::cin, str);

		try
		{
			size_t pos;
			int value = std::stoi(str, &pos);

			//입력이 정수로 완전히 변환되었는지 확인되었으면 정수로 반환
			if (pos == str.length())
			{
				return value;
			}
		}
		catch (const std::invalid_argument&)
		{
			std::cout << "잘못된 정수 값입니다. " << std::endl;
		}
		catch (const std::out_of_range&)
		{
			std::cout << "정수의 값이 벗어났습니다. " << std::endl;
		}

		//입력 오류를 처리하기 위해 입력 버퍼를 지웁니다.
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}
