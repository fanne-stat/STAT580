#include <stdio.h>
#include <time.h>
#include <Rmath.h>

int main(void){
	set_seed(time(NULL), 19921129);
	printf("%f\n", pow(10,unif_rand()));
	return(0);
}

