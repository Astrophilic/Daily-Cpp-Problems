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


void insertionsort(int ar[],int n)
{

	
	for(int i=1;i<n;i++)
	{
		int key=ar[i];

		int j=i-1;

		while(j>=0 && ar[j]>key)
		{
			ar[j+1]=ar[j];
			j--;
		}
		ar[j+1]=key;
	}
}

void merge(int ar[],int s,int m,int e)
{


	int tleft[m-s+1];

	int s1=m-s+1;
	int s2=e-m;


	int tright[e-m];

	for(int i=s;i<=m;i++)
		tleft[i-s]=ar[i];

	for(int i=m+1;i<=e;i++)
		tright[i-m-1]=ar[i];


	int i=0,j=0;

	int k=s;

	while(i<s1 && j<s2)
	{

		if(tleft[i]<=tright[j])
		{
			ar[k++]=tleft[i++];
		}
		else
		{
			ar[k++]=tright[j++];
		}
	}

	while(i<s1)
		ar[k++]=tleft[i++];

	while(j<s2)
		ar[k++]=tright[j++];



}

void mergesort(int ar[], int s,int e)
{
	if(s>=e)
		return;

	int m=(s+e)/2;

	mergesort(ar,s,m);
	mergesort(ar,m+1,e);
	merge(ar,s,m,e);


}
void heapify(int *ar, int i,int n)
{
	int left=2*i+1;
	int right=2*i+2;

	int largest=i;

	if(left<n && ar[left]>ar[i])
		largest=left;
	if(right<n && ar[right]>ar[largest])
		largest=right;

	if(largest==i)
		return;
	swap(ar[largest],ar[i]);

	heapify(ar,largest,n);

}

void buildheap(int *ar, int n)
{

	for(int i=n/2;i>=0;i--)
		heapify(ar,i,n);

}

void heapsort(int *ar,int n)
{
	buildheap(ar,n);

	cout<<"array after pass\n";

		for(int j=0;j<n;j++)
			cout<<ar[j]<<" ";
		cout<<"\n";

	int sz=n;

	for(int i=n-1;i>=0;i--)
	{
		swap(ar[i],ar[0]);
		sz--;
		heapify(ar,0,sz);
		cout<<"array after pass\n";

		for(int j=0;j<n;j++)
			cout<<ar[j]<<" ";
		cout<<"\n";


	}
}
int extractmax(int *ar, int& sz)
{
	int res=ar[0];

	swap(ar[0],ar[sz-1]);

	sz--;
	heapify(ar,0,sz);

	cout<<"array after pass\n";

		for(int j=0;j<sz;j++)
			cout<<ar[j]<<" ";
		cout<<"\n";
	return res;
}

void insert(int *ar ,int key, int &sz)
{
	
	ar[sz]=key;
	sz++;

	int i=sz-1;

	while(i>=0 && ar[i/2]<ar[i])
	{
		swap(ar[i],ar[i/2]);
		i/=2;
	}

	cout<<"array after pass\n";

		for(int j=0;j<sz;j++)
			cout<<ar[j]<<" ";
		cout<<"\n";



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

    	buildheap(ar,n);

    	int q;
    	cin>>q;

    	while(q--)
    	{
    		int ch;
    		cin>>ch;

    		if(ch==1)
    		{
    			cout<<extractmax(ar,n)<<"\n";
    		}
    		else
    		{
    			int x;
    			cin>>x;
    			insert(ar,x,n);
    		}
    	}
    	
    	mergesort(ar,0,n-1);

    	for(int i=0;i<n;i++)
    		cout<<ar[i]<<" ";
    	cout<<"\n";

    	insertionsort(ar,n);

    	for(int i=0;i<n;i++)
    		cout<<ar[i]<<" ";
    	cout<<"\n";
    }

    return 0;
}