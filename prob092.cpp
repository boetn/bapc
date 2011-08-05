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

typedef long long ll;

int main()
{
    freopen("in.txt", "r", stdin);

    int num;
    cin >> num;
    while (num--) {
        ll n;
        cin >> n;

        ll t = (n + 2) / 3;
        ll odd = (n - (n % 3) - (t + (t % 2 == 0))) / 2 + 1;
        ll even = (2 * n - (n + 1 + (n % 2 == 0))) / 2 + 1;

        if (!n)
            cout << 0 << endl;
        else
            cout << n << ": " << even + odd << endl;
    }

    return 0;
}
