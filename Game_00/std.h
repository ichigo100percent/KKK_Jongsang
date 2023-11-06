#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <tchar.h>
#include <iostream>
#include <string>
#include <atlconv.h>
#include <list>
#include <vector>
#include <map>

using namespace std;

static std::wstring to_mw(const std::string& src)
{
	USES_CONVERSION;
	return std::wstring(A2W(src.c_str()));
}

static std::string to_wm(const std::wstring& src)
{
	USES_CONVERSION;
	return std::string(W2A(src.c_str()));
}

//��Ƽ����Ʈ(����:1����Ʈ, �ѱ� 2����Ʈ)
using C_STR = std::basic_string<char>;
//�����ڵ�(������ 2����Ʈ�� ���� ǥ��)
using W_STR = std::basic_string<wchar_t>;

