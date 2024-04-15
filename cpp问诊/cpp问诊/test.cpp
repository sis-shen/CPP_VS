//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//typedef int DataType; 
//
//typedef struct Node
//{
//	DataType val;
//	struct Node* next;
//	struct Node* prev;
//}Node;
//
//
//Node* InitNode(Node* phead);//��ʼ��
//void PushFront(Node* phead, DataType x);//ͷ��
//void PushBack(Node* phead, DataType x);//β��
//void PopFront(Node* phead);//ͷɾ
//void PopBack(Node* phead);//βɾ
//void DestroyList(Node* phead);//ɾ������
//
//int FindNode(Node* phead, DataType x);//�ҵ���һ��ֵΪx�Ľڵ㣬�������±�,�涨�ڱ�λΪ0���������μ�һ,�����Ҳ����ͷ���0
//void InsertNode(Node* phead, DataType x, int pos);//ʹ�²���Ľڵ��±�Ϊ pos
//void EraseNode(Node* phead, int pos);//ɾ���±�Ϊpos�Ľڵ�
//
//
//Node* InitNode(Node* phead)
//{
//	//�����ڱ�λ
//	Node* ret = (Node*)malloc(sizeof(Node));
//	//ret->val  //�ڱ�λ��ֵ��������
//	ret->next = ret;
//	ret->prev = ret;
//	ret->val = 0;
//	return ret;
//}
//
//Node* BuyNode(DataType x)
//{
//	Node* ret = (Node*)malloc(sizeof(Node));
//	ret->val = x;
//	ret->next = NULL;
//	ret->prev = NULL;
//	return ret;
//}
//
//void PushFront(Node* phead, DataType x)
//{
//	assert(phead);
//	Node* newNode = BuyNode(x);
//	Node* next = phead->next;
//
//	next->prev = newNode;
//	newNode->next = next;
//	newNode->prev = phead;
//	phead->next = newNode;
//}
//
//void PushBack(Node* phead, DataType x)
//{
//	assert(phead);
//	Node* newNode = BuyNode(x);
//	Node* tail = phead->prev;
//
//	phead->prev = newNode;
//	newNode->next = phead;
//	tail->next = newNode;
//	newNode->prev = tail;
//
//}
//
//void PopFront(Node* phead)
//{
//	assert(phead);
//	Node* front = phead->next;
//	assert(front != phead);
//	phead->next = front->next;
//	front->prev = phead;
//
//	free(front);
//}
//
//void PopBack(Node* phead)
//{
//	assert(phead);
//	Node* tail = phead->prev;
//
//	assert(tail != phead);
//
//	tail->prev->next = phead;
//	phead->prev = tail->prev;
//
//	free(tail);
//}
//
//void DestroyList(Node* phead)
//{
//	assert(phead);
//	Node* cur = phead->next;
//	while (cur != phead)
//	{
//		Node* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	free(phead);
//}
//
//int FindNode(Node* phead, DataType x)
//{
//	assert(phead);
//	int cnt = 0;
//	Node* cur = phead->next;
//	while (cur != phead)
//	{
//		cnt++;
//		if (cur->val == x)
//		{
//			return cnt;
//		}
//		else
//		{
//			cur = cur->next;
//		}
//	}
//
//	return 0;
//}
//
//void InsertNode(Node* phead, DataType x, int pos)
//{
//	assert(pos > 0);
//	assert(phead);
//	Node* nNode = BuyNode(x);
//	Node* cur = phead;
//	while (pos - 1)
//	{
//		cur = cur->next;
//		if (cur == phead)
//		{
//
//			return;
//		}
//		pos--;
//	}
//
//	Node* next = cur->next;
//	cur->next = nNode;
//	nNode->prev = cur;
//	nNode->next = next;
//	next->prev = nNode;
//}
//
//void EraseNode(Node* phead, int pos)
//{
//	assert(pos > 0);
//	assert(phead->next != phead);
//	Node* cur = phead;
//	while (pos - 1)
//	{
//		cur = cur->next;
//		if (cur == phead)
//		{
//			return;
//		}
//		pos--;
//	}
//
//	Node* next = cur->next;
//	cur->next = next->next;
//	next->next->prev = cur;
//
//	free(next);
//}
//
//void PrintList_int(Node* phead)
//{
//	assert(phead);
//	Node* cur = phead->next;
//	while (cur != phead)
//	{
//		printf("%d->", cur->val);
//		cur = cur->next;
//	}
//	printf("NULL\n");
//}
//
//
//int ysf(int n, int m) {
//	Node* phead = NULL;
//	phead = InitNode(phead);
//
//	for (int i = 0; i < n; i++)
//	{
//		PushBack(phead, i + 1);
//	}
//	Node* cur = phead;
//	Node* next = cur->next;
//	for (int i = 0; i < n - 1; i++)
//	{
//		int cnt = 1;
//		cur = next;
//
//		while (cnt != m)
//		{
//			cnt++;
//			cur = cur->next;
//			if (cur == phead)
//			{
//				cur = cur->next;
//			}
//			next = cur->next;
//			if (next == phead)
//			{
//				next = next->next;
//			}
//		}
//
//		Node* prev = cur->prev;
//		prev->next = next;
//		next->prev = prev;
//		printf("%d ", cur->val);
//		free(cur);
//	}
//
//	int ret = phead->next->val;
//	DestroyList(phead);
//	return ret;
//}
//
//int main()
//{
//	printf("%d", ysf(5, 2));
//
//	return 0;
//}

//#include<iostream>
//using namespace std;
//
//int main()
//{
//	cout << -5 % 2;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//int sum;
//int wei(int m)
//{
//    int n = 0;
//    while (m)
//    {
//        m /= 10;
//        n++;
//    }
//    return n;
//}
//int main()
//{
//    for (int icopy = 1; icopy <= 100; icopy++)
//    {
//        int i = icopy;
//        int shuwei = wei(i);
//        if (shuwei % 2 == 1)
//        {
//            continue;
//        }
//        int a = 0;
//        for (int m = 1; m <= shuwei / 2; m++)
//        {
//            a += i % 10;
//            i /= 10;
//        }
//        int b = 0;
//        for (int m = 1; m <= shuwei / 2; m++)
//        {
//            b += i % 10;
//            i /= 10;
//        }
//        if (a == b)
//        {
//            sum++;
//        }
//    }
//    cout << sum;
//    // 请在此输入您的代码
//    return 0;
//}

//#include <iostream>
//#include <queue>
//#include <vector>
//#include <unordered_set>
//using namespace std;
//int main()
//{
//    typedef pair<int, int> PII;
//    int n, k;
//    cin >> n >> k;
//    vector<int> arr(n);
//    vector<int> next(n), prev(n);
//    priority_queue<PII, vector<PII>, greater<PII>> q;
//    for (int i = 0; i < n; i++)
//    {
//        int num = 0;
//        cin >> num;
//        q.push({ num,i });
//        arr[i] = num;
//        prev[i] = i - 1;
//        next[i] = i + 1;
//    }
//
//    while (q.size() > n - k)
//    {
//        int num = q.top().first;
//        int id = q.top().second;
//        q.pop();
//
//        if (num != arr[id])//oops,弹错了，更新一下
//        {
//            q.push({ arr[id], id });
//        }
//        else
//        {
//            if (next[id] < n) { arr[next[id]] += arr[id]; prev[next[id]] = prev[id]; }
//            if (prev[id] >= 0) { arr[prev[id]] += arr[id]; next[prev[id]] = next[id]; }
//        }
//    }
//
//    //提取答案
//    vector<int> ret(n);
//    while (q.size())
//    {
//        int id = q.top().second; q.pop();
//        ret[id] = arr[id];
//    }
//
//    for (auto e : ret)
//    {
//        if (e)
//            cout << e << " ";
//    }
//
//    return 0;
//}

#include <iostream>

using namespace std;

int main()
{
	int num = 1e9 + 7;
	double q = 1e9 + 7;
	cout << num<<endl;
	cout << q << endl;
	return 0;
}