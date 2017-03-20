#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;
vector<long int> v[1000001];

int main()
{

	int n,q;
	long num,k;
	while(scanf("%d%d",&n,&q)!=EOF)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%ld",&num);
			v[num].push_back(i);
		}

		while(q--)
		{
			scanf("%ld%ld",&k,&num);
			if(v[num].size()>=k)
			{
				printf("%ld\n",v[num][k-1]);
			}
			else
				printf("0\n");
		}
		memset(v,0,sizeof(v));
	}
	return 0;
}

//8 4
//1 3 2 2 4 3 2 1
//1 3
//2 4
//3 2
//4 2
