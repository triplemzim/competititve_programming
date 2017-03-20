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


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int n,num[310],pos[310];
    char mat[310][310];
    scan(n);
    for (int  i = 0; i < n; i++) {
        cin>>num[i];
        pos[num[i]]=i;
    }
    getchar();
    for (int  i = 0; i < n; i++) {
            gets(mat[i]);
//            printf("this: %s\n",mat[i]);
    }


    for(int k=0;k<n;k++)
    {
        int i=pos[k+1];

        bool flag=true;
        while(flag)
        {
            flag=false;
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]=='1')
                {
                    if(num[i]<num[j] && j<i)
                    {
                        swap(pos[num[i]],pos[num[j]]);
                        swap(num[i],num[j]);
                        i=pos[num[j]];
                        flag=true;
                    }
                    if(num[i]>num[j] && j>i)
                    {
                        swap(pos[num[i]],pos[num[j]]);
                        swap(num[i],num[j]);
                        i=pos[num[j]];
                        flag=true;
                    }
                }
            }
        }
    }


//        for(int j=0;j<i;j++)
//        {
//            if(mat[i][j]=='1')
//            {
//                if(i<j && num[i]>num[j])
//                {
//                    swap(pos[num[i]],pos[num[j]]);
//                    swap(num[i],num[j]);
//                    i=pos[num[j]];
//                    j=0;
////                    break;
//
//                }
////                if(i>j && num[i]<num[j])
////                {
////                    swap(pos[num[i]],pos[num[j]]);
////                    swap(num[i],num[j]);
////                    break;
////                }
//            }
//        }
//    }

    for(int i=0;i<n;i++) cout<<num[i]<<' ';
    cout<<endl;



    return 0;
}
