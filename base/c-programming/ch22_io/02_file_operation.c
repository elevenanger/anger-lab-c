/*
 * @author Anger
 * @date 2022/10/17
 * @brief 文件操作
 */
#include <stdio.h>
#include <stdlib.h>

#define FILE_PATH "/Users/liuanglin/data/tmp/c.dat"
#define FILE_PATH_D "/Users/liuanglin/data/tmp/d.dat"

/* 打开文件 */
void open_file(void);
/* 关闭文件 */
void close_file(void);
/* 未打开的流附加文件 */
void attach_file_for_opened_stream(void);
/* 临时文件 */
void temp_file(void);
/* 文件缓冲 */
void file_buffer(void);
/* 文件的其他操作 */
void other_operation(void);

int main(void) {
    return 0;
}

void open_file(void) {
    /* 将文件用作流打开时需要使用 fopen 函数
     * fopen 函数有两个参数
     * 第一个参数是打开文件名的字符串
     * 第二个参数是"模式字符串"，用来指定打算对文件执行的操作
     * fopen 函数返回一个文件指针
     * 程序将该文件指针存储在一个变量中
     * 稍后需要对文件进行操作的时候使用它
     * 无法打开文件则会返回一个空指针
     * 以下是打开文本文件的模式 */
    fopen(FILE_PATH, "r"); /* r 打开文件用于读 */
    fopen(FILE_PATH, "w"); /* w 打开文件用于写 */
    fopen(FILE_PATH, "wx"); /* wx 创建文件用于写（文件不能已存在）*/
    fopen(FILE_PATH, "w+x"); /* w+x 创建文件用于更新（文件不能已存在）*/
    fopen(FILE_PATH, "a"); /* a 打开文件用于追加（文件可以已存在）*/
    fopen(FILE_PATH, "r+"); /* r+ 打开文件用于读和写，从文件头开始 */
    fopen(FILE_PATH, "w+"); /* w+ 打开文件用于读和写，如果文件存在就截去 */
    fopen(FILE_PATH, "a+"); /* a+ 打开文件用于读和写（如果文件存在就追加）*/

    /* 以下是打开二进制文件的模式 */
    fopen(FILE_PATH, "rb"); /* 打开文件用于读 */
    fopen(FILE_PATH, "wb"); /* 打开文件用于写 */
    fopen(FILE_PATH, "wbx"); /* 打开文件用于写,文件不能是已存在 */
    fopen(FILE_PATH, "ab"); /* 打开文件用于追加 */
    fopen(FILE_PATH, "r+b"); /* 打开文件用于读和写，从文件头开始 */
    fopen(FILE_PATH, "w+b"); /* 打开文件用于更新，如果文件存在就截去 */
    fopen(FILE_PATH, "w+bx"); /* 打开文件用于更新，文件不能已存在 */
    fopen(FILE_PATH, "a+b"); /* 打开文件用于更新（如果文件存在就追加）*/
}

void close_file(void) {
    FILE *fp = fopen(FILE_PATH, "r");
    if (fp == NULL) {
        printf("Can't open file => %s\n", FILE_PATH);
        exit(EXIT_FAILURE);
    }
    /* 使用 fclose() 函数关闭文件
     * 如果文件正常关闭 fclose() 函数返回 0
     * 否则会返回错误代码 EOF */
    int closed = fclose(fp);
    if (closed == EOF) {
        printf("Can't close file => %s\n", FILE_PATH);
        exit(EXIT_FAILURE);
    }
}

void attach_file_for_opened_stream(void) {
    FILE *fp1 = fopen(FILE_PATH, "r");
    if (fp1 == NULL) {
        printf("Can't open file => %s\n", FILE_PATH);
        exit(EXIT_FAILURE);
    }
    /* freopen 为已经打开的流附件一个不同的文件 */
    if (freopen(FILE_PATH_D, "w", fp1) == NULL) {
        printf("Can't open file => %s\n", FILE_PATH_D);
        exit(EXIT_FAILURE);
    }
}

void temp_file(void) {
    FILE *temp_ptr;
    /* tmpfile() 函数创建临时文件
     * 如果文件创建失败，会返回空指针
     * 临时文件会一直存在，除非关闭它或者程序终止
     * tmpfile() 函数创建的临时文件的缺点：
     * 1、无法知道 tmpfile 函数创建的文件名
     * 2、无法在以后使文件变成永久的
     * 备选方案是使用 fopen 函数产生临时文件
     * 但是文件名不能和已存在的文件名相同，因此需要使用一种方法来产生文件名
     * 这是 tmpnam 出现的原因 */
    temp_ptr = tmpfile();
    if (tmpfile() == NULL) {
        printf("临时文件创建失败\n");
        exit(EXIT_FAILURE);
    }
    fclose(temp_ptr);

    FILE *tmp_file_ptr;
    char *tmp_file_name;
    /* tmpnam() 函数创建临时文件名 */
    tmp_file_name = tmpnam(NULL);
    tmp_file_ptr = fopen(tmp_file_name, "r");
    fclose(tmp_file_ptr);
}

void file_buffer(void) {
    /* 向磁盘写入数据或者从磁盘驱动器中传出数据都是比较慢的操作
     * 因此，在每次程序想要读写字符时都直接访问磁盘文件是不可行的
     * 获得较好性能的方式是 缓冲
     * 把写入流的数据存储在内存中的缓冲区域
     * 缓冲区满了(或者关闭流时)，对缓冲区进行清洗(flush)写入实际的输出设备
     * 输入流可以使用类似的方式进行缓冲
     * 缓冲区包含来自输入设备的数据
     * 从缓冲区读取数据而不是从设备本身读取数据
     * 缓冲可以大幅提升效率
     * 把缓冲区的内容传递给磁盘或者从磁盘传递给缓冲区是需要花时间的
     * 但是这是一次大的"块移动"比多次移动小的字节要快得多 */
    FILE *fp = tmpfile();;

    /*  stdio.h 中的函数会在缓冲有用时自动进行缓冲操作
     * 缓冲是在后台发生的，通常不需要关心它的操作
     * 如果需要程序介入
     * 可以通过 fflush setbuf setvbuf 函数
     * 程序向文件中写输出时，数据通常先放入缓冲区
     * 通过调用 fflush() 函数可以控制文件清洗 */
    fflush(fp);
    /* fflush(NULL) 清洗全部的输出流
     * 调用成功 fflush 返回 0
     * 失败返回 EOF */
    fflush(NULL);

    char buffer[1024];
    /* setvbuf() 允许改变缓冲流的方法
     * 并且允许控制缓冲区的大小和位置
     * 函数的第三个参数指定了期望的缓冲类型
     * _IOFBF 满缓冲 缓冲区为空时从流中读取数据，缓冲区满则向流中写入数据
     * _IOLBF 行缓冲 每次从流中读入一行数据或者写入一条数据
     * _IONBF 无缓冲 直接从流中读入数据或者直接向流中写入数据
     * 第二个参数如果不是空指针则是期望的缓冲区的地址
     * 最后一个参数是缓冲区的字节数量
     * setvbuf 函数的调用必须在流打开后，在对流执行其它操作之前 */
    setvbuf(fp, buffer, _IOFBF, 1024);
    fclose(fp);
}

void other_operation(void) {
    /* remove() 函数对文件名进行操作，删除文件 */
    remove("foo");
    /* rename() 重命名文件
     * 确保文件是未打开的情况下使用 rename() 文件
     * 不然函数调用会失败 */
    rename("foo", "bar");
}