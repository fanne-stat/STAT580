## (a)
n = 1500
set.seed(20170311)
rand_unif <- runif(n, 0, 1)
mean(1/(1+rand_unif))

## (b)
b_opt <- sum((1/(1+rand_unif)- mean(1/(1+rand_unif)))*
               ((1+rand_unif)-mean((1+rand_unif))))/
               (var(1+rand_unif)*(n-1))

mean(1/(1+rand_unif)) - b_opt*(mean(1+rand_unif) - 1.5)

## (c)
var(1/(1+rand_unif))/n
var(1/(1+rand_unif)-b_opt*(1+rand_unif))/n

## (d)
(1-log(2)*1.5)/((1/2-log(2)^2)/12)^(1/2)
(2*sqrt(2)-2-log(2)*((4*sqrt(2)-2)/3))/
  ((1/2-log(2)^2)*(1.5-((4*sqrt(2)-2)/3)^2))^(1/2)
