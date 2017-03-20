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
#define itr_all(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
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
int num[5009];
char ex[5009];
int len;

stack<iii> st1,st2;

iii calc(int x,int y)
{
//    printf(" ( %d %d )",x,y);
    iii val=0;

    for(int i=x-1;i<y;i+=2){
        st1.push(num[i]);
        if(i+1<y) st1.push(ex[i+1]);
    }

    while(st1.size()>1){
        iii a=st1.top();st1.pop();
        char ch=st1.top();st1.pop();
        

        if(ch=='*'){
            iii b=st1.top(); st1.pop();
            a*=b;
            st1.push(a);
        }
        else{
            val+=a;
        }
    }
    if(!st1.empty()){
        val+=st1.top();
        st1.pop();
    }
//    cout<<"step1: "<<val<<' ';
    

    for(int i=1;i<x-1;i++){
        if(i&1) st1.push(num[i]);
        else st1.push(ex[i]);
    }
    st1.push(val);
//    cout<<endl;
    for(int i=y;i<=len;i++){
        if(i&1) st1.push(num[i]);
        else st1.push(ex[i]);
//        if(i&1) cout<<st1.top();
//        else cout<<(char)st1.top();
    }

    val=0;
    while(st1.size()>1){
        iii a=st1.top();st1.pop();
        char ch=st1.top();st1.pop();
        

        if(ch=='*'){
            iii b=st1.top(); st1.pop();
            a*=b;
            st1.push(a);
        }
        else{
            val+=a;
        }
    }
    if(!st1.empty()){
        val+=st1.top();
        st1.pop();
    }


//    cout<<endl;

    return val;
}



        





int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    iii mx=0;
    string st;
    cin>>st;

    len=st.length();


    for (int  i = 0; i < len; i++) {
        if(i%2) ex[i+1]=st[i];
        else num[i+1]=st[i]-'0';
    }


    mx=calc(2,len+1);
//    cout<<"cur: "<<mx<<endl;
    vector<int> mul;
    mul.pb(0);
    

    for(int i=2;i<len;i+=2){
        if(ex[i]=='*') mul.pb(i);
    }
    mul.pb(len+1);


    iii temp;
    for(int i=0;i<(int)mul.size()-1;i++){
        for(int j=i+1;j<(int)mul.size();j++){
            temp=calc(mul[i]+2,mul[j]);
            
//            cout<<temp<<' ';
            mx=max(mx,temp);
        }
//        cout<<endl;
    }

    cout<<mx<<endl;

    return 0;
}
