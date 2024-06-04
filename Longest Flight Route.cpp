#include <bits/stdc++.h>

#define forr(i, a, b) for(ll i = (ll) a; i < (ll) b; i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define fst first
#define snd second

typedef long long ll;
typedef long double ld;
const ll INF = 9e18;

using namespace std;

vector<int> adj[100050];
int dp[100500];
int hijo[100500];
int finciclo = -1;
int n, m;

int dfs(int s)
{
    if (s == n) {
        finciclo = 1;
    }
    if (dp[s] != -1)
        return dp[s];
    for (auto u : adj[s])
    {
        int distact = dfs(u) + 1;
        if (distact > dp[s]) {
            dp[s] = distact;
            hijo[s] = u;
        }
    }
    return dp[s];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    dp[n] = 1;
    forn(i, m)
    {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    int cant = dfs(1);
    if (finciclo == 1) {
        cout << cant << '\n';
        if (cant == 2) {
            cout << 1 << " " << n;
        }
        else {
            int u = 1;
            while (u != n) {
                cout << u << " ";
                u = hijo[u];
            }
            cout << u << '\n';
        }
    }
    else {
        cout << "IMPOSSIBLE" << '\n';
    }
}