#include "subject.h"

void subject::set_subject(int _kor, int _mat, int _eng)
{
	kor = _kor;
	mat = _mat;
	eng = _eng;
}

int subject::get_eng() const
{
	return eng;
}

int subject::get_mat() const
{
	return mat;
}

int subject::get_kor() const
{
	return kor;
}

