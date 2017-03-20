#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;


int main()
{
	int track[35],stk[35],index,temp;
	char c;
	while(scanf("%d",&temp)!=EOF)
	{
		scanf("%c",&c);
		index=1;
		stk[temp]=index;
		track[index++]=temp;
		while((int)c!=10)
		{
			scanf("%d%c",&temp,&c);
			stk[temp]=index;
			track[index++]=temp;
		}
		index--;
		int flip;
		for(int i=index;i>0;i--)
		{
			if(stk[i]!=i)
			{
				flip=stk[i];
				if(flip!=1) cout<<"1st "<<stk[i]<<" ";
				for(int j=flip;j>=flip/2;j--)
				{
					temp=stk[j];
					stk[j]=stk[flip-j+1];
					stk[flip-j+1]=temp;
					temp=track[j];
					track[j]=track[flip-j+1];
					track[flip-j+1]=temp;;
				}
				cout<<"list: "<<stk[5]<<stk[4]<<stk[3]<<stk[1]<<endl;
				flip=i;
				cout<<"2nd "<<flip<<" ";
				for(int j=i;j>=i/2;j--)
				{
					temp=stk[j];
					stk[j]=stk[flip-j+1];
					stk[flip-j+1]=temp;
					temp=track[j];
					track[j]=track[flip-j+1];
					track[flip-j+1]=temp;
				}
				cout<<"list: "<<stk[5]<<stk[4]<<stk[3]<<stk[1]<<endl;

			}
		}
		cout<<endl;
//		cout<<temp<<endl;

	}
	return 0;
}
