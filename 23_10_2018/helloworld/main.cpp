#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
#define ll long long
const ll M=1e6+10;

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
#define ll long long
//const ll M=1e6+10;



int main()
{

    ll t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

       ll i=0;
       ll j=1;

       ll L[s.size()]={0};

       while(j<s.size())
       {

           if(s[i]==s[j])
           {
            //   cout<<s[i]<<" "<<s[j]<<endl;
               L[j]=i+1;
               i++;
               j++;
           }
           else
           {

               if(i==0)
               {
                   L[j]=0;
                   j++;
               }
               else
               i=L[i-1];
           }
       }

   for(ll i=0;i<s.size();i++)
       cout<<L[i]<<" ";

    ll ans=s.size()-L[s.size()-1];

    cout<<"ans "<<ans<<endl;

    if(ans&&s.size()%ans!=0)
        cout<<s.size()<<"\n";
    else
        cout<<ans<<"\n";
    }


return 0;

}
//<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!


//<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
