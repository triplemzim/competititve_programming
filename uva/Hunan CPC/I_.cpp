#include<bits/stdc++.h>

	using namespace std;


	#define ms(x,val) memset(x,val,sizeof(x))
	#define scan(x) scanf("%d",&x)
	#define scanL(x) scanf("%I64d",&x)
	#define print(x) printf("%d\n",x)
	#define debug(x) printf("DEBUG: %d\n",x)
	#define printL(x) printf("%I64d\n",x)
	#define ull unsigned long long
	#define iii long long
	#define pi acos(-1)
	#define pb push_back
	#define PII pair<int,int>
	#define vi vector<int>
	#define itr_all(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
	#define MAPL map<long long, int > 
	#define MAPI map<int,int> 
	#define MAPP map< pair<int,int> , int>
	#define MP make_pair
	#define eps 1e-9
	#define inf 999999999
	#define MAXN 1000009
	#define MOD 1000000007 // 10^9 + 7

	template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
	template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
	template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
	inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}
	

    int sx,sy,tx,ty,cx,cy;
    int fx[]={-1,-1,-1,0,1,1,1,0};
    int fy[]={-1,0,1,1,1,0,-1,-1};
    bool color[30][30];
    int dist[30][30];

    bool check(int a,int b)
    {
        if(a>=1 && b>=1 && a<=8 && b<=8)
            return true;
        return false;
    }


    int dfs(int a,int b)
    {
        queue <pair<int,int> > Q;
        Q.push(MP(a,b));
        dist[a][b]=0;
        color[a][b]=true;
        while(!Q.empty())
        {
            pair <int,int> x=Q.front();
            Q.pop();
            int p=x.first;
            int q=x.second;
            for (int i=0; i<8; i++)
            {
                int u=p+fx[i];
                int v=q+fy[i];
                if(check(u,v) && !color[u][v])
                {
                    color[u][v]=true;
                    dist[u][v]=dist[p][q]+1;
                    Q.push(MP(u,v));
                }
            }
        }
        return dist[tx][ty];
    }



	int main()
	{
	//	  ios::sync_with_stdio(false);
		  // freopen("in.txt","r",stdin);

        int cases,caseno=1;
        // cin>>cases;
        // while(cases--)
        // {
            while((cin>>sx>>sy>>tx>>ty>>cx>>cy)!=NULL)
            {
                // cout<<"w";
                ms(color,false);
                ms(dist,0);
                color[cx][cy]=true;
                printf("Case %d: ", caseno++);
                cout<<dfs(sx,sy)<<endl;
                // for (int i=1; i<=8; i++)
                //     for (int j=1; j<=8; j++)
                //         cout<<dist[i][j]<<" ";
            }
        // }




		return 0;
	}
