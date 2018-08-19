#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "ZeroFuncao.h"

int main ()
{
	Polinomio p1, p2, p3, p4;

	p1.p = malloc(5);
	p2.p = malloc(6);
	p3.p = malloc(5);
	p4.p = malloc(4);

	p1.p[0] = -15;
	p1.p[1] = -10;
	p1.p[2] = 3;
	p1.p[3] = 4;
	p1.p[4] = 2;
	p.grau = 4;

	p2.p[0] = -24;
	p2.p[1] = -4;
	p2.p[2] = 22;
	p2.p[3] = -9;
	p2.p[4] = -2;
	p2.p[4] = 1;
	p.grau = 5;

	p3.p[0] = -30;
	p3.p[1] = 25;
	p3.p[2] = 4;
	p3.p[3] = 2;
	p3.p[4] = 3;
	p.grau = 4;

	p4.p[0] = 3;
	p4.p[1] = -1;
	p4.p[2] = -5;
	p4.p[3] = 2;
	p.grau = 3;	

  return 0;
}

