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

vector<pii> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve(){
    int n, m; cin >> n >> m;
    vector<string> v(n);
    forr(x, v) cin >> x;
    int x1, y1, x2, y2;
    rep(i, 0, n) rep(j, 0, m){
        if(v[i][j] == 'E') x1 = i, y1 = j;
        else if(v[i][j] == 'S') x2 = i, y2 = j;
    }

    vector<vi> dist(n, vi(m, INF));
    dist[x1][y1] = 0;
    queue<pii> q; q.push({x1, y1});
    while(!q.empty()){
        pii c = q.front(); q.pop();
        forr(mo, moves){
            int x = c.ff+mo.ff, y = c.ss+mo.ss;
            if(x < 0 or x >= n or y < 0 or y >= m or v[x][y] == 'T') continue;
            if(dist[x][y] > dist[c.ff][c.ss]+1) dist[x][y] = dist[c.ff][c.ss]+1, q.push({x, y});
        }
    }

    vi dists(n*m+1);
    rep(i, 0, n) rep(j, 0, m){
        if(v[i][j] >= '0' and v[i][j] <= '9' and dist[i][j] <= n*m)
            dists[dist[i][j]] += (v[i][j]-'0');
    }

    rep(i, 0, n*m) dists[i+1] += dists[i];

    dist = vector<vi>(n, vi(m, INF));
    dist[x2][y2] = 0;
    q = queue<pii>(); q.push({x2, y2});
    while(!q.empty()){
        pii c = q.front(); q.pop();
        forr(mo, moves){
            int x = c.ff+mo.ff, y = c.ss+mo.ss;
            if(x < 0 or x >= n or y < 0 or y >= m or v[x][y] == 'T') continue;
            if(dist[x][y] > dist[c.ff][c.ss]+1) dist[x][y] = dist[c.ff][c.ss]+1, q.push({x, y});
        }
    }

    cout << dists[dist[x1][y1]] << endl;
}

int main(){ _
    int ttt = 1; // cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
