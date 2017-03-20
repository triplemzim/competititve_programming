#include<bits/stdc++.h>
 
using namespace std;
 
 
#define ms(x,val) memset(x,val,sizeof(x))
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define pb push_back
#define PII pair<int,int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999
#define MAXN 1009
#define MOD 1000000007 // 10^9 + 7
 
int tree[MAXN][MAXN];
int maxval=1002;
 
void update(int x,int y,int val)
{
    int temp;
    while(x<=maxval)
    {
        temp=y;
        while(temp<=maxval)
        {
            tree[x][temp]+=1;
            temp+=(temp&-temp);
        }
        x+=(x&-x);
    }
}
 
int read(int x,int y)
{
    int sum=0;
    int temp=y;
    while(x>0 )
    {
        y=temp;
        while(y>0){
 
            sum+=tree[x][y];
            y-=(y&-y);
        }
        x-=(x&-x);
    }
    return sum;
}
       
 
int main()
{
//~    freopen("in.txt","r",stdin);
   
   
    int x,y,com,cases,q,a,b,caseno=1;
    scanf("%d",&cases);
    map< pair<int,int>, bool> mp;
    pair<int ,int > temp_p;
    while(cases--)
    {
        printf("Case %d:\n",caseno++);
        ms(tree,0);
        mp.clear();
        scanf("%d",&q);
        while(q--){
            scanf("%d %d %d",&com,&x,&y);
            x++;y++;
            if (com==0) {
                temp_p=MP(x,y);
                if(mp.find(temp_p)==mp.end()){
                    mp[temp_p]=true;
                    update(x,y,1);
                }
            }
            else {
                scanf("%d %d",&a,&b);
                a++;b++;
                printf("%d\n",read(a,b)-read(x-1,b)-read(a,y-1)+read(x-1,y-1));
            }
        }
    }
           
 
 
   
 
 
 
 
    return 0;
}