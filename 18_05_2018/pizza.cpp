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
#define ld double
const ld EPS=1e-15;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }



int main()
{   
	ios::sync_with_stdio(0);
	//cin.tie(NULL);
	//cout.tie(NULL);
	
    {

    
    int n;
    cin>>n;

    map<string,int>mp;
    mp["1/4"]=0;
    mp["1/2"]=1;
    mp["3/4"]=2;

  	int half=0,quar=0,thquar=0;

  	for (int i = 0; i < n; ++i)
  	{
  		string s;
  		cin>>s;
  		if(mp[s]==0)
  			quar++;
  		else if(mp[s]==1)
  			half++;
  		else
  			thquar++;
  	}

  		//cout<<"half "<<half<<" quar "<<quar<<" thrq"<<thquar<<endl;

  		

  		

  		


  
  		


  		int x=min(thquar,quar);

  		//cout<<"added to comp min of quar thrq "<<x<<endl;

  		comp+=x;



  		if(thquar>=quar)
  		{
  			thquar-=quar;
  			quar=0;
  		}
  		else
  		{
  			
  			quar-=thquar;
  			thquar=0;

  		}

  		//cout<<"status quar "<<quar<<" thqar"<<thquar<<" half "<<half<<endl;


  		if(quar)
  		{
  			if(quar%2)
  			{
  				comp+=1;

  				//cout<<"added 1 to comp as quar is odd "<<endl;
  				quar--;
  				if(half)
  					half--;

  				//cout<<"status quar "<<quar<<" thqar"<<thquar<<" half "<<half<<endl;

  			}

  			int req=quar/2;

  			quar=0;

  			x=min(req,half);
  			comp+=x;

  			//cout<<"added half and quar "<<x<<endl;


  			if(half>=req)
  			{
  				
  				half-=req;
  				req=0;
  			}
  			else
  			{
  				req-=half;
  				half=0;
  			}

  			quar+=2*req;
  			//cout<<"status quar "<<quar<<" thqar"<<thquar<<" half "<<half<<endl;
  		}


  		//cout<<"remaining h q th "<<half<<" "<<quar<<"  "<<thquar<<"\n";

  		comp+=half/2;
  		comp+=quar/4;
  		quar%=4;
  		half=half%2;

  		comp+=half+quar+thquar;

  		


  		cout<<comp<<"\n";


  	}


    
    return 0;
}