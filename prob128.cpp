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

#define EPS 1e-9

double w;

void read(double *a, int n)
{
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
}

int check(double *a, int n, int max)
{
    if (a[0] - w / 2 > EPS) return 0;
    if (max - (a[n-1] + w / 2) > EPS) return 0;

    for (int i = 1; i < n - 1; ++i) {
        if (a[i] - w - a[i-1] > EPS)
            return 0;
        if (a[i+1] - (a[i] + w) > EPS)
            return 0;
    }
    return 1;
}

int main()
{
    int nx, ny;

    while (1) {
        cin >> nx >> ny >> w;
        if (!nx && !ny && !w)
            break;

        double x[nx], y[ny];
        read(x, nx);
        read(y, ny);

        if (check(x, nx, 75.0) && check(y, ny, 100.0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
