#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"图.h"

int search(ALGraph a,char *p)       //查找节点 
{
	int i; 
	for(i = 0;i < a.vexnum;i++)
	{
		if(strcmp(a.vertices[i].vexdata,p) == 0)
		{
			return i;
		}
	}
	return -1;
}

int route(ALGraph a,int *b,int *c,int *f)     //计算最佳游览路径 
{
	if(*f >= (a.vexnum-1))
	{
		ArcNode *p;
		for(p = a.vertices[b[*f]].firstarc;p != NULL;p = p->nextarc)
		{
			if(p->adjvex == 0)
			{
			    return 1;	
			}
		}
		if(p == NULL)
		{			
	        c[b[*f]] = 0;
	        (*f)--;
			return 0;
		}
	}
	else
	{
	    ArcNode *p;
	    for(p = a.vertices[b[*f]].firstarc;p != NULL;p = p->nextarc)
		{
			if(c[p->adjvex] == 0)
			{
				(*f)++;
				c[p->adjvex] = 1;
				b[*f] = p->adjvex;
				if(route(a,b,c,f))
				{
					return 1;
				}
			}
		}
		if(p == NULL)
		{		
	        c[b[*f]] = 0;
	        (*f)--;
			return 0;
		}
	}
}

int member[ARR_SIZE], V[ARR_SIZE];


void optimal_sightseeing_route(ALGraph a,int *e)    //打印最佳游览路径 
{
	int number = 0;
	memset(V,0,sizeof(V));
	V[0] = 1;
	member[number] = 0;
	route(a,member,V,&number);
	for(int i = 0;i < a.vexnum;i++)
	{
		e[i] = member[i];
	}
}

int main()
{
    FILE *r;
    if((r = fopen("data.txt","r")) == NULL)
	{
	    exit(-1);
	}
	ALGraph graph;
	CreateGraph(&graph,r);
	for(;;)
	{
		printf("\n请选择: \n1.显示景点名称 2.查看景点介绍 3.从景点A到景点B的最短路径 4.最优游览路径 5.退出\n");
		int choice;
		scanf("%d",&choice);
		getchar();
		switch(choice)
		{
			case 1:
				do
				{
					for(int i = 0;i < graph.vexnum;i++)
					{
						printf("%s ",graph.vertices[i].vexdata);
					}
				}while(0);
				break;
			case 2:
				do
				{
					printf("请输入要查看的景点名称：");
					char name[40];
					scanf("%s",&name[0]);
					getchar();
					int number = strlen(name); 
					name[number] = '\0';
					number = search(graph,name);
					if(number == -1)
					{
						printf("对不起，无此景点。");
					}
					else
					{
						printf("%s",graph.vertices[number].information);
					}
				}while(0);
				break;
			case 3:
				do
				{  
					printf("请输入景点A名称：");
					char name[40],Name[40];
				    int b,c,*d,e;
					scanf("%s",&name[0]);
					getchar();
					name[strlen(name)] = '\0';
					b = search(graph,name);
					printf("请输入景点B名称：");
					scanf("%s",&Name[0]);
					getchar();
					Name[strlen(Name)] = '\0';
					c = search(graph,Name);
					dijkstra(graph,b,c,&d,&e);
					printf("最短路径为：\n");
					for(int i = 1;i < (e - 1);++i)
					{
						printf("%s ->",graph.vertices[d[i]].vexdata);
					}
					printf("%s",graph.vertices[d[e - 1]].vexdata);
				}while(0);
				break;
			case 4:
				do
				{
					int trace[ARR_SIZE];
					optimal_sightseeing_route(graph,trace);
					printf("最优游览路径：");
					for(int i = 0;i < graph.vexnum;i++)
					{
						printf("%s->",graph.vertices[trace[i]].vexdata);
					}
					printf("%s",graph.vertices[0].vexdata);
				}while(0);
				break;
			case 5:
			    return 0;
				break;	
		}
	}	
} 
