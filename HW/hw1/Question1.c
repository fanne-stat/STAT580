#include <stdio.h>

int main() {
	int lower, upper,nrow;
	double step,f,c;
	lower = 0;
	upper = 200;

	printf("Please input the number of rows: ");
	scanf("%d",&nrow);

	step = (upper - lower)/(nrow-1);

	f = lower;

	printf("F\tC\n");

	while(f<=upper){
		c = 5*(f-32)/9;
		printf("%.1f\t%.1f\n",f,c);
		f = f + step;
	}

	return(0);
}

