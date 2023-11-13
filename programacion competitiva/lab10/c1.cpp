#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXI = (1e5) + 2;
ll t[4 * MAXI];
int min_index[4 * MAXI];

void join(int v) {
    if (t[2 * v] < t[2 * v + 1])
        min_index[v] = min_index[2 * v];
    else if (t[2 * v] > t[2 * v + 1])
        min_index[v] = min_index[2 * v + 1];
    else
        min_index[v] = min(min_index[2 * v], min_index[2 * v + 1]);
}

void build(ll a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
        min_index[v] = tl;
    } else {
        int tm = tl + (tr - tl) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        join(v);
    }
}

ll sum(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return INT_MAX;
    if (l == tl && r == tr)
        return t[v];
    int tm = tl + (tr - tl) / 2;
    return min(sum(2 * v, tl, tm, l, min(r, tm)), sum(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void update(int v, int tl, int tr, int pos, ll new_value) {
    if (tl == tr) {
        t[v] = new_value;
    } else {
        int tm = tl + (tr - tl) / 2;
        if (pos <= tm)
            update(2 * v, tl, tm, pos, new_value);
        else
            update(2 * v + 1, tm + 1, tr, pos, new_value);
        join(v);
    }
}

int find_min_index(int v, int tl, int tr, int x) {
    if (tl == tr) {
        if (t[v] >= x)
            return tl;
        else
            return -1;
    }
    int tm = tl + (tr - tl) / 2;
    if (t[2 * v] >= x)
        return find_min_index(2 * v, tl, tm, x);
    else if (t[2 * v + 1] >= x)
        return find_min_index(2 * v + 1, tm + 1, tr, x);
    else
        return -1;
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
            ll new_value;
            cin >> pos >> new_value;
            update(1, 0, n, pos, new_value);
        } else {
            ll x;
            cin >> x;
            int index = find_min_index(1, 0, n, x);
            cout << index << "\n";
        }
    }

    return 0;
}