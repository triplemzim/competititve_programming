#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
#include<cmath>

using namespace std;

double cost[110][110];
vector<double> v[110];
vector<int> vnew;

class data
{
	public:
	int u,e;
	double cst;
	bool operator<(const data &p) const{return cst>p.cst;}
};

bool color[110];

double prim(int n)
{
	priority_queue<data> q;
	int top;
	data temp,current;
	memset(color,true,sizeof(color));
	top=1;
	int count=1;
	double total=0;
	vnew.push_back(1);
	color[1]=false;
	while(count!=n)
	{
		for(int i=0;i<count;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(color[j])
				{
//					cout<<"pushed "<<vnew[i]<<" "<<j<<endl;
					temp.u=vnew[i];
					temp.e=j;
					temp.cst=cost[vnew[i]][j];
					q.push(temp);
				}
			}
		}
		current=q.top();
		while(!color[current.e])
		{
			q.pop();
			current=q.top();
		}
//		cout<<"Got "<<current.u<<" "<<current.e<<endl;
		color[current.e]=false;
		vnew.push_back(current.e);
		total+=cost[current.u][current.e];
		q.empty();
		count++;
	}
	vnew.clear();
	return total;
}

int main()
{
	int n,cases;
	double x,y;

	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf",&x,&y);
			v[i].push_back(x);
			v[i].push_back(y);
		}
		for(int i=1;i<n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				cost[i][j]=cost[j][i]=sqrt( (v[i][0]-v[j][0])*(v[i][0]-v[j][0])+ (v[i][1]-v[j][1])*(v[i][1]-v[j][1]));
//				cout<<cost[i][j]<<endl;
			}
		}
		printf("%.2lf\n",prim(n));
		if(cases!=0) printf("\n");
		for(int i=1;i<=n;i++)
			v[i].clear();

	}
	return 0;

}

