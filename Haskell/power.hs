power :: Int -> Int -> Int
power _ 0 = 1
power x n = x * power x (n-1)