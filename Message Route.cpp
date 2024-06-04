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
int distancia[100050];
int padres[100050];
queue<int> q;


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
    visited[1] = true;
    distancia[1] = 1;
    padres[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int s = q.front();
        q.pop();
        for (auto u : adj[s]) {
            if (visited[u]) continue;
            visited[u] = true;
            distancia[u] = distancia[s] + 1;
            padres[u] = s;
            q.push(u); 
        }
    }
    if (visited[n] == false) {
        cout << "IMPOSSIBLE" << '\n';
    }
    else {
        cout << distancia[n] << '\n';
        vector<int> path;
        int u = n;
        path.pb(u);
        while(padres[u] != 0) {
            path.pb(padres[u]);
            u = padres[u];
        }
        forn(i,path.size()) {
            cout << path[path.size() - i - 1] << " ";
        }
        cout << '\n';
    }
}