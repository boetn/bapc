#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
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
#include <utility>
#include <vector>
using namespace std;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

int absurdity(int n)
{
    int last = 0;
    while (!last) {
        last = n % 10;
        n /= 10;
    }

    int num = 1;
    while (n) {
        n /= 10;
        num++;
    }

    return last == 5 ? 2 * num - 1 : 2 * num;
}

int prev(int n, int dist)
{
    return n - n % dist;
}

int next(int n, int dist)
{
    return n + dist - n % dist;
}

int found(int n)
{
    int low = ceil(0.95 * n);
    int high = floor(1.05 * n);
    int fac = 1;
    int dist = 5;
    int abn = absurdity(n);

    while (1) {
        int pr = prev(n, dist * fac);
        int ne = next(n, dist * fac);

        if (pr < low && ne > high)
            break;

        if (pr >= low && absurdity(pr) < abn)
            return 1;
        if (ne <= high && absurdity(ne) < abn)
            return 1;

        if (dist == 1) {
            dist = 5;
            fac *= 10;
        } else
            dist = 1;
    }

    return 0;
}

int main()
{
    int num;
    cin >> num;

    while (num--) {
        int n;
        cin >> n;

        if (!found(n))
            cout << "not ";
        cout << "absurd" << endl;
    }

    return 0;
}
