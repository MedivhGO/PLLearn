calBmis :: (RealFloat a) => [(a,a)] -> [a]
calBmis xs = [bmi w h|(w,h)<-xs]
	where bmi weight height = weight / height ^ 2
