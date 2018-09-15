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


int partition(int [], int,int);

int k;

int quicksort(int ar[], int s,int e)
{	
	cout<<"f with s "<<s<<" e"<<e<<endl;
	if(s<e)
	{
		int partindex=partition(ar,s,e);

		cout<<"array after partition about"<<partindex<<endl;

		/*for(int i=s;i<=e;i++)
			cout<<ar[i]<<" ";
		cout<<endl;
		*/

		if(partindex==k-1)
		{
			cout<<"returning answer"<<ar[partindex]<<endl;
			return k-1;
		}

		if(partindex>k-1)
		 return quicksort(ar,s,partindex-1);
		else
		 return quicksort(ar,partindex+1,e);

	}

	cout<<"returning bak";
	return INT_MAX;
}

int partition(int ar[],int s,int e)
{
	int pivot=ar[e];

	int index=s;

	for (int i = s; i < e; ++i)
	{
		if(ar[i]<pivot)
		{
			swap(ar[i],ar[index]);
			index++;

		}
	}
	swap(ar[index],ar[e]);

	return index;
}
int main()
{   
	//fastIO
	t
    {

    	int n;
    	cin>>n;

    	int *ar=new int[n];

    	for(int i=0;i<n;i++)
    		cin>>ar[i];

    	cin>>k;
    	ll ans=quicksort(ar,0,n-1);
    	cout<<"index ans"<<ans<<endl;

    	cout<<ar[ans]<<endl;

    	for(int i=0;i<n;i++)
    		cout<<ar[i]<<" ";
    	cout<<"\n";

    }

    return 0;
}
/*
1
10
11 13 12 14 16 15 17 19 18 20
6
*/