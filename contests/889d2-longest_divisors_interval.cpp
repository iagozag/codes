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

void solve(){
    ll n; cin >> n;
    for(ll i = 1; i <= n+1; i++){
        if(n%i != 0){ cout << i-1 << endl; break; }
    }
}

int main(){ _
    int t; cin >> t;
    while(t--){
        solve();
    }

    exit(0);
}
