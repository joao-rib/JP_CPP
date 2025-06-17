#pragma once

#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>
#include <locale>
#include <iomanip>
#include <cstdlib>
#include <cmath>

class ScalarCoverter
{
private:
	int _num;
	const static int _bits = 8;
public:
	ScalarCoverter();
	ScalarCoverter(const int num);
	ScalarCoverter(const float num);
	ScalarCoverter(const ScalarCoverter &orig);
	~ScalarCoverter();

	ScalarCoverter &operator = (const ScalarCoverter &orig);

	bool operator == (const ScalarCoverter &another) const;
	bool operator != (const ScalarCoverter &another) const;
	bool operator < (const ScalarCoverter &another) const;
	bool operator <= (const ScalarCoverter &another) const;
	bool operator > (const ScalarCoverter &another) const;
	bool operator >= (const ScalarCoverter &another) const;

	ScalarCoverter operator + (const ScalarCoverter &amount) const;
	ScalarCoverter operator - (const ScalarCoverter &amount) const;
	ScalarCoverter operator * (const ScalarCoverter &amount) const;
	ScalarCoverter operator / (const ScalarCoverter &amount) const;

	ScalarCoverter &operator ++ (void); //pre
	ScalarCoverter operator ++ (int); //post
	ScalarCoverter &operator -- (void); //pre
	ScalarCoverter operator -- (int); //post

	static ScalarCoverter &min(ScalarCoverter &n1, ScalarCoverter &n2);
	static const ScalarCoverter &min(const ScalarCoverter &n1, const ScalarCoverter &n2);
	static ScalarCoverter &max(ScalarCoverter &n1, ScalarCoverter &n2);
	static const ScalarCoverter &max(const ScalarCoverter &n1, const ScalarCoverter &n2);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator << (std::ostream& out, const ScalarCoverter& fp_num);

#endif
