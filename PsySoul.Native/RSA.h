#pragma once
#ifndef H__RSA
#define H__RSA

#include "MPUnit.h"

void GenerateKeys(MPUnit &d, MPUnit &e, MPUnit &n);

inline void EncryptDecrypt(MPUnit &result, const MPUnit &source,
	const MPUnit &e, const MPUnit &n)
{
	MPUnit::Power(source, e, n, result);
}

#endif