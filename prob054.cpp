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
    int n;
    cin >> n;
    while (n--) {
        int ncoins, m;
        cin >> ncoins >> m;

        int coins[ncoins];
        for (int i = 0; i < ncoins; i++)
            cin >> coins[i];
        sort(coins, coins+ncoins);

        unsigned long long dp[m+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for (int i = 0; i < ncoins; i++)
            for (int j = 0; j <= m; j++)
                if ((i == 0 || coins[i] != coins[i-1]) && coins[i] <= j)
                    dp[j] += dp[j-coins[i]];

        cout << dp[m] << endl;
    }

    return 0;
}
