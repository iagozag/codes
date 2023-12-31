#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define all(a) (a).begin(), (a).end()
#define endl '\n'
#define f first
#define s second
#define pb push_back

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vi id;
vector<vi> sts;

int find(int x){
    return id[x] = (id[x] == x ? x : find(id[x]));
}

void unio(int a, int b){
    a = find(a), b = find(b);
    if(sts[a].size() > sts[b].size()) swap(a, b);
    for(auto& x: sts[a]) sts[b].pb(x); 
    id[a] = b; 
}

void solve(){
    int n; cin >> n;
    id = vi(n); iota(all(id), 0); sts = vector<vi>(n); int k = 0;
    for(auto& x: sts) x.pb(k), k++;

    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; a--, b--;
        unio(a, b);
    }

    int p = find(0);
    for(auto& x: sts[p]) { cout << x+1 << " "; }
    cout << endl;
}

int main(){ _
    int t = 1;
    while(t--){
        solve();
    }

    exit(0);
}

