describeList:: [a] -> String
describrList xs = "This list is" ++ what xs
	where what [] = "empty."
	      what [x] = "a singleton list."
		  what xs = "a longer list."
