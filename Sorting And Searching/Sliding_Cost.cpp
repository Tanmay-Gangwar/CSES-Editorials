#include<bits/stdc++.h>
using namespace std;
 
template<class T, class Cmp = less<T>>
class BST{
    public:
    struct Node{
        T val;
        long long sum;
        int height, size;
        Node *left, *right, *parent;
        Node(T val, long long sum, int height, int size, Node *left, Node *right, Node *parent){
            this->val = val;
            this->sum = sum;
            this->height = height;
            this->size = size;
            this->left = left;
            this->right = right;
            this->parent = parent;
        }
        Node(){
            this->sum = 0;
            this->height = 0;
            this->size = 0;
        }
    };
 
    Cmp cmp;
    Node *null = new Node();
    Node *root = null;
 
    void update(Node *node){
        node->height = max(node->left->height, node->right->height) + 1;
        node->size = node->left->size + node->right->size + 1;
        node->sum = node->left->sum + node->right->sum + node->val.first;
    }
 
    void rightRotate(Node *x){
        Node *y = x->left;
        Node *p = x->parent;
        if (y->right != null) y->right->parent = x;
        x->left = y->right;
        x->parent = y;
        y->right = x;
        y->parent = p;
        if (p == null) root = y;
        else if (cmp(y->val, p->val)) p->left = y;
        else p->right = y;
        update(x);
        update(y);
    }
 
    void leftRotate(Node *x){
        Node *y = x->right;
        Node *p = x->parent;
        if (y->left != null) y->left->parent = x;
        x->right = y->left;
        x->parent = y;
        y->left = x;
        y->parent = p;
        if (p == null) root = y;
        else if (cmp(y->val, p->val)) p->left = y;
        else p->right = y;
        update(x);
        update(y);
    }
 
    void insert(T val){
        Node *parent = null, *curr = root;
        while (curr != null){
            parent = curr;
            if (val == curr->val) return;
            if (cmp(val, curr->val)) curr = curr->left;
            else curr = curr->right;
        }
        Node *node = new Node(val, val.first, 1, 1, null, null, parent);
        if (parent == null) root = node;
        else if (cmp(val, parent->val)) parent->left = node;
        else parent->right = node;
        update(node);
        subtreeFixup(node->parent);
    }
 
    void subtreeFixup(Node *node){
        while (node != null){
            update(node);
            if (node->left->height == node->right->height + 2){
                if (node->left->left->height + 2 == node->left->height) leftRotate(node->left);
                rightRotate(node);
            }
            else if (node->right->height == node->left->height + 2){
                if (node->right->right->height + 2 == node->right->height) rightRotate(node->right);
                leftRotate(node);
            }
            node = node->parent;
        }
    }
 
    void erase(T val){
        Node *node = find(val);
        if (node == null) return;
        erase(node);
    }
 
    void erase(Node *node){
        if (node->right == null){
            if (node->left != null) node->left->parent = node->parent;
            if (node->parent == null) root = node->left;
            else if (node->parent->left == node) node->parent->left = node->left;
            else node->parent->right = node->left;
            subtreeFixup(node->parent);
            return;
        }
        if (node->left == null){
            node->right->parent = node->parent;
            if (node->parent == null) root = node->right;
            else if (node->parent->left == node) node->parent->left = node->right;
            else node->parent->right = node->right;
            subtreeFixup(node->parent);
            return;
        }
        Node *toDelete = successor(node);
        node->val = toDelete->val;
        erase(toDelete);
    }
 
    Node *find(T val){
        Node *node = root;
        while (node != null){
            if (val == node->val) return node;
            if (cmp(val, node->val)) node = node->left;
            else node = node->right;
        }
        return node;
    }
 
    Node *find_by_order(int i){
        Node *node = root;
        while (node != null){
            if (node->left->size == i) return node;
            if (node->left->size < i){
                i -= node->left->size + 1;
                node = node->right;
            }
            else node = node->left;
        }
        return node;
    }
 
    long long sum_by_order(int i){
        long long sum = 0;
        Node *node = root;
        while (node != null){
            if (node->left->size == i) return sum + node->left->sum;
            if (node->left->size < i){
                i -= node->left->size + 1;
                sum += node->left->sum + node->val.first;
                node = node->right;
            }
            else node = node->left;
        }
        return sum;
    }
 
    Node* successor(Node *node){
        if (node->right != null){
            node = node->right;
            while (node->left != null) node = node->left;
            return node;
        }
        while (node->parent->right == node) node = node->parent;
        return node->parent;
    }
 
    Node *predecessor(Node *node){
        if (node->left != null){
            node = node->left;
            while (node->right != null) node = node->right;
            return node->right;
        }
        while (node->parent->left == node) node = node->parent;
        return node->parent;
    }
};
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    BST<pair<long long, int>> b;
    for (long long i = 0; i < k - 1; i++) {
        b.insert({a[i], i});
    }
    for (long long i = k - 1; i < n; i++){
        b.insert({a[i], i});
        auto it = b.find_by_order((k - 1) / 2);
        long long val = it->val.first;
        long long left = b.sum_by_order((k - 1) / 2);
        long long right = b.root->sum - left;
        cout << val * ((k - 1) / 2) - left + right - val * (k - (k - 1) / 2) << " ";
        b.erase({a[i - k + 1], i - k + 1});
    }
 
    return 0;
}