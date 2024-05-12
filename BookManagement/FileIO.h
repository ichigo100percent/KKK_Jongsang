#pragma once
#include "std.h"

namespace Js
{
	class FileIO
	{
	public:
		FILE* CreateFile(const char* _fileName, const char* _mode);
		void CloseFile();
	private:
		FILE* m_File;
	};
}
