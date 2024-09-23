#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define per(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a.size())
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "No" << endl; }
void yes(){ cout << "Yes" << endl; }

const int MAX = 1e6+10, MOD = 1e9+7;

void solve(){
    ll n, k; cin >> n >> k;
    vl v(n); forr(x, v) cin >> x;

    if(n == 1){ cout << (v[0] < k ? k : k-1) << endl; return; }

    ll g = 0;
    rep(i, 0, n) g = __gcd(g, v[i]);

    ll l = 0, r = 2e18+10, ans = 0;
    while(l <= r){
        ll m = l+(r-l)/2;
        if(m <= k-2+min(n, m/g+1)) ans = m, l = m+1;
        else r = m-1;
    }

    cout << ans+1 << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
