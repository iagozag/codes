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

const int MAX = 1e4+5, MOD = 1e9+7;

void solve(){
    int n, m; cin >> n >> m;
    vector<vi> g(MAX*2);
    rep(i, 1, MAX+1) g[i].eb(i*2), g[i].eb(i-1);

    vi dist(MAX*2, INF);
    queue<int> q; q.push(n); dist[n] = 0;
    while(!q.empty()){
        int v = q.front(); q.pop();
        if(v == m) break;
        forr(ve, g[v]) if(dist[ve] > dist[v]+1)
            dist[ve] = dist[v]+1, q.push(ve);
    }

    cout << dist[m] << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
