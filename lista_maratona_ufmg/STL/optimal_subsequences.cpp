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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAX = 2e5+10;

void solve(){
    int n; cin >> n;
    vector<ii> v(n); vi vv(n);
    rep(i, 0, n){
        int a; cin >> a; v[i] = {a, i}, vv[i] = a;
    }
    sort(all(v), [](const ii &a, const ii &b){
        if(a.ff != b.ff) return a.ff > b.ff;
        else return a.ss < b.ss;
    });

    int q; cin >> q;
    vector<pair<ii, int>> queries; 
    rep(i, 0, q){
        int k, p; cin >> k >> p; p--;
        queries.pb({{k, p}, i});
    }
    sort(all(queries));

    ordered_set os;
    vi ans(q); int len = 0;
    rep(i, 0, q){
        while(len < queries[i].ff.ff){
            os.insert(v[len].ss), len++;
        }

        ans[queries[i].ss] = vv[*(os.find_by_order(queries[i].ff.ss))];
    }

    forr(ans) cout << x << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
