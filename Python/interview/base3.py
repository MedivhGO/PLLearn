class Father(object):
    def foo(self):
        print('foo in father')

class Son(object):

    def foo(self):
        print('foo in son.')

obj = Father()
obj.foo()