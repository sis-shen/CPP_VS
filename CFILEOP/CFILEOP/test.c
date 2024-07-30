#define  _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <sys/stat.h>


//int main()
//{
//	//准备一个文件
//	FILE* pfile = fopen("file.txt", "w");//"w"模式打开文件file.txt
//	int code = 1;
//	const char* msg = "this is a msg";
//	fprintf(pfile, "get msg : %s code:%d", msg, code);
//	fclose(pfile);
//	//=====
//
//	pfile = fopen("file.txt", "r");
//	char str[5] = { 0 };
//	fgets(str, sizeof(str), pfile);//除去自动添加的\0,最多从文件里读入4个字符
//	printf(str);
//	printf("|");
//	return 0;
//}

int main()
{
	FILE* pfile = fopen("file.txt", "w");//"w"模式打开文件file.txt
	char msg[] = "this is a msg";
	fwrite(msg, sizeof(char), strlen(msg), pfile);

	fclose(pfile);

	return 0;
}

