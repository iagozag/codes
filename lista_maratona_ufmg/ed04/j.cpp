#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repr(i,n,x) for(int i=n;i>=x;i--)
#define forr(v) for(auto& x: v)
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define ff first
#define ss second
#define pb push_back

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

const int MAX = 2e5+10;

void solve(){
    int n, m; cin >> n >> m;
    vi v(n+1);
    rep(i, 1, n+1) cin >> v[i];

    int ans = 0;
    rep(i, 1, n+1){
        if(v[i] < v[i-1]){
            int diffant = m-v[i-1]+v[i-2], diffcur = v[i-1]-v[i];
            if(v[i]<v[i-2] and v[i]-v[i-2] > diffant) diffant += v[i]-v[i-2]-diffant;

            if(diffant < diffcur){ ans = max(ans, diffant); if(v[i]<v[i-2]) v[i] = v[i-2]; }
            else if(diffant > diffcur) ans = max(ans, diffcur), v[i] = v[i-1];
            else ans = max(ans, diffant), dbg(v[i]), v[i] = min(v[i-1], v[i-2]);
        }
    }

    cout << ans << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
