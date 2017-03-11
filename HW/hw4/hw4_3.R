## 
v = 0.1
N <- 100000
set.seed(20170311)
rand_norm <- rnorm(N, mean = 1.5, sd = v)
mean(v*exp(-rand_norm^2/2)/exp(-(rand_norm-1.5)^2/(2*v^(2)))*
       ifelse(rand_norm<2&rand_norm>1,1,0))
sqrt(var(v*exp(-rand_norm^2/2)/exp(-(rand_norm-1.5)^2/(2*v^(2)))*
       ifelse(rand_norm<2&rand_norm>1,1,0))/N)*1.96

## v = 1
v = 1
set.seed(20170311)
rand_norm <- rnorm(N, mean = 1.5, sd = v)
mean(v*exp(-rand_norm^2/2)/exp(-(rand_norm-1.5)^2/(2*v^(2)))*
       ifelse(rand_norm<2&rand_norm>1,1,0))
sqrt(var(v*exp(-rand_norm^2/2)/exp(-(rand_norm-1.5)^2/(2*v^(2)))*
           ifelse(rand_norm<2&rand_norm>1,1,0))/N)*1.96

## v = 10
v = 10
set.seed(20170311)
rand_norm <- rnorm(N, mean = 1.5, sd = v)
mean(v*exp(-rand_norm^2/2)/exp(-(rand_norm-1.5)^2/(2*v^(2)))*
       ifelse(rand_norm<2&rand_norm>1,1,0))
sqrt(var(v*exp(-rand_norm^2/2)/exp(-(rand_norm-1.5)^2/(2*v^(2)))*
           ifelse(rand_norm<2&rand_norm>1,1,0))/N)*1.96
