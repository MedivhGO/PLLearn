from socket import *

myhost=""
myport=9999
socketobj=socket(AF_INET,SOCK_STREAM)
socketobj.bind((myhost,myport))
socketobj.listen(120)
while True:
    connection,address = socketobj.accept()
    print "connect by",address
    while True:
        data = connection.recv(1024)
        if not data:
            break

        connection.send("echo: "+data)
    connection.close()

