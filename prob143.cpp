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
        cin >> n;
        int num[n];

        for (int i = 0; i < n; ++i)
            cin >> num[i];

        int m = 1;
        while (1) {
            int used[m], ok = 1;
            memset(used, 0, sizeof(used));

            for (int i = 0; i < n; ++i) {
                if (used[num[i] % m]) {
                    ok = 0;
                    break;
                }
                used[num[i] % m] = 1;
            }
            if (ok) break;
            ++m;
        }

        cout << m << endl;
    }

    return 0;
}
