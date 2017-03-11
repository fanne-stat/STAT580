## (a)
N <- 100000
set.seed(20170311)
rand_exp<- rexp(N, rate = 1)
mean((rand_exp^2+5)*rand_exp)
sqrt(var((rand_exp^2+5)*rand_exp)/N)*1.96

## (b)
set.seed(20170311)
rand_norm <- rnorm(N, mean = 0, sd = 1/sqrt(2))
rand_unif <- runif(N, min = 0, max = 1)
mean(cos(rand_norm*rand_unif)*sqrt(pi))

## (c)
set.seed(20170311)
rand_weibull <- rweibull(N, shape = 3, scale = 4^(1/3))
mean(rand_weibull^2)
sqrt(var(rand_weibull^2)/N)*1.96
