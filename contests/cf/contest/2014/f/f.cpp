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

const int MAX = 2e5+10, MOD = 1e9+7;

int n; ll cost;
vector<vi> g;
vl a; vector<vl> memo;

ll dp(int v, int c, int p, int u){
    if(memo[v][c] != -LINF) return memo[v][c];
    memo[v][c] = 0;

    if(!c){
        memo[v][c] = 0;
        forr(ve, g[v]) if(ve != p)
            memo[v][c] += max(dp(ve, 0, v, c), dp(ve, 1, v, c));
    } else{
        memo[v][c] = a[v];
        forr(ve, g[v]) if(ve != p)
            memo[v][c] += max(dp(ve, 0, v, c), dp(ve, 1, v, c)-2*cost);
    }

    return memo[v][c];
}

void solve(){
    cin >> n >> cost;
    g = vector<vi>(n), a = vl(n);
    forr(x, a) cin >> x;
    rep(i, 0, n-1){ int v1, v2; cin >> v1 >> v2; --v1, --v2; g[v1].eb(v2), g[v2].eb(v1); }

    memo = vector<vl>(n, vl(2, -LINF));
    cout << max(dp(0, 0, -1, 0), dp(0, 1, -1, 0)) << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
