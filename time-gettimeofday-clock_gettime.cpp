/*******************************************
 *
 *
 *
 ******************************************/
time(){
}





/*******************************************
 *
 *
 *
 ******************************************/
一.gettimeofday()函数的使用方法：

1.简介：

在C语言中可以使用函数gettimeofday()函数来得到时间。它的精度可以达到微妙

2.函数原型：

#include<sys/time.h>

int gettimeofday(struct  timeval*tv,struct  timezone *tz )

3.说明：

gettimeofday()会把目前的时间用tv 结构体返回，当地时区的信息则放到tz所指的结构中

4.结构体：

1>timeval

struct  timeval{
   long  tv_sec;/*秒*/
   long  tv_usec;/*微妙*/
}；

2>timezone 结构定义为：

struct  timezone{
   int tz_minuteswest;/*和greenwich 时间差了多少分钟*/
   int tz_dsttime;/*type of DST correction*/
}

3>在gettimeofday()函数中tv或者tz都可以为空。如果为空则就不返回其对应的结构体。

4>函数执行成功后返回0，失败后返回-1，错误代码存于errno中。

5.程序实例：

#include<stdio.h>
#include<sys/time.h>
#include<unistd.h>

int main()

{

    struct  timeval    tv;
    struct  timezone   tz;

    gettimeofday(&tv,&tz);
    printf(“tv_sec:%d\n”,tv.tv_sec);
    printf(“tv_usec:%d\n”,tv.tv_usec);
    printf(“tz_minuteswest:%d\n”,tz.tz_minuteswest);
    printf(“tz_dsttime:%d\n”,tz.tz_dsttime);
}

说明：在使用gettimeofday()函数时，第二个参数一般都为空，因为我们一般都只是为了获得当前时间，而不用获得timezone的数值

/*******************************************
 *
 *
 *
 ******************************************/
clock_gettime(){

}
