/* Uma simples implementação do método de Newton-Raphson para conseguir zero de funções
Para esta aplicação é necessário:
Alterar no código a função desejada (funcao(double x));
INserir a derivada da função desejada (derivada(double x));

Alterar os valores de interesse, como o chute inicial e o valor de epsilon (critério de parada)
No presente código, é calculada a raíz da função f(x) = ln(x)-1
*/

#include<stdio.h>
#include<math.h> // Para usar as funções log(x) e sqrt(x)
#define MAX 100 // Número máximo de iterações


double funcao(double x){
	// funcao: f(x) = ln(x)-1
	return(log(x)-1.0); //log presente em math.h

}

double derivada(double x){
	//derivada: f'(x) = 1/x
	return(1.0/x);
}

double NewtonRaphson(double x,double epsilon){
	int i;
	for (i = 0; i<MAX; i++){
	
		x = x - (funcao(x)/derivada(x));
		printf("iteração n %d. X= %lf. Valor da funcao: f(%lf)=%lf\n",i,x,x,funcao(x)); 
		if (sqrt(funcao(x)*funcao(x)) < epsilon) return (x);  // Sqrt(x²) = Valor Absoluto
	
	}

	return (x);
}


int main(){

	
	double e = 0.00000001; //critério de parada
	double x=3.0; // chute inicial
	printf("Raiz: %lf\n",NewtonRaphson(x,e));


return 0;
}
