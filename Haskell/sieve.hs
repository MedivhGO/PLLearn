{-shaixuanfa-}
sieve :: (Integral a) => [a] -> [a]
sieve (p:xs) = p:sieve[x|x<-xs,x `mod` p /= 0]
primes = sieve [2..]
