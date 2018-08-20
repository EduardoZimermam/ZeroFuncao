#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "ZeroFuncao.h"

int main (){
	Polinomio p;
	double x0, x1, a, b, raiz, tempo_inic, tempo_final, erro;
	int it;

	printf("Digite o grau do polinômio:\n");
	scanf("%d", &p.grau);

	p.p = (double*) malloc (sizeof(double*) * (p.grau + 1));

	printf("\nDigite os coeficientes do polinômio, iniciando pelo de maior grau, separando por espaços:\n");
	for(int i = p.grau; i > -1; --i){
		scanf("%lf", &p.p[i]);
	}

	printf("\nDigite os parametros x0 e x1, respectivamente, para o método da Secante, separando por espaço:\n");
	scanf("%lf %lf", &x0, &x1);

	printf("\nDigite os parametros a e b, respectivamente, para o método da Bissecção, separando por espaço:\n");
	scanf("%lf %lf", &a, &b);

	printf("\n\n");

	printf("|        Metodo         |             Raiz            |              Erro             |   Iterações   |            Tempo             |\n");

	tempo_inic = timestamp();
	erro = bisseccao_rapido(p, a, b, EPS, &it, &raiz);
	tempo_final = timestamp();

	printf("|    Bissecção_rapido   |   %.21lf   |    %.21lf    |      %3d      |    %.21lf   |\n", raiz, erro, it, tempo_final - tempo_inic);

	tempo_inic = timestamp();
	erro = newtonRaphson_rapido(p, x0, EPS, &it, &raiz);
	tempo_final = timestamp();

	printf("| Newton Raphson_rapido |   %.21lf   |    %.21lf    |      %3d      |    %.21lf   |\n", raiz, erro, it, tempo_final - tempo_inic);

	tempo_inic = timestamp();
	erro = secante_rapido(p, x0, x1, EPS, &it, &raiz);
	tempo_final = timestamp();

	printf("|     Secante_rapido    |   %.21lf   |    %.21lf    |      %3d      |    %.21lf   |\n", raiz, erro, it, tempo_final - tempo_inic);

	tempo_inic = timestamp();
	erro = bisseccao_lento(p, a, b, EPS, &it, &raiz);
	tempo_final = timestamp();

	printf("|    Bissecção_lento    |   %.21lf   |    %.21lf    |      %3d      |    %.21lf   |\n", raiz, erro, it, tempo_final - tempo_inic);

	tempo_inic = timestamp();
	erro = newtonRaphson_lento(p, x0, EPS, &it, &raiz);
	tempo_final = timestamp();

	printf("| Newton Raphson_lento  |   %.21lf   |    %.21lf    |      %3d      |    %.21lf   |\n", raiz, erro, it, tempo_final - tempo_inic);

	tempo_inic = timestamp();
	erro = secante_lento(p, x0, x1, EPS, &it, &raiz);
	tempo_final = timestamp();

	printf("|     Secante_lento     |   %.21lf   |    %.21lf    |      %3d      |    %.21lf   |\n", raiz, erro, it, tempo_final - tempo_inic);

 	return 0;
}

