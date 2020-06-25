#list1 = [1,2,3,4]

#list2 = [i for i in list1 if i > 2]
#print(list2)

#list3 = [i for i in list1 if i%2]
#print(list3)

#dict1 = {x: x**2 for x in (2,4,6)}
#print(dict1)

#dict2 = {x : f'item{x **2}' for x in (2,4,6) }
#print(dict2)

#set1 = {x for x in 'hello world' if x not in 'abcdefg'}

#print(len(set1))
from collections import Counter

p = "abc"
print(Counter(p))


