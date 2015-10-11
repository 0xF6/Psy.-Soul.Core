#pragma once
#ifndef H__MPUINT
#define H__MPUINT

extern void numeric_overflow(void);

class MPUnit
{
private:
	unsigned short remainder(unsigned short);
	void shift(unsigned);
public:
	unsigned short *value;
	bool IsZero(void) const;
	int Compare(const MPUnit &) const;
	int Compare(unsigned short) const;
	unsigned length;
	MPUnit(unsigned);
	MPUnit(const MPUnit &);
	~MPUnit();
	void operator = (const MPUnit &);
	void operator = (unsigned short);
	void operator += (const MPUnit &);
	void operator += (unsigned short);
	void operator -= (const MPUnit &);
	void operator -= (unsigned short);
	void operator *= (const MPUnit &);
	void operator *= (unsigned short);
	void operator /= (const MPUnit &);
	void operator /= (unsigned short);
	void operator %= (const MPUnit &);
	void operator %= (unsigned short);
	static void Divide(const MPUnit &, const MPUnit &, MPUnit &, MPUnit &);
	char *edit(char *) const;
	bool scan(const char *&);
	void dump() const;
	bool MPUnit::operator == (const MPUnit &n) const { return Compare(n) == 0; }
	bool MPUnit::operator != (const MPUnit &n) const { return Compare(n) != 0; }
	bool MPUnit::operator >  (const MPUnit &n) const { return Compare(n) >  0; }
	bool MPUnit::operator >= (const MPUnit &n) const { return Compare(n) >= 0; }
	bool MPUnit::operator <  (const MPUnit &n) const { return Compare(n) <  0; }
	bool MPUnit::operator <= (const MPUnit &n) const { return Compare(n) <= 0; }
	bool MPUnit::operator == (unsigned short n) const { return Compare(n) == 0; }
	bool MPUnit::operator != (unsigned short n) const { return Compare(n) != 0; }
	bool MPUnit::operator >  (unsigned short n) const { return Compare(n) >  0; }
	bool MPUnit::operator >= (unsigned short n) const { return Compare(n) >= 0; }
	bool MPUnit::operator <  (unsigned short n) const { return Compare(n) <  0; }
	bool MPUnit::operator <= (unsigned short n) const { return Compare(n) <= 0; }
	static void Power(const MPUnit &, const MPUnit &, const MPUnit &,
		MPUnit &);
};

#endif