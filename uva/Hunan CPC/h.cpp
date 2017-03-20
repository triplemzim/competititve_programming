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
#define inf 9999999
#define MAXN 1000009
#define MOD 1000000007 // 10^9 + 7

template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}
char fd[]={'E','N','W','S'};
char dir[10000];
int len,min_x;

char go_left(char ch)
{
    switch(ch){
        case 'E':
            return 'N';
        case 'N': return 'W';
        case 'W': return 'S';
        case 'S': return 'E';
    }
    return 'a';
}
char go_right(char ch)
{
    switch(ch){
        case 'E': return 'S';
        case 'N': return 'E';
        case 'W': return 'N';
        case 'S': return 'W';
    }
    return 'a';
}
#define p1 1010
#define p2 30
int dp[p1][p2],dpx[p1][p2],dpy[p1][p2],dpyy[p1][p2];

int cal_min_x(int pos,char direction)
{
    if(pos==len)
    {
        return 0;
    }

    int temp_ret;
    int &ret=dp[pos][direction-'A'];

    if(ret!=inf) return ret;

    if(dir[pos]=='L')
    {
        temp_ret=cal_min_x(pos+1,go_left(direction));
    }
    else if(dir[pos]=='R')
    {
        temp_ret=cal_min_x(pos+1,go_right(direction));
    }
    else if(dir[pos]=='F')
    {
        
        if(direction=='E')
        {
            temp_ret=cal_min_x(pos+1,direction)+1;
        }
        else if(direction=='W')
        {
            temp_ret=cal_min_x(pos+1,direction)-1;
        }
        else
        {
            temp_ret=cal_min_x(pos+1,direction);
        }
    }
    else
    {
        temp_ret=cal_min_x(pos+1,go_left(direction));
        temp_ret=min(temp_ret,cal_min_x(pos+1,go_right(direction)));
        if(direction=='E')
        {
            temp_ret=min(temp_ret,cal_min_x(pos+1,direction)+1);
        }
        else if(direction=='W')
        {
            temp_ret=min(temp_ret,cal_min_x(pos+1,direction)-1);
        }
        else
        {
            temp_ret=min(temp_ret,cal_min_x(pos+1,direction));
        }
    }
    return ret=temp_ret;
}


int cal_max_x(int pos,char direction)
{
    if(pos==len)
    {
        return 0;
    }

    int temp_ret;
    int &ret=dpx[pos][direction-'A'];

    if(ret!=inf) return ret;

    if(dir[pos]=='L')
    {
        temp_ret=cal_max_x(pos+1,go_left(direction));
    }
    else if(dir[pos]=='R')
    {
        temp_ret=cal_max_x(pos+1,go_right(direction));
    }
    else if(dir[pos]=='F')
    {
        
        if(direction=='E')
        {
            temp_ret=cal_max_x(pos+1,direction)+1;
        }
        else if(direction=='W')
        {
            temp_ret=cal_max_x(pos+1,direction)-1;
        }
        else
        {
            temp_ret=cal_max_x(pos+1,direction);
        }
    }
    else
    {
        temp_ret=cal_max_x(pos+1,go_left(direction));
        temp_ret=max(temp_ret,cal_max_x(pos+1,go_right(direction)));
        if(direction=='E')
        {
            temp_ret=max(temp_ret,cal_max_x(pos+1,direction)+1);
        }
        else if(direction=='W')
        {
            temp_ret=max(temp_ret,cal_max_x(pos+1,direction)-1);
        }
        else
        {
            temp_ret=max(temp_ret,cal_max_x(pos+1,direction));
        }
    }
    return ret=temp_ret;
}



int main()
{
//	  ios::sync_with_stdio(false);
	  freopen("in.txt","r",stdin);
    int caseno=1;
    while(scanf("%s",dir)!=EOF)
    {
        for(int i=0;i<p1;i++)
        {
            for(int j=0;j<p2;j++)
            {
                dpx[i][j]=dp[i][j]=inf;
            }
        }
        len=strlen(dir);
        printf("Case %d: ",caseno++);
        int min_x=cal_min_x(0,'E');
//        cout<<min_x<<endl;
        cout<<min_x<<' '<<cal_max_x(0,'E')<<' ';
//        for(int i=0;i<p1;i++)
//        {
//            for(int j=0;j<p2;j++)
//            {
//                dpx[i][j]=dp[i][j]=inf;
//            }
//        }

        cout<<cal_min_x(0,'S')<<' '<<cal_max_x(0,'S')<<endl;
    }



    return 0;
}
