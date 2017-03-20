#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<iterator>
#include<cassert>

using namespace std;

#define ms(x,val) memset(x,val,sizeof(x))
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define repi(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define PII pair<int,int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999



int main()
{
	int n,left,right,num[1010];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}
	left=0;right=n-1;
	bool flag=true;
	int s=0,d=0;
	for(int i=0;i<n && left<=right;i++)
	{
	if(flag){
		if(flag && num[left]>num[right])
		{
			s+=num[left];
			left++;
			flag=false;
		}
		else if(flag)
		{
			s+=num[right];
			flag=false;
			right--;
		}
		}
		else
		{
			flag=true;
			if(num[left]>num[right])
			{
				d+=num[left];
				left++;
			}
			else d+=num[right--];
		}
	}
	cout<<s<<' '<<d<<endl;



	return 0;
}

