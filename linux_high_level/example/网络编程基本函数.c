 Linux系统是通过提供套接字(socket)来进行网络编程的.网络程序通过socket和其它几个函数的调用,
   会返回一个 通讯的文件描述符,我们可以将这个描述符看成普通的文件的描述符来操作,这就是linux的设备无关性的好处.
   我们可以通过向描述符读写操作实现网络之间的数据交流.
(一)socket
 
  int socket(int domain, int type,int protocol)

  domain:说明我们网络程序所在的主机采用的通讯协族(AF_UNIX和AF_INET等).
        AF_UNIX只能够用于单一的Unix 系统进程间通信,
        而AF_INET是针对Internet的,因而可以允许在远程
        主机之间通信(当我们 man socket时发现 domain可选项是 PF_*而不是AF_*,因为glibc是posix的实现所以用PF代替了AF,
        不过我们都可以使用的).

  type:我们网络程序所采用的通讯协议(SOCK_STREAM,SOCK_DGRAM等)
        SOCK_STREAM表明我们用的是TCP 协议,这样会提供按顺序的,可靠,双向,面向连接的比特流.
        SOCK_DGRAM 表明我们用的是UDP协议,这样只会提供定长的,不可靠,无连接的通信.

  protocol:由于我们指定了type,所以这个地方我们一般只要用0来代替就可以了 socket为网络通讯做基本的准备.
  成功时返回文件描述符,失败时返回-1,看errno可知道出错的详细情况.


(二)bind
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

(三)listen
  int listen(int sockfd,int backlog)

  sockfd:是bind后的文件描述符.

  backlog:设置请求排队的最大长度.当有多个客户端程序和服务端相连时, 使用这个表示可以介绍的排队长度.
  listen函数将bind的文件描述符变为监听套接字.返回的情况和bind一样.


(四)accept
  int accept(int sockfd, struct sockaddr *addr,int *addrlen)

  sockfd:是listen后的文件描述符.

  addr,addrlen是用来给客户端的程序填写的,服务器端只要传递指针就可以了. bind,listen和accept是服务器端用的函数,
  accept调用时,服务器端的程序会一直阻塞到有一个 客户程序发出了连接. accept成功时返回最后的服务器端的文件描述符,
  这个时候服务器端可以向该描述符写信息了. 失败时返回-1

(五)connect
   int connect(int sockfd, struct sockaddr * serv_addr,int addrlen)

   sockfd:socket返回的文件描述符.

   serv_addr:储存了服务器端的连接信息.其中sin_add是服务端的地址

   addrlen:serv_addr的长度

   connect函数是客户端用来同服务端连接的.成功时返回0,sockfd是同服务端通讯的文件描述符 失败时返回-1.