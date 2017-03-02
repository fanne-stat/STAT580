#include<stdio.h>

#define N 16 /* number of observations */
#define P 2 /* number of predictors */

void dgesvd_(char *JOBU, char *JOBVT, int *M, int *n, 
		double *A, int *LDA, double *S, double *U, 
		int *LDU, double *VT, int *LDVT, double *WORK, 
		int *LWORK, int *INFO);

int main(){
	double X[N][P] ={{83,107.608},{88.5,108.632},
		{88.2,109.773},{89.5,110.929},
		{96.2,112.075}, {98.1,113.27},
		{99,115.094},{100,116.219},
		{101.2,117.388},{104.6,118.734},
		{108.4,120.445},{110.8,121.95},
		{112.6,123.366},{114.2,125.368},
		{115.7,127.852},{116.9,130.081}};
	
	int i,j,k;
	int n1=N,n2=P,info,LWORK=5*N*P;
	char JOBU='A', JOBVT='A';
	double Zt[N*P],X_colMean[P],S[P],U[N*N],VT[N*N],WORK[5*N*P];

	for(i=0;i<P;i++){
		X_colMean[i] = 0;
		for(j=0;j<N;j++)
			X_colMean[i] += X[j][i];
		X_colMean[i] = X_colMean[i]/N;
	}
	
	for(i=0;i<N;i++){
		for(j=0;j<P;j++){
			X[i][j] = X[i][j] - X_colMean[j];
			Zt[j*N+i] = X[i][j];
		}
	}
	
	dgesvd_(&JOBU,&JOBVT,&n1,&n2,Zt,&n1,S,U,&n1,
			VT,&n2,WORK,&LWORK,&info);	
	
	printf("The principal component scores:\n");
	for(i=0;i<N;i++){
		for(j=0;j<P;j++){
			printf("%f ",U[j*N+i]*S[j]);		
		}
		printf("\n");
	}
	
	return(0);
}
