p <- 0.3
lambda <- 2
n <- 100
set.seed(580)
Y <- rpois(n, lambda)
R <- rbinom(n, 1, p)
X <- R*Y

