// includes {{{
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
// }}}
// defines {{{
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define all(c) (c).begin(),(c).end()
#define foreach(c,i) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
// }}}

vector<string> read()
{
    string a, t;
    getline(cin, a);
    stringstream s(a);
    vector<string> res;
    while (s >> t)
        res.pb(t);
    return res;
}

int edit_dist(string as, string bs)
{
    int n = sz(as), m = sz(bs);
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; ++i)
        dp[i][0] = i;
    for (int j = 1; j <= m; ++j)
        dp[0][j] = j;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (as[i-1] == bs[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1] + 1, min(dp[i][j-1] + 1, dp[i-1][j] + 1));
        }
    }

    return dp[n][m];
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int ncases;
    cin >> ncases;
    cin.ignore();

    while (ncases--) {
        vector<string> a = read(), b = read();
        int dist[sz(a)][sz(b)];
        for (int i = 0; i < sz(a); ++i)
            for (int j = 0; j < sz(b); ++j)
                dist[i][j] = edit_dist(a[i], b[j]);

        int mini = INT_MAX;
        int indices[sz(a)];
        for (int i = 0; i < sz(a); ++i)
            indices[i] = i;
        do {
            int curr = 0;
            for (int i = 0; i < sz(b); ++i)
                curr += dist[indices[i]][i];
            mini = min(curr, mini);
        } while (next_permutation(indices, indices + sz(a)));

        cout << mini << endl;
    }

    return 0;
}
