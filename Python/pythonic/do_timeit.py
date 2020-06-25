from timeit import Timer

print Timer("temp = x;x = y; y = temp","x = 2;y=3").timeit()

print "**************************************************"

print Timer("x,y = y,x","x = 2;y=3").timeit()

