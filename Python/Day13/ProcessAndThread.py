from random import randint
from time import time,sleep
from multiprocessing import Process
from threading import Thread

def download_task(filename):
    time_to_download = randint(5,10)
    sleep(time_to_download)
    print('%s 下载完成，耗费%d秒' %(filename,time_to_download))

def main1():
    start = time()
    p = Process(target = download_task,args = ('Ping',))
    p2 = Process(target = download_task,args = ('Pong',))
    p.start()
    p2.start()
    p.join()
    p2.join()
    end = time()
    print('总共耗费了%.2f秒' %(end - start))

def main2():
    start = time()
    p = Thread(target = download_task,args = ('Ping',))
    p2 = Thread(target = download_task, args = ('Pong',))

    p.start()
    p2.start()
    p.join()
    p2.join()

    end = time()

    print('总共耗费了%.2f秒' % (end - start))

if __name__ == '__main__':
    main1()