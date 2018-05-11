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
//#define t int t; cin>>t; while(t--)
using namespace std;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }


int main()
{   
	ios::sync_with_stdio(false);
	//cin.tie(NULL);cout.tie(NULL);

	ll n,t,k,d;
	cin>>n>>t>>k>>d;

	ll t1=ceil(double(n)/k)*t;

	ll v1=ceil ( double(n-(d/t)*k) /(2*k));

 cout<<"v1 :"<<v1<<"\n";

	ll t2=(d+  v1*t);


	cout<<"t1 :"<<t1<<" t2:"<<t2<<endl;

		if(t2<t1)
			cout<<"YES\n";
		else
			cout<<"NO\n";
    

    return 0;
}