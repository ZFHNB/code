// 可以使用man man open查看帮助信息
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief 读取文件内容中的一行
 * @param  fd 读取文件的描述符，buf 读入数据缓冲区
 * @retval n表示读到了一行数据的数据个数
 *         -1表示读到文件尾部（或出错）
 */
static int read_line(int fd, unsigned char *buf)
{
    /* 循环读入一个字符 */

    /* 如何判断已读完一行？ 读到0xd0, 0x0a */

    unsigned char c[1];
    int len;
    int i = 0;
    int err = 0;

    while (1)
    {
        len = read(fd, c, 1);
        if (len <= 0)
        {
            err = -1;
            break;
        }
        else
        {
            if (c[0] != '\n' && c[0] != '\r') /* 碰到回车,i=n; 碰到换行，由于换行紧接在回车后，故未读取到数据，i=0 */
                buf[i++] = c[0];
            else
            {
                /* 碰到回车/换行 */
                err = 0;
                break;
            }
        }
    }

    buf[i] = '\0';

    if (err && (i == 0))
        /* 读到文件尾部了，并且一个数据都没有读进来 */
        return -1;
    else
    {
        return i;
    }
}

int process_data(unsigned char *data_buf, unsigned char *result_buf)
{
    /*示例1: data_buf = ",语文,数学,英语,总分,评价"
     *       result_buf = ",语文,数学,英语,总分,评价"
     *示例2: data_buf = "张三,90,91,92,,"
     *       result_buf = "张三,90,91,92,273,A+"
     */

    char name[100];
    int scores[3];
    int sum;
    char *levels[] = {"A+", "A", "B"};
    int level;

    // 文件前几位数据为文件的编码格式
    if (data_buf[0] == 0xef) /* 对于UTF-8编码的文件，它的前三个字符为：0xef 0xbb 0xbf*/
    {
        strcpy(result_buf, data_buf);
    }
    else
    {
        // 比较int scanf(const char *format, ...);
        // int sscanf(const char *str, const char *format, ...);
        sscanf(data_buf, "%[^,],%d,%d,%d,", name, &scores[0], &scores[1], &scores[2]);
        // printf("result: %s,%d,%d,%d,\n\r", name, scores[0], scores[1], scores[2]);
        // printf("result: %s --->get name---> %s\n\r", data_buf, name);
        sum = scores[0] + scores[1] + scores[2];
        level = (sum >= 270) ? 0 : ((sum >= 240) ? 1 : 2);

        sprintf(result_buf, "%s,%d,%d,%d,%d,%s", name, scores[0], scores[1], scores[2], sum, levels[level]);
        // printf("result: %s",result_buf);
    }
}

/*
 * ./process_excle data.csv result.csv
 * argc = 3
 * argv[0] = ./process_excle
 * argv[1] = data.csv
 * argv[2] = result.csv
 */

int main(int argc, char **argv)
{
    int fd_data, fd_result;
    int i;
    int len;
    unsigned char data_buf[1000];
    unsigned char result_buf[1000];

    if (argc != 3)
    {
        printf("Usage: %s <data csv file> <result csv file>\n", argv[0]); //<>表示参数不可省略
        exit(1);
    }

    fd_data = open(argv[1], O_RDONLY); // int open(const char *pathname, int flags, mode_t mode)
    if (fd_data < 0)
    {
        printf("Can not open file %s\n", argv[1]);
        perror("open");
    }
    else
    {
        printf("data file fd = %d\n", fd_data);
    }

    fd_result = open(argv[2], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd_result < 0)
    {
        printf("Can not create file %s\n", argv[2]);
        perror("create");
        exit(1);
    }
    else
    {
        printf("result file fd = %d\n", fd_result);
    }

    while (1)
    {
        /* 从数据文件里读取一行 */
        len = read_line(fd_data, data_buf);
        if (len == -1)
        {
            break;
        }
        // //test
        // if(len != 0)
        //     printf("line: %s\n\r", data_buf);
        if (len != 0)
        {
            /* 处理数据 */
            process_data(data_buf, result_buf);

            /* 写入结果文件 */
            // write_data(fd_result, result_buf);
            write(fd_result, result_buf, strlen(result_buf));

            write(fd_result, "\r\n", 2);
        }
    }

    close(fd_data);
    close(fd_result);

    return 0;
}