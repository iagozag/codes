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

bool good(ll m, ll b, ll n, ll e, ll sb, ll sn, ll se, ll sum, vl& c){
    rep(i, 0, sum){
        ll need = (m+c[i]-1)/c[i];
        if(b >= 2 and sb*2 >= need) b -= 2;
        else if(b and n and sb+sn >= need) b--, n--;
        else if(b and e and sb+se >= need) b--, e--;
        else if(n >= 2 and sn*2 >= need) n -= 2;
        else if(n and e and sn+se >= need) n--, e--;
        else if(e >= 2 and se*2 >= need) e -= 2;
        else return false;
    }

    return true;
}

void solve(){
    ll b, n, e; cin >> b >> n >> e; ll sum = b+n+e; sum >>= 1;
    ll sb, sn, se; cin >> sb >> sn >> se;
    vl c(sum); rep(i, 0, sum) cin >> c[i];
    sort(all(c));

    ll l = 0, r = 1e18, ans = 0;
    while(l <= r){
        ll m = l+(r-l)/2;
        if(good(m, b, n, e, sb, sn, se, sum, c)) ans = m, l = m+1;
        else r = m-1;
    }
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
