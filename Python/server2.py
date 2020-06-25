from SocketServer import TCPServer,BaseRequestHandler
import traceback

class MyBaseRequestHandler(BaseRequestHandler):

    def handle(self):
        while True:
            try:
                data = self.request.recv(1024).strip()

                self.client_address

                print "receive from (%r):%r" % (self.client_address,data)
                self.request.sendall(data.upper())
            except:
                traceback.print_exc()
                break

if __name__ == "__main__":

    host = ""
    port = 9999
    addr = (host,port)

    server = TCPServer(addr,MyBaseRequestHandler)

    server.serve_forever()


