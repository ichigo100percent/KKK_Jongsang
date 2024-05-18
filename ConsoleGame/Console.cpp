#include "Console.h"

namespace Js
{
	void Clear(void)
	{
		system("cls");
	}

	void GotoXY(int _x, int _y)
	{
		COORD pos = { _x, _y };

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

	COORD GetXY(void)
	{
		COORD pos;
		CONSOLE_SCREEN_BUFFER_INFO curInfor;

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfor);
		pos.X = curInfor.dwCursorPosition.X;
		pos.Y = curInfor.dwCursorPosition.Y;
		return pos;
	}

	void SetTitle(std::wstring _szConsoleName)
	{
		SetConsoleTitle(_szConsoleName.c_str());
	}

	void SetColor(unsigned char _BgColor, unsigned char _TextColor)
	{
		/*
			0: Black(°ËÁ¤)
			1 : Blue(ÆÄ¶û)
			2 : Green(ÃÊ·Ï)
			3 : Aqua(Cyan) (Ã»·Ï)
			4 : Red(»¡°­)
			5 : Purple(ÀÚÁÖ»ö)
			6 : Yellow(³ë¶û)
			7 : White(Èò»ö)
			8 : Gray(È¸»ö)
			9 : Light Blue(¹àÀº ÆÄ¶û)
			10 : Light Green(¹àÀº ÃÊ·Ï)
			11 : Light Aqua(¹àÀº Ã»·Ï)
			12 : Light Red(¹àÀº »¡°­)
			13 : Light Purple(¹àÀº ÀÚÁÖ»ö)
			14 : Light Yellow(¹àÀº ³ë¶û)
			15 : Bright White(¹àÀº Èò»ö)
		*/
		if (_BgColor > 15 || _TextColor > 15) return;

		unsigned short ColorNum = (_BgColor << 4) | _TextColor;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNum);
	}

	void SetCursor(BOOL _bShow)
	{
		CONSOLE_CURSOR_INFO curInfo;
		GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
		curInfo.bVisible = _bShow;
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	}

	void SetConsoleSize(int _col, int _lines)
	{
		char setText[100];
		sprintf_s(setText, "mode con cols=%d lines=%d", _col, _lines);
		system(setText);
	}
}