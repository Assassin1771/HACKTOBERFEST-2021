#include <bits/stdc++.h>
using namespace std;

#define lli long long
#define loop(i, l, r) for (lli i = l; i < r; i++)
#define rev(i, r, l) for (lli i = r; i >= l; i--)
#define itr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define endl "\n"
#define inputarray(arr, start, size) \
    loop(i, start, size) { cin >> arr[i]; }
#define printarray(arr, start, size)                \
    loop(i, start, size) { cout << arr[i] << " "; } \
    cout << endl;
#define mod 1000000007
#define inf 1e18
#define sp(x, y) fixed << setprecision(y) << x << endl;
#define pii pair<lli, lli>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define debug(x) cout << #x << " = " << x << endl

int main()
{
    lli t = 1;
    cin >> t;
    while (t--)
    {
        lli n;
        cin >> n;
        vector<lli> v(n);
        loop(i, 0, n) cin >> v[i];
        vector<lli> sorted(v.begin(), v.end());
        sortall(sorted);
        vector<vector<int>> vv;
        printarray(sorted, 0, n);
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == sorted[i]) continue;
            for (int j = i; j < n; j++) {
                if (v[j] == sorted[k]) {
                    cout << i << j << "sdfa" << endl;
                    vector<int> res;
                    if (j != i) {
                        res.push_back(i); res.push_back(j); res.push_back(j - i); vv.push_back(res);
                        for (int x = 0; x < j - i; x++) {
                            int y, first;
                            first = v[i];
                            for (y = i; y < j; y++) {
                                v[y] = v[y + 1];
                            }
                            v[y] = first;
                        }
                        for (int x = 0; x < n; x++) cout << v[x] << "-" ;
                        cout << endl;

                        k++;
                    }


                }
                if (j == n - 1) k++;
            }
        }
        cout << vv.size() << endl;
        for (int i = 0; i < vv.size(); i++) {
            cout << vv[i][0] + 1 << " " << vv[i][1] + 1 << " " << vv[i][2] << endl;
        }

    }
    return 0;
}