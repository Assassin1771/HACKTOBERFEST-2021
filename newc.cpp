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

#define N 5
#define M 4



int main()
{
    lli t = 1;
    // cin >> t;
    while (t--)
    {
        int mat[M][N] =
        {
            {1, 2, 1, 4, 8},
            {2, 1, 8, 5, 1},

            {8, 1, 7, 3, 1},
            {8, 1, 1, 7, 9},
        };

        unordered_set<int> st;
        for (int i = 0; i < N; i++) {
            st.insert(mat[0][i]); // 1,2,4,8
        }


        for (int i = 1; i < M; i++)
        {
            unordered_set<int> temp;
            for (int j = 0; j < N; j++) {
                if (st.find(mat[i][j]) != st.end()) {
                    temp.insert(mat[i][j]);
                }
            }
            st.clear();
            st = temp;
        }
        for (auto it : st) cout << it << " ";
    }
    return 0;
}