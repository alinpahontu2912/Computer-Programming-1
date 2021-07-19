#include <stdio.h>
void read_vect(int n, int v[]) {
    for (int i = 0; i < n ; i++) {
        scanf("%d", &v[i]);
    }
}
int sum(int n, int v[], int c[]) { // calculam punctele
    int p = 0;
    for (int i = 0; i < n ; i++) {
        p = p + v[i] * c[i];
    }
    return p;
}
void sort(int n, int v[]) { // sortare descrescatoare a vectorului
    int aux;
    for (int i=0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] < v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}
int main() {
    int n, m, i, v[100], c[100], w[100], p_min, p;
    scanf("%d", &n);
    read_vect(n, v);
    read_vect(n, c);
    scanf("%d", &p_min);
    p = sum(n, v, c);
    m = 0;
    if (p > p_min) {
        m = -1;
    } else {
        for (int i = 0; i < n ; i++) { // calculam ponderea fiecarei discipline
            w[i] = c[i] * 10;
            w[i] = w[i] - v[i] * c[i];
        }
        sort(n, w); // sortam dupa ponderea cea mai mare
        i = 0;
        while (i < n && p < p_min) { // ne oprim cand i ajunge la n
        // dar putem avea mai putine puncte decat minimul
            p = p + w[i];
            m++;
            i++;
        }
    }
    if ((m == 0) || (p < p_min)) { // daca nu avem p_min sau nu trebuie marire
        m = -1;
    }
    printf("%d", m);
    return 0;
}

