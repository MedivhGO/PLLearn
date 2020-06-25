mygcd :: Int -> Int ->Int
mygcd x y = if y == 0 then x else mygcd y (mod x y)