#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "ZeroFuncao.h"

int main ()
{
	Polinomio p;
	double rpx, rdpx, lpx, ldpx;

	p.p = malloc(2);

	p.p[0] = 3;
	p.p[1] = 0;
	p.p[2] = 2;
	p.grau = 2;	

	calcPolinomio_rapido(p, 2, &rpx, &rdpx);
	calcPolinomio_lento(p, 2, &lpx, &ldpx);

	printf("Rapido: Polinomio = %lf  ;  Derivada = %lf\n", rpx, rdpx);
	printf("Lento: Polinomio = %lf  ;  Derivada = %lf\n", lpx, ldpx);

  return 0;
}

