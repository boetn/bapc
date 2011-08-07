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

#define MAX 101
int N, T, M;
int t[MAX], m[MAX], v[MAX];
int dp[MAX][MAX][MAX]; //tijd, massa, steen
int res = 0;

int solve(int time, int mass, int stone)
{
    if (stone == N)
        return 0;
    if (dp[time][mass][stone] != -1)
        return dp[time][mass][stone];

    int take = -1;
    if (time + t[stone] <= T && mass + m[stone] <= M)
        take = solve(time + t[stone], mass + m[stone], stone + 1) + v[stone];
    int notake = solve(time, mass, stone + 1);

    res = max(res, max(take, notake));
    return (dp[time][mass][stone] = max(take, notake));
}

int main()
{
    int ncases;
    cin >> ncases;
    while (ncases--) {
        memset(dp, -1, sizeof(dp));
        res = 0;
        cin >> N >> T >> M;
        for (int i = 0; i < N; i++)
            cin >> t[i] >> m[i] >> v[i];
        solve(0, 0, 0);
        cout << res << endl;
    }

    return 0;
}
