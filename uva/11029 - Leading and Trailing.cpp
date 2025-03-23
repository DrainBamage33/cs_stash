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
		// debug(x,y,z,ans);
		if(y%2) ans = (ans*x)%z;
		x = (x*x)%z;
		y/=2;
		// debug(x,y,z,ans);
	}
	return ans%z;
}

ll xyMODz2double(ll x, ll y, ll z){
	ll ans = 1;
	while(x>z*z)x/=10;
	while(y){
		debug(x,y,z,ans);
		if(y%2) ans = (ans*x);
		x = (x*x);
		y/=2;
		while(ans>z)ans/=10;
		while(x>z)x/=10;
		debug(x,y,z,ans);
	}
	while(ans>z)ans/=10;
	return ans;
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
	for(i=0;i<n;i++){
		cin>>a>>b;
		//trialing.
		p=xyMODz2(a,b,1000);
		// leading.
        // n^k = 10 ^ (log10(n^k))
        // n^k = 10 ^ (k * log10(n))
        // n^k = 10 ^ (k * log10(n))
        // n^k = 10 ^ (Z) where Z = k * log10(n) 
        // n^k = 10 ^ ([Z] + (Z - [Z])) where [] = floor 
        // n^k = (10 ^ [Z]) * (10 ^ (Z - [Z])) where [] = floor 
        //       ^^^^(just 0s) ^^^^^^^^^^^^^^ -> actual digits our goal
        double pp = b * log10(a);
        double ex = pp - floor(pp);
        double lead = pow(10,ex)*100.00;
        printf("%03d...%03d\n",(int)lead,p);
	}


}