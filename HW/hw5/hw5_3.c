#include <R.h>
#include <Rinternals.h>
#include <Rmath.h>

SEXP Gibbs_Sampler(SEXP Rm, SEXP RX, SEXP RY, SEXP Ra,
	       	SEXP Rb, SEXP Rinit_lambda, 
		SEXP Rinit_p, SEXP Rinit_r){
	int m = asInteger(Rm), *init_r = INTEGER(Rinit_r), n, k, t;
	double a = asReal(Ra), b = asReal(Rb);
	double init_lambda = asReal(Rinit_lambda);
        doubleinit_p = asReal(Rinit_p);
	int *X = INTEGER(RX), *Y = INTEGER(RY);
	int sum_X = 0, sum_r_k=0;

	n = length(RX);

	SEXP lambda = PROTECT(allocVector(REALSXP, m));
	SEXP p = PROTECT(allocVector(REALSXP, m));
	SEXP r = PROTECT(allocMatrix(INTSXP, m, n));
	SEXP Rout = PROTECT(allocVector(REALSXP, 2*m));

	REAL(lambda)[0] = init_lambda;
	REAL(p)[0] = init_p;
	for(k=0;k<n;k++){
		INTEGER(r)[k] = init_r[k];
		sum_X += X[k];
	}

	GetRNGstate();
	for(k=1;k<m;k++){
		sum_r_k = 0;
		for(t=0;t<n;t++){
			sum_r_k +=INTEGER(r)[(k-1)*n+t];
		}

		REAL(lambda)[k] = rgamma(a+sum_X, 1.0/(b+sum_r_k));
		REAL(p)[k] = rbeta(1+sum_r_k,n+1-sum_r_k);
		for(t=0;t<n;t++){
			if(X[t]==0)
			     INTEGER(r)[k*n+t] = rbinom(1,
					REAL(p)[k]*exp(-REAL(lambda)[k])/
					(REAL(p)[k]*exp(-REAL(lambda)[k])+
					1 - REAL(p)[k]));
     			 else INTEGER(r)[k*n+t] = 1;
   		}
		
	}
	PutRNGstate();

	for(k=1;k<2*m;k++){
		if(k<m) REAL(Rout)[k] = REAL(lambda)[k];
		else REAL(Rout)[k] = REAL(p)[k-m];
	}

	UNPROTECT(4);
	return(Rout);
}
