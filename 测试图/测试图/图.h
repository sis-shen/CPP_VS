#define NAME 40
#define introduce 85
#define MAX 1000000000

typedef struct ArcNode{
	int adjvex;
	int weigth; 
	struct ArcNode *nextarc;
}ArcNode;    //邻接表结构 

typedef struct VNode{
	char vexdata[NAME];
	char information[introduce]; 
	ArcNode *firstarc;
}VNode;     // 点结构 

typedef struct{
	VNode *vertices;
	int vexnum;
	int arcnum; 
}ALGraph;   //图结构 

#define ARR_SIZE 250

int disk[ARR_SIZE][ARR_SIZE], dis[ARR_SIZE], u[ARR_SIZE], V[ARR_SIZE];

void dijkstra(ALGraph a,int b,int c,int **trace,int *x)     //求最短路径 
{
	int num = 0;
	memset(V,0,sizeof(V));
	for(int i = 0;i < a.vexnum;i++)
	{
		for(int j = 0;j < a.vexnum;j++)
		{
			disk[i][j] = MAX;
		}
	}
	for(int i = 0;i < a.vexnum;i++)
	{
		disk[i][i] = 0;
		dis[i] = disk[b][i];
		for(ArcNode *p = a.vertices[i].firstarc;p != NULL;p = p->nextarc)
		{
			disk[i][p->adjvex] = p->weigth;
		}
	}
	u[num] = b;
	V[u[num]] = -1;
	for(int j = 1;j < a.vexnum;j++)
	{
		for(int i = 0;i < a.vexnum;i++)
		{
			if(dis[i] > disk[u[num]][i] + dis[u[num]])
			{
				dis[i] = disk[u[num]][i] + dis[u[num]];
				V[i] = u[num];
			}
		}
		int k = MAX,o = 0; 
		for(int i = 0;i < a.vexnum;i++)
		{
			if(dis[i] > dis[u[num]]&&dis[i] < k)
			{
				k = dis[i];
				o = i;
			}
		}
		u[++num] = o;
	}
	int sum = 1;
	for(int i = c;i != -1;i = V[i])
	{
		sum++;
	} 
	*x = sum;
	*trace = (int*)malloc(sum * sizeof(int));
	(*trace)[sum - 1] = c;
	for(int i = sum - 2;i >= 0;--i)
	{
		(*trace)[i] = V[(*trace)[i + 1]];
	}
}

int LocateVex(ALGraph *a,char *ch)
{
	for(int i = 0;i < a->vexnum;++i)
	{
		if(strcmp(&a->vertices[i].vexdata[0],ch) == 0)
		{
			return i;
		}
	}
	exit(-1);
}

void CreateGraph(ALGraph *a,FILE *r)     //创建图 
{
	char ch;
	fscanf(r,"%d %d",&a->vexnum,&a->arcnum);                         
	fscanf(r,"%c",&ch);
	a->vertices = (VNode*)malloc(a->vexnum * sizeof(VNode));
	for(int i = 0;i < a->vexnum;++i)
	{
		fscanf(r,"%s",&a->vertices[i].vexdata[0]);                 
		int number = strlen(a->vertices[i].vexdata);
		a->vertices[i].vexdata[number] = '\0';
		fscanf(r,"%c",&ch);
		fscanf(r,"%s",&a->vertices[i].information[0]);
		number = strlen(a->vertices[i].information);
		a->vertices[i].information[number] = '\0';
		fscanf(r,"%c",&ch);	
		a->vertices[i].firstarc = NULL;
	}
	for(int i = 0;i < a->arcnum;++i)
	{
		char sv[NAME],tv[NAME],dh; 
		int we;
		fscanf(r,"%[^ ]s",&sv);
		int number = strlen(sv);
		sv[number] = '\0';
		fscanf(r,"%c",&dh);	
        fscanf(r,"%[^ ]s",&tv);
		number = strlen(tv);
		tv[number] = '\0';
		fscanf(r,"%c",&dh);	
		fscanf(r,"%d",&we);                            
		fscanf(r,"%c",&ch);
		int j = LocateVex(a,sv);
		int k = LocateVex(a,tv);
		ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = k;
		p->weigth = we;
		p->nextarc = a->vertices[j].firstarc;
		a->vertices[j].firstarc = p;
		ArcNode *q = (ArcNode*)malloc(sizeof(ArcNode));
		q->adjvex = j;
		q->weigth = we;
		q->nextarc = a->vertices[k].firstarc;
		a->vertices[k].firstarc = q;
	}
}


