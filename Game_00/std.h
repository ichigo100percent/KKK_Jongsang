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

//멀티바이트(영문:1바이트, 한글 2바이트)
using C_STR = std::basic_string<char>;
//유니코드(무지건 2바이트로 문자 표현)
using W_STR = std::basic_string<wchar_t>;

