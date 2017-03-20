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
#define vi vector<int>
#define MAPL map<long long, int > 
#define MAPI map<int,int> 
#define MAPP map< pair<int,int> , int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999
#define MAXN 1000009
#define MOD 1000000007 // 10^9 + 7

int cases,caseno=1,n;
char greed[30][30];
vector<pair<int,int> > ghost,human,graph[30];

void cal_pos()
{
    for (int  i = 0; i < n; i++) {
        for (int  j = 0; j < n; j++) {
            if(greed[i][j]=='G')
            {
                ghost.pb(MP(i,j));
            }
            else if(greed[i][j]=='H')
            {
                human.pb(MP(i,j));
            }
        }
    }
}

            
int fx[]={0,0,1,-1},fy[]={1,-1,0,0};
//int fx[]={0,0,1,-1,1,-1,-1,1},fy[]={1,-1,0,0,1,-1,1,-1};

bool possible(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=n || greed[x][y]=='#') return false;
    return true;
}

PII target;
bool color[30][30];

int path(int a,int b)
{
    if(target==MP(a,b)) return 0;
    if(color[a][b]==true) return -100;
    int temp=1<<10;
    bool flag=false;
    color[a][b]=true;
    for(int i=0;i<4;i++)
    {
        for (int  j = 0; j < 4; j++) {
            int x=a+fx[i],y=b+fy[j];
            if(possible(x,y))
            {
                if(path(x,y)==0)
                {
                    flag=true;
                    temp=min(temp,1+path(x,y));
                }
                
            }
        }
    }
    return flag?temp:-100;

}

int main()
{
    freopen("in.txt","r",stdin);
    
    
    scan(cases);
    while(cases--)
    {
        scan(n);
        getchar();
        for (int  i = 0; i < n; i++) {
            scanf("%s",greed[i]);
        }

        cal_pos();
        for (int  i = 0; i <(signed) ghost.size(); i++) {
            for (int  j = 0; j <(signed) human.size(); j++) {
                target=human[j];
                int temp=path(ghost[i].first,ghost[i].second);
                if(temp>0)
                {
                    cout<<"ghost: "<<ghost[i].first<<' '<<ghost[i].second<<endl;
                    cout<<"Human: "<<human[j].first<<' '<<human[j].second<<endl;
                    cout<<endl;
                    cout<<"temp: "<<temp<<endl;
//                    graph[i].pb(j);
                }
            }
        }
    }


    return 0;
}
