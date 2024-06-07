#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("*********************************\n");
	printf("**********   1. play   **********\n");
	printf("**********   0. exit   **********\n");
	printf("*********************************\n");
}

void game()
{
	// 存放数据的类型太多，容易产生歧义
	// 在统计一个坐标周围的雷的个数的时候，可能会越界
	
	char mine[ROWS][COLS];
	char show[ROWS][COLS];

	// 初始化棋盘
	InitBoard(mine, ROWS, COLS, '0'); // '0'
	InitBoard(show, ROWS, COLS, '*'); // '*'

	// 打印棋盘
	DisplayBoard(show, ROW, COL);

	// 1.布置雷
	SetMine(mine, ROW, COL);

	// 2.排查雷

}

// 写项目的时候，注意写一点验证一点，不要最后再来检查
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请输入:");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择！\n");
			break;
		}
	} while (input);

	return 0;
}