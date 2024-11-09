const int N = 2e5 + 10;
const long long INF = 1e18;
long long st[4*N], lazy[4*N], a[N];

void build(int idx, int l, int r) {
    if (l == r) st[idx] = a[l];
    else {
        int mid = (l + r) >> 1;
        build(2*idx, l, mid);
        build(2*idx + 1, mid + 1, r);
        st[idx] = min(st[2*idx], st[2*idx + 1]);
    }
}

void propagate(int idx, int l, int r) {
    if (lazy[idx] != 0) {
        st[idx] += lazy[idx];
        if (l != r) {
            lazy[2*idx] += lazy[idx];
            lazy[2*idx + 1] += lazy[idx];
        }
        lazy[idx] = 0;
    }
}

long long query(int idx, int l, int r, int i, int j) {
    if (l > j || r < i) return INF;
    propagate(idx, l, r);
    if(l >= i && r <= j) return st[idx];
    int mid = (l + r) >> 1;
    long long left = query(2*idx, l, mid, i, j);
    long long right = query(2*idx + 1, mid + 1, r, i, j);
    return min(left, right);
}

void update(int idx, int l, int r, int i, int j, long long val) {
    propagate(idx, l, r);
    if (l  > j || r < i) return;
    if (l >= i && r <= j) {
        st[idx] += val;
        if (l != r) {
            lazy[2*idx] += val;
            lazy[2*idx + 1] += val;
        }
        return;
    }
    int mid = (l + r) >> 1;
    update(2*idx, l, mid, i, j, val);
    update(2*idx + 1, mid + 1, r, i, j, val);
    st[idx] = min(st[2*idx], st[2*idx + 1]);
}