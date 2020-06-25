#import time
#import os

#def fun():
#    content='hello world......'
#    while True:
#        print(content)
#        time.sleep(0.2)
#        content = content[1:]+content[0]

#fun()


def suffix(filename,has_dot = False):
    pos = filename.rfind('.')
    if 0 < pos < len(filename)-1:
        index = pos if has_dot else pos+1
        return filename[index:]
    else:
        return ''

print(suffix('aaa.aaa.cpp',True))


str = 'abcdefghijklmn'

print(str[::2])
print(str[::-1])
print(str[-3:-1])
# remove删除已经存在某个元素
list1 = [1,5,6,8,10,11]
list1.remove(5)
print(list1)
list1.clear()
print(list1)

list2 = ['orange', 'apple', 'zoo', 'internationalization', 'blueberry']
list3 = sorted(list2) #sorted函数不会修改list2中的内容，会返回一个已经排序后的list
list4 = sorted(list2,reverse=True)


print([x**2 for x in range(1,10)])

