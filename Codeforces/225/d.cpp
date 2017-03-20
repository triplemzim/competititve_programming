#include<bits/stdc++.h>

using namespace std;


#define ms(x,val) memset(x,val,sizeof(x))
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define repi(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define PII pair<int,int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999

map<pair<long long,long long>,iii> parent;
queue< pair<iii,iii> >q;
vector<int> v[100009];
pair<iii,iii>t,s;
map<pair<long long,long long>,bool>m,color;
int mp;
iii n;

//iii bfs()
//{
//	iii top,temp;
//	iii x=1,y=1;
//	parent[MP(x,y)]=0;
//	q.push(MP(x,y));
//	while(!q.empty())
//	{
//
//		t=q.front();
//		x=t.first;y=t.second;
////		cout<<x<<' '<<y<<endl;
//		if(x==n && y==n) return parent[t];
//		if(x+1<=n && color.find(MP(x+1,y))==color.end() && m.find(MP(x+1,y))==m.end())
//		{
//			color[MP(x+1,y)]=true;
//			q.push(MP(x+1,y));
//			parent[MP(x+1,y)]=parent[t]+1;
//		}
//		if(y+1<=n && color.find(MP(x,y+1))==color.end() && m.find(MP(x,y+1))==m.end())
//		{
//			color[MP(x,y+1)]=true;
//			q.push(MP(x,y+1));
//			parent[MP(x,y+1)]=parent[t]+1;
//		}
//
//		q.pop();
//	}
//	return -1;
//}
//&& color.find(MP(x,y+1))==color.end()&& color.find(MP(x+1,y))==color.end()


map<pair<iii,iii>,bool> ::iterator it;
bool bfs()
{
	for(it=m.begin();it!=m.end();it++)
	{
		t=(*it).first;
		if(color[t]==false)
		{
			color[t]=true;
			q.push(t);
			while(!q.empty())
			{
				if(colo
	}
	return false;
}

int main()
{

	iii temp,x,y,index;
	cin>>n>>mp;
//	cout<<n;
	for(int i=0;i<mp;i++)
	{
		cin>>x>>y;
		if(m.find(MP(x,y))==m.end())
		{
			m[MP(x,y)]=false;
		}
	}
//	cout<<"paici";
	temp=bfs();
	if(temp==-1)
	{
		cout<<-1<<endl;
	}
	else
	{
		cout<<temp<<endl;
	}



	return 0;
}

