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
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }


int main()
{   
	ios::sync_with_stdio(false);
	//cin.tie(NULL);cout.tie(NULL);

	
	
	{
	string s;
	cin>>s;
	std::vector<int>v;
	for (int i = 0; i < s.size(); ++i){
		if(s[i]!='+')
			v.push_back(s[i]-48);

	}
	sort(v.begin(), v.end());

	for(int it=0;it<v.size()-1;it++)
		cout<<v[it]<<"+";
	cout<<v[v.size()-1]<<'\n';

	}
    

    return 0;
}