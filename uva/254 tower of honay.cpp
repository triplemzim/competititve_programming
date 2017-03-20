#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int tell(int a, int b)
{
	int s=min(a,b);
	a=max(a,b);
	if(s==1 && a==2) return 0;
	if(s==0 && a==2) return 1;
	if(s==0 && a==1) return 2;
}

int main()
{
	char num[100];
	int bin[1000],n[100];
	int i,bin_index,going_to,len,temp,total,index,carry,last_pos,a[4],b,c;
	while(scanf("%d %s",&a[0],num)==2)
	{
		len=strlen(num);
		if(len==1 && num[0]=='0'&& a[0]==0) break;

		for(i=0;i<len;i++)
		{
			n[i]=(int)num[i]-48;
		}

		bin_index=0;
		len--;
		if(len==0 && num[0]=='0')
		{
			printf("%d 0 0\n",a[0]);
			continue;
		}
		while(len>=0)
		{

			if(n[len]%2==1)
			{
				bin[bin_index++]=1;
			}
			else bin[bin_index++]=0;

			index=0;carry=0;bool flag=false;

			for(i=0;i<=len;i++)
			{
				n[i]+=(10*carry);
				carry=n[i]%2;
				if(!flag && n[i]<2) continue;
				flag=true;
				n[index++]=n[i]/2;


			}

			len= index-1;
		}

		bin_index--;
//		cout<<bin_index<<endl;
		last_pos=0;
		a[1]=a[2]=0;

		if(1)
		{
			while(bin_index>=0)
			{
				if((bin_index)%2==1)
				{
					going_to=(last_pos+1)%3;
					a[going_to]+=bin_index;
					a[last_pos]-=(bin_index+1);
					a[tell(last_pos,going_to)]++;

					last_pos=going_to;
				}
				else
				{
					going_to=(last_pos+2)%3;
					a[going_to]+=bin_index;
					a[last_pos]-=(bin_index+1);
					a[tell(last_pos,going_to)]++;
					last_pos=going_to;
				}

				bool flag=false;
				for(int i=bin_index-1;i>=0;i--)
				{
					if(bin[i])
					{
						bin_index=i;
						flag=true;
						break;
					}

				}
				if(!flag) break;


			}
		}
		cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
	}
	return 0;
}



