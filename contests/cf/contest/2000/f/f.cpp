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

template<typename X, typename Y> bool ckmin(X& x, const Y& y) { return (y < x) ? (x=y,1):0; }
template<typename X, typename Y> bool ckmax(X& x, const Y& y) { return (x < y) ? (x=y,1):0; }

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    ll n, k; cin >> n >> k;
    vl a(n), b(n); rep(i, 0, n) cin >> a[i] >> b[i];

    vl dp(k+2, INF); dp[0] = 0;
    rep(i, 0, n){
        repr(j, k-1, 0){
            if(dp[j] == INF) continue; 

            int ta = a[i], tb = b[i], pt = 0, op = 0;
            while(ta > 1 or tb > 1){
                if(tb > 1 and ta < tb) op += ta, tb--;
                else op += tb, ta--;
                pt++;

                if(j+pt <= k+1) ckmin(dp[j+pt], dp[j]+op);
                else break;
            }

            op += 1, pt += 2;
            if(j+pt <= k+1) ckmin(dp[j+pt], dp[j]+op);
        }
    }

    ckmin(dp[k], dp[k+1]);
    cout << (dp[k] == INF ? -1 : dp[k]) << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
