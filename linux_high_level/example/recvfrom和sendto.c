recvfrom和sendto
int recvfrom(int sockfd,void *buf,int len,unsigned int flags,struct sockaddr * from int *fromlen)
int sendto(int sockfd,const void *msg,int len,unsigned int flags,struct sockaddr *to int tolen)
sockfd,buf,len的意义和read,write一样,分别表示套接字描述符,发送或接收的缓冲区及大小.
recvfrom负责从 sockfd接收数据,如果from不是NULL,那么在from里面存储了信息来源的情况,如果对信息的来源不感兴趣,
可以将from和fromlen 设置为NULL.sendto负责向to发送信息.此时在to里面存储了收信息方的详细资料.