#include <cstdio>
#include <string.h>
using namespace std;

#define MAX 200

int dist(char *s1, char *s2)
{
    int n=0;
    while (*s1)
        n += (*s1++ != *s2++);
    return n;
}

int main()
{
    int n;
    scanf("%d", &n);

    while (n--) {
        char sacha[MAX];
        int szDict;
        scanf("%s", sacha);
        scanf("%d", &szDict);
        
        int minDist = 200;
        char closest[MAX];
        while (szDict--) {
            int min;
            char cmp[MAX];
            scanf("%s", cmp);
            
            if ((min = dist(sacha, cmp)) < minDist) {
                minDist = min;
                strcpy(closest, cmp);
            }
        }
        printf("%s\n", closest);
    }

    return 0;
}
