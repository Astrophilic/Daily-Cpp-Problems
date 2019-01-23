#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    string s;
    cin>>s;
    ll k;
    cin>>k;

    const ll inf=1e18;

    ll mi=inf,mx=-1;

    ll bets=0,sc=0;
    ll f=0;

    string rs="";
    for(ll i=0;i<s.size();i++)
    {
        if(isalpha(s[i]))
            {
                bets++;
                rs+=s[i];
            }
        else
        {
            if(s[i]=='*')
                f=1;
            sc++;
        }
    }
    //cout<<"rs "<<rs<<endl;
    mi=bets-sc;

    mx=bets;

    if(mi<=k&&k<=mx)
        {
            ll rmv=mx-k;
            if(rmv==0)
                cout<<rs<<"\n";
            else
            {
                string nw="";

                ll j=s.size()-1;

                while(j>=0)
                {
                    if(rmv>0 && !isalpha(s[j]))
                    {
                        j-=1;
                        rmv-=1;
                    }
                    else if(isalpha(s[j]))
                        nw+=s[j];
                    j--;
                }
                reverse(nw.begin(),nw.end());
                cout<<nw<<"\n";
            }
        }
        else if(k>mx && f==1)
        {
           ll req=k-mx;

           string nw="";
           for(ll i=0;i<s.size();i++)
           {
               if(isalpha(s[i]))
                nw+=s[i];

               if(s[i]=='*'&& f==1)
               {
                   f=0;
                   while(req--)
                    nw+=s[i-1];
               }
           }
           cout<<nw<<'\n';
        }
        else
            cout<<"Impossible\n";


    return 0;
}
