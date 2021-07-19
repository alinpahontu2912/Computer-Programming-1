#include <stdio.h>
int digits(long int n) { // aflam nr de cifre al numarului
    int x = 0;
    while (n) {
        x++;
        n /= 10;
    }
    return x;
}
void create_v(long int n, int v[]) { // vector cu cifrele unui numar
    int i = 0;
    while (n) {
        v[i++] = n % 10;
        n /= 10;
    }
}
void rising_v(int n, int v[]) { // ordonare descrescatoare
    for (int i = 0 ; i < n-1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (v[i] > v[j]) {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}
long int create_number(int n, int v[]) { // creem numarul
    long int x = 0, p = 1;
    for (int i = 0; i < n ; i++) {
        x = x + v[i] * p;
        p *= 10;
    }
    return x;
}
long int reverse(long int x) { // calculam palindrom
    long int r = 0;
    while (x) {
        if (x % 10 == 0) {
            x /= 10;
        }
        r = r * 10 + x % 10;
        x /= 10;
    }
    return r;
}
long int dif(long int x, long int y) {
    return x - y;
}
int verify(int n, long int v[]) { // verificam daca se repeta vreun element
    for (int i = 0; i < n-1; i++) {
        long int x = v[i];
        for (int j = i+1; j < n; j++) {
            if (x == v[j]) {
                return 0;
            }
        }
    }
    return 1;
}
int main() {
    long int n, v[100];
    int c[100], m, a, l, k, ok, i;
    scanf("%ld", &n);
    m = digits(n);
    create_v(n, c);
    rising_v(m, c);
    v[0] = create_number(m, c);
    v[0] = dif(v[0], reverse(v[0]));
    n = v[0];
    m = digits(n);
    create_v(n, c);
    rising_v(m, c);
    v[1] = create_number(m, c);
    v[1] = dif(v[1], reverse(v[1]));
    ok = 1;
    i = 2;
    while (ok) {
        ok = verify(i, v);
        n = v[i-1];
        m = digits(n);
        create_v(n, c);
        rising_v(m, c);
        v[i] = create_number(m, c);
        v[i] = dif(v[i], reverse(v[i]));
        i++;
    }
    a = i; // i e nr de numere pe care le compune pana se opreste
    for (int i = 0; i < a-1; i++) {
        for (int j = i + 1; j < a; j++) {
            if (v[i] == v[j]) {
                k = i;
                l = j;
                break;
            }
        }
    }
    printf("%d\n", k-1);
    for (int i = k-1 ; i < l-1 ; i++) {
        printf("%ld ", v[i]);
    }
    return 0;
}

