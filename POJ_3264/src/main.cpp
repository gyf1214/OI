#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define ma(a,b) (a)>(b)?(a):(b)
#define mi(a,b) (a)<(b)?(a):(b)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define clr(i,a) memset(i,a,sizeof(i))
#define mm 200000
#define infimax 2000000
#define infimin 0
using namespace std;

int key[mm],mma[mm],mmi[mm],ll[mm],rr[mm],l[mm],r[mm],size,root,n,q;

int maketree(int a,int b)
{
	int p=++size;
	l[p]=a;
	r[p]=b;
	if (a==b)
	{
		ll[p]=-1;
		rr[p]=-1;
		mma[p]=key[a];
		mmi[p]=key[a];
		return p;
	}
	int mid=(a+b)/2;
	ll[p]=maketree(a,mid);
	rr[p]=maketree(mid+1,b);
	mma[p]=ma(mma[ll[p]],mma[rr[p]]);
	mmi[p]=mi(mmi[ll[p]],mmi[rr[p]]);
	return p;
}

void init()
{
	scanf("%d %d",&n,&q);
	rep(i,0,n-1)
		scanf("%d",key+i);
	size=-1;
	root=maketree(0,n-1);
}

int query1(int p,int a,int b)
{
	if (a>r[p] || b<l[p])
		return infimin;
	if (a<=l[p] && b>=r[p])
		return mma[p];
	int x=query1(ll[p],a,b);
	int y=query1(rr[p],a,b);
	return ma(x,y);
}

int query2(int p,int a,int b)
{
	if (a>r[p] || b<l[p])
		return infimax;
	if (a<=l[p] && b>=r[p])
		return mmi[p];
	int x=query2(ll[p],a,b);
	int y=query2(rr[p],a,b);
	return mi(x,y);
}

int main()
{
	init();
	rep(i,1,q)
	{
		int st,ed;
		scanf("%d %d",&st,&ed);
		int ans=query1(root,st-1,ed-1)-query2(root,st-1,ed-1);
		printf("%d\n",ans);
	}
	return 0;
}
