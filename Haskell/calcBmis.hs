clacBmis ::(RealFloat a) => [(a,a)]->[a]
clacbmis xs = [bmi |(w,h)<- xs,let bmi = w/h ^2,bmi >=25.0] 
