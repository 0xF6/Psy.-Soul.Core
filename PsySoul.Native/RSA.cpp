#include <stdlib.h>
#include "rsa.h"
#include "euclid.h"
#include "random.h"

/*----------------------------------------------------------------------------
This function uses Fermat's Theorem 100 times to test the primeness of a
(large) positive integer.
----------------------------------------------------------------------------*/

static bool IsPrime(const MPUnit &p)
{
	MPUnit pminus1(p);
	pminus1 -= 1;
	unsigned count = 101;
	while (--count != 0)
	{
		MPUnit r(p.length);
		MPUnit x(p.length);
		{
			for (unsigned i = 0; i < x.length; i++)
				x.value[i] = rand() << 8 | rand();
		}
		x %= p;
		if (x != 0)
		{
			MPUnit::Power(x, pminus1, p, r);
			if (r != 1)
				return false;
		}
	}
	return true;
}

/*----------------------------------------------------------------------------
This function generates a (large) prime.
----------------------------------------------------------------------------*/

static void GeneratePrime(MPUnit &p)
{
	Random(p);
	p.value[p.length - 1] |= 0x8000;
	p.value[0] |= 1;
	while (!IsPrime(p))
		p += 2;
}


void GenerateKeys(MPUnit &d, MPUnit &e, MPUnit &n)
{
	MPUnit p(d.length / 2);
	GeneratePrime(p);
	MPUnit q(d.length / 2);
	GeneratePrime(q);
	MPUnit pp(p);
	pp -= 1;
	MPUnit qq(q);
	qq -= 1;
	MPUnit pq(d.length);
	pq = pp;
	pq *= qq;
	n = p;
	n *= q;
	Random(d);
	d %= pq;
	MPUnit temp(d.length);
	MPUnit g(d.length);
	while (true)
	{
		EuclideanAlgorithm(d, pq, e, temp, g);
		if (g == 1)
			break;
		d += 1;
	}
}

