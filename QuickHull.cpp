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
set<pii>hull;
int n;
pii a[1000000];
int side(pii p1,pii p2,pii p)
{
	int val=(p.second-p1.second)*(p2.first-p1.first)-(p2.second-p1.second)*(p.first-p1.first);
	if(val>0)
		return 1;
	if(val<0)
		return -1;
	return 0;
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
double line_dist(pii p1,pii p2,pii p)
{
	int val=abs((p.second-p1.second)*(p2.first-p1.first)-(p2.second-p1.second)*(p.first-p1.first));
	double temp=sqrt(dist(p1,p2));
	double res=1.0*val/temp;
	return res;
}
void solve(pii p1,pii p2,int num)
{
	int ind=-1;
	double max_dist=0.0;
	for(int i=0;i<n;i++)
	{
		double temp=line_dist(p1,p2,a[i]);
		if(side(p1,p2,a[i])==num && temp>max_dist)
		{
			ind=i;
			max_dist=temp;
		}
	}
	if(ind==-1)
	{
		hull.insert(p1);
		hull.insert(p2);
		//cout<<"done\n";
		return;
	}
	solve(a[ind],p1,-side(a[ind],p1,p2));
	solve(a[ind],p2,-side(a[ind],p2,p1));

}
int main()
{
    ios::sync_with_stdio(0);
    cout<<"Number of points: \n";
    cin>>n;
    cout<<"Enter all the points \n";
    for(int i=0;i<n;i++)
    	cin>>a[i].first>>a[i].second;
    int min_x=0,max_x=0;
    for(int i=1;i<n;i++)
    {
    	if(a[i].first<a[min_x].first)
    		min_x=i;
    	if(a[i].first>a[max_x].first)
    		max_x=i;
    }
    cout<<"The points in convex hull are: \n";
    solve(a[min_x],a[max_x],1);
    solve(a[min_x],a[max_x],-1);
    while(!hull.empty())
    {
    	cout<<"("<<(*hull.begin()).first<<","<<(*hull.begin()).second<<")";
    	hull.erase(hull.begin());
    }
    return 0;
}