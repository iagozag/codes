#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
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

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

vi mult(vi a, vi b, int n){
    vi ans(n);
    rep(i, 0, n) ans[i] = a[b[i]]; 
    return ans;
}

vi fexp(vi a, ll b, int n){
    vi ans(n); rep(i, 0, n) ans[i] = i;
    while(b){
        if(b&(1LL)) ans = mult(ans, a, n);
        a = mult(a, a, n), b >>= (1LL);
    }
    return ans;
}

void solve(){
    int n; ll k; cin >> n >> k;
    vi p(n); forr(x, p) cin >> x, --x;
    vi v(n); forr(x, v) cin >> x;

    p = fexp(p, k, n);
    rep(i, 0, n) cout << v[p[i]] << " \n"[i==n-1];
}

int main(){ _
    int ttt = 1; // cin >> ttt;
    while(ttt--) solve();

    exit(0);
}

