//#define  _CRT_SECURE_NO_WARNINGS 1
//#include<assert.h>
//#include <stdbool.h>
//#include <stdlib.h>
//#include <stdio.h>
//
//typedef struct stackint {
//	int* a;
//	int top;
//	int capacity;
//}stack;
//
//typedef struct stackchar {
//	char* a;
//	int top;
//	int capacity;
//}stackchar;
//void StackInit(stack* st)
//{
//	assert(st);
//	st->a = (int*)malloc(sizeof(int) * 4);
//	st->top = 0;
//	st->capacity = 4;
//}
//void StackcharInit(stackchar* st)
//{
//	assert(st);
//	st->a = (char*)malloc(sizeof(char) * 4);
//	st->top = 0;
//	st->capacity = 4;
//}
//void StackPush(stack* st, int x)
//{
//	assert(st);
//	if (st->top == st->capacity)
//	{
//		st->capacity *= 2;
//		int* tmp = realloc(st->a, st->capacity * sizeof(int));
//		if (!tmp)
//		{
//			exit(-1);
//		}
//		st->a = tmp;
//	}
//	st->a[st->top] = x;
//	st->top++;
//}
//void StackPop(stack* st)
//{
//	assert(st);
//	assert(st->top > 0);
//	st->top--;
//}
//int StackTop(stack* st)
//{
//	assert(st);
//	return st->a[st->top - 1];
//}
//void StackcharPush(stackchar* st, char x)
//{
//	assert(st);
//	if (st->top == st->capacity)
//	{
//		st->capacity *= 2;
//		char* tmp = realloc(st->a, st->capacity * sizeof(char));
//		if (!tmp)
//		{
//			exit(-1);
//		}
//		st->a = tmp;
//	}
//	st->a[st->top] = x;
//	st->top++;
//}
//void StackcharPop(stackchar* st)
//{
//	assert(st);
//	assert(st->top > 0);
//	st->top--;
//}
//int StackcharTop(stackchar* st)
//{
//	assert(st);
//	return st->a[st->top - 1];
//}
//bool Char(char* s)//ÅÐ¶ÏÊÇ·ñÊÇ²Ù×÷·û
//{
//	switch (*s)
//	{
//	case'+':case'-':case'*':case'(':case')':return true;
//	default:return false;
//	}
//}
//char Precede(char t1, char t2) {
//	char f;
//	switch (t2)
//	{
//	case'+':
//		if (t1 == '(' || t1 == '#')
//			f = '<';
//		else
//			f = '>';
//		break;
//	case'-':
//		if (t1 == '(' || t1 == '#')
//			f = '<';
//		else
//			f = '>';
//		break;
//	case'*':
//		if (t1 == '(' || t1 == '#' || t1 == '+' || t1 == '-')
//			f = '<';
//		else
//			f = '>';
//		break;
//	case'(':
//		if (t1 == '(')
//			f = '=';
//		else
//			f = '<';
//		break;
//	case')':
//		if (t1 == '(' || t1 == '#')
//			f = '=';
//		else
//			f = '>';
//		break;
//	case'#':
//		if (t1 == '(' || t1 == '#')
//			f = '=';
//		else
//			f = '>';
//		break;
//	}
//	return f;
//}
//int Operate(char x, int a, int b)
//{
//	int c = 0;
//	switch (x)
//	{
//	case'+':c = a + b; break;
//	case'-':c = b - a; break;
//	case'*':c = a * b; break;
//	}return c;
//}
//int solve(char* s) {
//    // write code here
//    stack stackint;
//    stackchar stackChar;
//    StackInit(&stackint);
//    StackcharInit(&stackChar);
//    StackcharPush(&stackChar, '#');
//    while (*s != '\0')
//    {
//        if (!Char(s))
//        {
//            char* p = s; int x = 0; char ch = 0;
//            while (*(p + x) != 0)
//            {
//                if (*(p + x) == '*' || *(p + x) == '+' || *(p + x) == '-' || *(p + x) == '(' || *(p + x) == ')')
//                {
//                    ch = *(p + x);
//                    *(p + x) = 0;
//                    break;
//                }x++;
//            }
//            int num = atoi(p); 
//			StackPush(&stackint, num);
//            *(s + x) = ch; s = s + x;
//        }
//        else
//        {
//            if (Precede(StackcharTop(&stackChar), *s) == '<')
//            {
//                StackcharPush(&stackChar, *s); s++;
//            }
//            else if (*s == ')') {
//                while (StackcharTop(&stackChar) != '(')
//                {
//                    int a = StackTop(&stackint);
//                    StackPop(&stackint);
//                    int b = StackTop(&stackint);
//                    StackPop(&stackint);
//                    char z = StackcharTop(&stackChar);
//                    StackcharPop(&stackChar);
//                    StackPush(&stackint, Operate(z, a, b));
//                }s++; StackcharPop(&stackChar);
//            }
//            else if (Precede(StackcharTop(&stackChar), *s) == '>')
//            {
//                int a = StackTop(&stackint);
//                StackPop(&stackint);
//                int b = StackTop(&stackint);
//                StackPop(&stackint);
//                char z = StackcharTop(&stackChar);
//                StackcharPop(&stackChar);
//                StackPush(&stackint, Operate(z, a, b));
//                StackcharPush(&stackChar, *s); s++;
//            }
//
//        }
//    }
//    while (StackcharTop(&stackChar) != '#')
//    {
//        int a = StackTop(&stackint);
//        StackPop(&stackint);
//        int b = StackTop(&stackint);
//        StackPop(&stackint);
//        char z = StackcharTop(&stackChar);
//        StackcharPop(&stackChar);
//        StackPush(&stackint, Operate(z, a, b));
//    }
//    return StackTop(&stackint);
//}
//int main()
//{
//	char str[] = "1+2";
//	int ret = solve(str);
//	printf("%d", ret);
//	return 0;
//}