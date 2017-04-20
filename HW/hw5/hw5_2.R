theta_1 <- 1.5
theta_2 <- 2
Expec_Z <- sqrt(theta_2/theta_1)
Expec_Inv_Z <- sqrt(theta_1/theta_2) + 1/(2*theta_2)
f <- function(z){
  z^{-1.5}*exp(-theta_1*z-theta_2/z+2*sqrt(theta_1*theta_2)+
                 log(sqrt(2*theta_2)))
}

IMH <- function(m, gamma_shape, gamma_rate, init){
  X <- rep(NA, m)
  X[1] <- init
  for(i in 2:m){
    U <- runif(1,0,1)
    Y <- rgamma(1,gamma_shape, gamma_rate)
    r <- min(f(Y)/f(X[i-1])*dgamma(X[i-1],gamma_shape, gamma_rate)/
               dgamma(Y,gamma_shape, gamma_rate),1)
    if(U<=r) X[i] <- Y
    else X[i] <- X[i-1]
  }
  return(X)
}

IMH_sample <- IMH(10000,0.1,0.1,0.7)
abs(mean(IMH_sample) - Expec_Z)
abs(mean(1/IMH_sample) - Expec_Inv_Z)
