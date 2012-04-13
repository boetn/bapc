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
    string s;

    while (cin >> n >> s) {
        if (!n) break;

        char last = '.';
        int poslast = 0;
        int mindist = INT_MAX;
        for (int i = 0; i < sz(s); ++i) {
            if (s[i] == '.')
                continue;
            if (s[i] == 'Z') {
                mindist = 0;
                break;
            }

            if (last == '.') {
                last = s[i];
                poslast = i;
                continue;
            }

            if (s[i] == last) {
                poslast = i;
                continue;
            }

            mindist = min(mindist, i - poslast);
            poslast = i;
            last = s[i];
        }

        cout << mindist << endl;
    }

    return 0;
}
