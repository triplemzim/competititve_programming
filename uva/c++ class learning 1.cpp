//#include<iostream>
//#include<cstdio>
//#include<ctime>
//#include<cstring>
//
//using namespace std;
//
//class pluss
//{
//	int x;
//	int y;
//	public:
//		pluss() {x=0;y=0;}
//		pluss(int i,int j) {x=i;y=j;}
//		pluss operator+(pluss ob)
//		{
//			pluss temp;
//			temp.x=x+ob.x;
//			temp.y=y+ob.y;
//			return temp;
//		}
//		void getx(int &i,int &j)
//		{
//			i=x;
//			j=y;
//		}
//};
//
//
//int main()
//{
//	pluss ob1(1,2),ob2(2,3),ob3;
//	int x=1,y=2,z=3;
//	x=y=z;
//	cout<<x<<y<<z;
//
//	ob3=ob2+ob1;
//	ob3.getx(x,y);
//	cout<<x<<" " <<y<< endl;
//	return 0;
//}
#include <iostream>
#include <queue>

using namespace std;

struct hambaa
{
string apprnce;
int age;
hambaa(string s, int nmbr){apprnce=s; age=nmbr;}
bool operator < ( const hambaa &p) const { return p.age < age; }
};

main ()
{
    priority_queue <hambaa> pq;
    pq.push(hambaa("bachhur",1));
    pq.push( hambaa("boro goru",16 ));
    pq.push( hambaa("majhari goru", 6));
    pq.push(hambaa("majhari boro goru", 10));

    while ( !pq.empty() )
    {
        cout << pq.top().apprnce<< " " << pq.top().age << endl;
        pq.pop();
    }
}
