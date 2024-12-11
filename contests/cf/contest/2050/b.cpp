#include <bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define int ll

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 2e5+10, MOD = 1e9+7;

void solve(){
	int n; cin >> n;
	vector<int> v(n); int sum = 0;
	for(int i = 0; i < n; i++){ cin >> v[i]; sum += v[i]; }
	if(sum%n != 0){ cout << "NO" << endl; return; }

	int med = sum/n;
	for(int i = 1; i < n-1; i++){
		if(v[i-1] < med) v[i+1] -= med-v[i-1], v[i-1] += med-v[i-1];
		else if(v[i-1] > med) v[i+1] += v[i-1]-med, v[i-1] -= v[i-1]-med;
	}

	for(int i = 0; i < n; i++) if(v[i] != med){cout << "NO" << endl; return; }
	cout << "YES" << endl;
}

int32_t main(){ _
    int ttt = 1; cin >> ttt;

    while(ttt--) solve();

    exit(0);
}