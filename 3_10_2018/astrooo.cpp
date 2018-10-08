#include <bits/stdc++.h>
#define ll long long
#define ff first 
#define ss second
using namespace std;



ll recur(ll x)
{
	if(x/10==0)
		return x;

	ll sum=0;

	while(x>0)
	{
		sum+=x%10;
		x/=10;

	}
	return recur(sum);

}

ll sumofdig(ll x)
{
	

	ll sum=0;

	while(x>0)
	{
		sum+=x%10;
		x/=10;

	}
	return sum;

}
map<ll,ll>cnt;

void bfs(ll src,ll d)
{
	set<ll>qset,vset;
	queue< pair<ll,ll> >cq;

	cnt[0]=-1;

	cq.push({src,0});
	qset.insert(src);

	while(!cq.empty())
	{
		auto x=cq.front();
		cq.pop();
		
		qset.erase(x.ff);

		if(cnt.find(x.ff)==cnt.end())
		cnt[x.ff]=1+cnt[x.ss];
		else
			continue;
		
		

		vset.insert(x.ff);
		ll value=recur(x.ff);


		ll val2=sumofdig(x.ff);

		if(qset.find(value)==qset.end() && vset.find(value)==vset.end()&&qset.find(val2)==qset.end() && vset.find(val2)==vset.end())
		{	
			qset.insert(val2);
			cq.push({val2,x.ff});
		}

		value=x.ff+d;
		value=recur(value);
		val2=x.ff+d;

		if(qset.find(value)==qset.end() && vset.find(value)==vset.end()&&qset.find(val2)==qset.end() && vset.find(val2)==vset.end())
		{	
			qset.insert(val2);
			cq.push({val2,x.ff});	
		}
	}
}


void solve()
{
	
	ll tc;
	cin>>tc;

	while(tc--)
	{	
		cnt.clear();

		ll n,d;	
		cin>>n>>d;
		bfs(n,d);

		auto it=cnt.begin();
		it++;
		cout<<it->first<<" "<<it->second<<endl;
	}
	
}
int main()
{   
	solve();
    return 0;
}