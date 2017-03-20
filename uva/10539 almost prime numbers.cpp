#include<iostream>
#include<cstdio>
#include<string.h>
#include<math.h>
#include<vector>
#define check(n,pos) (bool(n & (1<<pos)))
#define set(n,pos) (n | (1<<pos))
#define num sqrt(1000000000000)+1
using namespace std;

int pt(long x)
{
if(x<3 || x==4) return 0;
        int k=sqrt(x);
        for(int i=3;i<=k;i+=2)
        {
            if(x%i==0) return 0;
        }
        return 1;

}



int main()
{
    long long i,j,k=0;
    long status[10000000/32+5];

    vector<long> p;
    vector<long> track;
//    track.push_back(0);
//    track.push_back(0);
//    track.push_back(0);
//    prime.push_back(1);
    p.push_back(2);

    for(i=3;i<num;i+=2)
    {
        if(check(status[i>>5],(i&31))==0)
        {
			k=i<<1;
			p.push_back(i);
            for(j=i*i;j<num;j+=k)
            {
                status[j>>5]=set(status[j>>5],(j&31));
            }
        }
//        track.push_back(k);
//        track.push_back(k);
    }
    unsigned long long mul,low,high,sum;
    int cases,count;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%llu%llu",&low,&high);
        count=0;
        int sq=sqrt(high);
        double cube=cbrt(high);
//        cout<<cube;
        for(i=0;p[i]<=sq;i++)
        {
			mul=p[i];
			sum=mul;

//			if(mul<=cube)
				unsigned long long lim=high/mul;
				while(sum<=lim)
				{
					sum*=mul;
					if(sum>=low) count++;


					cout<<mul<<" "<<sum<<" "<<count<<endl;
				}
//			else if(sum<=high) count++;
		}
        cout<<count<<endl;


    }
    return 0;
}

