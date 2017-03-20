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
#define printv(vec) for(int i=0;i<vec.size();i++)cout<<vec[i]<<' ';cout<<endl;
#define itr_all(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define MAPL map<long long, int > 
#define MAPI map<int,int> 
#define MAPP map< pair<int,int> , int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999
#define MAXN 1000009
#define MOD 1000000007 // 10^9 + 7

template <class T> inline T bigmod(T p,T e,T M)
{
    iii ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}

iii costx[555555],costy[555555];

int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

	int n,a,b,T;
	string st;
	cin>>n>>a>>b>>T;
	cin>>st;

	iii time=0;

	iii ans=0;
	if(st[0]=='w') ans=b+1;
	else ans=1;
	for(int i=1;i<n;i++){
		if(st[i]=='w') ans+=b;

		ans+=a+1;
		costx[i-1]=ans;
	}
	
	if(st[0]=='w') ans=b+1;
	else ans=1;
	for(int i=n-1;i>0;i--){
		if(st[i]=='w') ans+=b;
		ans+=a+1;
		costy[n-i-1]=ans;
	}
	if(ans<=T){
		cout<<n<<endl;
		return 0;
	}

	if(st[0]=='w') ans=b+1;
	else ans=1;

	int mx=0;
	if(ans>T){
		cout<<0<<endl;
		return 0;
	}
	mx=1;
	time=ans;
	int count=0;

	if(st[0]=='w') ans=b+1;
	else ans=1;

	for(int i=0;i<n-1;i++){
		if(costy[i]<=T){
			count=i+2;
			time=costy[i]+(i+1)*a;
			time=T-time+ans;
			if(time>0){
				int low=0,high=n-1,mid;

				while(low<=high){
					mid=(low+high)/2;
					if(costx[mid]>time){
						high=mid-1;
					}
					else low=mid+1;
				}
				if(costx[high]<=time) count+=high+1;
			}

			mx=max(mx,count);
		}
		else break;
	}


	for(int i=0;i<n-1;i++){
		if(costx[i]<=T){
			count=i+2;
			time=costx[i]+(i+1)*a;
			time=T-time+ans;
			if(time>0){
				int low=0,high=n-1,mid;

				while(low<=high){
					mid=(low+high)/2;
					if(costy[mid]>time){
						high=mid-1;
					}
					else low=mid+1;
				}
				if(costy[high]<=time) count+=high+1;
			}

			mx=max(mx,count);
		}
		else break;
	}



	cout<<mx<<endl;
		



	



	return 0;
}
