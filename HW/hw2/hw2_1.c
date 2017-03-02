#include <stdio.h>
#include <math.h>

#define P0 0.01 /* lower limit of the probability (p) */
#define P1 0.5 /* upper limit of the probability (p) */
#define PLEN 10 /* number of columns */
#define N 5 /* number of experiments (n) */

int factorial(int n){
	if(n==0) return(1);
	//if(n<0) return(EOF);
	if(n>1){
		return(n*factorial(n-1));
	}
	else{
		return(n);
	}
}

int main(){
	int x=0, i=0;
	double prob, density_value;

	printf("%s\t", "x\\p");
	
	for(i=0;i<PLEN;i++){
		prob = P0+i*(P1-P0)/(PLEN-1);
		printf("%5.4f  ", prob);
	}
	printf("%s","\n");

	for(x=0;x<N+1;x++){
		printf("%d  \t",x);
		for(i=0;i<PLEN;i++){
		        prob = P0+i*(P1-P0)/(PLEN-1);
			density_value = factorial(N)/(factorial(x)*factorial(N-x))*pow(prob,x)*pow(1-prob,N-x);
			printf("%5.4f  ", density_value);
		}
		printf("%s","\n");
	}
	return 0;
}

