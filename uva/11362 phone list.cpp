#include<bits/stdc++.h>

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
#define lim 12
struct tree
{
    tree *node[lim];
    tree()
    {
        for(int i=0;i<lim;i++)
        {
            node[i]=NULL;
        }
    }
    bool endmark=false;
}*root;

bool flag;

void insert_node(char *st)
{
    int len=strlen(st);
    tree *temp;
    temp=root;
    int i;
    for(int j=0;j<len;j++)
    {
        i=st[j]-'0';
        if(temp->node[i]==NULL)
        {
            temp->node[i]=new tree();
        }
        if(temp->endmark==true) flag=false;
        temp=temp->node[i];
    }
    for(int i=0;i<lim;i++)
    {
        if(temp->node[i]!=NULL)
        {
            flag=false;
            break;
        }
    }
    temp->endmark=true;
}


void clear_nodes(tree *temp)
{

    for(int i=0;i<lim;i++)
    {
        if(temp->node[i]!=NULL) clear_nodes(temp->node[i]);

    }
    delete(temp);

}



int main()
{
   // freopen("in.txt","r",stdin);

    int cases,n;
    char ch[10009][12];
    scanf("%d",&cases);
    while(cases--)
    {
        root=new tree();
        scanf("%d",&n);
        getchar();
        flag=true;
        for(int i=0;i<n;i++)
        {
            gets(ch[i]);
            insert_node(ch[i]);
        }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        if(root!=NULL)
            clear_nodes(root);
    }



    return 0;
}

