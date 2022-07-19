#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7;
ll factorial[1000010];

ll power(ll a, ll n){
    ll ans = 1;
    while (n){
        if (n & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return ans;
}

ll inverse(ll x){
    return power(x, mod - 2);
}

ll nCr(ll n, ll r){
    ll res = (factorial[n] * inverse(factorial[r])) % mod;
    res = (res * inverse(factorial[n - r])) % mod;
    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    string s;
    cin >> s;
    if (n & 1){
        cout << "0";
        return 0;
    }
    ll m = s.length();
    stack<ll> stk;
    for (char c: s){
        if (c == '(') stk.push(c);
        else if (stk.empty()){
            cout << "0";
            return 0;
        }
        else stk.pop();
    }
    ll k = stk.size();
    n -= m + k;
    n >>= 1;
    factorial[0] = 1;
    for (ll i = 1; i <= 1000000; i++) factorial[i] = (factorial[i - 1] * i) % mod;

    ll ans = ((k + 1) * nCr(2 * n + k, n)) % mod;
    ans = (ans * inverse(n + k + 1)) % mod;
    cout << ans;


    return 0;
}