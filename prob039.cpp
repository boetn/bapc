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
#define NUM 6

int main()
{
    freopen("in.txt", "r", stdin);

    int n;
    cin >> n;
    while (n--) {
        int c[NUM];
        for (int i = 0; i < NUM; ++i)
            cin >> c[i];

        int dp[10*MAX];
        memset(dp, 0, sizeof(dp));

        queue<int> q;
        for (int i = 0; i < NUM; ++i) {
            dp[c[i]] = 1;
            q.push(c[i]);
        }

        while (!q.empty()) {
            int value = q.front();
            q.pop();

            for (int i = 0; i < NUM; i++) {
                int prev = value - c[i];
                int next = value + c[i];

                if (prev > 0 && !dp[prev]) {
                    dp[prev] = dp[value] + 1;
                    q.push(prev);
                }
                if (next < 10 * MAX && !dp[next]) {
                    dp[next] = dp[value] + 1;
                    q.push(next);
                }
            }
        }

        printf("%.2f %d\n", accumulate(dp + 1, dp + MAX + 1, 0) / 100.0,
                            *max_element(dp + 1, dp + MAX + 1));
    }

    return 0;
}
