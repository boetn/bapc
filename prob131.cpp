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


int main()
{
    //freopen("in.txt", "r", stdin);

    int ncases;
    cin >> ncases;
    while (ncases--) {
        int n;
        string a, b;
        cin >> n >> a >> b;

        int dp[n+1][n+1], best = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (abs(a[i-1] - b[j-1]) <= 1)
                    dp[i][j] = dp[i-1][j-1] + 1, best = max(best, dp[i][j]);

        if (best >= (n + 1) / 2)
            cout << "POSITIVE" << endl;
        else
            cout << "NEGATIVE" << endl;
    }

    return 0;
}
