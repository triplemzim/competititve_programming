// verdict: TLE


#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<iterator>
#include<cassert>

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





int main()
{
	set<string> st;
	set<string> temp_st;
	set<string> st2;
	string s,a,b;
	cin>>a>>b;

//	st.insert(a);

	set<string>::iterator it;
	//it=st.begin();

//	s=*it;
//	cout<<s;

	int len1=a.length(),len2=b.length();

	int temp_len=0;

	for(int i=0;i<len1;i++)
	{
		s="";
		for(int j=i;j<len1;j++)
		{
			s+=a[j];

			if(st.find(s)!=st.end()) temp_st.insert(s);
			else st.insert(s);

		}

	}
	set<string>::iterator temp_it;

	for(it=temp_st.begin();it!=temp_st.end();it++)
	{

		st.erase(st.find(*it));
	}

	temp_st.clear();

	int len=st.size();

	temp_len=0;

	for(int i=0;i<len2;i++)
	{
		s="";
		for(int j=i;j<len2;j++)
		{
			s+=b[j];
	//		cout<<s<<endl;

			if(st2.find(s)!=st2.end())	temp_st.insert(s);
			else st2.insert(s);

		}

	}

	for(it=temp_st.begin();it!=temp_st.end();it++)
	{
		st2.erase(st2.find(*it));
	}

	bool flag=false;
	int temp=0;



	temp=5010;
	for(it=st2.begin();it!=st2.end();it++)
	{
		if((*it).length()<temp)
		if( st.find(*it)!=st.end())
		{

			s=*it;
			temp=s.size();


			flag=true;

		}
	}

//	cout<<s<<endl;

	if(flag) cout<<s.size()<<endl;
	else cout<<-1<<endl;

	return 0;
}
//
//

//#include <cstdio>
//#include <cstring>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//    char a[5002],b[5002];
//    gets(a);
//    gets(b);
//    int x= strlen(a);
//    int y= strlen(b);
//    vector <int> v[x];
//    int s[x];
//    int z[y];
//    memset(s, 0, sizeof(s));
//    memset(z, 0 ,sizeof(z));
//    for(int i=0; i<x; i++)
//    {
//        //printf("1 %d %d\n",i,s[i]);
//        for(int j=i+1; j<x; j++)
//        {
//            if(a[i]==a[j])
//            {
//                int cnt=0;
//                for(int k=0; k<x-j; k++)
//                {
//                    if(a[i+k]== a[j+k])
//                    {
//                        cnt++;
//                    }
//                    else break;
//                }
//                if(cnt>s[j]) s[j]=cnt;
//                if(cnt>s[i])
//                {
//                    s[i]= cnt;
//                }
//                //printf("   %d %d\n",j,s[j]);
//            }
//        }
//        //printf("i %d %d\n",i,s[i]);
//        for(int j=0; j<y; j++)
//        {
//            if(a[i]==b[j])
//            {
//                v[i].push_back(j);
//            }
//        }
//    }
//    for(int i=0; i<y; i++)
//    {
//        for(int j=i+1; j<y; j++)
//        {
//            if(b[i]==b[j])
//            {
//                int cnt=0;
//                for(int k=0; k<y-j; k++)
//                {
//                    if(b[i+k]== b[j+k])
//                    {
//                        cnt++;
//                    }
//                    else break;
//                }
//                if(cnt>z[j]) z[j]=cnt;
//                if(cnt>z[i])
//                {
//                    z[i]= cnt;
//                }
//                //printf("   %d %d\n",j,z[j]);
//            }
//        }
//        //printf("iz %d %d\n",i,z[i]);
//        for(int j=0; j<y; j++)
//        {
//            if(a[i]==b[j])
//            {
//                v[i].push_back(j);
//            }
//        }
//    }
//
//    int ans=6000;
//    for(int i=0; i<x; i++)
//    {
//        for(int j=0; j<v[i].size(); j++)
//        {
//            int cn=0;
//            for(int k=0; ; k++)
//            {
//                if(i+k==x || v[i][j]+k==y) break;
//                if(a[i+k]== b[v[i][j]+k])
//                {
//                    cn++;
//                }
//                else break;
//            }
//            int mx= max(s[i], z[v[i][j]]);
//            //printf("  %d %d %d %d %d\n",i, v[i][j],s[i], z[v[i][j]],mx);
//            if(cn>mx)
//            {
//                if(ans>mx+1)
//                {
//                    ans=mx +1;
//                    //printf("           %d\n",ans);
//                }
//                break;
//            }
//        }
//    }
//    if(ans<6000) printf("%d",ans);
//    else printf("-1");
//}
//

//
//#include <stdio.h>
//#include <string.h>
//#include <algorithm>
//#include <iostream>
//#include <vector>
//#include <string>
//
//
//#define SZ 5007
//using namespace std;
//
//struct Tree
//{
//    short first , second;
//    struct Tree* Child[26];
//    Tree()
//    {
//        first = 0; second = 0;
//        for(int i=0;i<26;i++) Child[i] = 0 ;
//    }
//};
//
//
//typedef Tree* TreePtr;
//
//char str1[2][SZ+7];
//
//TreePtr root;
//
//void Go(TreePtr cur,int t,int pos)
//{
//    if(cur!=root) {
//        if(t==0) cur->first++;
//        else cur->second++;
//    }
//    if(str1[t][pos] == 0 )    {
//
//        return ;
//    }
//    int ps = str1[t][pos] - 'a';
//    if(cur->Child[ps]==0) cur->Child[ps] = new Tree();
//    Go(cur->Child[ps] ,t , pos+1 );
//
//}
//
//int ans;
//
//void Calc(TreePtr cur,int pos) {
//    if(cur==NULL)   return ;
//    if(cur->first ==1 && cur->second == 1) {
//        if(ans==-1) ans = pos;
//        else ans = min(ans , pos);
//    }
//    for(int i=0;i<26;i++) Calc(cur->Child[i] , pos+1);
//}
//
//
//
//int main()
//{
//    ans = -1;
//    root = new Tree();
//    scanf("%s",&str1[0]);
//    scanf("%s",&str1[1]);
//
//    for(int t=0;t<2;t++) {
//        for(int i=0;str1[t][i]!=0;i++) {
//            Go(root,t,i);
//        }
//    }
//    Calc(root,0);
//    printf("%d\n",ans);
//
//
//    return 0;
//}
