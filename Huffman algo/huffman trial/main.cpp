#include<stdio.h>
#include<queue>
#include<string.h>

using namespace std;

struct htree
{
	public:
		int w,type;
		char a;
		int pos,index1,index2,par_pos;
		bool operator<(const htree& obj)const { return obj.w<w;}
};

priority_queue<htree> q;
char seq[1000];
int frequency[200]={0};
htree tree[1000];
char val[256][100];

int initialize(int len)
{
	int index=1;
	for(int i=0;i<200;i++)
	{
		if(frequency[i]==0) continue;
		htree temp;
		temp.type=0;							//বেসিক নোড এর টাইপ ০ করে দেওয়া হচ্ছে
		temp.a=(char)i;
		temp.w=frequency[i];

		temp.pos=index;
		tree[index]=temp;
		index++;
		q.push(temp);
	}
	return index;
}

int construct_huffman_algo(int start)
{
	int index=start;
	htree ob1,ob2;
	while(q.size()>1)
	{
		ob1=q.top();q.pop();
		ob2=q.top();q.pop();

		tree[index].index1=ob1.pos;             //চাইল্ড এর পজিশন প্যারেন্ট এ ইনপুট হচ্ছে

		tree[index].index2=ob2.pos;

		tree[index].w=ob1.w+ob2.w;				// ওয়েট আপডেট হচ্ছে

		tree[index].pos=index;

		tree[ob1.pos].par_pos=tree[ob2.pos].par_pos=index;			// চাইল্ড জানবে প্যারেন্ট কে?


		tree[index].type=1;						// স্টার্টিং নোড নয় তাই টাইপ ১ নইলে ০

		q.push(tree[index]);

		index++;

	}



	return index;
}

void print_tree(int index,int len)
{
//	printf("%d %d",index,len);
	for(int i=index-1;i>=len;i--)
	{
		htree cur=tree[i];
		printf("left-%d ",cur.index1);
		if(tree[cur.index1].type==0)
		{
			printf("%c ",tree[cur.index1].a);
		}
		printf("right-%d ",cur.index2);
		if(tree[cur.index2].type==0)
		{
			printf("%c ",tree[cur.index2].a);
		}
		printf("\n");

	}

	return;
}

void collect_value(int index)
{

	int in=0;
	for(int i=96;i<200;i++)
	{
		in =0;
		if(frequency[i]==0) continue;
		int j;
		for(j=1;j<=index;j++)
		{
			if((int)tree[j].a==i) break;
		}
		htree temp=tree[j];
		do
		{
			if(tree[temp.par_pos].index1==temp.pos)
			{
				val[i][in++]='0';
			}
			else val[i][in++]='1';
			temp=tree[temp.par_pos];

		}while(temp.pos!=index);

		for(int ii=0;ii<=(in-1)/2;ii++)         // storing compressed values of the characters
		{
			char temp=val[i][ii];
			val[i][ii]=val[i][in-ii-1];
			val[i][in-ii-1]=temp;
		}
		val[i][in]='\0';
		printf("%c = ",i);
		for(int ii=0;ii<in;ii++)
		{
			printf("%c",val[i][ii]);
		}
		printf("\n");

	}

	return;
}


void print_encoded_message(int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%s",val[(int)seq[i]]);
	}
	return ;
}

int main()
{

	while(gets(seq))
	{
		q.empty();
		int len=strlen(seq);
		for(int i=0;i<len;i++)
		{
			frequency[(int)seq[i]]++;
		}
		int last=initialize(len);

		int index=construct_huffman_algo(last);

		print_tree(index,last);

		collect_value(index-1);

		print_encoded_message(len);

		return 0;

	}

    return 0;
}
