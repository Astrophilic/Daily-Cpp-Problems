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
#define t int t; cin>>t; while(t--)
using namespace std;
const ll EPS=1e-15;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }


int bin(int *ar,int key,int n)
{

	int lo=0;
	int hi=n-1;

	while(lo<hi)
	{
		int mid=(lo+hi+1)/2;


		if(ar[mid]<=key)
			lo=mid;
		else
			hi=mid-1;


	}
	return lo;
}


int main()
{   t
    {
    	int n;
    	cin>>n;
    	int ar[n];

    	for (int i = 0; i < n; ++i)
    	{
    		cin>>ar[i];
    	}

    	int k;
    	cin>>k;
    	cout<<bin(ar,k,n)<<endl;
    }

    return 0;
}