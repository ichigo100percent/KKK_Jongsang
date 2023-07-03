#include "test.h"


int getIntegerInput()
{
	while (true)
	{
		std::string str;

		std::cout << "������ �Է��Ͻÿ�. ";

		std::getline(std::cin, str);

		try
		{
			size_t pos;
			int value = std::stoi(str, &pos);

			//�Է��� ������ ������ ��ȯ�Ǿ����� Ȯ�εǾ����� ������ ��ȯ
			if (pos == str.length())
			{
				return value;
			}
		}
		catch (const std::invalid_argument&)
		{
			std::cout << "�߸��� ���� ���Դϴ�. " << std::endl;
		}
		catch (const std::out_of_range&)
		{
			std::cout << "������ ���� ������ϴ�. " << std::endl;
		}

		//�Է� ������ ó���ϱ� ���� �Է� ���۸� ����ϴ�.
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}
