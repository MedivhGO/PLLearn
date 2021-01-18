struct sockaddr_in serverAddr;
serverAddr.sin_family = PF_INET;
serverAddr.sin_port = htons(SERVER_PORT);
serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

int sock = socket(PF_INET,SOCK_STREAM,0);
if (sock<0) {
    
    perror("sock error");
    exit(-1);

}
if (connect(sock,(struct sockaddr*)&serverAddr,sizeof(serverAddr)) < 0){
    perror("connect error");
    exit(-1);
}

void addfd(int epollfd,int fd,bool enable_et)
{
    struct epoll_event ev;
    ev.data.fd = fd;
    ev.events = EPOLLIN;
    if (enable_et){
        ev.events = EPOLLIN | EPOLLET;
    }
    epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&ev);
    setnonblocking(fd);
    printf("fd add to epoll!\n\n");
}