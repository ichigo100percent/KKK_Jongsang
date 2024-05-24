#include "FileIO.h"

namespace Js
{
	FILE* FileIO::CreateFile(const char* _fileName, const char* _mode)
	{
		m_File = fopen(_fileName, _mode);

		if (!m_File)
			nullptr;

		return m_File;
	}
	
	void FileIO::CloseFile()
	{
		fclose(m_File);
	}
}