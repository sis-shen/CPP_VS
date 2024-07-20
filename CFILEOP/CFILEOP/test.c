
#include <stdio.h>

int main()
{
	FILE* pfile = fopen("file.txt", "w");//"w"模式打开文件file.txt
	int code = 1;
	const char* msg = "this is a msg";
	fprintf(pfile, "get msg : %s code:%d", msg, code);
	fclose(pfile);
	pfile = fopen("file.txt", "a");
	fprintf(pfile, "ADD");
	fclose(pfile);
	return 0;
}