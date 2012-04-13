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

    int n;
    cin >> n;

    while (n--) {
        int p, l0, l1, s0, s1;
        cin >> p >> l0 >> l1 >> s0 >> s1;

        int dribble0[p - 1], pass0[p - 1], dribble1[p - 1], pass1[p - 1];
        for (int i = 0; i < p - 1; ++i) cin >> pass0[i];
        for (int i = 0; i < p - 1; ++i) cin >> dribble0[i];
        for (int i = 0; i < p - 1; ++i) cin >> pass1[i];
        for (int i = 0; i < p - 1; ++i) cin >> dribble1[i];

        int dp[p][2]; //point, player
        dp[0][0] = l0;
        dp[0][1] = l1;

        for (int i = 1; i < p; ++i) {
            dp[i][0] = min(dp[i - 1][0] + dribble0[i - 1],
                           dp[i - 1][1] + pass1[i - 1]);
            dp[i][1] = min(dp[i - 1][1] + dribble1[i - 1],
                           dp[i - 1][0] + pass0[i - 1]);
        }

        cout << min(dp[p - 1][0] + s0, dp[p - 1][1] + s1) << endl;
    }

    return 0;
}
