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

void solve(){
    int n; cin >> n;
    vi v(n); forr(x, v) cin >> x;
    int m; cin >> m;
    rep(i, 0, m){
        string s; cin >> s;
        if(sz(s) != n){
            cout << "NO" << endl;
            continue;
        }
        map<char, int> mp;
        map<int, char> mp2;
        bool ok = true;
        rep(j, 0, sz(s)){
            if(!mp.count(s[j])) mp[s[j]] = v[j];
            else if(mp[s[j]] != v[j]){
                ok = false; 
                break;
            }
            if(!mp2.count(v[j])) mp2[v[j]] = s[j];
            else if(mp2[v[j]] != s[j]){
                ok = false;
                break;
            }
        }
        
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}
