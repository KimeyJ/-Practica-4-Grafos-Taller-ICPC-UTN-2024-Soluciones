#include <bits/stdc++.h>

#define forr(i, a, b) for(ll i = (ll) a; i < (ll) b; i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define fst first
#define snd second

typedef long long ll;
typedef long double ld;

using namespace std;

vector<int> adj[100050];
bool visited[100050];

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    for (auto u : adj[s]) {
        dfs(u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    vector<int> conex;
    cin >> n >> m;
    forn(i,m) {
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=1;i<=n;i++) {
        if (visited[i] == false) {
            conex.pb(i);
            dfs(i);
        }
    }
    cout << conex.size()-1 << '\n';
    forn(i,conex.size()-1) {
        cout << conex[i] << " " << conex[i+1] << '\n';  
    }
}