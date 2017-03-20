#include<iostream>
#include<cstdio>
#include<string.h>


using namespace std;

int main()
{
    char c[1000];
    int a=0,b=0;
    int count=0,ans=0;

    while(scanf("%s",c)==1)
    {
        a=0;b=0;ans=0;
        int i=0,len=strlen(c);
        while(c[i]!='-' && c[i]!='+')
        {
            a=a*10+c[i++]-48;
        }
        char ch=c[i++];
        while(c[i]!='=')
        {
            b=b*10+c[i++]-48;
        }
        if(ch=='-') a=a-b;
        else a=a+b;
        i++;
        if(c[i]=='?') continue;

        while(i<len)
        {
            ans=ans*10+c[i++]-48;
        }

        if(a==ans) count++;
        cout<<count<<endl;
    }
    printf("%d\n",count);
    return 0;
}
