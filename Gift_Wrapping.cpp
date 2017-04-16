#include <bits/stdc++.h>
#define gcd __gcd
#define pb(x) push_back(x)
#define ll long long
#define in(x) scanf("%d",&x)
#define mod 1000000007
#define sz(x) x.size()
#define mst(x,a) memset(x,a,sizeof(x))
#define pii pair<int,int>
#define m_p make_pair
using namespace std;
int orient(pii p,pii q,pii r)
{
	int res=(q.second-p.second)*(r.first-q.first)-(r.second-q.second)*(q.first-p.first);
	if(res==0)
		return 0;//collinear
	if(res<0)
		return 2;//counter-clockwise
	return 1;// clockwise
}
int main()
{
    ios::sync_with_stdio(0);
    cout<<"Number of points: \n";
    int n;
    cin>>n;
    pii a[n];
    cout<<"enter all the points \n";
    for(int i=0;i<n;i++)
    	cin>>a[i].first>>a[i].second;
    if(n<3)
	{
		cout<<"convex hull is not possible\n";
		return 0;
	}
	vector<pii>hull;
	int p=0;
	for(int i=1;i<n;i++)
	{
		if(a[p].first<a[i].first)
			p=i;
	}
	int same=p;
	do
	{
		hull.pb(a[p]);
		int q=(p+1)%n;
		for(int i=0;i<n;i++)
		{
			if(orient(a[p],a[i],a[q])==2)
				q=i;
		}
		p=q;
	}
	while(p!=same);
	cout<<"the points in convex hull are:\n";
	for(auto e:hull)
		cout<<"("<<e.first<<","<<e.second<<")"<<endl;
    return 0;
}
