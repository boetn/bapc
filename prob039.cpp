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

#define MAX 100

int main()
{
    freopen("in.txt", "r", stdin);

    int n;
    cin >> n;
    while (n--) {
        int c[6];
        for (int i = 0; i < 6; ++i)
            cin >> c[i];

        int dp[MAX + 1];
        fill(dp, dp + MAX + 1, 1000);
        dp[0] = 0;

        //optellen
        for (int j = 1; j <= MAX; ++j)
            for (int i = 0; i < 6; ++i)
                if (c[i] <= j)
                    dp[j] = min(dp[j], dp[j-c[i]] + 1);

        copy(dp, dp+20, ostream_iterator<int>(cout, " "));
        cout << endl;

        //aftrekken
        for (int j = MAX; j >= 1; --j)
            for (int i = 0; i < 6; ++i)
                if (c[i] <= j)
                    dp[j-c[i]] = min(dp[j-c[i]], dp[j] + 1);

        copy(dp, dp+20, ostream_iterator<int>(cout, " "));
        cout << endl;

        printf("%.2f %d\n", accumulate(dp + 1, dp + 101, 0) / 100.0,
                            *max_element(dp + 1, dp + 101));
    }

    return 0;
}
