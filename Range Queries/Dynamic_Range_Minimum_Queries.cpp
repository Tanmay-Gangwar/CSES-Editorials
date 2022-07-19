#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

template<class T>
struct SegOp{
    SegOp(){}
    T operator()(T a, T b){
        return min(a, b);
    }
};

template<class T, class Op = SegOp<T>>
class SegmentTree{
    public:

    struct Node{
        T val, updateValue;
        bool pendingUpdate;
        int l, r;
        Node *left, *right;

        Node(T val, int l, int r, Node *left, Node *right){
            this->val = val;
            this->l = l;
            this->r = r;
            this->left = left;
            this->right = right;
            this->pendingUpdate = false;
        }
    };

    int n;
    vector<T> a;
    Node* root;
    SegOp<T> op;

    SegmentTree(){}
    Node *create(vector<T> &a, int l, int r){
        if (l == r) return new Node(a[l], l, r, nullptr, nullptr);
        int m = (l + r) / 2;
        Node *left = create(a, l, m);
        Node *right = create(a, m + 1, r);
        return new Node(op(left->val, right->val), l, r, left, right);
    }

    void build(vector<T> a){
        root = create(a, 0, a.size() - 1);
    }

    void propogatePendingUpdate(Node *node){
        node->val = node->updateValue * (node->r - node->l + 1);            // How to update node value
        if (node->left){
            if (!node->left->pendingUpdate) {
                node->left->pendingUpdate = true;
                node->left->updateValue = 0;
            }
            if (!node->right->pendingUpdate) {
                node->right->pendingUpdate = true;
                node->right->updateValue = 0;
            }
            node->left->updateValue = node->updateValue;                    // How to update node updateValue
            node->right->updateValue = node->updateValue;                   // How to update node updateValue
        }
        node->pendingUpdate = false;
    }

    void update(Node *node, int l, int r, T val){
        if (node->pendingUpdate) propogatePendingUpdate(node);
        if (node->l == l && node->r == r){
            node->pendingUpdate = true;
            node->updateValue = val;
            return;
        }
        int m = (node->l + node->r) / 2;
        if (r <= m) update(node->left, l, r, val);
        else if (l > m) update(node->right, l, r, val);
        else{
            update(node->left, l, m, val);
            update(node->right, m + 1, r, val);
        }
        if (node->left->pendingUpdate) propogatePendingUpdate(node->left);
        if (node->right->pendingUpdate) propogatePendingUpdate(node->right);
        node->val = op(node->left->val, node->right->val);
    }

    void update(int l, int r, T val){
        update(root, l, r, val);
    }

    T query(Node *node, int l, int r){
        if (node->pendingUpdate) propogatePendingUpdate(node);
        if (node->l == l && node->r == r) return node->val;
        int m = (node->l + node->r) / 2;
        if (r <= m) return query(node->left, l, r);
        if (l > m) return query(node->right, l, r);
        return op(query(node->left, l, m),  query(node->right, m + 1, r));
    }

    T query(int l, int r){
        return query(root, l, r);
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (ll &x: a) cin >> x;
    SegmentTree<ll> tree;
    tree.build(a);
    while (q--){
        ll t;
        cin >> t;
        if (t == 1){
            ll i, x;
            cin >> i >> x;
            i--;
            tree.update(i, i, x);
        }
        else{
            ll l, r;
            cin >> l >> r;
            l--;
            r--;
            cout << tree.query(l, r) << "\n";
        }
    }    

    return 0;
}