#include<bits/stdc++.h>

using namespace std;


#define ms(x,val) memset(x,val,sizeof(x))
#define scan(x) scanf("%d",&x)
#define print(x) printf("debug= %d\n",x)
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define pb push_back
#define PII pair<int,int>
#define vi vecotr<int>
#define MAPL map<long long, int > 
#define MAPI map<int,int> 
#define MAPP map< pair<int,int> , int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999
#define MAXN 1000009
#define MOD 1000000007 // 10^9 + 7

int a[110],b[110],n,m,graph[110][110];
int store[110];

bool assign(bool seen[],int i)
{
    for (int  j = 0; j < m; j++) {
        if(graph[i][j]==1 && seen[j]==false)
        {
            seen[j]=true;
            if(store[j]<0 || assign(seen,store[j])==true)
             {
                 store[j]=i;
                 return true;
             }
        }
    }
    return false;
}




int bpm()
{
    int count=0;
    bool seen[110];
    ms(store,-1);
    for(int i=0;i<n;i++)
    {
        ms(seen,false);
        if(assign(seen,i)==true)
        {
            count++;
        }
//        else cout<<"painai"<<endl;
    }
    return count;
}

    

int main()
{
 //   freopen("in.txt","r",stdin);
   
    
    int cases,caseno=1;
    cin>>cases;
    while(cases--)
    {
        cin>>n;
        for (int  i = 0; i < n; i++) {
            cin>>a[i];
        }
        cin>>m;

        for (int  i = 0; i < m; i++) {
            cin>>b[i];
        }
        for(int i=0;i<n;i++)
        {
            for (int  j = 0; j < m; j++) {
                if(b[j]%a[i]==0)
                {
                    graph[i][j]=1;
                }
                else graph[i][j]=0;
            }
        }
        
        printf("Case %d: %d\n",caseno++,bpm());
    }



    return 0;
}
