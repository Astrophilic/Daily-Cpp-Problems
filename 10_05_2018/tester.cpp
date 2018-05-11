#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
#define vvll vector< vll >
#define pll pair<ll ,ll >
#define vpll vector< pll >
#define mp make_pair
#define pb push_back
#define MOD 1000000007
 
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define fst first
#define scd second
 
#define forn(i,n) for(int (i) = 0 ; (i) < (n) ; ++(i))
#define for1(i,n) for(int (i) = 1 ; (i) <= (n) ; ++(i))
#define forr(i,n) for(int (i) = (n)-1 ; (i)>=0 ; --(i))
#define forab(i,a,b) for(int (i) = a ; (i) <= (b) ; ++i)
 
#define mst(A , v) forn(i , (sizeof A) / (sizeof A[0]) ) A[i] = v;
#define mstv(V , v) forn(i , V.size()) V[i] = v;
using namespace std;
 
void read(ll &x){
	scanf("%lld",&x);
}
void read(ll &x,ll &y){
	scanf("%lld%lld",&x,&y);
}
void read(ll &x,ll &y,ll &z){
	scanf("%lld%lld%lld",&x,&y,&z);
}
void read(ll &x,ll &y,ll &z,ll &w){
	scanf("%lld%lld%lld%lld",&x,&y,&z,&w);
}
 
 
void read(vll &oneD){
	for(ll i=0;i<oneD.size();i++){
		read(oneD[i]);
	}
}
void read(vvll &twoD){
	for(ll i=0;i<twoD.size();i++){
		read(twoD[i]);
	}
}
 
 
void write(vll &oneD){
	for(ll i=0;i<oneD.size();i++){
		printf("%lld ",oneD[i]);
	}
	printf("\n");
}
void write(vvll &twoD){
	for(ll i=0;i<twoD.size();i++){
		write(twoD[i]);
	}
}
void write(vpll &oneDP){
	forn(i,oneDP.size()){
		printf("%lld %lld\n" , oneDP[i].fst , oneDP[i].scd);
	}
}
void write(map< ll , ll > &mpp){
	for(map<ll , ll >::iterator it = mpp.begin() ; it != mpp.end() ; it++){
		cout<<it->fst<<" : "<<it->scd<<endl;
	}
	cout<<endl;
}
 
vll seive;
void Seive(){
	const ll maxn = 1000005;
	seive.resize(maxn);
	forn(i,maxn) seive[i] = i;
	seive[1] = -1;
	seive[0] = -1;
	forab(i,2,maxn) if(i == seive[i]) for(ll j = 2*i ; j < maxn ; j+=i) if(seive[j] == j) seive[j] = i;
}
 
ll power(ll x, ll y , ll m){
	if(y == 1) return x%m;
	if(y == 0) return 1;
	if(y&1) return (x*power((x*x)%m , (y-1)/2 , m))%m;
	return power((x*x)%m , y/2 , m)%m;
}
 
ll modinv(ll x , ll mod = MOD){
	return power(x , mod - 2 , mod);
}
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ll n;
vpll A;
ld dp[55][4];
ld rec(ll i , ll p = -1){
	if(i == n){
		return INT_MAX;
	}
	ll j = p+2;
	if(dp[i][j] != -1) return dp[i][j];
	ld a = INT_MAX, b = INT_MAX;
	if(p == -1){
		ld t1 = (ld)(A[i].fst - A[i-1].fst)/(ld)(A[i].scd - A[i-1].scd);
		if(t1 < 0) t1 = INT_MAX;
		a = min(t1 , rec(i + 1 , -1));
		b = rec(i + 1 , 1);
	}else{
		ld t1 = (ld)(A[i].fst - A[i-1].fst)/(ld)(A[i-1].scd - A[i].scd);
		if(t1 < 0) t1 = INT_MAX;
		a = min(t1 , rec(i + 1 , 1));
		ld t2 = (ld)(A[i].fst - A[i-1].fst)/(ld)(A[i-1].scd + A[i].scd);
 
		b = min(t2 , rec(i + 1 , -1) );
	}
 
	return dp[i][j] = max(a , b);
 
}
 
 
 
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("A.in","r",stdin);
    	freopen("A.out","w",stdout);
    #endif
 
	ll t;
	read(t);
	while(t--){
		read(n);
		A.clear();
		A.resize(n);
		forn(i , n){
			cin>>A[i].fst>>A[i].scd;
		}
		forn(i , 55) forn(j,4) dp[i][j] = -1;
		sort(all(A));
		ld ans = rec(1 , -1);
		if(ans >= INT_MAX) ans = -1;
		cout<<fixed<<setprecision(10)<<ans<<endl;
 
	}
 
 
	#ifndef ONLINE_JUDGE
    	cout<<"\nTime Elapsed : " << 1.0*clock() / CLOCKS_PER_SEC << " s\n";
    #endif
 
    return 0;
}