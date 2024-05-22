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

int b, n, e, sb, sn, se;
vi c, part;

bool good(int m){
    int mi = INF;


    return mi >= m;
}

void solve(){
    cin >> b >> n >> e; int sum = b+n+e; sum >>= 1;
    cin >> sb >> sn >> se;
    rep(i, 0, sum) cin >> c[i];

    rep(i, 0, b) part.eb(sb);
    rep(i, 0, n) part.eb(sn);
    rep(i, 0, e) part.eb(se);

    int l = 0, r = 1e9, ans;
    while(l <= r){
        int m = l+(r-l)/2;
        if(good(m)) ans = m, l = m+1;
        else r = m-1;
    }
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
