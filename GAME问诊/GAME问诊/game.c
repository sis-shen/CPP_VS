#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char arr[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	// 行
	for (i = 0; i < rows; i++) 
	{
		int j = 0;
		// 列
		for (j = 0; j < cols; j++) 
		{
			arr[i][j] = set;
		}
	}
}

void DisplayBoard(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;

	// 先打印列号
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++) 
	{
		int j = 0;
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char arr[ROWS][COLS], int row, int col)
{
	// 布置10个雷
	int count = 10;
	while (count)
	{
		// 布置雷
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (arr[x][y] == '0')
		{
			arr[x][y] = '1';
			count--;
		}
		// 布置成功一个雷，count
	}
}