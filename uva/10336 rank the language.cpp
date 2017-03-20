#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<iterator>

#define ull unsigned long long
#define iii long long

using namespace std;


vector< string > country;
bool color[10000][10000]={false};
int h,w;

queue <int> q;


int bfs(int i,int j)
{
	if(color[i][j]==true) return 0;
	int temp1,temp2,a=i,b=j;
	char ch;
	q.push(i);q.push(j);
	color[i][j]=true;
	ch=country[i][j];
	while(!q.empty())
	{
		i=q.front();q.pop();
		j=q.front();q.pop();
		temp1=i;temp2=j+1;
		while(temp2<w && country[temp1][temp2]==ch)
		{
			if(color[temp1][temp2]==false)
			{
				q.push(temp1);q.push(temp2);
				color[temp1][temp2]=true;

			}
			temp2++;
		}
		temp2=j-1;
		while(temp2>=0 && country[temp1][temp2]==ch)
		{
			if(color[temp1][temp2]==false)
			{
				q.push(temp1);q.push(temp2);
				color[temp1][temp2]=true;

			}
			temp2--;
		}
		temp1=i+1;temp2=j;
		while(temp1<h && country[temp1][temp2]==ch)
		{
			if(color[temp1][temp2]==false)
			{
				q.push(temp1);q.push(temp2);
				color[temp1][temp2]=true;

			}
			temp1++;
		}
		temp1=i-1;
		while(temp1>=0 && country[temp1][temp2]==ch)
		{
			if(color[temp1][temp2]==false)
			{
				q.push(temp1);q.push(temp2);
				color[temp1][temp2]=true;
			}
			temp1--;
		}
	}

//	printf("%c %d\n",country[i][j],count);
	return (int)country[a][b]-96;
}

class ob
{
	public:
	int num;
	int let;
	bool operator<(const ob& a)const { if(a.num>num) return true;else if(a.let<let) return true;else return false;}
};
int main()
{
	priority_queue< ob > pq;
	int cases,caseno=1;
	string st;
	int store[27]={0},temp;
	scanf("%d",&cases);
	while(cases--)
	{

		scanf("%d %d",&h,&w);
		for(int i=0;i<h;i++)
		{
			cin>>st;
//			cout<<st<<endl;
			country.push_back(st);
		}

		for(int i=0;i<h;i++)
		{
			for(int j=0;j<w;j++)
			{
				temp=bfs(i,j);

//				cout<<country[i][j]<<endl;
				if(temp) store[temp]++;

			}
		}

		ob sam;
		for(int i=1;i<=26;i++)
		{

			if(store[i])
			{
//				cout<<i<<endl;
				sam.num=store[i];
				sam.let=i;
				pq.push(sam);
			}
		}
		printf("World #%d\n",caseno++);
		while(!pq.empty())
		{
			printf("%c: %d\n",pq.top().let+96,pq.top().num);
			pq.pop();
		}
		memset(store,0,sizeof(store));

		country.clear();

		for(int i=0;i<=h;i++)
		{
			for(int j=0;j<=w;j++)
			{
				color[i][j]=false;
			}
		}
//		cout<<color[1][1]<<endl;
	}


	return 0;
}
