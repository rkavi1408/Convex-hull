#include <bits/stdc++.h>
#define pb(x) push_back(x)
#define ll long long
#define in(x) scanf("%d",&x)
#define mod 1000000007
#define sz(x) x.size()
#define mst(x,a) memset(x,a,sizeof(x))
#define pii pair<int,int>
#define m_p make_pair
using namespace std;
pii p0;
int orientation(pii p,pii q,pii r)
{
	int res=(q.second-p.second)*(r.first-q.first)-(r.second-q.second)*(q.first-p.first);
	if(res==0)
		return 0;
	if(res<0)
		return 2;
	return 1;
}
bool compare(pii p1,pii p2)
{
	int val=(p1.second-p0.second)*(p2.first-p0.first)
			-(p1.first-p0.first)*(p2.second-p0.second);
	if(val<0)
		return 1;
	if(val>0)
		return 0;
	return (dist(p1,p0)<=dist(p2,p0));
}
pii next_top(stack<pii>s)
{
	s.pop();
	return s.top();
}
int dist(pii p,pii q)
{
	int res=0;
	res+=(p.second-q.second);
	res*=res;
	int tes=(p.first-q.first);
	tes*=tes;
	res+=tes;
	return res;
}
int main()
{

    ios::sync_with_stdio(0);
    cout<<"enter the number of points\n";
    int n;
    cin>>n;
    pii a[n];
    cout<<"enter the points\n";
    for(int i=0;i<n;i++)
    	cin>>a[i].first>>a[i].second;
    if(n<3)
	{
		cout<<"convex hull not possible\n";
		return 0;
	}
	int mini=0;
	for(int i=1;i<n;i++)
	{
		if(a[i].second<a[mini].second)
			mini=i;
		else if(a[i].second==a[mini].second)
			if(a[i].first<a[mini].first)
				mini=i;
	}
	p0=a[mini];
	swap(a[mini],a[0]);
	sort(a,a+n,compare);

	vector<pii>final;
	final.pb(a[0]);
	for(int i=1;i<n;i++)
	{
		while(i+1<n&&orientation(p0,a[i],a[i+1])==0)
			i++;
		final.pb(a[i]);
	}
	if(sz(final)<3)
	{
		cout<<"convex hull not possible\n";
		return 0;
	}
	stack<pii>s;
	s.push(final[0]);
	s.push(final[1]);
	s.push(final[2]);
	for(int i=3;i<sz(final);i++)
	{
		while(orientation(next_top(s),s.top(),final[i])!=2)
			s.pop();
		s.push(final[i]);
	}
	cout<<"the points in convex hull are:\n";
	while(!s.empty())
	{
		pii temp=s.top();
		cout<<"("<<temp.first<<","<<temp.second<<")";
		s.pop();
	}

    return 0;
}
