from time import time,localtime,sleep

class Clock(object):
    def __init__(self,second=0,minute=0,hour=0):
        self._second = second
        self._minute = minute
        self._hour = hour

    @classmethod
    def now(cls):
        ctime = localtime(time())
        return cls(ctime.tm_sec,ctime.tm_min,ctime.tm_hour)

    def run(self):
        self._second+=1
        if self._second == 60:
            self._second = 0
            self._minute+=1
            if self._minute == 60:
                self._minute=0
                self._hour+=1
                if self._hour == 24:
                    self._hour = 0

    def show(self):

        return '%02d:%02d:%02d' %(self._hour,self._minute,self._second)


class Student(object):
    def __init__(self,name,age):
        self.name = name
        self.age = age

    def study(self,course_name):
        print('%s正在学习%s' %(self.name,course_name))

    def watch(self):
        if self.age < 18:
            print('%s 熊出没.' %self.name)
        else:
            print('%s正在观察.' %self.name)

#在python中属性和方法的访问权限只有两种，公开和私有，如果希望是私有的，在给属性命名的时候可以用两个下划线作为开头

class Test:
    def __init__(self,foo):
        self.__foo = foo
    def __bar(self):
        print(self.__foo)
        print('__bar')


def main():
    print('111')
    test = Test('hello')
    test._Test__bar()
    print(test._Test__foo)

if __name__ == '__main__':
    main()



