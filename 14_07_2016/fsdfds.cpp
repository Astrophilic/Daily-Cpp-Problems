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
#define ld double
#define fastIO ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
const ld EPS=1e-15;
int toInt(string s)  { int sm; stringstream ss(s); ss>>sm; return sm; }
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }


#include <iostream>

using namespace std;

const int c_limit=1010;

// To check if a number is prime.
bool markPrime[c_limit];

// This function marks all the primes
// in range 1 to 1010.
// Initially it is assumed that all numbers are prime
// the multiples are marked as not prime.
// In this way all primes are marked.

void seive(){

    for(int i=2;i<c_limit;i++)
        markPrime[i]=true;

    for(int i=2;i<c_limit;i++){
        if (markPrime[i]==true){

            for(int j=2*i;j<c_limit;j+=i){
                markPrime[j]=false;
            }
        }
    }
}
int main()
{

    seive();

    int testCases;
    cin>>testCases;

    for(int i=1;i<=testCases;i++) {
        int queryValue;
        cin>>queryValue;

        if (markPrime[queryValue]==true) {
            cout<< queryValue <<" is Prime\n";
        } else {
            cout<< queryValue <<" is not Prime.\n";
        }
    }
    // No space between typename and associated pointer.
    // Use nullptr instead of null.




    // This is how you write a comment
    // in microsoft .
    // Start with a capital letter
    // and end with a full stop.
    // Insert 1 space after //.
    // Never create formatted block around comment.



    return 0;
}
