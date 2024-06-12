// https://www.youtube.com/watch?v=fWLCQAwDt-0

#include <iostream>
#include <stdio.h>

using namespace std;

const int MAXN = 1 + 1e6;

int n, q, parent[MAXN];

void make_set(int u) {
    parent[u] = u;
}

int find_set(int u) {
    if (u == parent[u])
        return u;
    return find_set(parent[u]);
}

void union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u == v)
        return;
    parent[u] = v;
}

int main() {
    freopen("CTDL.inp", "r", stdin);
    freopen("CTDL.out", "w", stdout);
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        make_set(i);
    }

    while (q--) {
        char query = 'Q';
        int x, y;
        cin >> query >> x >> y;
        if (query == 'Q') {
            if (find_set(x) == find_set(y))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        } else {
            union_set(x, y);
        }
    }
}