#include <bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//
//template<typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f(i,a,b) for(ll i=a;i<b;i++)
#define rev(i,a,b) for(ll i=a;i>=b;i--)
#define pb push_back
#define bp pop_back
#define mp make_pair
#define all(v) (v).begin() , (v).end()
#define ff first
#define ss second
#define sd(x) ((ll)(v).size())
#define print(x) cout<<x<<"\n"
#define itr(it, v) for (auto it = v.begin(); it != v.end(); it++)
#define PI 3.141592653589793238462
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e13
#define inf 0x3f3f3f3f  //1061109567
#define sp(x, y) fixed << setprecision(y) << x << endl;
#define pll pair<ll,ll>
#define zrobits(x)      __builtin_ctzll(x)
#define setbits(x)      __builtin_popcountll(x)
#define mem(x,y) memset(x, y, sizeof(x))
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; PRINT(x); cerr << endl;
#else
#define debug(x)
#endif

void PRINT(ll t) {cerr << t;}
void PRINT(int t) {cerr << t;}
void PRINT(string t) {cerr << t;}
void PRINT(char t) {cerr << t;}
void PRINT(ld t) {cerr << t;}
void PRINT(double t) {cerr << t;}
void PRINT(ull t) {cerr << t;}

template <class T, class V> void PRINT(pair <T, V> p);
template <class T> void PRINT(vector <T> v);
template <class T> void PRINT(set <T> v);
template <class T, class V> void PRINT(map <T, V> v);
template <class T, class V> void PRINT(unordered_map <T, V> v);
template <class T> void PRINT(multiset <T> v);
template <class T, class V> void PRINT(pair <T, V> p) {cerr << "{"; PRINT(p.ff); cerr << ","; PRINT(p.ss); cerr << "}";}
template <class T> void PRINT(vector <T> v) {cerr << "[ "; for (T i : v) {PRINT(i); cerr << " ";} cerr << "]";}
template <class T> void PRINT(set <T> v) {cerr << "[ "; for (T i : v) {PRINT(i); cerr << " ";} cerr << "]";}
template <class T> void PRINT(multiset <T> v) {cerr << "[ "; for (T i : v) {PRINT(i); cerr << " ";} cerr << "]";}
template <class T, class V> void PRINT(map <T, V> v) {cerr << "[ "; for (auto i : v) {PRINT(i); cerr << " ";} cerr << "]";}
template <class T, class V> void PRINT(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {PRINT(i); cerr << " ";} cerr << "]";}

ll power(ll x, ll y, ll mod) { ll res = 1; x = x % mod; while (y > 0) { if (y & 1) { res = (res * x);}  y = y >> 1; x = (x * x); res = res % mod; x = x % mod;}  return res % mod;}
ll invert(ll a, ll b) {return power(a, b - 2, b);} //For finding (a^-1)%b which equals to (a^(b-2) )%b(FERMAT'S LITTLE THEOREM)
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<ll> sieve(ll n) {ll*arr = new ll[n + 1](); vector<ll> vect; for (ll i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (ll j = (ll(i) * ll(i)); j <= n; j += i)arr[j] = 1;} return vect;}
ll next_prime(ll n) {vector<ll>v = sieve(n + 400); auto it = upper_bound(all(v), n); return *it;} // Maximum difference between 2 prime numbers in range of 1 to 1e8 is 220
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, invert(b, m), m) + m) % m;} //If m is prime
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : x;}
ll lcm(ll x, ll y) {return (x * y) / gcd(x, y);}

inline long long  MAX2(long long  a, long long  b) {return (a) > (b) ? (a) : (b);}
inline long long  MAX3(long long  a, long long  b, long long  c) {return (a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c));}
inline long long  MIN2(long long  a, long long  b) {return (a) < (b) ? (a) : (b);}
inline long long  MIN3(long long  a, long long b, long long c) {return (a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c));}

// ll *fact = new ll[200000 + 5];
// ll *ifact = new ll[200000 + 5];
bool check(ll x, ll y, ll n, ll m, vector<vector<char>>v, ll d, map<pair<ll, ll>, ll>&m1) {
    ll i = x - 1, j = y - 1; ll c1 = 0, c2 = 0, c = 0;
    while (i >= 0 && j >= 0) {
        if (v[i--][j--] == '*') c1++;
        else break;
    }
    i = x - 1, j = y + 1;
    while (j < m && i >= 0) {
        if (v[i--][j++] == '*') c2++;
        else break;
    }
    if (MIN2(c1, c2) < d) return false;

    debug(c1)debug(c2)
    c = MIN2(c1, c2);
    m1[mp(x , y )] = 1;
    i = x - 1, j = y - 1; m1[mp(i, j )] = 1;
    while (i >= 0 && j >= 0 && --c) {

        if (v[i--][j--] == '*') m1[mp(i, j )] = 1;
        else break;
    }
    c = MIN2(c1, c2);
    i = x - 1, j = y + 1; m1[mp(i , j )] = 1;
    while (j < m && i >= 0 && --c) {

        if (v[i--][j++] == '*') m1[mp(i , j )] = 1;
        else break;
    }
    return true;

}
void solution()
{

    ll n, m, d;
    cin >> n >> m >> d;
    vector<vector<char>>v(n, vector<char>(m));
    map<pair<ll, ll>, ll>m1;
    f(i, 0, n) {
        f(j, 0, m) {
            cin >> v[i][j];
            if (v[i][j] == '*') m1[mp(i, j)] = -1;
        }
    }

    f(i, 0, n) {
        f(j, 0, m) {

            if (v[i][j] == '*') {
                bool flag = check(i, j, n, m, v, d, m1);
            }
        }
    }
    debug(m1)
    for (auto i : m1) {
        if (i.ss == -1) {print("NO"); return;}

    }
    print("YES");

}



signed main()
{

#ifndef ONLINE_JUDGE
    freopen("check.txt", "w", stderr);
#endif
    FAST_IO;

    // // FOR FINDING FACTORIAL OF NUMBERS FROM 1 TO 2*10^5 and here MODULO is 1e9+7
    // fact[0] = 1, ifact[0] = 1;
    // for (ll i = 1; i <= 2e5; i++) {
    //   fact[i] = mod_mul(fact[i - 1], i, MOD);
    //   ifact[i] = invert(fact[i], MOD);
    // }

    ll t = 1;
    cin >> t;

    f(i, 0, t)
    {
        solution();
    }

}


 