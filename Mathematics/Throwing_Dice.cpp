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


template<class T>
class Matrix{
    public:
    int n, m;
    vector<vector<T>> matrix;
    Matrix(int n, int m){
        this->n = n;
        this->m = m;
        matrix = vector<vector<T>>(n, vector<T>(m));
    }

    Matrix<T> operator+(Matrix<T> &other){
        assert(n == other.n && m == other.m);
        Matrix<T> ans(n, m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) 
                ans.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
        return ans;
    }

    Matrix<T> operator-(Matrix<T> &other){
        assert(n == other.n && m == other.m);
        Matrix<T> ans(n, m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) 
                ans.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
        return ans;
    }

    Matrix<T> operator*(Matrix<T> &other){
        assert(m == other.n);
        Matrix<T> ans(n, other.m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < other.m; j++){
                for (int k = 0; k < m; k++)
                    ans.matrix[i][j] += matrix[i][k] + other.matrix[k][j];
            }
        }
        return ans;
    }

    void operator+=(Matrix<T> other){
        assert(n == other.n && m == other.m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) 
                matrix[i][j] += other.matrix[i][j];
        }
    }

    void operator-=(Matrix<T> other){
        assert(n == other.n && m == other.m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) 
                matrix[i][j] -= other.matrix[i][j];
        }
    }

    void operator*=(Matrix<T> other){
        assert(m == other.n);
        Matrix<T> ans(n, other.m);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < other.m; j++){
                for (int k = 0; k < m; k++)
                    ans.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
        matrix = ans.matrix;
        m = other.m;
    }

    void operator=(Matrix<T> other){
        n = other.n;
        m = other.m;
        matrix = other.matrix;
    }
};

template<class A, class N>
A binary_exponent(A a, N n){
    assert(n > 0);
    A ans = a;
    n--;
    while (n){
        if (n & 1) ans *= a;
        a *= a;
        n >>= 1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Matrix<modll<mod>> a(6, 6);
    for (ll i = 0; i < 6; i++) a.matrix[0][i].setVal(1);
    for (ll i = 0; i < 5; i++) a.matrix[i + 1][i].setVal(1);
    ll n;
    cin >> n;
    if (n == 1) cout << "1\n";
    else if (n == 2) cout << "2\n";
    else if (n == 3) cout << "4\n";
    else if (n == 4) cout << "8\n";
    else if (n == 5) cout << "16\n";
    else{
        Matrix<modll<mod>> ans = binary_exponent(a, n - 5);
        cout << ans.matrix[0][0] * 16ll + ans.matrix[0][1] * 8ll + ans.matrix[0][2] * 4ll + ans.matrix[0][3] * 2ll + ans.matrix[0][4] + ans.matrix[0][5] << "\n";
    }

    return 0;
}