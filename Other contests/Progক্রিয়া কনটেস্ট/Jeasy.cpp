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

struct stck{
    public:
        int val;
        stck *prev=NULL,*last=NULL,*next=NULL;
        stck(){
            last=this;
            prev=this;
            val=-1;
        }
};



int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int cases;
    int qno,op;
    scan(cases);
    int caseno=1;
    while(cases--){
        stck *st[100009];
        scan(qno);
        scan(op);
        for (int  i = 0; i < 2+qno; i++) {
            st[i]=new stck();
        }
        string ch;
        int q1,q2;
        stck *temp;
        printf("Case %d:\n",caseno++);
        while(op--){
            cin>>ch>>q1;
            
            if(ch=="push"){
                cin>>q2;
                if(st[q1]==NULL) st[q1]=new stck();
                temp=new stck();
                temp->val=q2;
                temp->prev=st[q1]->last;
                st[q1]->last->next=temp;
                st[q1]->last=temp;
            }
            else if(ch=="top"){
                if(st[q1]==st[q1]->last){
                    cout<<"Empty!"<<endl;
                    continue;
                }
                cout<<st[q1]->last->val<<endl;
            }
            else if(ch=="pop")
            {
                if(st[q1]==st[q1]->last) continue;
                temp=st[q1]->last;
                st[q1]->last=temp->prev;
                st[q1]->last->next=NULL;
                delete temp;
            }
            else if(ch=="put"){
                cin>>q2;
                
                if(st[q2]==st[q2]->last){
                    continue;
                }
                
                if(st[q1]==st[q1]->last) {
                    st[q1]=st[q2];
                    st[q1]->last=st[q2]->last;
                    st[q1]->prev=st[q2]->prev;
                    st[q1]->val=st[q2]->val;
                }
                else{
//                    cout<<"here"<<endl;
                    st[q2]->next->prev=st[q1]->last;
                    st[q1]->last=st[q2]->last;
                }
                st[q2]=new stck();
               
            }
                

        }


    }




    return 0;
}
