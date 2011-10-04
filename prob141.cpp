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
        int n, k, x, y, l = 0, m = 0;
        cin >> n >> k;
        int a[n+2][n+2];

        memset(a, 0, sizeof(a));
        for (int i = 0; i < k; ++i) {
            cin >> x >> y;
            a[x][y] = 1;
        }

        cin >> x >> y;

        if (x == 0) l = 1;
        if (y == 0) m = 1;
        if (x == n + 1) l = -1;
        if (y == n + 1) m = -1;

        int cnt = 0, ok = 1;
        do {
            x += l;
            y += m;
            if (++cnt > n * n + 10) {
                ok = 0;
                break;
            }

            if (a[x][y]) {
                swap(l, m);
                if (!l)
                    m = -m;
            }
        } while (0 < x && x <= n && 0 < y && y <= n);

        if (!ok)
            x = y = 0;
        cout << x << " " << y << endl;
    }

    return 0;
}
