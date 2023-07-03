#pragma once

class subject
{
public:
	int kor;
	int mat;
	int eng;

public:
	void set_subject(int _kor, int _mat, int _eng);
	int get_eng() const;
	int get_mat() const;
	int get_kor() const;
};