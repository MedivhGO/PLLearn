#ifndef CHATROOM_COMMON_H
#define CHATROOM_COMMON_H

#include <iostream>
#include <list>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8888

#define EPOLL_SIZE 5000

#define BUF_SIZE 0xFFFF

#define SERVER_WELCOME "welcome you join to the chat room"

#define SERVER_MESSAGE "ClientID %d say >> %s"

#define EXIT "EXIT"

#define CAUTION "There is only one in the chat room"

static void addfd(int epollfd,int fd,bool enable_et){

        struct epoll_event ev;
        

}