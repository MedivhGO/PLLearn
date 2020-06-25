doubleMe x = x+x
doubleUs x y = doubleMe x + doubleMe y
doubleSmallNumber x = if x>100
						then x
						else x*2
doubleSmallNumber' x = (if x > 100 then x else x*2)+1
doubleSmallNumber'' x = if x > 100 then x else x*2 + 1
conan0'Brien = "It's a-me,Conan 0'Brien!"
