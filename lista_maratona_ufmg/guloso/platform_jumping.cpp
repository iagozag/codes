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
    int n, m, d; cin >> n >> m >> d;
    vi v(m); forr(v) cin >> x;
    
    vi ans(n); int i = n-1, j = m, cnt = 0;
    for(; i >= 0; i--){
        ans[i] = j, cnt++;
        if(cnt == v[j-1]) cnt = 0, j--;
        if(j == 0) break;
    }

    int k = 0;
    for(j = d-1; j < n; j += d-1){
        if(ans[j]) break;
        while(v[k]--) swap(ans[j], ans[i]), j++, i++;
        k++; if(k == m) break;
    }

    if(ans[n-1] or j-1+d >= n){
        cout << "YES" << endl;
        forr(ans) cout << x << " ";
        cout << endl;
    } else cout << "NO" << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}
