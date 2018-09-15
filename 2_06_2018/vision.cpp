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
#define ld long double
#define fastIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const ld EPS=1e-10;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }
 
 
 
struct point
{
	ld x,y,z;
 
};
 
ld radius;
 
ll discomp(point p,point q, point c, ld lamb)
{
	ld dis=( (q.x)*lamb +p.x -(1+lamb)*c.x )*( (q.x)*lamb +p.x -(1+lamb)*c.x );
 
	dis+=( (q.y)*lamb +p.y -(1+lamb)*c.y )*( (q.y)*lamb +p.y -(1+lamb)*c.y );
 
	dis+=( (q.z)*lamb +p.z -(1+lamb)*c.z )*( (q.z)*lamb +p.z -(1+lamb)*c.z );
 
	ld dis2=radius*radius*(1+lamb)*(1+lamb);
 
	return dcmp(dis,dis2);
 
 
 
}
int main()
{
    fastIO
	t
    {
    point p,q,d,c;
 
 	cin>>p.x>>p.y>>p.z;
 	cin>>q.x>>q.y>>q.z;
 	cin>>d.x>>d.y>>d.z;
 	cin>>c.x>>c.y>>c.z;
 	cin>>radius;
 
 
 	ld lo=0.0;
 	ld hi=3e9+10;
 
 
 	ld lamb=0.0;
 	ld ans=0.0;
 
 	while(1)
 	{
 		point qnew;
 
 		//cout<<"lo:"<<lo<<" hi"<<hi<<endl;
 		ld tm=lo+(hi-lo)/2.0;
 
 		//cout<<"tm:"<<tm<<endl;
 
 		qnew.x=q.x+(d.x)*tm;
 
 		qnew.y=q.y+(d.y)*tm;
 
 		qnew.z=q.z+(d.z)*tm;
 
        if(fabs(lo-hi)<EPS)
        {
 
            ans=hi;
            break;
        }
 
 		lamb= - (  (p.x-qnew.x)*(p.x-c.x)  + (p.y-qnew.y)*(p.y-c.y)  + (p.z-qnew.z)*(p.z-c.z) )/ (  (qnew.x-c.x)*(p.x-qnew.x)  +    (qnew.y-c.y)*(p.y-qnew.y) + (qnew.z-c.z)*(p.z-qnew.z) );
 
 
 		ll flag=discomp(p,qnew,c,lamb);
 
 		if(flag==0)
 		{
 			ans=tm;
 			break;
 		}
 		else if(flag==-1)
 		lo=tm;
 		else
 		hi=tm;
 
 
 
 
 
 	}
 	cout<<fixed<<setprecision(12)<<ans<<endl;
 
 
 
    }
 
    return 0;
}
 