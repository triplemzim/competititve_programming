#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;

    cin>>n>>k;

    int time;
    time = 4*60;
    time-=k;
    int x=0;
    for(int i=1;i<=n;i++){
        if(time-i*5>=0){
            time-=(i*5);
            x++;
        }
        else break;
    }
    cout<<x<<endl;

}
