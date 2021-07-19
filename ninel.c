#include <stdio.h>
int main() {
    long int n, nrc, nr, x, y, s, H = 0, h = 1000001;
    double avg;
    int ok1, ok2; // 2 variabile cu care sa verificam inaltimile copacilor
    scanf("%ld", &n);
    scanf("%ld%ld", &x, &y);
    nr = 2; // am citit primii 2 copaci
    nrc = 0;
    s = 0;
    for (int i = 1; i < n - 1; i++) {
        ok1 = x < y;
        x = y;
        scanf("%ld", &y);
        nr++;
        ok2 = x > y;
        if (ok1 == 1 && ok2 == 1) { // daca arborele din mijloc e special
            s += x;
            nrc++;
            if (nr % 2 && x > H) {
                H = x;
            }
            if (nr % 2 == 0 && x < h) {
                h = x;
            }
        }
        ok1 = ok2 = 0; // dupa 3 copaci modificam iar ok1 si ok2
    }
    if (nrc == 0) { // daca nu exista copaci speciali
        avg = 0;
        H = 0;
        h = 0;
    } else {
        avg = (double) s/nrc*1.0;
    if (H == 0) { // daca nu exista niciun copac special pe pozitie impara
        H = -1;
    }
    if (h == 1000001) { // daca nu exista niciun copac speciaal pe poz para
        h = -1; // h este 1000001 ptc este mai mare decat inaltimea maxima
    }
    }
    printf("%ld\n", s);
    printf("%0.7f\n", avg);
    printf("%ld\n", H);
    printf("%ld\n", h);
    return 0;
}
