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



int n,m,q,mat[555][555],mx;
int ar[555];

int calc(int row){
    int count=0,temp_mx=0;
    for(int i=1;i<=m;i++){
        if(mat[row][i]==0){
            temp_mx=max(count,temp_mx);
            count=0;
        }
        else count++;
    }
    temp_mx=max(count,temp_mx);
    ar[row]=temp_mx;

    mx=0;
    for(int i=1;i<=n;i++){
        mx=max(ar[i],mx);
    }

    return mx;
}




int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    scan(n);
    scan(m);
    scan(q);

    for (int  i = 0; i < n; i++) {
        for (int  j = 0; j < m; j++) {
            scanf("%d",&mat[i+1][j+1]);
        }
    }


    mx=0;
    int temp_mx=0;

    for(int i=1;i<=n;i++){
        int count=0;
        temp_mx=0;
        for(int j=1;j<=m;j++){
            if(mat[i][j]==0){
                temp_mx=max(count,temp_mx);
                count=0;
            }
            else count++;
        }
        temp_mx=max(temp_mx,count);
        ar[i]=temp_mx;
    }

    int a,b;

    while(q--){

        scan(a);
        scan(b);
        if(mat[a][b]==0) mat[a][b]=1;
        else mat[a][b]=0;
        printf("%d\n",calc(a));
    }






    return 0;
}
