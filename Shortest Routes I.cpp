#include <bits/stdc++.h>

#define forr(i, a, b) for(ll i = (ll) a; i < (ll) b; i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define fst first
#define snd second

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 9223372036854775807;

vector<pair<int,int>> adj[100050];
bool visited[100050];
ll distancia[100050];
priority_queue <pair<ll,ll>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    forn(i,m) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].pb({b,c});
    }
    for (int i = 1; i <=n; i++) distancia[i] = INF;
    distancia[1] = 0;
    q.push({0,1});
    while(!q.empty()) {
        ll a = q.top().snd;
        q.pop();
        if (visited[a]) continue;
        visited[a] = true;
        for (auto u : adj[a]) {
            ll b = u.fst;
            ll c = u.snd;
            if (distancia[a]+c < distancia[b]) {
                distancia[b] = distancia[a]+c;
                q.push({-distancia[b],b});
            }
        }
    }
    for (int i = 1; i<=n; i++) {
        cout << distancia[i] << " ";
    }
    cout << '\n';
}