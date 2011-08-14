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

#define P 11

int skill[P][P];
int used[P];

int solve(int pos)
{
    if (pos == P) return 0;
    int best = -2000;
    for (int i = 0; i < P; i++) {
        if (!used[i] && skill[pos][i]) {
            used[i] = 1;
            best = max(best, solve(pos + 1) + skill[pos][i]);
            used[i] = 0;
        }
    }
    return best;
}

int main()
{
    int ncases;
    cin >> ncases;

    while (ncases--) {
        for (int i = 0; i < P; ++i)
            for (int j = 0; j < P; ++j)
                cin >> skill[i][j];
        memset(used, 0, sizeof(used));
        cout << solve(0) << endl;
    }

    return 0;
}
