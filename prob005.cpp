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

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

deque< pair<int, pair<int, int> > > change;
deque< pair<int, pair<int, int> > > join;

struct row {
    int timeneeded;
    int progress;
    deque<int> q;

    int waiting_time() {
        return accumulate(all(q), 0) + timeneeded * sz(q) - progress;
    }

    int time_msx() 
    {
        deque<int>::iterator pos = find(all(q), -1);
        return accumulate(q.begin(), pos, 0) +
               (pos - q.begin()) * timeneeded
               - progress;
    }
};

pair<int, int> best_row(row *bk, int n)
{
    int mintijd = 1000000;
    int best = 0;

    for (int i = 0; i < n; i++) {
        int curr = bk[i].waiting_time();
        if (curr < mintijd) {
            mintijd = curr;
            best = i;
        }
    }

    return make_pair(best, mintijd);
}

int simulate(row bk[], int n)
{
    int row = best_row(bk, n).first;
    bk[row].q.pb(-1);
    int time = 0;

    for (int i = 0; i < sz(change); i++) {
        int changetime = change[i].first;
        int r = change[i].second.first;
        int perf = change[i].second.second;

        //mensen toevoegen tot aan changetime
        int cnt = 0;
        tr (join, it) {
            if (it->first <= changetime) {
                cnt++;
                bk[it->second.first].q.pb(it->second.second);
            } else
                break;
        }
        while (cnt--) join.pop_front();

        //voorbijgegane tijd verwerken
        for (int i = 0; i < n; i++) {
            int timepast = changetime - time;
            while (timepast) {
                if (bk[i].q.empty()) break;
                int next = bk[i].q.front();
                if (next == -1)
                    return changetime - timepast;
                next += bk[i].timeneeded - bk[i].progress;
                if (next <= timepast) {
                    timepast -= next;
                    bk[i].q.pop_front();
                    bk[i].progress = 0;
                } else {
                    bk[i].progress = timepast;
                    timepast = 0;
                }
            }
        }

        time = changetime;

        //consider rijwissel
        bk[r].timeneeded = perf;
        bk[r].progress = 0;
        pair<int, int> curr = best_row(bk, n);
        if (curr.first != row && curr.second < bk[row].time_msx()) {
            bk[row].q.erase(find(all(bk[row].q), -1));
            bk[curr.first].q.pb(-1);
            row = curr.first;
        }
    }

    //-1 komt na alle changes
    return time + bk[row].time_msx();
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int ncases;
    cin >> ncases;

    while (ncases--) {
        int nqueues, total;
        cin >> nqueues;
        row bk[nqueues];

        total = nqueues;
        while (nqueues--) {
            int id, cust, mintime;
            cin >> id >> cust >> mintime;
            bk[id].timeneeded = mintime;
            bk[id].progress = 0;

            while (cust--) {
                int time;
                cin >> time;
                bk[id].q.pb(time);
            }
        }

        int nevents;
        cin >> nevents;

        join.clear();
        change.clear();
        while (nevents--) {
            string kind;
            int time, id, data;
            cin >> kind >> time >> id >> data;

            if (kind == "join")
                join.pb(make_pair(time, make_pair(id, data)));
            else if (kind == "change")
                change.pb(make_pair(time, make_pair(id, data)));
        }

        for (int i = 0; i < total; i++) {
            sort(all(join));
            sort(all(change));
        }

        cout << simulate(bk, total) << endl;
    }

    return 0;
}
