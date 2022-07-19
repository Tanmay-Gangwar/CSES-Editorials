#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;
 
vector<ll> primeFactor;
void getFactors(ll n){
    primeFactor = vector<ll>(n + 1);
    for (ll i = 1; i <= n; i++) primeFactor[i] = i;
    for (ll i = 2; i * i <= n; i++){
        for (ll j = i; j <= n; j += i){
            if (i < primeFactor[j]) primeFactor[j] = i;
        }
    }
}
 
vector<ll> mobius;
void getMobius(ll n){
    mobius = vector<ll>(n + 1);
    mobius[1] = 1;
    for (ll i = 2; i <= n; i++){
        if (primeFactor[i] == i) mobius[i] = -1;
        else if (primeFactor[i] == primeFactor[i / primeFactor[i]]) mobius[i] = 0;
        else mobius[i] = mobius[primeFactor[i]] * mobius[i / primeFactor[i]];
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    ll n, MX = 1e6;
    cin >> n;
    vector<ll> a(n);
    vector<ll> TempCnt(MX + 1);
    vector<ll> cnt(MX + 1);
    for (ll &x: a) {
        cin >> x;
        TempCnt[x]++;
    }
    for (ll d = MX; d >= 1; d--){
        for (ll i = d; i <= MX; i += d) cnt[d] += TempCnt[i];
    }
    getFactors(MX);
    getMobius(MX);
    ll ans = 0;
    for (ll i = 1; i <= MX; i++){
        ans += mobius[i] * cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << ans << "\n";
 
    return 0;
}