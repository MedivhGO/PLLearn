power1 :: Int -> Int -> Int
power1 _ 0 =1
power1 x n | odd n = let p = power x ((n-1) `div` 2) in x * p * p
           | otherwise = let p = power x (n `div` 2) in p * p