#include <stdio.h>
#define NMAX 100

void read_matrix(int a[NMAX][NMAX], int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &a[i][j]);
    }
  }
}
void rest_lin(int l[NMAX], int n) { // creem vectorul de restrictie linie
  int x, y, k = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    for (int j = 0; j < x; j++) {
      scanf("%d", &y);
      l[k] = l[k] + y;
    }
    k++;
  }
}
void rest_col(int c[NMAX], int m) { // creem vectorul de restrictie coloana
  int x, y, k = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d", &x);
    for (int j = 0; j < x; j++) {
      scanf("%d", &y);
      c[k] = c[k] + y;
    }
    k++;
  }
}
int ver_lin(int a[NMAX][NMAX], int b[NMAX], int m, int n, int l) {
  int nr = 0;
  for (int i = 0; i < m; i++) {
    if (a[l][i] == 0) {
      nr++;
    }
  }
  if (nr != m - b[l]) {
    return 0;
  }
  return 1;
} // verificam daca linia are suma dorita
int ver_col(int a[NMAX][NMAX], int b[NMAX], int m, int n, int c) {
  int nr = 0;
  for (int i = 0; i < n; i++) {
    if (a[i][c] == 0) {
      nr++;
    }
  }
  if (nr != n - b[c]) {
    return 0;
  }
  return 1;
} // verificam daca o coloana are suma dorita
int check(int a[NMAX][NMAX], int b[NMAX], int c[NMAX], int n, int m) {
  int ok1, ok2;
  ok1 = 1;
  ok2 = 1;
  for (int i = 0; i < n; i++) {
    if (ver_lin(a, b, m, n, i) == 0) {
      ok1 = 0;
    }
  }
  for (int i = 0; i < m; i++) {
    if (ver_col(a, c, m, n, i) == 0) {
      ok2 = 0;
    }
  }
  if (ok1 == 1 && ok2 == 1) {
    return 1;
  }
  return 0;
} // verficiam intreaga matrice in functie de restrictii
int main() {
  int t, n, m, l[NMAX], c[NMAX], p[NMAX][NMAX];
  scanf("%d", &t);
  for (int k = 0; k < t; k++) {
    for (int i = 0; i < NMAX; i++) {
      l[i] = 0;
      c[i] = 0;
      for (int j = 0; j < NMAX; j++) {
        p[i][j] = 0;
      }
    }
    scanf("%d%d", &n, &m);
    rest_lin(l, n);
    rest_col(c, m);
    read_matrix(p, n, m);
    if (check(p, l, c, n, m) == 1) {
      printf("Corect\n");
    } else {
      printf("Eroare\n");
    }
  }
  return 0;
}
