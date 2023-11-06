//#include "std.h"
//
//int main()
//{
//	char data[] = "100명";
//	int iData = stoi(data);
//	cout << iData << endl;
//	float fData = stof(data);
//	string szData1 = to_string(iData);
//	string szData2 = to_string(iData);
//
//	string strData = "kgca대한민국";
//	wstring wString = to_mw(strData);
//	string  mString = to_wm(wString);
//
//	char AString[10] = "KGCA";
//	char BString[10] = "kgca";
//	char copyString[10];
//	int Asize = strlen(AString);  //널문자 제외
//
//	//copyString = AString; //error
//    //error C4996 : 'strcpy' : This function or variable may be unsafe.
//	//Consider using strcpy_s instead.
//	//To disable deprecation, use _CRT_SECURE_NO_WARNINGS.
//	strcpy(copyString, BString);
//
//	char* pointCopyString = copyString;
//	int iRet = strcmp(AString, copyString);
//	//int iRet = strcmp(AString, BString);
//	if (iRet == 0)
//	{
//		cout << "같다" << endl;
//	}
//	else
//	{
//		cout << "다르다" << endl;
//	}
//
//	C_STR AString2 = "KGCA";
//	string BString2 = "kgca";
//	string copyString2;
//	copyString2 = AString2;
//
//	string aData = "ggA";
//	aData += "Game";
//	aData += "Academy";
//
//	size_t pos = aData.find('A');
//	string findString = aData.substr(0, pos + 1);
//	std::string::size_type a = aData.find_first_of('g');
//	std::string::size_type b = aData.find_first_not_of("g");
//
//	auto c = aData.find_last_not_of("g");
//	auto d = aData.find_last_of("g");
//
//	if (a != string::npos)
//	{
//		cout << "Found charcter '" << aData[a] << "' at index " << a << endl;
//	}
//	else
//	{
//		cout << "No found." << endl;
//	}
//
//	string f = aData.substr(d, c);
//
//	for (std::string::iterator iter = AString2.begin();
//					  iter != AString2.end();
//					  iter++)
//	{
//		cout << *iter;
//	}
//
//	const char* pAdd2 = AString2.c_str();
//	const char* pAdd3 = AString2.data();
//	int ASize2 = AString2.size();
//	int ASizestring = strlen(pAdd2);
//
//	//주소비교
//	if (copyString2 == AString2)
//	{
//		cout << "같다" << endl;
//	}
//	else
//	{
//		cout << "다르다" << endl;
//	}
//	
//	//유니코드
//	W_STR AString3 = L"KGCA";
//	std::wstring BString3 = L"kgca";
//	std::wstring copyString3;
//	copyString3 = AString3; //error
//	int ASize3 = AString3.size();
//	const wchar_t* pAddress3 = AString3.c_str();
//	int ASizestring3 = _tcslen(pAddress3);
//
//	if (copyString3 == AString3)
//	{
//		std::cout << "같다" << endl;
//	}
//	else
//	{
//		std::cout<<"다르다"<<endl;
//	}
//}