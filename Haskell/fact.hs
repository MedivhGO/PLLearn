factorial :: (Integral a) => a -> a
factorial 0 = 0
factorial 1 = 1
factorial x = factorial (x-1) * x
