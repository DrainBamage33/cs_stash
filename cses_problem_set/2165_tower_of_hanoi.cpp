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

ll power(ll a, ll b){
	if(b==0)return 1;
	if(b==1)return a;
	if(b%2)return power(a,b/2)*power(a,b/2)*a;
	return power(a,b/2)*power(a,b/2);
}

void Move(ll n, ll from, ll to, ll buffer, vector<pair<ll,ll>> &moves, bool is_print){
	// Trivial case.
	if (n==0) return;
	// Transfer everything above to the buffer stick.
	Move(n-1, from, buffer, to, moves, is_print);
	// Transfer the last item to the correct spot.
	moves.push_back({from,to});
	if(is_print){
		cout<<from<<" "<<to<<"\n";
	}
	// Transfer everything back from buffer to where it should be.
	Move(n-1, buffer, to, from, moves, is_print);
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
	cout<<power(2,n) - 1<<"\n";
	vector<pair<ll,ll>> answ;
	Move(n, 1, 3, 2, answ, true);
	// cout<<answ.size()<<"\n";
	// for(i=0;i<answ.size();i++){
	// 	cout<<answ[i].first<<" "<<answ[i].second<<"\n";
	// }

}