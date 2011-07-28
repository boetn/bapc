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

//betere oplossing: enkel events verwerken, en aan change alles optellen

struct row {
    int timeneeded;
    int progress;
    deque<int> q;
    deque< pair<int, int> > join;
    deque< pair<int, int> > change;

    int waiting_time() {
        int time = 0;
        tr (q, it) time += *it;
        return time + timeneeded * q.size();
    }
};

pair<int, int> best_row(row *bk, int n)
{
    int mintijd = 10000;
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

int simulate(row *bk, int n)
{
    int row = best_row(bk, n).first;
    bk[row].q.push_back(-1);
    int time = 0;

    while (1) {
        //events
        int nope = 0;
        for (int i = 0; i < n; i++) {
            if (bk[i].join.empty())
                continue;
            pair<int, int> join = bk[i].join.front();
            if (join.first == time) {
                bk[i].q.pb(join.second);
                bk[i].join.pop_front();
                nope = 1;
                break;
            }
        }

        for (int i = 0; !nope && i < n; i++) {
            if (bk[i].change.empty())
                continue;
            pair<int, int> change = bk[i].change.front();
            if (change.first == time) {
                bk[i].timeneeded = change.second;
                pair<int, int> curr_best = best_row(bk, n);
                if (curr_best.second < bk[row].waiting_time()) {
                    bk[row].q.erase(find(all(bk[row].q), -1));
                    bk[curr_best.first].q.push_back(-1);
                    bk[curr_best.first].progress = 0;
                }
                bk[i].change.pop_front();
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (bk[i].q.empty())
                continue;
            int cust = bk[i].q.front();
            if (cust == -1) //MSX
                return time;
            bk[i].progress++;
            if (bk[i].progress == cust + bk[i].timeneeded) { //customer afgehandeld
                bk[i].progress = 0;
                bk[i].q.pop_front();
            }
        }

        time++;
    }
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
                if (mintime == 0 && time == 0) continue;
                bk[id].q.pb(time);
            }
        }

        int nevents;
        cin >> nevents;

        while (nevents--) {
            string kind;
            int time, id, data;
            cin >> kind >> time >> id >> data;

            if (kind == "join")
                bk[id].join.pb(make_pair(time, data));
            else if (kind == "change")
                bk[id].change.pb(make_pair(time, data));
        }

        //for (int i = 0; i < total; i++) {
        //    sort(all(bk[i].join));
        //    sort(all(bk[i].change));
        //}

        cout << simulate(bk, total) << endl;
    }

    return 0;
}
