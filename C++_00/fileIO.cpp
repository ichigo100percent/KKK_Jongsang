#include "fileIO.h"

FILE* FileIO::CreateFile(const char* filename, const char* fpMode)
{
    m_pFP = fopen(filename, fpMode);
    if (m_pFP != nullptr)
    {
        return m_pFP;
    }
    return m_pFP;
};
void FileIO::CloseFile()
{
    fclose(m_pFP);
}

void FileIO::Release()
{
}