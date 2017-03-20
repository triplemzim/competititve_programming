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

int tree[MAXN][MAXN];
int mx_x,mx_y;       //must be defined elsewhere

void update(int x,int y,int val)
{
	int temp_y=y;
	while(x<=mx_x){
		y=temp_y;;
		while(y<=mx_y){
			tree[x][y]+=val;
			y+=(y&-y);
		}
		x+=(x&-x);
	}
}

int read(int x,int y)
{
	int sum=0;
	int temp_y=y;
	while(x>0){
		y=temp_y;
		while(y>0){
			sum+=tree[x][y];
			y-=(y&-y);
		}
		x-=(x&-x);
	}
	return sum;
}


int calc(int x)
{
	int count=0;
	while(x>0 && x%5==0){
		count++;
		x/=5;
	}
	return count;
}



int n,temp;
vector<iii> v;
map<iii,int> mp,mpc;
map<pair<iii,iii>,bool> track;

int main()
{

	scan(n);


	for(int i=0;i<n;i++){
		scan(temp);
		v.pb(temp);
		mp[temp]++;
		
	}
	int ans=2;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j) continue;
			iii a,b,c;
			a=v[i];
			b=v[j];
			if(track.find(MP(a,b))!=track.end()) continue;

			int count=2;
			mpc.clear();
			mpc[a]=mp[a]-1;
			if(mpc.find(b)==mpc.end()) mpc[b]=mp[b]-1;
			else mpc[b]--;
			track[MP(a,b)]=true;

			while(true){
				if(mp.find(a+b)==mp.end()) break;
				else {
					c=a+b;
					if(mpc.find(c)==mpc.end())mpc[c]=mp[c];
					if(mpc[c]==0) break;
					mpc[c]--;
					count++;
					a=b;
					b=c;
					//cout<<"mpc: "<<mpc[c]<<endl;
				}
			}
			ans=max(ans,count);
		}
	}

	cout<<ans<<endl;





	
	


	return 0;
}

