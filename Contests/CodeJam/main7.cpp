#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

#define MAX_VALUE ll(1e8 + 10)
#define MAX_SIZE ll(1e5 + 5)
#define SP << fixed << showpoint << setprecision(1)
ll a[MAX_SIZE];

class Node
{
public:
    pair<ll, ll> min_max;
};

Node *tree = new Node[MAX_SIZE];

Node MaxMin(int l, int r, int lq, int rq, int idx)
{
    if (r < lq || l > rq)
    {
        Node tmp;
        tmp.min_max.first = MAX_VALUE;
        tmp.min_max.second = 0;

        return tmp;
    }

    if (lq <= l && rq >= r)
        return tree[idx];

    Node left, right, aim;
    int mid = l + (r - l) / 2;

    left = MaxMin(l, mid, lq, rq, 2 * idx + 1);
    right = MaxMin(mid + 1, r, lq, rq, 2 * idx + 2);

    aim.min_max.first = min(left.min_max.first, right.min_max.first);
    aim.min_max.second = max(left.min_max.second, right.min_max.second);

    return aim;
}

void makeST(int l, int r, int idx)
{
    if (l == r)
    {
        tree[idx].min_max.first = a[l];
        tree[idx].min_max.second = a[r];
        return;
    }

    int mid = l + (r - l) / 2;

    makeST(l, mid, idx * 2 + 1);
    makeST(mid + 1, r, idx * 2 + 2);

    tree[idx].min_max.first = min(tree[idx * 2 + 1].min_max.first, tree[idx * 2 + 2].min_max.first);
    tree[idx].min_max.second = max(tree[idx * 2 + 1].min_max.second, tree[idx * 2 + 2].min_max.second);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int h = (int)(ceil(log2(n)));
    int len = 2 * (int)pow(2, h) - 1;

    makeST(0, n - 1, 0);

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        Node res = MaxMin(0, n - 1, l, r, 0);
        Node res1, res2;

        if (l > 0 && r < n - 1)
        {
            res1 = MaxMin(0, n - 1, 0, l - 1, 0);
            res2 = MaxMin(0, n - 1, r + 1, n - 1, 0);

            if (1.0 * (res.min_max.second - res.min_max.first) / 2.0 > max(res1.min_max.second, res2.min_max.second))
                cout SP << (double)(res.min_max.first + 1.0 * (res.min_max.second - res.min_max.first) / 2.0);
            else
                cout SP << (double)(res.min_max.first + max(res1.min_max.second, res2.min_max.second));
        }
        else if (l > 0)
        {
            res1 = MaxMin(0, n - 1, 0, l - 1, 0);

            if (1.0 * (res.min_max.second - res.min_max.first) / 2.0 > res1.min_max.second)
                cout SP << (double)(res.min_max.first + 1.0 * (res.min_max.second - res.min_max.first) / 2.0);
            else
                cout SP << (double)(res.min_max.first + res1.min_max.second);
        }
        else if (r < n - 1)
        {
            res2 = MaxMin(0, n - 1, r + 1, n - 1, 0);

            if (1.0 * (res.min_max.second - res.min_max.first) / 2.0 > res2.min_max.second)
                cout SP << (double)(res.min_max.first + 1.0 * (res.min_max.second - res.min_max.first) / 2.0);
            else
                cout SP << (double)(res.min_max.first + res2.min_max.second);
        }
        else
        {
            cout SP << (double)(res.min_max.first + 1.0 * (res.min_max.second - res.min_max.first) / 2.0);
        }

        cout << "\n";
    }

    return 0;
}
