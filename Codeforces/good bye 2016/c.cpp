#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long c,d,cur_rating,min_1,mx_2;
    mx_2=-1000000000;
    min_1=1000000000;


    cin>>n;
    bool inf_flag=true;

    for(int i=0;i<n;i++){


//        scanf("%lld %lld",&c,&d);
        cin>>c>>d;
        if(i==0){
//            if(d==2) cur_rating=-1;
//            else cur_rating=0;
            cur_rating=0;
            mx_2=-10000000000000;
            min_1=10000000000000;
        }


        if(d==2){
            inf_flag=false;
            mx_2=max(mx_2,cur_rating);
        }
        else{
            min_1=min(min_1,cur_rating);
        }
        cur_rating+=c;

    }

    if(inf_flag==true){
        cout<<"Infinity"<<endl;
    }
    else if(mx_2>min_1){
//        if(n==199897) cout<<mx_2<<' '<<min_1<<endl;
        cout<<"Impossible"<<endl;
    }
    else{
        int dif = 1899-mx_2;
        cur_rating+=dif;
        cout<<cur_rating<<endl;
    }

}
