total' [] n = n
total' (x:xs) n = total' xs (n+x)
total' xs = total' xs 0