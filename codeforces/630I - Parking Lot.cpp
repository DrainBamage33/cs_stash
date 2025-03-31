// https://codeforces.com/problemset/problem/630/I

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

ll xyMODz2(ll x, ll y, ll z){
	ll ans = 1;
	x=x%z;
	while(y){
		if(y%2) ans = (ans*x)%z;
		x = (x*x)%z;
	}
	return ans%z;
}

int main()
{
	boost;
	vars;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	cin>>n;
	if(n==3){
		cout<<24<<"\n";
	}
    // Case: 1
    // ... _ {n} _ ...
    // n cars in between, so neighbours will only have 3 choices.
    // so (4c1)(3c1)(3c1) = k for that.
    // rest cars = (2n - 2 - n - 2) = n - 4.
    // so k = k*(4 ^ (n - 4)) for that.
    // and there'd be (n - 3) ways for this position to occur.
    // so k = k * (n - 3).
    // Case 1 ans: (4c1)(3c1)(3c1)(4^(n-4))(n-3)
    // Case: 2
    // {n} _ ...
    // ... _ {n}
    // Both boundary cases.
    // so Case 2 ans: 2 * (4c1)(3c1)(4^(n-3))
    // final is Case 1 + Case 2.
	else{
		cout<<xyMODz2(4,n-4,LLONG_MAX)*(36*(n-3) + 96);
	}
}