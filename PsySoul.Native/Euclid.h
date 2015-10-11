#pragma once
#ifndef H__EUCLID
#define H__EUCLID

#include "MPUnit.h"

typedef MPUnit UITYPE;

void EuclideanAlgorithm(const UITYPE &x, const UITYPE &y, UITYPE &a, UITYPE &b, UITYPE &g);
void GreatestCommonDivisor(const UITYPE &x, const UITYPE &y, UITYPE &g);
#endif