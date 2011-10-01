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

#define MAX 100100

vector<int> g[MAX];
int dist[MAX];

int dfs(int v, int prev)
{
    int max_dist = 0;
    foreach (g[v], u)
        if (*u != prev)
            max_dist = max(max_dist, 1 + dfs(*u, v));
    return (dist[v] = max_dist);
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int ncases;
    cin >> ncases;

    while (ncases--) {
        int numV;
        cin >> numV;

        memset(dist, -1, sizeof(dist));
        for (int i = 0; i < numV; ++i)
            g[i].clear();

        for (int i = 0; i < numV - 1; ++i) {
            int u, v;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }

        dfs(0, -1);

        int max1 = 0, max2 = 0;
        foreach (g[0], v) {
            if (dist[*v] + 1 >= max1) {
                max2 = max1;
                max1 = dist[*v] + 1;
            }
            else if (dist[*v] + 1 >= max2) 
                max2 = dist[*v] + 1;
        }

        cout << (max1 + max2 + 1) / 2 << endl;
    }

    return 0;
}
