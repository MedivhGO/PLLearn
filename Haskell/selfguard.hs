bmiTell :: (RealFloat a) => a -> String
bmiTell bmi
	| bmi <= 18.5 = "a"
	| bmi <= 25.0 = "b"
	| bmi <= 30.0 = "c"
	| otherwise = "d"
