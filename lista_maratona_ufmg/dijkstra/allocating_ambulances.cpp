#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(auto i=x;i<n;i++)
#define repr(i,n,x) for(auto i=n;i>=x;i--)
#define forr(x, v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
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

void DBG() {
    cerr << "]" << endl;
}

void DBGC() {
    cerr << "]" << endl;
}

template<class H, class... T> void DBG(H h, T... t) {
    cerr << to_string(h);
    if(sizeof...(t)) cerr << ", ";
    DBG(t...);
}

template<class H, class... T> void DBGC(H h, T... t) {
    for(auto& x: h) cerr << x << " ";
    if(sizeof...(t)) cerr << "], [ ";
    DBGC(t...);
}

#ifndef _DEBUG
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define dbgc(...) cerr << "["<< #__VA_ARGS__ << "]: [ "; DBGC(__VA_ARGS__) 
#else
#define dbg(...) 0
#define dbgc(...) 0
#endif

void no(){ cout << "NO" << endl; }
void yes(){ cout << "YES" << endl; }

const int MAX = 2e5+10, MOD = 1e9+7;

int n, m, q;
vector<vector<ii>> g;
vi dist, vis;
unordered_set<int> hosp;

void dijkstra(){
	priority_queue<ii> pq;
	forr(x, hosp) dist[x] = 0, pq.push({0, x});

	while(!pq.empty()){
		auto [w, v] = pq.top(); pq.pop(); w *= -1;
		if(vis[v]) continue;
		
		vis[v] = 1;
		for(auto [ve, d]: g[v]) if(w+d < dist[ve]) dist[ve] = w+d, pq.push({-w-d, ve});
	}
}

void solve(){
    g = vector<vector<ii>>(n), dist = vi(n, INF), vis = vi(n), hosp.clear();

    rep(i, 0, m){
        int a, b, w; cin >> a >> b >> w; --a, --b;
        g[a].eb(b, w), g[b].eb(a, w);
    }

    rep(i, 0, q) { int a; cin >> a; --a; hosp.insert(a); }

    dijkstra();

	int ma = 0;
	rep(i, 0, n) ma = max(ma, dist[i]);
	cout << ma << endl;
}

int main(){ _ 
    while(cin >> n >> m >> q) solve();

    exit(0);
}
