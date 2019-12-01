//爬取用例 1
#include<string>
#include<fstream>

	std::ifstream myfile("C:\\Users\\apple\\Documents\\q42.txt");
	string temp; 
    if (!myfile.is_open()) 
    { 
        cout << "未成功打开文件" << endl; 
    } 

//爬取用例 2
	string input;
	ofstream mycout("C:\\Users\\apple\\Documents\\q42.txt", ios::app);
	while (getline(cin, input)) {
		mycout << input << endl;

	}
	cin >> input;
	mycout << "done" << endl;
	mycout.close();

//新建二维数组
	int **bomb = new int *[numOfBombs];
	for(int i=0; i<numOfBombs; i++){
		bomb[i] = new int[2];
	}

//出现烫，初始化
	int a[10], b[10] = { 0 };

/*
strcmp 比大小
如果返回值 < 0，则表示 str1 小于 str2。
如果返回值 > 0，则表示 str2 小于 str1。
如果返回值 = 0，则表示 str1 等于 str2。
*/
	int ret = strcmp(str1, str2);
	int ret = strncmp(str1, str2, 4);

/*
strcpy 复制
strncpy
*/
	memset(dest, '\0', sizeof(dest));
	strcpy(src, "This is runoob.com");
	strncpy(dest, src, 10);//This is ru

//strlen 计算长度
//|This is runoob.com| 的长度是 |18|
#include <stdio.h>
#include <string.h>

int main ()
{
   char str[50];
   int len;

   strcpy(str, "This is runoob.com");

   len = strlen(str);
   printf("|%s| 的长度是 |%d|\n", str, len);
   
   return(0);
}

//strcat 把 src 所指向的字符串追加到 dest 所指向的字符串的结尾
//strncat
#include <stdio.h>
#include <string.h>
 
int main ()
{
   char src[50], dest[50];
 
   strcpy(src,  "This is source");
   strcpy(dest, "This is destination");
 
   strcat(dest, src);
 
   printf("最终的目标字符串： |%s|", dest);//|This is destinationThis is source|
   
   return(0);
}

//strchr 参数 str 所指向的字符串中搜索第一次出现字符 c（一个无符号字符）的位置
#include <stdio.h>
#include <string.h>

int main ()
{
   const char str[] = "http://www.runoob.com";
   const char ch = '.';
   char *ret;

   ret = strchr(str, ch);

   printf("|%c| 之后的字符串是 - |%s|\n", ch, ret);//|.| 之后的字符串是 - |.runoob.com|
   
   return(0);
}

//strcspn 检索字符串 str1 开头连续有几个字符都不含字符串 str2 中的字符。
#include <stdio.h>
#include <string.h>


int main ()
{
   int len;
   const char str1[] = "ABCDEF4960910";
   const char str2[] = "013";

   len = strcspn(str1, str2);

   printf("第一个匹配的字符是在 %d\n", len + 1);//10
   
   return(0);
}

//strstr 在字符串 haystack 中查找第一次出现字符串 needle 的位置，不包含终止符 '\0'。
#include <stdio.h>
#include <string.h>


int main()
{
   const char haystack[20] = "RUNOOB";
   const char needle[10] = "NOOB";
   char *ret;

   ret = strstr(haystack, needle);

   printf("子字符串是： %s\n", ret);//NOOB
   
   return(0);
}

//strtok 分解字符串 str 为一组字符串，delim 为分隔符
#include <string.h>
#include <stdio.h>
 
int main () {
   char str[80] = "This is - www.runoob.com - website";
   const char s[2] = "-";
   char *token;
   
   /* 获取第一个子字符串 */
   token = strtok(str, s);
   
   /* 继续获取其他的子字符串 */
   while( token != NULL ) {
      printf( "%s\n", token );
    
      token = strtok(NULL, s);
   }
   
   return(0);
}
/*
This is 
 www.runoob.com 
 website
*/


