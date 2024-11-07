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

void solve(){
    int n; cin >> n; map<int, vi> mp;
    vi v(n); rep(i, 0, n) cin >> v[i], mp[v[i]].eb(i);

    ll ans = 0; int prev = 0;
    forr(x, mp){
        int i = lower_bound(all(x.ss), prev)-x.ss.begin(), past = i;
        if(i == sz(x.ss)) i = 0, past = i;

        while(i < sz(x.ss)){
            if(x.ss[i] < prev) ans += n-prev+x.ss[i];
            else ans += x.ss[i]-prev;
            prev = x.ss[i], i++;
        }

        rep(j, 0, past){
            if(x.ss[j] < prev) ans += n-prev+x.ss[j];
            else ans += x.ss[j]-prev;
            prev = x.ss[j];
        }
    }

    cout << ans << endl;
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}