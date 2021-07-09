#include<bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

struct vertex {
    int element;
    int lazy;
    int mx;
    int sm;

    vertex() {
        element = -1;
        lazy = -1;
        sm = 0;
        mx = 0;
    }

    vertex(int val) {
        element = val;
        sm = val;
        mx = val;
    }
};


const int N = 100005;
int arr[N];
vertex tree[4 * N];


vertex merge(vertex a, vertex b) {
    vertex c;
    c.mx = max(a.mx, b.mx);
    c.sm = a.sm + b.sm;

    if (a.element == b.element and a.element > 0) {
        c.element = a.element;
    }

    return c;
}

void assign(int node, int val, int start, int end) {
    tree[node].element = val;
    tree[node].mx = val;
    tree[node].sm = (end - start + 1) * val;
    tree[node].lazy = val;
}

void push(int node, int start, int end) {
    if (tree[node].lazy != -1) {
        if (start != end) {
            assign(2 * node, tree[node].lazy, start, end);
            assign(2 * node + 1, tree[node].lazy, start, end);
            tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
        }
        tree[node].lazy = -1;
    }
}

void buildTree(int node, int start, int end) {
    if (start == end) {
        tree[node] = vertex(arr[start]);
        return;
    }
    int mid = (start + end) / 2;
    buildTree(2 * node, start, mid);
    buildTree(2 * node + 1, mid + 1, end);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    return;
}

void update(int node, int start, int end, int l, int r, int val) {
    if (r < start || end < l) {
        return;
    }
    if (l <= start and r >= end) {
        assign(node, val, start, end);
        return;
    }
    push(node, start, end);

    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, val);
    update(2 * node + 1, mid + 1, end, l, r, val);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

void update2(int node, int start, int end, int l, int r, int val) {
    if (r < start || end < l) {
        return;
    }
    if (l <= start and r >= end and tree[node].element > 0) {
        assign(node, __gcd(val, tree[node].element), start, end);
        return;
    }
    push(node, start, end);


    int mid = (start + end) / 2;
    update2(2 * node, start, mid, l, r, val);
    update2(2 * node + 1, mid + 1, end, l, r, val);
    tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
}

vertex query(int node, int start, int end, int l, int r) {
    if (l > end  || r < start) {
        vertex c;
        return c;
    }
    push(node, start, end);
    if (l <= start and r >= end) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    if (r <= mid) {
        return query(2 * node, start, mid, l, r);
    }
    if (l > mid) {
        return query(2 * node + 1, mid + 1, end, l, r);
    }
    vertex left = query(2 * node, start, mid, l, r);
    vertex right = query(2 * node + 1, mid + 1, end, l, r);
    return merge(left, right);
}

int32_t main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    buildTree(1, 1, n);

    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        } else if (op == 2) {
            int l, r, x;
            cin >> l >> r >> x;
            update2(1, 1, n, l, r, x);
        } else if (op == 3) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r).mx << endl;
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r).sm << endl;
        }
    }
    return 0;
}