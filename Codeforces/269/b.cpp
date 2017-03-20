#include<bits/stdc++.h>

using namespace std;


#define ms(x,val) memset(x,val,sizeof(x))
#define scan(x) scanf("%d",&x)
#define scanL(x) scanf("%I64d",&x)
#define print(x) printf("%d\n",x)
#define debug(x) printf("DEBUG: %d\n",x)
#define printL(x) printf("%I64d\n",x)
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define pb push_back
#define PII pair<int,int>
#define vi vector<int>
#define MAPL map<long long, int > 
#define MAPI map<int,int> 
#define MAPP map< pair<int,int> , int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999
#define MAXN 1000009
#define MOD 1000000007 // 10^9 + 7

template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}

struct ob{
    int a,b;
    bool operator<(const ob temp)const { return a<temp.a;}
};
int main()
{
//    vector<ob> t;
//    ob x;
//    x.a=1;
//    x.b=1;
//    t.pb(x);
//    x.a=3;
//    x.b=2;
//    t.pb(x);
//    x.a=3;
//    x.b=3;
//    t.pb(x);
//    x.a=1;
//    x.b=4;
//    t.pb(x);
//    sort(t.begin(),t.end());
//    next_permutation(t.begin(),t.end());
//    for(int i=0;i<(int) t.size();i++)
//    {
//        cout<<t[i].b<<endl;
//    }
    vector< PII > v;
    PII temp;
    int n;
    int count[2010]={0};
    cin>>n;
    for (int  i = 0; i < n; i++) {
        cin>>temp.first;
        temp.second=i+1;
        v.pb(temp);
        count[temp.first]++;
    }
    sort(v.begin(),v.end());

    int test=1;
    bool flag=false;
    int c=0;
    for(int i=0;i<2001;i++)
    {
        if(count[i]>2) c++;
        if(count[i]>2)
        {
            flag=true;
            break;
        }
        else if(count[i]>1)
        {
            test*=2;
            if(test>2)
            {
                flag=true;
                break;
            }
        }
    }
    if(flag==false)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<(int)v.size();i++)
        {
            cout<<v[i].second<<' ';
        }
        cout<<endl;
        for(int i=0;i<(int)v.size();i++)
        {
            for(int j=i+count[v[i].first]-1;j>i-1 && v[i].first==v[j].first;j--)
            {
                cout<<v[j].second<<' ';
            }
            i+=count[v[i].first]-1;
        }
        cout<<endl;
        if(c==0)
        for(int i=0;i<(int)v.size();i++)
        {
            if(count[v[i].first]>1) flag=false;
            for(int j=i+count[v[i].first]-1;j>i-1 && v[i].first==v[j].first;j--)
            {
                cout<<v[j].second<<' ';
            }
            i+=count[v[i].first]-1;
            if(flag==false)
            {
                for(i=i+1;i<(int)v.size();i++)
                {
                    cout<<v[i].second<<' ';
                }
                break;
            }
        }
        else
        {
            for(int i=0;i<(int)v.size();i++)
            {
                if(count[v[i].first]>2)
                {
                    PII x=v[i];
                    v[i]=v[i+1];
                    v[i+1]=x;
                    break;
                }
            }
            for(int i=0;i<(int)v.size();i++)
            {
                cout<<v[i].second<<' ';
            }
            cout<<endl;
        }


            

//        for(int i=0;i<(int)v.size();i++)
//        {
//            if(count[v[i].first]>1)
//            {
//                next_permutation(v.begin()+i,v.begin()+i+count[v[i].first]);
//                break;
//
//            }
//        }
//        for (int  i = 0; i < (int)v.size(); i++) {
//            cout<<v[i].second<<' ';
//        }
//        cout<<endl;
//        flag=false;
//        for(int i=0;i<(int)v.size();i++)
//        {
//            if(count[v[i].first]>1)
//            {
//                if(flag)
//                {
//                    next_permutation(v.begin()+i,v.begin()+i+count[v[i].first]);
//                    break;
//                }
//                flag=true;
//            }
//        }
//        
//        for (int  i = 0; i < (int)v.size(); i++) {
//            cout<<v[i].second<<' ';
//        }
//        cout<<endl;
    }



    return 0;
}
