#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,count;
	string st[111];

	cin>>n;

	for(int i=0;i<n;i++){
		cin>>st[i];
	}

	count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(st[i][j]=='C'){
				for(int k=i+1;k<n;k++){
					if(st[k][j]=='C') count++;
				}
				for(int k=j+1;k<n;k++){
					if(st[i][k]=='C') count++;
				}
			}
		}
	}


	cout<<count<<endl;

	return 0;
}
