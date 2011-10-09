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

typedef vector< pair<int, int> > vii;

int main()
{
    //freopen("105.in", "r", stdin);

    while (1) {
        int n, m;
        cin >> n >> m;
        if (!n && !m)
            break;

        vii calls;
        for (int i = 0; i < n; ++i) {
            int source, dest, start, duration;
            cin >> source >> dest >> start >> duration;
            calls.pb(pair<int, int>(start, start + duration));
        }
        
        
        while (m--) {
            int begin, end;
            cin >> begin >> end;
            end += begin;

            int num = 0;
            foreach(calls, c)
                if ((c->st < begin && c->nd > begin) ||
                    (c->st >= begin && c->nd <= end) ||
                    (c->st < end && c->nd > end))
                ++num;
            cout << num << endl;
        }
    }

    return 0;
}
