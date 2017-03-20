#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>


using namespace std;




class data
{
	public:
		int u,e,cst;
	bool operator<(const data &p)const { return cst<p.cst;}
//	data data::operator=(data p){ u=p.u;e.p.e;cst=p.cst; return *this;}
};

vector<int>v[210];
int cost[210][210];
char store[210][35];
int n,r;
int parent[210];
bool color[210];


int prim(int src,int target)
{

	memset(color,true,sizeof(color));
	priority_queue<data> q;

	data temp,current;
	vector<int>vnew;
	int top=src,a;

	color[src]=false;
	vnew.push_back(src);
//	temp.u=src;
//	temp.e=v[src][0];
//	temp.cst=cost[src][temp.e];
//	q.push(temp);

	int count=1;

	while(count!=n)
	{
//		printf("atke aci   ");
		for(int i=0;i<count;i++)
		{
			top=vnew[i];
			for(int j=0;j<v[top].size();j++)
			{

				if(color[v[top][j]]==true)
				{

					temp.u=top;
					temp.e=v[top][j];
					temp.cst=cost[top][v[top][j]];
					q.push(temp);
//					cout<< "Pushing " <<temp.u<<" "<<temp.e<<" "<<cost[top][v[top][j]]<<endl;
				}
			}
		}
		current=q.top();
		while(color[current.e]==false)
		{
			q.pop();
			current=q.top();
		}
		a=current.e;
		parent[a]=current.u;
		if(target==a) break;
		vnew.push_back(a);
		count++;

		color[a]=false;
		q.empty();
//		cout<<"got "<<current.u<<" "<<current.e<<" "<<cost[current.u][current.e]<<endl;
	}


	return 0;


}


int main()
{
	map<string,int> m;


   int src,target,pos1,pos2,len,d,temp,caseno=1;
   char c[35];


   bool flag=false;
    while(scanf("%d%d",&n,&r)==2)
    {
        if(n==0 && r==0)
            break;
        len=1;
        flag=false;
        for(int i=0;i<r;i++)
        {
            scanf("%s",c);
            if(m[c]) pos1=m[c];
            else pos1=m[c]=len++;

            scanf("%s",c);
            if(m[c]) pos2=m[c];
            else pos2=m[c]=len++;

            v[pos1].push_back(pos2);
            v[pos2].push_back(pos1);
            scanf("%d",&d);
            cost[pos1][pos2]=d;
            cost[pos2][pos1]=d;
        }

        scanf("%s",c);
		src=m[c];

		scanf("%s",c);
        target=m[c];

        prim(src,target);
        int temp_cost=100000;

        while(target!=src)
        {

			temp=cost[target][parent[target]];
			if(temp_cost>temp) temp_cost=temp;
			target=parent[target];
		}
		temp_cost!=100000 ? printf("Scenario #%d\n%d tons\n\n",caseno++,temp_cost) : printf("Scenario #%d\n0 tons\n\n",caseno++);

		for(int i = 1; i <= len; i++)
			v[i].clear();
		m.clear();

    }
    return 0;

}

//#include<iostream>
//#include<cstdio>
//#include<map>
//
//using namespace std;
//
//int main()
//{
//	int cases,n,mul;
//	long long num[10010],temp;
//	unsigned long long sum;
//	map<long long,int> m;
//	cin>>cases;
//	while(cases--)
//	{
//		cin>>n;
//		int index=0;
//		for(int i=0;i<n;i++)
//		{
//
//			cin>>temp;
//			if(m[temp]==0)
//			{
//				m[temp]=1;
////				cout<<"boshalam";
//				num[index++]=temp;
//			}
//
//		}
////		cout<<index<<endl;
//		sum=0;
//		mul=index-1;
//
////		int lim;
////		if(index%2==0) lim=index/2-1;
////		else lim=index/2;
//		for(int i=0;i<index/2;i++)
//		{
////			cout<<sum<<endl;
//			sum+= num[index-i-1]*mul -num[i]*mul;
//			mul-=2;
//		}
////		if(n%2==1) sum+=num[n/2];
//		cout<<sum<<endl;
//		m.clear();
//	}
//	return 0;
//}
