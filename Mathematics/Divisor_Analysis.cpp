#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
template<class T, class _Cmp = std::less<T>>
using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, _Cmp, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;
using namespace std;
using ll = long long;
using ld = long double;

const ll mod = 1e9 + 7;

map<ll, ll> mappingModToPhi;
template<long long mod>
class modll{
    public:
    ll val, phi;
    modll(ll val = 0, ll phi = 0){
        this->val = (val % mod + mod) % mod;
        if (phi) this->phi = phi;
        else this->phi = getPhi();
    }

    void setVal(ll val){
        this->val = (val % mod + mod) % mod;
    }

    ll getPhi(){
        auto it = mappingModToPhi.find(mod);
        if (it != mappingModToPhi.end()) return it->second;
        ll n = mod;
        ll phi = mod;
        for (ll i = 2; i * i <= n; i++){
            if (n % i == 0){
                while (n % i == 0) n /= i;
                phi -= phi / i;
            }
        }
        if (n > 1) phi -= phi / n;
        mappingModToPhi[mod] = phi;
        return phi;
    }

    operator long long(){ return this->val;}
    modll operator +(ll num){ return modll<mod>(val + num, phi);}
    modll operator -(ll num){ return modll<mod>(val - num, phi);}
    modll operator *(ll num){ return modll<mod>(val * num, phi);}
    modll operator ^(ll num){
        ll a = val;
        ll ans = 1;
        num = (num % phi + phi) % phi;
        while (num){
            if (num & 1) ans = (ans * a) % mod;
            a = (a * a) % mod;
            num >>= 1;
        }
        return modll<mod>(ans, phi);
    }
    modll operator /(ll num){
        modll<mod> x(num, phi);
        x ^= -1;
        return operator*(x);
    }

    void operator +=(ll num){ setVal(val + num);}
    void operator -=(ll num){ setVal(val - num);}
    void operator *=(ll num){ setVal(val * num);}
    void operator ^=(ll num){
        ll a = val;
        ll ans = 1;
        num = (num % phi + phi) % phi;
        while (num){
            if (num & 1) ans = (ans * a) % mod;
            a = (a * a) % mod;
            num >>= 1;
        }
        setVal(ans);
    }
    void operator /=(ll num){
        modll<mod> x =  operator/(num);
        setVal(x);
    }
};

template<long long mod>
istream &operator>>(istream &in, modll<mod> &a){
    ll x;
    in >> x;
    a.setVal(x);
    return in;
}

template<long long mod>
ostream &operator<<(ostream &out, modll<mod> &a){
    out << a.val;
    return out;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    modll<mod> cnt(1), sum(1), product(1), number(1), rt(1);
    modll<mod - 1> cnt2(1);
    bool allEven = true;
    while (n--){
        modll<mod> p, q;
        cin >> p >> q;
        if (q.val & 1) allEven = false;
        cnt *= (q + 1ll);
        sum *= ((p ^ (q + 1ll)) - 1ll) / (p - 1ll);
        number *= p ^ q;
        rt *= p ^ (q / 2ll);
        cnt2 *= (q + 1ll);
    }
    if (allEven) product = rt ^ cnt2;
    else product = number ^ (cnt2 / 2ll);
    cout << cnt << " " << sum << " " << product << "\n";

    return 0;
}