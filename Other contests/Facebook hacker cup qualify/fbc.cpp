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

int cases,caseno=1,m,n;
char grid[110][110];

int fx[]={0,0,1,-1},fy[]={1,-1,0,0};
bool check(int x,int y)
{
    if(x<0 || y<0 || x>=m || y>=n || grid[x][y]=='#') return false;
    if(grid[x][y]=='.' || grid[x][y]=='S' || grid[x][y]=='G') return true;
    return false;
}

bool laser(char ch){ if(ch=='<' || ch=='>' || ch=='^' || ch=='v') return true;
    return false;
}

char cal_dir(char ch,int step)
{
    int pos;
    if(ch=='<') pos=1;
    else if(ch=='^') pos=2;
    else if(ch=='>') pos=3;
    else pos=4;

    pos=pos+step%4;
    if(pos>4) pos%=4;
    if(pos==1) return 'l';
    if(pos==2) return 'u';
    if(pos==3) return 'r';
    return 'd';
}




bool notDead(int x,int y,int step)
{
    bool flag=false;
    for(int i=y;i<n;i++)
    {
        if(flag) break;
        if(grid[x][i]=='#' || laser(grid[x][i])==true)
        {
            flag=true;
        }
        if(laser(grid[x][i]))
        {
            if(cal_dir(grid[x][i],step)=='u') return false;
        }
    }
    flag=false;
    for(int i=y;i>=0;i--){
        if(flag) break;
        if(grid[x][i]=='#' || laser(grid[x][i])==true)
        {
            flag=true;
        }
        if(laser(grid[x][i]))
        {
            if(cal_dir(grid[x][i],step)=='d') return false;
        }
    }
    flag=false;
    for(int i=x;i<m;i++){
        if(flag) break;
        if(grid[i][y]=='#' || laser(grid[i][y])==true)
        {
            flag=true;
        }
        if(laser(grid[i][y])==true)
        {
            if(cal_dir(grid[i][y],step)=='l') return false;
        }
    }
    for(int i=x;i>=0;i--){
        if(flag) break;
        if(grid[i][y]=='#' || laser(grid[i][y])==true)
        {
            flag=true;
        }
        if(laser(grid[i][y])==true)
        {
            if(cal_dir(grid[i][y],step)=='r') return false;
        }
    }
    return true;
}
        
        

int bfs(int x,int y)
{
    queue<PII > q;
    PII p; 
    bool color[110][110]={false};
    int dist[110][110]={0},temp_x,temp_y;
    
    q.push(MP(x,y));
    while(!q.empty()){
        p=q.front();
        q.pop();
        x=p.first;
        y=p.second;

        if(grid[x][y]=='G') return dist[x][y];

        for (int  i = 0; i < 4; i++) {
            temp_x=x+fx[i];
            temp_y=y+fy[i];

            if(check(temp_x,temp_y)==true && color[temp_x][temp_y]==false)
            {
                if(notDead(temp_x,temp_y,dist[x][y]+1)==true)
                {
                    color[temp_x][temp_y]=true;
                    q.push(MP(temp_x,temp_y));
                    dist[temp_x][temp_y]=dist[x][y]+1;
                }
            }
        }
    }
    return -1;
}

            


int main()
{
//	  ios::sync_with_stdio(false);
	  freopen("in.txt","r",stdin);

    scan(cases);
    while(cases--)
    {
        scan(m);
        scan(n);
        getchar();
        for (int  i = 0; i < m; i++) {
            scanf("%s",grid[i]);
        }
        int start_x,start_y;

        for(int i=0;i<m;i++){
            for (int  j = 0; j < n; j++) {
                if(grid[i][j]=='S'){
                    start_x=i;
                    start_y=j;
                }
            }
        }
        int move=bfs(start_x,start_y);

        if(move!=-1){
            printf("Case #%d: %d\n",caseno++,move);
        }
        else printf("Case#%d: impossible\n",caseno++);
    }


    



    return 0;
}                   
