#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

vector<ll> primeFactor;
vector<ll> factorCount;

void getFactors(ll n){
    primeFactor = vector<ll>(n + 1);
    for (ll i = 1; i <= n; i++) primeFactor[i] = i;
    for (ll i = 2; i * i <= n; i++){
        for (ll j = i; j <= n; j += i){
            if (i < primeFactor[j]) primeFactor[j] = i;
        }
    }
}

void countFactors(ll n){
    factorCount = vector<ll>(n + 1);
    factorCount[1] = 1;
    for (ll i = 2; i <= n; i++){
        ll cnt = 0;
        ll j;
        for (j = i; j % primeFactor[i] == 0; j /= primeFactor[i]) cnt++;
        factorCount[i] = (cnt + 1) * factorCount[j];
    }
}

void Solve(){
    ll n;
    cin >> n;
    cout << factorCount[n] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    getFactors(ll(1e6 + 10));
    countFactors(ll(1e6 + 10));
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++){
        // cout << "Case #" << i << ": ";
        // cerr << "Case #" << i << ": \n";
        Solve();
    }

    return 0;
}