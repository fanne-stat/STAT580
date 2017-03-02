#include<stdio.h>

#define N 16 /* number of observations */
#define P 2 /* number of predictors */

void dgesv_(int *n, int *NRHS, double *A, int *LDA, 
		int *IPIV, double *B, int *LDB, int *INFO);

void dgemm_(char *TRANSA, char *TRANSB, int *M, int *n, int *K,
	       	double *ALPHA, double *A,nt *LDA, double *B, 
		int *LDB, double *BETA, double *C, int *LDC);

int main(){
	double Y[N] = {60.323,61.122,60.171,61.187,63.221,
		63.639,64.989,63.761,66.019,67.857,68.169,
		66.513,68.655,69.564,69.331,70.551};
	double X[N][P] ={{83,107.608},{88.5,108.632},
		{88.2,109.773},{89.5,110.929},
		{96.2,112.075}, {98.1,113.27},
		{99,115.094},{100,116.219},
		{101.2,117.388},{104.6,118.734},
		{108.4,120.445},{110.8,121.95},
		{112.6,123.366},{114.2,125.368},
		{115.7,127.852},{116.9,130.081}};
	
	double x[N*(P+1)],xt[(P+1)*N],Design_Mat[(P+1)*(P+1)];
	int i,j,k;
	int n1=N,n2=P+1,n3=1,info, ipiv[P+1];
	double coef[P+1], beta=0, alpha=1;
	char TRANSA = 'N', TRANSB='N';
	
	// Add intercept column to X and X's transpose
	for(i=0;i<N;i++){
		for(j=0;j<=P;j++){
			if(j==0){
				 x[i*(P+1)+j] = 1;
				xt[j*N+i] = 1;
			}
			else{
				x[i*(P+1)+j] = X[i][j-1];
				xt[j*N+i] = X[i][j-1];
			}
		}
	}

	dgemm_(&TRANSA, &TRANSB, &n2, &n2, &n1, &alpha, x, 
			&n2, xt, &n1, &beta,Design_Mat,&n2);

	dgemm_(&TRANSA, &TRANSB, &n2, &n3, &n1, &alpha, x, 
			&n2, Y, &n1, &beta,coef,&n2);

	dgesv_(&n2,&n3, Design_Mat,&n2,ipiv,coef,&n2,&info);
	
	printf("The regression coefficients: ");
	for(i=0;i<=P;i++) 
		printf("%f  ", coef[i]);	
	printf("\n");
	return(0);
}
