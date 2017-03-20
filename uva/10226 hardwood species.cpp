//AC
// most Khaista problem ever :(
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
#define lim 256


struct prefix_tree
{
    prefix_tree *node[lim];
    int cnt=0;
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
        i=st[j];
        if(temp->node[i]==NULL)
        {
            temp->node[i]=new prefix_tree();
        }

        temp=temp->node[i];
    }
    temp->endmark=true;
    temp->cnt++;
}


void clear_nodes(prefix_tree *temp)
{

    for(int i=0;i<lim;i++)
    {
        if(temp->node[i]!=NULL) clear_nodes(temp->node[i]);

    }
    delete(temp);

}


int total;
void print(prefix_tree *temp,string ch)
{
    prefix_tree *t;
    t=temp;
    string s=ch;
    for(int i=0;i<lim;i++)
    {
        s=ch;
        if(temp->node[i]!=NULL)
        {
            t=temp->node[i];
            s+=(char)(i);
            if(t->endmark==true && total !=0)
            {
                cout<<s<<' ';
                printf("%.4lf\n",(double)((double)(t->cnt)/(double)(total) * (double)100 ));
            }
            print(t,s);
        }
    }
}

int main()
{

//    freopen("in.txt","r",stdin);
    int cases;
    char name[100];
    cin>>cases;
    int index=0;
    getchar();
    getchar();

    total=0;
    root=new prefix_tree();

    while(cases--)
    {
        do{
            if(gets(name)==NULL)
            {
                print(root,"");
                return 0;
            }

            for(int i=strlen(name)-1;i>=0;i--)
            {
                if(name[i]!=' ')
                {
                    name[i+1]='\0';
                    break;
                }
            }


            if(strlen(name)==0)
            {
                print(root,"");
                if(cases) cout<<endl;

                total=0;
                if(root!=NULL) clear_nodes(root);
                root=new prefix_tree();
                break;
            }

            total++;
            insert_node(name);
            index++;
        }while(true);
    }


    return 0;
}

