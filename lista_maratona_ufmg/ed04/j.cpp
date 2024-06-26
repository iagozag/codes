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

int n, m;

bool good(vi v, int x){
    if(v[0]+x >= m) v[0] = 0;
    rep(i, 1, n){
        if(v[i-1] < v[i] and m-v[i]+v[i-1] <= x) v[i] = v[i-1];
        else if(v[i-1] > v[i] and v[i-1]-v[i] <= x) v[i] = v[i-1];

        if(v[i-1] > v[i]) return false;
    }
    return true;
}

void solve(){
    cin >> n >> m;
    vi v(n); forr(x, v) cin >> x;

    int l = 0, r = m+1, ans = 0;
    while(l <= r){
        int mid = l+(r-l)/2;
        if(good(v, mid)) ans = mid, r = mid-1;
        else l = mid+1;
    }
    cout << ans << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
