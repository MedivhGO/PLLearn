contains6' :: [Int]
contains6' = map (\str->read str:: Int) $ filter (elem '6') (map show [1..100])