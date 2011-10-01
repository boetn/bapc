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

int ok(vector<int> &indep)
{
    int n = indep.size();
    if (n == 1)
        return 1;
    else if (n > 1)
        cout << "missing hints" << endl;
    else
        cout << "recheck hints" << endl;
    return 0;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int ncases;
    cin >> ncases;

    while (ncases--) {
        int n, h;
        cin >> n >> h;

        int indeg[n+1]; //indegree nodes
        vector<int> g[n+1], result, indep; //independent

        memset(indeg, 0, sizeof(indeg));
        for (int i = 0; i < h; ++i) {
            int a, b;
            cin >> a >> b;
            g[a].pb(b);
            ++indeg[b];
        }

        for (int i = 1; i <= n; ++i)
            if (indeg[i] == 0)
                indep.pb(i);

        int num = 0, fail = 0;
        while (num != n) {
            if (!ok(indep)) {
                fail = 1;
                break;
            }
            int curr = indep.back();
            indep.pop_back();
            result.pb(curr);
            ++num;

            foreach (g[curr], next) {
                if (--indeg[*next] == 0)
                    indep.pb(*next);
            }
        }

        if (fail)
            continue;

        cout << result[0];
        for (int i = 1; i < n; ++i)
            cout << " " << result[i];
        cout << endl;
    }

    return 0;
}
