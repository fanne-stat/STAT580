#include<stdio.h>

void dgesv_(int *n, int *NRHS, double *A, int *LDA, int *IPIV, double *B, int *LDB, int *INFO);

void dgemm_(char *TRANSA, char *TRANSB, int *M, int *n, int *K, double *ALPHA, double *A,
	int *LDA, double *B, int *LDB, double *BETA, double *C, int *LDC);

int main(int argc, char *argv[]){
        FILE *fp;
        int N=0, P1=1,P,i,j,k;
        char tmp;
	fp = fopen(argv[1],"r");
	while((tmp=fgetc(fp))!=EOF){
                if(tmp=='\n')   N++;
        }
        rewind(fp);
        while((tmp=fgetc(fp))!='\n'){
              if(tmp==' ') P1++;
        }
	rewind(fp);
	printf("Sample size and number of predictors are %d and %d respectively.\n",N,P1-1);

	double Y[N];
	if(atoi(argv[2])==1) P = P1;
	else P = P1 - 1;
	double X[N][P];
        for(i=0;i<N;i++){
                for(j=0;j<P1;j++){
                        if(j==0){
                                fscanf(fp, "%lf", &Y[i]);
				if(atoi(argv[2])==1) X[i][0] = 1;
			}
                        else{
                                if(atoi(argv[2])==1)
					fscanf(fp, "%lf", &X[i][j]);
				else fscanf(fp, "%lf", &X[i][j-1]);
			}
                }
        }

	double x[N*P], xt[P*N],Design_Mat[P*P];
	int n1=N,n2=P,n3=1,info, ipiv[P];
	double coef[P], beta=0, alpha=1;
	char TRANSA = 'N', TRANSB='N';

	for(i=0;i<N;i++){
		for(j=0;j<P;j++){
			x[i*P+j] = X[i][j];
			xt[j*N+i] = X[i][j];
		}
	}

	dgemm_(&TRANSA, &TRANSB, &n2, &n2, &n1, &alpha, x, &n2, xt, &n1, &beta,Design_Mat,&n2);
	dgemm_(&TRANSA, &TRANSB, &n2, &n3, &n1, &alpha, x, &n2, Y, &n1, &beta,coef,&n2);
	dgesv_(&n2,&n3, Design_Mat,&n2,ipiv,coef,&n2,&info);

	printf("The regression coefficients: ");
	for(i=0;i<P;i++)
		printf("%f  ", coef[i]);
	printf("\n");
	return(0);
}
