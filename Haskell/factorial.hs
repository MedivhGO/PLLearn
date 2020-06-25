factorial :: Integer -> Integer
factorial n  | n < 0 = error "i is less than 0"
             | n == 0 = 1
             | otherwise = n*factorial(n-1)