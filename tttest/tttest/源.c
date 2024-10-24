//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
////题目一
//typedef struct ListNode
//{
//	int data;//存储数据
//	struct ListNode* next;//后驱指针
//	struct ListNode* prev;//前驱指针
//
//}Node;
//Node* NodeCreate(int x)
//{
//	Node* newnode = (Node*)malloc(sizeof(Node));
//	if (newnode == NULL)
//	{
//		perror("malloc failed!\n");
//		return NULL;
//	}
//	newnode->data = x;//存储数据
//	newnode->next = newnode->prev = NULL;//前后指针均置为空
//	return newnode;
//}
//
//Node* ListInit(Node* head)
//{
//	head->next = head->prev = NULL;//前后均指向自身
//	return head;
//}
//
//void push_back(Node* head, int x)
//{
//	Node* newnode = NodeCreate(x);//创建新节点
//	Node* cur = head;
//	if (head == NULL)
//	{
//		head = newnode;//若链表为空直接填补
//
//	}
//	else
//	{
//		while (cur->next != NULL)
//		{
//			cur = cur->next;
//		}
//		cur->next = newnode;
//		newnode->prev = cur;//前后连接
//		newnode->next = head;//尾节点后驱指针指向头节点
//		head->prev = newnode;//头节点前驱指针指向尾节点
//	}
//}
//
//void FirstPrint(Node* head)
//{
//	Node* cur = head;
//	while (cur->next != head)
//	{
//		printf("%d ", cur->data);
//		cur = cur->next;
//	}
//}
//void LastPrint(Node* head)
//{
//	Node* cur = head->prev;
//	while (cur->prev != head)
//	{
//		printf("%d ", cur->data);
//		cur = cur->prev;
//	}
//}
//int main()
//{
//	Node phead;
//	Node* head = &phead;
//	ListInit(head);//初始化链表
//	push_back(head, 1);
//	push_back(head, 2);
//	push_back(head, 3);
//	push_back(head, 4);
//	FirstPrint(head);
//	LastPrint(head);
//	return 0;
//}