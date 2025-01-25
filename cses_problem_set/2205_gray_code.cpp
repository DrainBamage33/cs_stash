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

// use &, to avoid copy and use reference.
void GenerateGray(vector<string> & ans, ll n, ll m){
	// Base case
	if (n==1){
		string str = "";
		ll z = m;
		// instead of inserting only "0", "1" in base case,
		// insert with the margin as well. (so to avoid dummy copy later).
		while(z--)str+="0";
		ans.emplace_back(str);
		ans.emplace_back(str);
		ans[1][m-n]='1';
		return;
	}
	// Generate n-1 case.
	GenerateGray(ans, n-1, m);
	// Our goal:
	// Ans(n) =
	// <0 + Ans(n-1)><1 + Ans(n-1).reversed>
	// By induction:
	// Ans(n-1) will satify all condictions
	// Last element of Ans(n-1) and first element of Ans(n-1).reversed will be same.
	// So, the appened 0 and 1 will be the only elements being different.
	// Eg:
	// 0 + 00 -
	// 0 + 01 |--- (n-1) case is true.
	// 0 + 11 |
	// 0 + 10 -
	// 1 + 10 - (reversed from here, so we can chage first 0 -> 1)
	// 1 + 11 |--- (n-1) case is true.
	// 1 + 01 |
	// 1 + 00 -
	ll i;
	ll p = ans.size();
	for(i = p-1; i>=0; i--)ans.emplace_back(ans[i]);
	for(i = p; i<2*p ; i++){
		ans[i][m-n]='1';
	}
	return;
}

int main()
{
	boost;
	vars;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	vector<string> str;
	cin>>n;
	GenerateGray(str, n ,n);
	for(i=0;i<str.size();i++)cout<<str[i]<<"\n";
}