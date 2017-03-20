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

#define ms(x,val) memset(x,val,sizeof(x))
#define ull unsigned long long
#define iii long long

using namespace std;


int n,len[500009];

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>len[i];
	}
	sort(len,len+n);
//	for(int i=0;i<n;i++)
//	{
//		cout<<len[i]<<' ';
//	}
//	cout<<endl;
	int h=n,l=!(n%2) ? (n-1)/2 +1 : (n-1)/2,k=l;
	for(int i=0;i<=l;i++)
	{
		if(len[i]>0)
		{
			for(k=k;k<n;k++)
			{
				if(len[k]>0 && len[i]*2<=len[k])
				{
					len[k]=-1;
					h--;
					k++;
					break;
				}
			}
		}
	}


	cout<<h<<endl;


	return 0;
}



