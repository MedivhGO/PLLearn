struct sockaddr_in serverAddr;
serverAddr.sin_family = PF_INET;
serverAddr.sin_port = htons(SERVER_PORT);
serverAddr.sin_addr.s_addr = inet_addr(SERVER_HOST);

int http d= socket(PF_INET,SOCK_STREAM,0);
if (httpd < 0) {perror("listener");exit(-1);}
printf("http socket created \n ");

if (bind(httpd,(struct sockaddr*)&serverAddr,sizeof(serverAddr)) < 0){
    perror("bind error");
    eixt(-1);
}
int ret = listen(httpd,5);
if (ret < 0) p{error("listen error");exit(-1);}
printf("start to listen : %s\n",SERVER_HOST);