#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

class Node
{
public:
    int mn;
    int mx;
};

#define SP << fixed << showpoint << setprecision(1)

Node max_min(Node *tree, int l, int r, int lq, int rq, int idx)
{
    Node aim, left, right;
    if (lq <= l && rq >= r)
        return tree[idx];

    if (r < lq || l > rq)
    {
        aim.mn = INT_MAX;
        aim.mx = INT_MIN;
        return aim;
    }

    int mid = l + (r - l) / 2;
    left = max_min(tree, l, mid, lq, rq, 2 * idx + 1);
    right = max_min(tree, mid + 1, r, lq, rq, 2 * idx + 2);

    aim.mn = min(left.mn, right.mn);
    aim.mx = max(left.mx, right.mx);

    return aim;
}

Node getMax_Min(Node *tree, int n, int lq, int rq)
{
    Node tmp;

    if (lq < 0 || rq > n - 1 || lq > rq)
    {
        tmp.mn = INT_MAX;
        tmp.mx = INT_MIN;
        return tmp;
    }

    return max_min(tree, 0, n - 1, lq, rq, 0);
}

void makeSegmentTree(int arr[], int l, int r, Node *tree, int idx)
{
    if (l == r)
    {
        tree[idx].mn = arr[l];
        tree[idx].mx = arr[l];
        return;
    }

    int mid = l + (r - l) / 2;

    makeSegmentTree(arr, l, mid, tree, idx * 2 + 1);
    makeSegmentTree(arr, mid + 1, r, tree, idx * 2 + 2);

    tree[idx].mn = min(tree[idx * 2 + 1].mn, tree[idx * 2 + 2].mn);
    tree[idx].mx = max(tree[idx * 2 + 1].mx, tree[idx * 2 + 2].mx);
}

Node *makeST(int arr[], int n)
{
    int h = (int)(ceil(log2(n)));
    int max_size = 2 * (int)pow(2, h) - 1;
    Node *st = new Node[max_size];

    makeSegmentTree(arr, 0, n - 1, st, 0);

    return st;
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int h = (int)(ceil(log2(n)));
    int len = 2 * (int)pow(2, h) - 1;

    Node *tree = makeST(a, n);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        Node res = getMax_Min(tree, n, l, r);
        Node res1, res2;

        if (l > 0 && r < n - 1)
        {
            res1 = getMax_Min(tree, n, 0, l - 1);
            res2 = getMax_Min(tree, n, r + 1, n - 1);

            if (1.0 * (res.mx - res.mn) / 2.0 > max(res1.mx, res2.mx))
                cout SP << (double)(res.mn + 1.0 * (res.mx - res.mn) / 2.0);
            else
                cout SP << (double)(res.mn + max(res1.mx, res2.mx));
        }
        else if (l > 0)
        {
            res1 = getMax_Min(tree, n, l - 1, 0);

            if (1.0 * (res.mx - res.mn) / 2.0 > res1.mx)
                cout SP << (double)(res.mn + 1.0 * (res.mx - res.mn) / 2.0);
            else
                cout SP << (double)(res.mn + res1.mx);
        }
        else if (r < n - 1)
        {
            res2 = getMax_Min(tree, n, r + 1, n - 1);

            if (1.0 * (res.mx - res.mn) / 2.0 > res2.mx)
                cout SP << (double)(res.mn + 1.0 * (res.mx - res.mn) / 2.0);
            else
                cout SP << (double)(res.mn + res2.mx);
        }
        else
        {
            cout SP << (double)(res.mn + 1.0 * (res.mx - res.mn) / 2.0);
        }

        cout << "\n";
    }

    return 0;
}
