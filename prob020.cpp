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

#define MAX 10000
#define SQ 120

int main()
{
    //freopen("in.txt", "r", stdin);

    int board[SQ][SQ];
    int res[MAX+1];
    int cnt[6] = {0};
    int dir[][2] = {{0, -1}, { -1, -1}, { -1, 0}, {0, 1}, {1, 1}, {1, 0}};
    int x = SQ / 2, y = SQ / 2;
    int curr = 2, d = 0;

    memset(board, 0, sizeof(board));
    board[x][y] = 1;
    cnt[1]++;
    res[1] = 1;

    while (curr <= MAX) {
        x += dir[d][0];
        y += dir[d][1];

        int nd = (d + 1) % 6;
        if (!board[x+dir[nd][0]][y+dir[nd][1]])
            d = nd;
        if (curr == 2)
            d++;

        int adj[6] = {0};
        for (int i = 0; i < 6; ++i)
            adj[board[x+dir[i][0]][y+dir[i][1]]]++;

        int pick = -1;
        for (int i = 1; i <= 5; ++i)
            if (!adj[i] && (pick == -1 || cnt[i] < cnt[pick]))
                pick = i;

//        cout << "picked: " << pick << " with next direction " << d << endl;
//        cout << "\tplaced it on " << x << ", " << y << endl;

        board[x][y] = pick;
        res[curr] = pick;
        cnt[pick]++;
        curr++;
    }

    int n;
    cin >> n;

    while (n--) {
        int num;
        cin >> num;
        cout << res[num] << endl;
    }

    return 0;
}
