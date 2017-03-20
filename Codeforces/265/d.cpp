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

class point{
    public:
        iii a,b,c;
        friend double dist(point t,point temp)
        {
            return sqrt( (temp.a-t.a)*(temp.a-t.a)+(temp.b-t.b)*(temp.b-t.b)+(temp.c-t.c)*(temp.c-t.c));
        }
};


point v[9][7];
//vector<point>v[10];
double d[65];

int cnt=0;
point sending[9],ans[9];

bool test_cube()
{
    int in=0; 
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(i!=j){
//                cnt++;
                d[in++]=(dist(sending[i],sending[j]));
            }
        }
    }

    sort(d,d+in);

    if(absolute(d[0]-d[23])>=.01 || absolute(d[24]-d[47])>=.01) return false;

    if((2)*d[0]*d[0]-d[24]*d[24]>=.01 || absolute(d[0])<=0.01 || absolute(d[24])<=0.01) return false;

    if(d[48]*d[48]-(d[0]*d[0]+d[24]*d[24])>=.01) return false;
            

    return true;
}


//vector<point> sending,ans;

bool flag=false;
void add(int i)
{
    
    if(flag==true) return;
    if(i>7 ){
//        cnt++;
        if(test_cube()==true)
        {
            for (int  i = 0; i < 8; i++) {
                ans[i]=sending[i];
            }
            flag=true;
        }
        return;
    }

    for(int m=0;m<6;m++)
    {
        sending[i]=v[i][m];
        add(i+1);
    }
}


int main()
{
    freopen("in.txt","r",stdin);
    
    
    point temp;
    iii a,b,c;
    int in=0;
    for (int  i = 0; i < 8; i++) {
//        scanf("%I64d %I64d %I64d",&a,&b,&c);
//        scanf("%lld%lld%lld",&a,&b,&c);
        cin>>a>>b>>c;
        in=0;
        temp.a=a;
        temp.b=b;
        temp.c=c;
//        debug(temp.c);
        v[i][in++]=(temp);

        temp.a=a;
        temp.b=c;
        temp.c=b;
        v[i][in++]=(temp);

        
        temp.a=b;
        temp.b=a;
        temp.c=c;
        v[i][in++]=(temp);
    
    
        temp.a=b;
        temp.b=c;
        temp.c=a;
        v[i][in++]=(temp);


        temp.a=c;
        temp.b=a;
        temp.c=b;
        v[i][in++]=(temp);


        temp.a=c;
        temp.b=b;
        temp.c=a;
        v[i][in++]=(temp);


    }
    sending[0]=v[0][0];
//    vector<point> p;
//    for(int i=0;i<8;i++) p.pb(v[i][0]);
//    flag=test_cube(p);
//    ans=p;

    add(1);
//    cout<<"count: "<<cnt<<endl;
    

    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

//    cout<<"gadha: "<<ans[0].c<<endl;
//    printf("%lld\n",ans[0].c);

    if(flag)
    for(int i=0;i<8;i++)
    {
        cout<<ans[i].a<<' '<<ans[i].b<<' '<<ans[i].c<<endl;
    }



    return 0;


}



