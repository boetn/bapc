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
        int p, n;
        cin >> p >> n;
        ++p;
        int v[n];
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        sort(v, v + n);

        int each = n / p, som = 0;
        for (int i = n - 1; i > n - 1 - each; --i)
            som += v[i];
        cout << som << endl;
    }

    return 0;
}
