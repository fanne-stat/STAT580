#include <stdio.h>
#include <math.h>
#define N 10 /*The length of array*/

int main(){
	double x[N] = {3.1, -1.2, 5.3, 1, 4.4, 21, 3, 7, -1.2, 3.2};
	double tmp;
	int i,j;

	for(i=0;i<N-1;i++){
		tmp = x[i+1];
		for(j=i;j>=0;j--){
			if(x[j]>tmp){
				x[j+1] = x[j];
				if(j==0)
					x[j] = tmp;
			}
			else{
				x[j+1] = tmp; 
				break;
			}
		}
	}
	
	printf("Sorted data:\n");
	for(i=0;i<N;i++)
		printf("%f ", x[i]);
	printf("\nMedian:\n");

	if(fmod(N,2)<0.5){
		printf("%f", (x[N/2-1]+x[N/2])/2);
	}
	else{
		printf("%f",x[(N-1)/2]);
	}

	printf("\n");

	return(0);
}

