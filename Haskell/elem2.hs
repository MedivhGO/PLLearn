{-左折叠实现elem函数-}
elem2 :: (Eq a) => a->[a] -> Bool
elem2 y ys = foldl(\acc x -> if x==y then True else acc) False ys