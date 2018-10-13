#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define BitCnt(a) __builtin_popcountll(a)
#define MEM(a,val) memset(a,val,sizeof(a))
#define pul pair<ull,ull>
#define pl pair<ll,ll>
#define pi pair<int,int>

using namespace std;

#define t int t; cin>>t; while(t--)
#define ld double
#define fastIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const ld EPS=1e-15;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }



int main()
{   
	//fastIO
	ll n;
	cin>>n;

	priority_queue< pl >pq;

	std::vector<ll> v(n),h(n),w(n);

	ll width=0;

	for (int i = 0; i < n; ++i)
	{
		cin>>w[i]>>h[i];
		width+=w[i];
		pq.push({h[i],i});
	}

	for (int i = 0; i < n; ++i)
	{
		
		ll wid=width-w[i];
		ll mxh=0;
		auto x=pq.top();
		{
			if(x.ss==i)
			{
				pq.pop();
				mxh=pq.top().ff;
				pq.push(x);

			}
			else
				mxh=x.ff;

		}
		cout<<wid*mxh<<" ";
	}


    return 0;
}