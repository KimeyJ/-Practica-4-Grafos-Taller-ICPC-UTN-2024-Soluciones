#include <bits/stdc++.h>

#define forr(i, a, b) for(ll i = (ll) a; i < (ll) b; i++)
#define forn(i, n) forr(i, 0, n)
#define pb push_back
#define fst first
#define snd second

typedef long long ll;
typedef long double ld;

using namespace std;

char grid[1005][1005];
bool visited[1005][1005];
int n,m;


void countrooms(int i, int j) {
    if (visited[i][j] == true) return;
    visited[i][j] = true;
    if (i+1 < n && i+1 >= 0 && j<m && j >= 0 && grid[i+1][j] != '#') countrooms(i+1, j);
    if (i - 1 < n && i - 1 >= 0 && j < m && j >= 0 && grid[i-1][j] != '#') countrooms(i - 1, j);
    if (i<n && i>=0 && j+1<m && j+1 >= 0 && grid[i][j+1] != '#') countrooms(i,j+1);
    if (i<n && i>=0 && j-1<m && j-1 >= 0 && grid[i][j-1] != '#') countrooms(i,j-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int rooms=0;
    cin >> n >> m;
    forn(i,n) {
        forn(j,m) {
            cin >> grid[i][j];
        }
    }
    forn(i,n) {
        forn(j,m) {    
            if (visited[i][j] == false && grid[i][j] != '#') {
                rooms++;
                countrooms(i,j);
            }
        }
    }
   cout << rooms << '\n';
}