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

#define ms(x,val) memset(x,val,sizeof(x))
#define ull unsigned long long
#define iii long long

using namespace std;

char grid[509][509];
int n,m,k;
bool color[501][501];

bool check(int i,int j)
{
	if(i<n && i>=0 && j<m && j>=0) return true;
	else return false;
}


bool bfs(int x,int y)
{
//	cout<<x<<' '<<y<<endl;
	int count=0;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(grid[i][j]=='.') {
				color[i][j]=true;
				count++;
			}
		}
	}

//	cout<<count<<endl;
	bool flag=false;
	queue<int>q;
//	for(int i=n-1;i>=0;i--)
//	{
//
//		for(int j=m-1;j>=0;j--)
//		{
//			if(grid[i][j]=='.' && !(i==x && j==y))
//			{
//				q.push(i);q.push(j);
//				color[i][j]=false;
////				cout<<"eta"<<i<<' '<<j<<endl;
//				flag=true;
//				break;
//			}
//		}
//		if(flag) break;
//	}

	q.push(x);q.push(y);if(count==k) return true;
	color[x][y]=false;
	count--;

	while(!q.empty())
	{
		x=q.front();
		q.pop();
		y=q.front();
		q.pop();


//		if(check(x-1,y-1) && color[x-1][y-1])
//		{
////		cout<<"paici"<<endl;
//			q.push(x-1);q.push(y-1);
//			color[x-1][y-1]=false;count--;
//		}
//		if(count==k) return true;
		if(check(x-1,y) && color[x-1][y])
		{count--;
//		cout<<"paici"<<endl;
			q.push(x-1);q.push(y);
			color[x-1][y]=false;
		}
		if(count==k) return true;
//		if(check(x-1,y+1) && color[x-1][y+1])
//		{count--;
////		cout<<"paici"<<endl;
//			q.push(x-1);q.push(y+1);
//			color[x-1][y+1]=false;
//		}
//		if(count==k) return true;
		if(check(x,y-1) && color[x][y-1])
		{count--;
//		cout<<"paici"<<endl;
			q.push(x);q.push(y-1);
			color[x][y-1]=false;
		}
if(count==k) return true;
		if(check(x,y+1) && color[x][y+1])
		{count--;
//		cout<<"paici"<<endl;
			q.push(x);q.push(y+1);
			color[x][y+1]=false;
		}
//		cout<<color[1][0]<<endl;
if(count==k) return true;
//		if(check(x+1,y-1) && color[x+1][y-1])
//		{count--;
////		cout<<"paici"<<endl;
//			q.push(x+1);q.push(y-1);
//			color[x+1][y-1]=false;
//		}
//		if(count==k) return true;
		if(check(x+1,y) && color[x+1][y])
		{count--;
//		cout<<"paici"<<endl;
			q.push(x+1);q.push(y);
			color[x+1][y]=false;
		}
		if(count==k) return true;
//		if(check(x+1,y+1) && color[x+1][y+1])
//		{count--;
////		cout<<"paici"<<endl;
//			q.push(x+1);q.push(y+1);
//			color[x+1][y+1]=false;
//		}
//		if(count==k) return true;
//		cout<<"1st"<<count<<endl;
	}
	if(count==k) return true;
	else return false;
}

int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
	{
		scanf("%s",grid[i]);
	}
	bool flag=false;
	int count=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{

			if(flag==false && grid[i][j]=='.')
			{
				if(bfs(i,j)==true){
					flag=true;
//					count++;
//					grid[i][j]='X';
					break;
				}
			}


		}
		if(flag) break;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(color[i][j]) grid[i][j]='X';
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%s\n",grid[i]);
	}






	return 0;
}
