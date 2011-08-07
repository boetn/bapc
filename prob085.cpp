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

int mapcard(string c)
{
    int v = 0;
    if (isdigit(c[0])) v += c[0] - '0';
    else if (c[0] == 'T') v += 10;
    else if (c[0] == 'J') v += 11;
    else if (c[0] == 'Q') v += 12;
    else if (c[0] == 'K') v += 13;
    else if (c[0] == 'A') v += 14;
    v = (v - 2) * 4;

    if (c[1] == 'C') v += 0;
    else if (c[1] == 'D') v += 1;
    else if (c[1] == 'S') v += 2;
    else if (c[1] == 'H') v += 3;

    return v;
}

void readcards(int *a, int n)
{
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i] = mapcard(s);
    }
    sort(a, a + n);
}

int main()
{
    int ncases;
    cin >> ncases;
    while (ncases--) {
        int n;
        cin >> n;
        int a[n], e[n];

        readcards(a, n);
        readcards(e, n);

        int i = 0, j = 0;
        int wins = 0;
        while (j < n) {
            if (e[j] > a[i]) {
                ++wins;
                ++j;
                ++i;
            } else
                ++j;
        }

        cout << wins << endl;
    }

    return 0;
}
