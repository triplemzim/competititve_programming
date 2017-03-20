#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

int main()
{
    int n,i;
    string song[]={"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

    char name[110][110];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",name[i]);
    }
    int j=0;
    for(i=0;i<n;i++)
    {
        cout<<name[i]<<": "<<song[j++]<<endl;
        if(j>15) j=0;
    }
    i=0;
    for(int k=j;k<16;k++)
    {
        cout<<name[i++]<<": "<<song[k]<<endl;
        if(i>=n) i=0;
    }
    return 0;
}
