#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "ZeroFuncao.h"

double bisseccao (Polinomio p, double a, double b, double eps, int *it, double *raiz){
	double 
}


double newtonRaphson (Polinomio p, double x0, double eps, int *it, double *raiz){

}


double secante (Polinomio p, double x0, double x1, double eps, int *it, double *raiz){

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

	pol = p.p[p.grau];
	der = pol;

	for(k = p.grau - 1; k; --k){
		pol = pow(p.p[k], k) + pol * x;
		der = pol + der * x;
	}

	pol = p.p[0] + pol * x;

	*px = pol;
	*dpx = der;
}
