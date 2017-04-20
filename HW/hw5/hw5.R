##### Question 1 (a)
p <- 0.3
lambda <- 2
n <- 100
set.seed(580)
Y <- rpois(n, lambda)
R <- rbinom(n, 1, p)
X <- R*Y
X
##### Question 2 (b)
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
                                              (p[k]*exp(-lambda[k])+(1-p[k])*ifelse(X[t]==0,1,0)))})
  }
  return(list(lambda, p, r))
}

gibsamp_1_1 <- Gibbs_Sampler(1000,X,Y,1,1,2,0.3,R)
quantile(gibsamp_1_1[[1]], c(0.025,0.975))
quantile(gibsamp_1_1[[2]], c(0.025,0.975))


##### Question 2 
theta_1 <- 1.5
theta_2 <- 2
Expec_Z <- sqrt(theta_2/theta_1)
Expec_Inv_Z <- sqrt(theta_1/theta_2) + 1/(2*theta_2)
f <- function(z){
  z^{-1.5}*exp(-theta_1*z-theta_2/z+2*sqrt(theta_1*theta_2)+log(sqrt(2*theta_2)))
}

IMH <- function(m, gamma_shape, gamma_rate, init){
  X <- rep(NA, m)
  X[1] <- init
  for(i in 2:m){
    U <- runif(1,0,1)
    Y <- rgamma(1,gamma_shape, gamma_rate)
    r <- min(f(Y)/f(X[i-1])*dgamma(X[i-1],gamma_shape, gamma_rate)/dgamma(Y,gamma_shape, gamma_rate),1)
    if(U<=r) X[i] <- Y
    else X[i] <- X[i-1]
  }
  return(X)
}

IMH_sample <- IMH(10000,1,1,0.7)
abs(mean(IMH_sample) - Expec_Z)/Expec_Z
abs(mean(1/IMH_sample) - Expec_Inv_Z)/Expec_Inv_Z
