#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

int main()
{
    char ch[110];
    int gap,i;
    while(scanf("%d",&gap)==1 && gap)
    {
        scanf("%s",ch);
        int len=strlen(ch);


        gap=len/gap;
        for(i=gap-1;i<len;i+=gap)
        {
            for(int j=i;j>i-gap;j--)
            {
                printf("%c",ch[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
