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

iii n,chess[2001][2001];

iii fs[2001][2001],fe[2001][2001],gs[2001][2001],ge[2001][2001];

int main()
{
//    freopen("in.txt","r",stdin);
    
    
    scanf("%I64d",&n); 
    for (int  i = 0; i < n; i++) {
        for (int  j = 0; j < n; j++) {
            scanf("%I64d",&chess[i][j]);
        }
    }

    for (int  i = 0; i < n; i++) {
        ge[n-1][i]=chess[n-1][i];
    }

    for (int  i = 1; i < n; i++) {
        for (int  j = 0; j < n; j++) {
            fs[i][j]=(j-1>=0 ? fs[i-1][j-1]+chess[i-1][j-1] : 0) ;gs[i][j]= (j+1<n ? gs[i-1][j+1]+chess[i-1][j+1] :0);
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        for (int  j = 0; j < n; j++) {
            fe[i][j]=(j-1>=0? fe[i+1][j-1]+chess[i+1][j-1]: 0) ; ge[i][j]= (j+1<n? ge[i+1][j+1] : 0) +chess[i][j];
        }
    }

//    cout<<fs[3][1]+fe[3][1]-fe[3][1]<<endl;
    iii max_black=-1,max_white=-1,x,y,xx,yy,temp;
    bool flag=false;
    for (int  i = 0; i < n; i++) {
        if((n&1)==0) flag=!flag;
//        cout<<endl;
        for (int  j = 0; j < n; j++) {
            temp=fs[i][j]+fe[i][j]+gs[i][j]+ge[i][j];
//            cout<<flag<<' ';

            if(flag)
            {
                flag=false;
                if(temp>max_white)
                 {
                     max_white=temp;
                     x=i;y=j;
                 }
            }
            else
            {
                flag=true;
                if(temp>max_black)
                {
                    max_black=temp;
                    xx=i;yy=j;
                }
            }
        }
    }
    cout<<max_white+max_black<<endl;
    cout<<x+1<<' '<<y+1<<' '<<xx+1<<' '<<yy+1<<endl;
                

            
        

    return 0;
}
