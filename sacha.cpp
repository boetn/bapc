#include <iostream>
#include <string>
using namespace std;

int dist(string s1, string s2)
{
    int d = 0;
    for (unsigned int i=0; i<s1.size(); i++)
        if (s1[i] != s2[i])
            d++;
    return d;
}

int main()
{
    int n;
    cin >> n;

    while (n--) {
        string sacha;
        int szDict;
        cin >> sacha;
        cin >> szDict;
        
        int minDist = 200;
        string closest;
        while (szDict--) {
            int min;
            string cmp;
            cin >> cmp;
            
            if ((min = dist(sacha, cmp)) < minDist) {
                minDist = min;
                closest = cmp;
            }
        }
        cout << closest << endl;
    }

    return 0;
}
