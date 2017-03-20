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

int baad;
bool flag;
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

int substring_match(string ST,string sub_st)
{
//    if(sub_st=="") return start;
    int bad=baad;
    bool flg=false;
	int count=0;
    vector<int> v;
    v=cal_prefix_fun(sub_st);
    int k=-1,len=ST.length(),m=sub_st.length();
    for(int i=0;i<len;i++)
    {
        while(k>=0 && ST[i]!=sub_st[k+1]){

             k=v[k];
        }
        if(sub_st[k+1]==ST[i]) k++;
        if(k==m-1)
        {
            count++;
            k=v[k];
        }
    }
//    cout<<"return korlam"<<endl;
    return count;
}
    

int main()
{
    
    vector<int> v;
    v=cal_prefix_fun("mynameiskhan");
    for(int i=0;i<(int)v.size();i++)
     {
         cout<<v[i]<<' ';
     }
     cout<<endl;
     cout<<substring_match("mynamemymymymyan","my")<<endl;
    string s,p;
    cin>>s>>p;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        baad=i;
        int index=0,x=0;
        pair<int,int> pr[10000];
        for(int j=0;j<len;j++)
        {
               
            if(p[index]!=s[j])
            {
                baad--;
            }
            else if(p[index]==s[j])
            {
                index++;
            }
            
            if(index==len2)
            {
                pr[x++]=MP(baad,j);
            }
        }

    }
    cout<<endl;



    return 0;
}

