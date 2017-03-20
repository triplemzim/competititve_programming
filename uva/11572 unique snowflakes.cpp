#include<iostream>
#include<cstdio>
#include<map>
#include<vector>

using namespace std;

int main()
{

	int cases;
	long num,count,chain,i,j,last,temp2;
	vector<long> n;


	map<long long,long> track;

	long long temp;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%ld",&num);
		chain=0;count=0;last=0;
		for(i=1;i<=num;i++)
		{
			scanf("%lld",&temp);

			if(track[temp]!=0)
			{

				if(chain<count) chain=count;

				count=i-track[temp];
				temp2=track[temp];
				for(j=last;j<temp2;j++)
				{
					track[n[j]]=0;
				}
				last=temp2;

			}
			else count++;

			track[temp]=i;

			n.push_back(temp);
		}
		if(chain<count) chain=count;
		n.clear();
		track.clear();
		printf("%ld\n",chain);
	}
	return 0;
}
