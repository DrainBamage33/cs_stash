#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#include "cp_templates/debug_template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
 
#define errorl(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);cout<<"\n";}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);cout<<"___";}
#define debugl(args...) {if(DEBUG){ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args);cout<<"\n";}}
    
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cout << *it << " = " << a <<" , ";
    err(++it, args...);
}
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back 
#define vars ll h,i,j,k,d,l,p,q,r,x,y,a,b,c,v,var,n,m,z,s,ans,ind1,ind2,flag,limit1,limit2,limit3,mod;
#define vll vector<ll>
#define testcase ll tt; cin >> tt; while(tt--)
 
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const bool DEBUG = true;

int main()
{
	boost;
	vars;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}