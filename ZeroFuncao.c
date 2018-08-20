#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "ZeroFuncao.h"

double bisseccao_rapido (Polinomio p, double a, double b, double eps, int *it, double *raiz){
	double xm, pxm, dpxm, xmn, pxmn, dpxmn, pa, dpa, erro;
	int cont = 1;

	xmn = (a + b) / 2;

	do {
		xm = xmn;
		calcPolinomio_rapido(p, a, &pa, &dpa);
		calcPolinomio_rapido(p, xmn, &pxmn, &dpxmn);

		if((pa * pxmn) > ZERO){
			a = xm;
		} else {
			b = xm;
		}

		xmn = (a + b) / 2;

		erro = fabs((xmn - xm) / xmn);
		cont++;
	} while((erro > eps) && (cont < MAXIT));

	*raiz = xmn;
	*it = cont;

	return erro;
}


double newtonRaphson_rapido (Polinomio p, double x0, double eps, int *it, double *raiz){
	double x, px0, dpx0, erro;
	int cont = 1;

	calcPolinomio_rapido(p, x0, &px0, &dpx0);

	if(dpx0 != ZERO){
		
		x = x0 - px0 / dpx0;

		erro = fabs((x - x0) / x);

		while((erro > eps) && cont < MAXIT){
			x0 = x;
			calcPolinomio_rapido(p, x0, &px0, &dpx0);
			x = x0 - px0 / dpx0;

			cont++;
			erro = fabs((x - x0) / x);
		}

		*raiz = x;
		*it = cont;

		return erro;
	}

	return -1;
}

double secante_rapido (Polinomio p, double x0, double x1, double eps, int *it, double *raiz){
	double x, px0, dpx0, px1, dpx1, erro;
	int cont = 1;

	calcPolinomio_rapido(p, x0, &px0, &dpx0);
	calcPolinomio_rapido(p, x1, &px1, &dpx1);
		
	x = x1 - ((px1 * (x1 - x0)) / (px1 - px0));

	erro = fabs((x - x0) / x);

	while((erro > eps) && cont < MAXIT){
		x0 = x1;
		x1 = x;
		calcPolinomio_rapido(p, x0, &px0, &dpx0);
		calcPolinomio_rapido(p, x1, &px1, &dpx1);
		
		x = x1 - ((px1 * (x1 - x0)) / (px1 - px0));

		erro = fabs((x - x0) / x);
		cont++;
	}

	*raiz = x;
	*it = cont;

	return erro;
}

double bisseccao_lento (Polinomio p, double a, double b, double eps, int *it, double *raiz){
	double xm, pxm, dpxm, xmn, pxmn, dpxmn, pa, dpa, erro;
	int cont = 1;

	xmn = (a + b) / 2;

	do {
		xm = xmn;
		calcPolinomio_lento(p, a, &pa, &dpa);
		calcPolinomio_lento(p, xmn, &pxmn, &dpxmn);

		if((pa * pxmn) > ZERO){
			a = xm;
		} else {
			b = xm;
		}

		xmn = (a + b) / 2;

		erro = fabs((xmn - xm) / xmn);
		cont++;
	} while((erro > eps) && (cont < MAXIT));

	*raiz = xmn;
	*it = cont;

	return erro;
}


double newtonRaphson_lento (Polinomio p, double x0, double eps, int *it, double *raiz){
	double x, px0, dpx0, erro;
	int cont = 1;

	calcPolinomio_lento(p, x0, &px0, &dpx0);

	if(dpx0 != ZERO){
		
		x = x0 - px0 / dpx0;

		erro = fabs((x - x0) / x);

		while((erro > eps) && cont < MAXIT){
			x0 = x;
			calcPolinomio_lento(p, x0, &px0, &dpx0);
			x = x0 - px0 / dpx0;

			cont++;
			erro = fabs((x - x0) / x);
		}

		*raiz = x;
		*it = cont;

		return erro;
	}

	return -1;
}

double secante_lento (Polinomio p, double x0, double x1, double eps, int *it, double *raiz){
	double x, px0, dpx0, px1, dpx1, erro;
	int cont = 1;

	calcPolinomio_lento(p, x0, &px0, &dpx0);
	calcPolinomio_lento(p, x1, &px1, &dpx1);
		
	x = x1 - ((px1 * (x1 - x0)) / (px1 - px0));

	erro = fabs((x - x0) / x);

	while((erro > eps) && cont < MAXIT){
		x0 = x1;
		x1 = x;
		calcPolinomio_lento(p, x0, &px0, &dpx0);
		calcPolinomio_lento(p, x1, &px1, &dpx1);
		
		x = x1 - ((px1 * (x1 - x0)) / (px1 - px0));

		erro = fabs((x - x0) / x);
		cont++;
	}

	*raiz = x;
	*it = cont;

	return erro;
}


void calcPolinomio_rapido(Polinomio p, double x, double *px, double *dpx){
	double pol, der;
	int k;

	pol = p.p[p.grau];
	der = pol;

	for(k = p.grau - 1; k; --k){
		pol = p.p[k] + pol * x;
		der = pol + der * x;
	}

	pol = p.p[0] + pol * x;

	*px = pol;
	*dpx = der;
}


void calcPolinomio_lento(Polinomio p, double x, double *px, double *dpx){
	double pol, der;
	int k;

	pol = 0;
	der = pol;

	for(k = p.grau; k; --k){
		pol = p.p[k] * pow(x, k) + pol;
		der = (p.p[k] * k) * pow(x, k - 1) + der;
	}

	pol = p.p[0] * pow(x, 0) + pol;

	*px = pol;
	*dpx = der;
 }