#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <stdexcept>
#include <sstream>
#include <cstddef>

using namespace std;

class FileError : public exception
{
public:
	FileError(string_view fileName) : m_fileName(fileName) {}
	virtual const char* what() const noexcept override { return m_message.c_str(); }
	string_view getFileName() const noexcept { return m_message; }

protected:
	void setMessage(string_view message) { m_message = message; }

private:
	string m_fileName;
	string m_message;
};

class FileOpenError : public FileError
{
public:
	FileOpenError(string_view fileName)
		:FileError(fileName)
	{
		setMessage("Unable to open "s + fileName.data());
	}
};

class FileReadError : public FileError
{
public:
	FileReadError(string_view fileName, size_t lineNumber)
		: FileError(fileName), mLineNumber(lineNumber)
	{
		ostringstream ostr;
		ostr << "Error reading " << fileName << " at line " << lineNumber;
		setMessage(ostr.str());
	}

private:
	size_t mLineNumber;
};

vector<int> readIntegerFile(string_view fileName)
{
	ifstream inputStream(fileName.data());

	if (inputStream.fail())
	{
		//파일 열기 실패: 익셉션을 던진다.
		throw FileOpenError(fileName);
	}

	vector<int> integers;
	size_t lineNumber = 0;

	while (!inputStream.eof())
	{
		//파일에서 한 줄씩 읽는다.
		string line;
		getline(inputStream, line);
		++lineNumber;

		//방금 읽은 한 줄에 대한 스트링 스트림을 생성한다.
		istringstream lineStream(line);

		//파일에서 정수를 하나씩 읽어 벡터에 추가한다.
		int temp;
		while (lineStream >> temp)
		{
			integers.push_back(temp);
		}
		
		if (!lineStream.eof())
		{
			//파일 끝(EOF)에 도달하지 않았다.
			//다시 말해 파일을 읽는 도중에 에러가 발생했다.
			//따라서 익셉션을 던진다.
			throw FileReadError(fileName, lineNumber);
		}
	}

	return integers;
}

int main()
{
	const string fileName = "IntegerFile.txt";
	vector<int> myInts;

	try
	{
		myInts = readIntegerFile(fileName);
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
		return 1;
	}

	for (const auto& element : myInts)
	{
		cout << element << " ";
	}
	cout << endl;

	return 0;

}

//int main()
//{
//	std::ostringstream oss;
//
//	// 문자열을 스트림에 출력
//	oss << "Hello, ";
//	oss << 42;
//	oss << " World!";
//
//	// 스트림에서 문자열을 얻음
//	std::string result = oss.str();
//
//	// 결과 출력
//	std::cout << result << std::endl;
//
//	return 0;
//}