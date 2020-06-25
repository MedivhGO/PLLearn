elem' :: (Eq a) => a -> [a] -> Bool
elem' a [] = False
elem' a (x:xs)
	| a == x = True
	|ohterwise = a `elem'` xs
