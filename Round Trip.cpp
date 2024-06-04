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
int padres[100050];
int iniciclo = -1, finciclo;

bool dfs (int s, int padre) {
    visited[s] = true;
    for (auto u : adj[s]) {
        if (u == padre) continue;
        if (visited[u]) {
            finciclo = s;
            iniciclo = u;
            return true;
        }
        padres[u] = s;
        if (dfs(u,padres[u])) return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    forn(i,m) {
        int a,b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i,padres[i]) == true) break;
    }
    if (iniciclo == -1) cout << "IMPOSSIBLE" << '\n';
    else {
        vector<int> ans;
        ans.pb(iniciclo);
        ans.pb(finciclo);
        int u = padres[finciclo];
        while (u != iniciclo) {
            ans.pb(u);
            u = padres[u];
        }
        ans.pb(iniciclo);
        cout << ans.size() << '\n';
        forn(i, ans.size()) {
            cout << ans[ans.size()-1-i] << " ";
        }
        cout << '\n';
    }
}