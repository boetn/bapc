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

#define N 510

int seen[N][N][8]; //row, column, time%8
int vis[N][N][8];

int dr[] = {1, 0, -1, 0, 0};
int dc[] = {0, 1, 0, -1, 0};

struct point {
    int r, c, t;
    point(int r, int c, int t) : r(r), c(c), t(t) {}
};

inline int inside(int r, int c, int n)
{
    return (r > 0 && c > 0 && r < 2 * n && c < 2 * n);
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int ncases;
    cin >> ncases;

    while (ncases--) {
        int n, k;
        cin >> n >> k;

        memset(seen, 0, sizeof(seen));
        for (int i = 0; i < k; ++i) {
            int r, c, d = 0;
            char dir;
            cin >> r >> c >> dir;

            if (dir == 'B') d = 0;
            if (dir == 'R') d = 1;
            if (dir == 'F') d = 2;
            if (dir == 'L') d = 3;

            for (int j = 0; j < 4; ++j) {
                int cr = r, cc = c;
                while (inside(cr, cc, n)) {
                    seen[cr][cc][j*2] = 1;
                    seen[cr][cc][j*2+1] = 1;
                    cr += dr[d];
                    cc += dc[d];
                }
                d = (d + 1) % 4;
            }
        }

        int success = 0;
        memset(vis, 0, sizeof(vis));
        queue<point> q;
        for (int i = 1; i < 2 * n; i += 2) {
            q.push(point(0, i, 0));
            vis[0][i][0] = 1;
        }

        while (!q.empty()) {
            point curr = q.front();
            q.pop();
            if (curr.r == 2 * n) {
                success = 1;
                break;
            }
            for (int i = 0; i < 5; ++i) {
                point next(curr.r + dr[i], curr.c + dc[i], (curr.t + 1) % 8);
                if (!(next.r == 0 || next.r == 2 * n) && !inside(next.r, next.c, n))
                    continue;
                if ((next.r % 2 == 0 && next.c % 2 == 0) || vis[next.r][next.c][next.t])
                    continue;
                if (seen[curr.r][curr.c][(curr.t+1)%8] || seen[next.r][next.c][next.t])
                    continue;
                q.push(next);
                vis[next.r][next.c][next.t] = 1;
            }
        }

        cout << (success ? "succeeds" : "fails") << endl;
    }

    return 0;
}
