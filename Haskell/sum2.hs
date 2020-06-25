sum2:: (Num a) => [a] -> a
sum2 xs = foldl(\acc x -> acc + x) 0 xs