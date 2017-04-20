Gibbs_Sampler <- function(m, X, Y, a, b,init_lambda, init_p, init_r){
  n <- length(X)
  lambda <- rep(NA,m)
  p <- rep(NA,m)
  r <- matrix(NA, n, m)
  lambda[1] <- init_lambda
  p[1] <- init_p
  r[,1] <- init_r
  for(k in 2:m){
    lambda[k] <- rgamma(1,a+sum(X), b+sum(r[,k-1]))
    p[k] <- rbeta(1,1+sum(r[,k-1]),n+1-sum(r[,k-1]))
    r[,k] <- sapply(1:n, function(t){rbinom(1,1,p[k]*exp(-lambda[k])/
                                              (p[k]*exp(-lambda[k])+(1-p[k])
                                               *ifelse(X[t]==0,1,0)))})
  }
  return(list(lambda, p, r))
}

gibsamp_1_1 <- Gibbs_Sampler(10000,X,Y,10,10,2,0.3,R)
quantile(gibsamp_1_1[[1]], c(0.025,0.975))
quantile(gibsamp_1_1[[2]], c(0.025,0.975))
