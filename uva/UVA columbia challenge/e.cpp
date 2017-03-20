#include<bits/stdc++.h>

using namespace std;


#define ms(x,val) memset(x,val,sizeof(x))
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define pb push_back
#define PII pair<int,int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999
#define MAXN 1000009
#define MOD 1000000007 // 10^9 + 7


vector<int> cal_prefix_fun(string ch)
{
   int len=ch.length();
   int k=-1;
   vector<int> v(len,0);
   v[0]=-1;
//   cout<<ch<<endl;
   for(int i=1;i<len;i++)
   {
//       cout<<k<<endl;
       while(k>=0 && ch[k+1]!=ch[i]){ k=v[k];}
       
       
       if(ch[i]==ch[k+1]) k++;
       v[i]=k;
   }

   return v;
} 

int substring_match(string ST,string sub_st,int start)
{
//    if(sub_st=="") return start;
    vector<int> v;
    v=cal_prefix_fun(sub_st);
    int k=-1,len=ST.length(),m=sub_st.length();
    for(int i=start;i<len;i++)
    {
        while(k>=0 && ST[i]!=sub_st[k+1]){

             k=v[k];
        }
        if(sub_st[k+1]==ST[i]) k++;
        if(k==m-1)
        {
            return i+1;
        }
    }
//    cout<<"return korlam"<<endl;
    return len+1;
}


int main()
{
   freopen("in.txt","r",stdin);
     
     

    string Main,sub,temp;
    int cases,mlen,idx,last,len;
    bool flag;
    while(scanf("%d",&cases)==1)
    {
        cin>>Main;
        getchar();
        mlen=Main.length();
        temp="";
        while(cases--)
        {
            flag=true;
            getline(cin,sub);
//            cin>>sub;
            len=sub.length();
            last=idx=0;
            temp="";

            for(int i=0;i<len;i++)
            {
                if(sub[i]=='*' && temp!="")
                {
                    idx=substring_match(Main,temp,last);
//                    cout<<"flag: "<<Main<<' '<<sub<<' '<<temp<<' '<<idx<<endl;
                  
                    temp="";
                    if(idx==mlen+1)
                    {
                        flag=false;
                        break;
                    }
                    else last=idx;
                    
                }
                else if(sub[i]!='*') temp+=sub[i];
            }
            if(temp!="")
            {
                idx=substring_match(Main,temp,last);
//                cout<<"last: "<<temp<<' '<<idx<<endl;
                if(idx==mlen+1)
                {
                    flag=false;
                }
            }


            if(flag) printf("yes\n");
            else printf("no\n");
        }
    }


    return 0;
}
