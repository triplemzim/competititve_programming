//#include<iostream>
//#include<cstdio>
//#include<vector>
//#include<algorithm>
//#include<queue>
//#include<cstring>
//#include<map>
//#include<cmath>
//
//using namespace std;
//
//double cost[110][110];
//vector<double> v[110];
//vector<int> vnew;
//
//class data
//{
//	public:
//	int u,e;
//	double cst;
//	bool operator<(const data &p) const{return cst>p.cst;}
//};
//
//bool color[110];
//
//double prim(int n)
//{
//	priority_queue<data> q;
//	int top;
//	data temp,current;
//	memset(color,true,sizeof(color));
//	top=1;
//	int count=1;
//	double total=0;
//	vnew.push_back(1);
//	color[1]=false;
//	while(count!=n)
//	{
//		for(int i=0;i<count;i++)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				if(color[j])
//				{
////					cout<<"pushed "<<vnew[i]<<" "<<j<<endl;
//					temp.u=vnew[i];
//					temp.e=j;
//					temp.cst=cost[vnew[i]][j];
//					q.push(temp);
//				}
//			}
//		}
//		current=q.top();
//		while(!color[current.e])
//		{
//			q.pop();
//			current=q.top();
//		}
////		cout<<"Got "<<current.u<<" "<<current.e<<endl;
//		color[current.e]=false;
//		vnew.push_back(current.e);
//		total+=cost[current.u][current.e];
//		q.empty();
//		count++;
//	}
//	vnew.clear();
//	return total;
//}
//
//int main()
//{
//	int n,cases;
//	double x,y;
//
//	scanf("%d",&cases);
//	while(cases--)
//	{
//		scanf("%d",&n);
//		for(int i=1;i<=n;i++)
//		{
//			scanf("%lf%lf",&x,&y);
//			v[i].push_back(x);
//			v[i].push_back(y);
//		}
//		for(int i=1;i<n;i++)
//		{
//			for(int j=i+1;j<=n;j++)
//			{
//				cost[i][j]=cost[j][i]=sqrt( (v[i][0]-v[j][0])*(v[i][0]-v[j][0])+ (v[i][1]-v[j][1])*(v[i][1]-v[j][1]));
////				cout<<cost[i][j]<<endl;
//			}
//		}
//		printf("%.2lf\n",prim(n));
//		if(cases!=0) printf("\n");
//		for(int i=1;i<=n;i++)
//			v[i].clear();
//
//	}
//	return 0;
//
//}


//#include<iostream>
//#include<cstdio>
//#include<cstring>
//
//using namespace std;
//
//int main()
//{
//
//	long long ans,i,j,n;
//	while(scanf("%lld%lld%lld",&n,&i,&j)==3)
//	{
////		if((i&1)==1) i++;
////		if((j&1)==1) j++;
//		int count=1;
//		if(i>j)
//		{
//			ans=i;
//			i=j;j=ans;
//		}
//
//		while((i%2)!=1 || j-i!=1)
//		{
////			cout<<i<<" "<<j<<endl;
//			if((i&1)==1) i++;
//			if((j&1)==1) j++;
//			j=(j>>1);
//			i=(i>>1);
//			count++;
//		}
//
//		printf("%d\n",count);
//	}
//
//
//	return 0;
//}

//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//
//
//int main()
//{
//	int n,d,reach,u,dif,time;
//	while(scanf("%d%d%d",&n,&u,&d)==3 && n)
//	{
//
//		dif=u-d;reach=0;
//		time=0;
//		while(reach!=n)
//		{
//			if(reach+u>=n)
//			{
//				time++;
//				break;
//			}
//			reach+=dif;
//			time+=2;
//		}
//
//
//		printf("%d\n",time);
//	}
//	return 0;
//}

//#include<iostream>
//#include<cstdio>
//#include<algorithm>
//
//#define iii unsigned long long
//using namespace std;
//
//int main()
//{
//	iii a,b,c,num[40];
//	int cases,n,index,caseno=1;
//	scanf("%d",&cases);
//	while(cases--)
//	{
//		index=0;
//		scanf("%d",&n);
//		while(n--)
//		{
//			scanf("%llu",&num[index++]);
//
//		}
//		sort(num,num+index);
//
//		printf("Case %d: ",caseno++);
//		printf("%llu\n",num[index-1]);
//
//	}
//	return 0;
//
//}
//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//
//int main()
//{
//	int w,n,cases,gar,lim,x,last;
//	long dis;
//	scanf("%d",&cases);
//	while(cases--)
//	{
//		scanf("%d%d",&w,&n);
//		dis=0;gar=0;last=0;
//		while(n--)
//		{
//			scanf("%d%d",&x,&lim);
//			dis+=x-last;
//			last=x;
//			if(gar+lim>w)
//			{
//				gar=lim;
//				dis=dis+2*x;
//			}
//			else gar+=lim;
//
//			if(gar==w && n!=0)
//			{
//				gar=0;
//				dis=dis+2*x;
//			}
//
//		}
//		dis+=x;
//		printf("%ld\n",dis);
//	}
//    return 0;
//}
//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//
//int main()
//{
//	int grp[5]={0};
//	int n,a,car=0;
//	scanf("%d",&n);
//	while(n--)
//	{
//		scanf("%d",&a);
//		grp[a]++;
//	}
//	car=grp[4];
//	car+=grp[3];
//	if(grp[1]>grp[3]) grp[1]-=grp[3];
//	else grp[1]=0;
//
//	car=car+grp[2]/2;
//
//	if(grp[2]%2==1)
//	{
//	car++;
//	if(grp[1]>1) grp[1]-=2;
//	else grp[1]=0;
//	}
//	car=car+ grp[1]/4;
//	if(grp[1]%4!=0) car++;
//	printf("%d\n",car);
//
//	return 0;
//}

//#include<iostream>
//#include<cstdio>
//
//using namespace std;
//
//int main()
//{
//	int n,time;
//	char st[100];
//	scanf("%d%d%s",&n,&time,st);
//	for(int i=0;i<time;i++)
//	{
//		for(int j=0;j<n-1;j++)
//		{
//			if(st[j]=='B' && st[j+1]=='G')
//			{
//				st[j]='G';st[j+1]='B';j++;
//			}
//		}
//	}
//	printf("%s\n",st);
//	return 0;
//}
//
//
#include<iostream>
#include<cstdio>
#include<cmath>


using namespace std;




int main()
{
	int n;
	long x,y,num[2009];
	bool flag=true;
	scanf("%d%ld",&n,&num[1]);
	for(int i=2;i<=n;i++)
	{
		scanf("%ld",&num[i]);
	}
	num[0]=num[1];num[n+1]=num[n];
	for(int i=1;i<=n;i++)
	{
		if(num[i-1]>num[i]){
			x=num[i];y=num[i-1];
		}
		else
		{
			x=num[i-1];y=num[i];
		}
		for(int j=1;j<=n;j++)
		{
			if(num[j]>x && num[j]<y)
			{
					if(num[j-1]<x || num[j-1]>y || num[j+1]<x || num[j+1]>y)
					{
						flag=false;
						break;
					}
			}
		}
		if(!flag) break;
	}
	if(flag) printf("no\n");
	else printf("yes\n");

	return 0;
}

#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

vector<int>v[100002];

map<int,int> mp;
int main()
{
	int n,m,x,y,index=1;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		if(mp[x]==0) {
			mp[x]=index;
			v[index++].push_back(y);
		}
		else v[mp[x]].push_back(y);
		if(mp[y]==0) {
			mp[y]=index;
			v[index++].push_back(x);
		}
		else
			v[mp[y]].push_back(x);
	}
	int bus_out=0,bus_in=0,ring=0,s,cen_c=0,cen_out=0;
	for(int i=1;i<index;i++)
	{
		s=v[i].size();
		if(s==1)
		{
			cen_out++;
			bus_out++;
		}
		else if(s==2)
		{
			bus_in++;
			ring++;
		}
		else
		{
			cen_c++;
		}
	}
//	cout<<"busout "<<bus_out<<"busin "<<bus_in<<" cen_c "<<cen_c<<endl;
	if(n<m)
	{
		printf("unknown topology\n");
	}
	else if(n-1==m && bus_out==2 && bus_in==n-2)
	{
		printf("bus topology\n");
	}
	else if(ring==n && n==m)
	{
		printf("ring topology\n");
	}
	else if(n==m+1 && cen_c==1 && cen_out==n-1)
	{
		printf("star topology\n");
	}
	else
	{
		printf("unknown topology\n");
	}

	return 0;
}









