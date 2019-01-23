#include <iostream>
#define ll long long
using namespace std;

const ll M=1e6+10;

ll p[M];

void seive()
{

    for(ll i=1;i<M;i++)
        p[i]=i;

    for(ll i=2;i<M;i++)
    {
        if(p[i]==i)
        {
            p[i]=i-1;
            for(ll j=2*i;j<M;j+=i)
                p[j]=p[j]*(i-1)/i;
        }
    }
}
int main()
{
   seive();


    return 0;
}
