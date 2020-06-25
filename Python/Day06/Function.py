def fun(abc):
    print(abc)
    print(len(abc))

fun('aaaa')

def fun1(a=1,b=2,c=3):
    print(a+b+c)

fun1()


#接收多个参数
def func1(*args):
    total = 0
    for i in args:
        total+=i
    print(total)

func1(1,2,3,4,5,6)

#接收参数为字典

