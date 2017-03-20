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


// prefix tree for lowercase english letters only, lim is total number of elements;
#define lim 27


struct prefix_tree
{
    prefix_tree *node[lim];
    prefix_tree()
    {
        for(int i=0;i<lim;i++)
        {
            node[i]=NULL;
        }
    }
    bool endmark=false;
}*root;



void insert_node(char *st)
{
    int len=strlen(st);
    prefix_tree *temp;
    temp=root;
    int i;
    for(int j=0;j<len;j++)
    {
        i=st[j]-'a';
        if(temp->node[i]==NULL)
        {
            temp->node[i]=new prefix_tree();
        }

        temp=temp->node[i];
    }

    temp->endmark=true;
}


void clear_nodes(prefix_tree *temp)
{

    for(int i=0;i<lim;i++)
    {
        if(temp->node[i]!=NULL) clear_nodes(temp->node[i]);

    }
    delete(temp);

}

bool search_word(char *st)
{
    int len=strlen(st);
    int ch;
    prefix_tree *temp;
    temp=root;
    for(int i=0;i<len;i++)
    {
        ch=st[i]-'a';
        if(temp->node[ch]==NULL)
        {
            return false;
        }
        temp=temp->node[ch];
    }
    return temp->endmark;
}



int main()
{
    root=new prefix_tree();
    char ch[10];
    gets(ch);
    insert_node(ch);
    cout<<search_word("zim");
    clear_nodes(root);

    return 0;
}

