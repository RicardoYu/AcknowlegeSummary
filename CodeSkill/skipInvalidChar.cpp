/*********************************************
 *File Name  : skipInvalidChar.cpp
 *Description: skip the invalide charater.
 *It was used in analyzing the file, and getting
 *the useful information.
 *
 *
 ********************************************/
//Below will skip the uonnumeric charater
#define SKIP_CHAR(STRING) \
	do{\
		while((STRING != NULL) && \
				(*STRING < '0' || *STRING > '9')){\
			STRING++;\
		}\
	}while(0)

/*********************************************
 *
 ********************************************/
包含文件：string.h
函数名: strstr
函数原型：
1
extern char *strstr(char *str1, const char *str2);
语法：
1
* strstr(str1,str2)
str1: 被查找目标　string expression to search.
str2: 要查找对象　The string expression to find.
返回值：若str2是str1的子串，则返回str2在str1的首次出现的地址；如果str2不是str1的子串，则返回NULL。
例子：
1
2
3
char str[]="1234xyz";
char *str1=strstr(str,"34");
cout << str1 << endl;
显示的是: 34xyz




/*********************************************
 *
 ********************************************/
strtoul()会将参数nptr字符串根据参数base来转换成无符号的长整型数。参数base范围从2至36，或0。参数base代表采用的进制方式，如base值为10则采用10进制，若base值为16则采用16进制数等。当base值为0时会根据情况选择用哪种进制：如果第一个字符是'0'，就判断第二字符如果是‘x’则用16进制，否则用8进制；第一个字符不是‘0’，则用10进制。一开始strtoul()会扫描参数nptr字符串，跳过前面的空格字符串，直到遇上数字或正负符号才开始做转换，再遇到非数字或字符串结束时('')结束转换，并将结果返回。若参数endptr不为NULL，则会将遇到不合条件而终止的nptr中的字符指针由endptr返回。
返回值:
返回转换后的长整型数，否则返回ERANGE并将错误代码存入errno中。
附加说明:
ERANGE指定的转换字符串超出合法范围。
范例:
参考strtol()
例子：将十六进制 0xFF，转换成 10进制，得到 255

#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a;
    char pNum[]="0xFF";
    a=strtoul(pNum,0,0);//最后的0，表示自动识别pNum是几进制
    printf("%ul\n",a);
    return 0;
}
————输出 255
