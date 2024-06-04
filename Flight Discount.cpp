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


vector<pair<int,int>> adj[100050];
bool visited[100050][2];
ll distancia[100050][2]; // 0 - descuento usado --- 1 - descuento disponible
priority_queue<tuple<ll,int,int>> q;
int n,m;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    forn(i,m) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].pb({b,c});
    }
    for (int i=1; i<=n; i++) {
        distancia[i][0] = INF;
        distancia[i][1] = INF;
    }
    distancia[1][0] = 0;
    distancia[1][1] = 0;
    q.push({0,1,1});
    while(!q.empty()) {
        auto x = q.top();
        int a = get<1>(x);
        int disp = get<2>(x);
        q.pop();
        if (visited[a][disp]) continue;
        visited[a][disp] = true;
        for (auto u : adj[a]) {
            ll b = u.fst;
            ll c = u.snd;
            if (disp == 1) {
                if (distancia[a][1]+c <= distancia[b][1]) {
                    distancia[b][1] = distancia[a][1]+c;
                    q.push({-distancia[b][1],b,1});
                }
                if (distancia[a][1]+(c/2) <= distancia[b][0]) {
                    distancia[b][0] = distancia[a][1]+(c/2);
                    q.push({-distancia[b][0],b,0});
                }
            }
            else {
                if (distancia[a][0]+c <= distancia[b][0]) {
                    distancia[b][0] = distancia[a][0]+c;
                    q.push({-distancia[b][0],b,0});
                }
            }
        }
    }
    cout << min(distancia[n][0],distancia[n][1]) << '\n';
}