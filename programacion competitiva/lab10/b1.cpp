#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXI = (1e5) + 2;
ll t[4 * MAXI];
int ones_count[4 * MAXI];

void join(int v) {
    t[v] = t[2 * v] + t[2 * v + 1];
    ones_count[v] = ones_count[2 * v] + ones_count[2 * v + 1];
}

void build(ll a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
        ones_count[v] = a[tl];
    } else {
        int tm = tl + (tr - tl) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        join(v);
    }
}

ll sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v];
    int tm = tl + (tr - tl) / 2;
    return sum(2 * v, tl, tm, l, min(r, tm)) + sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        t[v] = 1 - t[v];
        ones_count[v] = t[v];
    } else {
        int tm = tl + (tr - tl) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos);
        else
            update(2 * v + 1, tm + 1, tr, pos);
        join(v);
    }
}

int find_kth_one(int v, int tl, int tr, int k) {
    if (tl == tr)
        return tl;
    int tm = tl + (tr - tl) / 2;
    if (ones_count[2 * v] > k)
        return find_kth_one(2 * v, tl, tm, k);
    else
        return find_kth_one(2 * v + 1, tm + 1, tr, k - ones_count[2 * v]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    build(a, 1, 0, n - 1);

    for (int i = 0; i < m; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int pos;
            cin >> pos;
            update(1, 0, n - 1, pos);
        } else {
            int k;
            cin >> k;
            int index = find_kth_one(1, 0, n - 1, k);
            cout << index << "\n";
        }
    }

    return 0;
}
