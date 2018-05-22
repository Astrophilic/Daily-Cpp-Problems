#include<bits/stdc++.h>

using namespace std;
#define ll unsigned long long 


std::vector< string > v;


void init()
{
	
	std::vector<ll> tmp;
	tmp.push_back(1);
	
	v.push_back("1");
	v.push_back("1");


	for (ll i = 2; i <=100; ++i)
	{
		
		ll carry=0;

		ll x=i;

		for (int j = 0; j <tmp.size() ; ++j)
		{
			ll p=tmp[j]*x+carry;
			tmp[j]=p%10;
			carry=p/10;

		}
		//cout<<"The carry is "<<carry<<endl;
		while(carry)
		{
			tmp.push_back(carry%10);
			carry/=10;
		}

		string s="";

		
		for(int k=int(tmp.size())-1;k>=0;k--)
		{
			s+=(tmp[k]+'0');
		}


		v.push_back(s);



	}
}
int main(int argc, char const *argv[])
{
	

	init();

	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<v[n]<<endl;
	}
	return 0;
}
