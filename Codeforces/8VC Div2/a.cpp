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
#define MAXN 1009
#define MOD 1000000007 // 10^9 + 7


int main()
{
	int r,c,n,K,a,b;
	int grid[11][11]={0};

	cin>>r>>c>>n>>K;
	for(int i=0;i<n;i++){
		scan(a);
		scan(b);
		grid[a-1][b-1]=1;
	}
	int ans=0;

	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			for(int k=i;k<r;k++){
				for(int l=j;l<c;l++){
					int count=0;
					for(int x=i;x<=k;x++){
						for(int y=j;y<=l;y++){
							count+=grid[x][y];
						}
					}
					if(count>=K) ans++;
				}
			}
		}
	}

	cout<<ans<<endl;

	return 0;
}
