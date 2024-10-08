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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    vi v(n); forr(x, v) cin >> x;
    vi pos(n);

    map<int, multiset<int>> mp;
    rep(i, 0, n){
        int x = v[i];
        if(x&1) x--;
        if(x&2) x -= 2;
        pos[i] = x;
        mp[x].insert(v[i]);
    }

    rep(i, 0, n){
        cout << *mp[pos[i]].begin() << " \n"[i==n-1];
        mp[pos[i]].erase(mp[pos[i]].find(*mp[pos[i]].begin()));
    }
}

int main(){ _
    int ttt; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
