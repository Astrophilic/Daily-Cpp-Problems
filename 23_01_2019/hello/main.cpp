#include <bits/stdc++.h>
typedef long long ll;

using namespace std;


vector<int>v[100];

void dfs(vector<int>&A,vector<int>&track,int src,int &ans,int dest,int mxwt,int parent)
{

    track.push_back(src);

    if(src==dest)
    {

        for(auto x:track)
        {
            cout<<x<<" "<<A[x]<<'\n';
            if(A[x]<=mxwt)
            {

                ans+=1;
                cout<<"ans so far"<<ans<<'\n';
            }
        }
    }

    for(auto child:v[src])
    {
        if(child!=parent)
            dfs(A,track,child,ans,dest,mxwt,src);
    }
    track.pop_back();
}
int main()
{

    ll tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        vector<int>A(n+1,0);

        for(int i=1;i<=n;i++)
            cin>>A[i];

        for(int i=0;i<n-1;i++)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        int q;
        cin>>q;
        vector<int>track;
        while(q--)
        {

            int src,dest,mxwt;
            cin>>src>>dest>>mxwt;

            int ans=0;
            dfs(A,track,src,ans,dest,mxwt,-1);
            cout<<ans<"\n";
        }

    }


    return 0;
}
