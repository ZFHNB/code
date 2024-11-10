bind中：
  int bind(int sockfd, struct sockaddr *my_addr, int addrlen)

  sockfd:是由socket调用返回的文件描述符.

  addrlen:是sockaddr结构的长度.

  my_addr:是一个指向sockaddr的指针. 在中有 sockaddr的定义

        struct sockaddr{
                unisgned short  as_family;
                char            sa_data[14];
        };

  不过由于系统的兼容性,我们一般不用这个头文件,而使用另外一个结构(struct sockaddr_in) 来代替.在中有sockaddr_in的定义
        struct sockaddr_in{
                unsigned short          sin_family;    
                unsigned short int      sin_port;
                struct in_addr          sin_addr;
                unsigned char           sin_zero[8];
        }
  我们主要使用Internet所以
        sin_family一般为AF_INET,
        sin_addr设置为INADDR_ANY表示可以和任何的主机通信,
        sin_port是我们要监听的端口号.sin_zero[8]是用来填充的.
  bind将本地的端口同socket返回的文件描述符捆绑在一起.成功是返回0,失败的情况和socket一样