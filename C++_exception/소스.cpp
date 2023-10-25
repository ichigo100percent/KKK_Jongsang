#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <exception>

using namespace std;

vector<int> readIntegerFile(string_view fileName)
{
	ifstream inputStream(fileName.data());
	
	if (inputStream.fail())
	{
		//파일 열기 실패: 익셉션을 던진다.
		throw runtime_error("Unable to open the file.");
	}

	//파일에 담긴 정숫값을 하나씩 읽어서 벡터에 추가한다.
	vector<int> integers;
	int temp;

	while (inputStream >> temp)
	{
		integers.push_back(temp);
	}

	if (!inputStream.eof())
	{
		//파일 끝에 도달하지 않았다
		//다시 말해 파일을 읽는 도중에 에러가 발생했다.
		//따라서 익셉션을 던진다.
		throw runtime_error("Error reading the file.");
	}



	return integers;
}

void myTerminate()
{
	cout << "Uncaught exception!" << endl;
	exit(1);
}


int main()
{
	set_terminate(myTerminate);

	const string fileName = "IntegerFile.txt";
	vector<int> myInt;

	try
	{
		myInt = readIntegerFile(fileName);
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
		return 1;
	}

	for (const auto& element : myInt)
	{
		cout << element << endl;
	}

	cout << endl;

	return 0;
}