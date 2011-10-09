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

struct die {
    int top, left, right, up, down, hidden;

    die () {
        top = 1, left = 3, right = 4, up = 5, down = 2, hidden = 6;
    }

    void moveright () {
        int temp = right;
        right = top;
        top = left;
        left = hidden;
        hidden = temp;
    }

    void moveleft () {
        int temp = left;
        left = top;
        top = right;
        right = hidden;
        hidden = temp;
    }

    void moveup() {
        int temp = up;
        up = top;
        top = down;
        down = hidden;
        hidden = temp;
    }

    void movedown() {
        int temp = down;
        down = top;
        top = up;
        up = hidden;
        hidden = temp;
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);

    int ncases;
    cin >> ncases;

    while (ncases--) {
        string s;
        cin >> s;

        int i = 0, sign = 1, x = 0, y = 0;
        die d;
        while (s[i] != '.') {
            int num = 0;
            if (s[i] == '-' || s[i] == '+') {
                sign *= -1;
                ++i;
            }
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                ++i;
            }
            if (!num) num = 1;
            int dir = s[i++];

            int dx = 0, dy = 0;
            if (dir == 'X')
                dx = sign * num;
            else
                dy = sign * num;

            x += dx;
            y += dy;
            num %= 4;

            while (num--) {
                if (sign < 0 && dir == 'X')
                    d.moveleft();
                else if (sign > 0 && dir == 'X')
                    d.moveright();
                else if (sign < 0 && dir == 'Y')
                    d.movedown();
                else if (sign > 0 && dir == 'Y')
                    d.moveup();
            }
        }

        cout << "position (" << x << "," << y << "), " << d.top << " dots" << endl;
    }

    return 0;
}
