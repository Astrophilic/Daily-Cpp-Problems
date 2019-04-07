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


void insertionSort(int *ar,int n)
{

	for (int i = 1; i < n; ++i)
	{
		
		int key=ar[i];

		int j=i-1;

		while(j>=0&&ar[j]>key)
		{
			ar[j+1]=ar[j];
			j--;
		}
		ar[j+1]=key;
	}

	for(int i=0;i<n;i++)
		cout<<ar[i]<<" ";

}



int main()
{   
	//fastIO
	t
    {
    	int n;
    	cin>>n;
    	int ar[n];
    	for (int i = 0; i < n; ++i)
    	{
    		cin>>ar[i];
    	}
    	insertionSort(ar,n);
    }

    return 0;
}