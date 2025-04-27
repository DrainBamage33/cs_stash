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

// via binary expontiation.
// given that permutation is transivitve,
// permutation n times is permute(permute(n/2), permute(n/2))
// time complexity is nlog2(n);
void permute(vll& arr, vll perm, ll i){
	for(; i>0; i>>=1){
		if (i&1){
			vll local; 
			for(ll j=0;j<arr.size();j++)local.emplace_back(arr[perm[j]]);
			arr = local;
		}
		vll local;
		for(ll j=0;j<arr.size();j++)local.emplace_back(perm[perm[j]]);
		perm = local;
	}
}

// via cycles.
// each individual element is involved in cycle.
// for eg:
// 1 2 3 4 5 6 7 (arr - it can be anything)
// 3 1 2 7 6 5 4 (permutation)
// notice 3 1 2 form a cycle of 3
// 4 7 form a cycle of 2
// 6 5 form a cycle of 2
// overall is lcm(3,2,2) - 6.
// complexity is O(n);
void permute_cycle(vll& arr, vll perm, ll k){
	ll n = perm.size();
	vll cycles, not_taken(n, -1), index(n, -1);
	vector<vll> pattern(n, vector<ll>(0));
	ll i;
	for(i=0;i<n;i++){
		ll v = 0;
		if(not_taken[i] == -1){
			ll z = i+1;
			do{
				pattern[i].emplace_back(z-1);
				not_taken[z-1]=v;
				index[z-1]=i;
				z = perm[z-1] + 1;
				v++;
			}while(z!=i+1);
			cycles.emplace_back(v);
		}
	}
	ll cycle_size = 1;
	for(i=0;i<cycles.size();i++){
		cycle_size = lcm(cycle_size, cycles[i]);
	}
	k = k % cycle_size;
	vll ans(n);
	for(i=0;i<n;i++){
		ll effective = k % pattern[index[i]].size();
		ll final = (not_taken[i] + effective) % (pattern[index[i]].size());
		ans[i] = arr[pattern[index[i]][final]];
	}
	arr = ans;
}


int main()
{
	boost;
	vars;
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	testcase{
		cin>>n>>k;
		vll arr;
		for(i=1;i<=n;i++)arr.emplace_back(i);
		vll perm;
		for(i=0; i<n; i+=2)perm.emplace_back(i);
		for(i=1; i<n; i+=2)perm.emplace_back(i);
		// permute(arr, perm, k);
		permute_cycle(arr, perm, k);
		for(i=0; i<arr.size(); i++){
			cout<<arr[i]<<" ";
		}cout<<"\n";
	}
}