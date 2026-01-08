#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

/* Gezegen Yercekimi Ivmeleri (m/s^2) */
double g_dizisi[] = {3.7, 8.87, 9.81, 3.71, 24.79, 10.44, 8.87, 11.15};
const char *g_isimleri[] = {"Merkur", "Venus", "Dunya", "Mars", "Jupiter", "Saturn", "Uranus", "Neptun"};

/* Tum Deney Fonksiyonlarinin Prototipleri */
void serbestDusme(double *p);
void yukariAtis(double *p);
void agirlikDeneyi(double *p);
void potansiyelEnerji(double *p);
void hidrostatikBasinc(double *p);
void arsimetKaldirma(double *p);
void basitSarkac(double *p);
void ipGerilmesi(double *p);
void asansorDeneyi(double *p);

int main() {
    char bilim_insani[100];
    int secim;

    printf("Bilim Insani Adini Giriniz: ");
    scanf("%s", bilim_insani);

    while (1) {
        printf("\n--- Sayin %s, Deney Menusu ---\n", bilim_insani);
        printf("1. Serbest Dusme\n2. Yukari Atis\n3. Agirlik\n4. Potansiyel Enerji\n5. Hidrostatik Basinc\n");
        printf("6. Arsimet Kaldirma\n7. Basit Sarkac\n8. Ip Gerilmesi\n9. Asansor Deneyi\n-1. CIKIS\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        if (secim == -1) break; /* -1 girilirse program durur */

        switch (secim) {
            case 1: serbestDusme(g_dizisi); break;
            case 2: yukariAtis(g_dizisi); break;
            case 3: agirlikDeneyi(g_dizisi); break;
            case 4: potansiyelEnerji(g_dizisi); break;
            case 5: hidrostatikBasinc(g_dizisi); break;
            case 6: arsimetKaldirma(g_dizisi); break;
            case 7: basitSarkac(g_dizisi); break;
            case 8: ipGerilmesi(g_dizisi); break;
            case 9: asansorDeneyi(g_dizisi); break;
            default: printf("Gecersiz secim!\n");
        }
    }
    return 0;
}

void serbestDusme(double *p) {
    double t, h;
    printf("Sure (s): "); scanf("%lf", &t);
    t = (t < 0) ? -t : t; /* Ternary mutlak deger */
    for (int i = 0; i < 8; i++) {
        h = 0.5 * (*(p + i)) * t * t; /* Pointer aritmetigi */
        printf("%s: %.2f m yol kat edildi.\n", *(g_isimleri + i), h);
    }
}

void yukariAtis(double *p) {
    double v0, hmax;
    printf("Firlatma Hizi (m/s): "); scanf("%lf", &v0);
    v0 = (v0 < 0) ? -v0 : v0;
    for (int i = 0; i < 8; i++) {
        hmax = (v0 * v0) / (2 * (*(p + i)));
        printf("%s: Maksimum Yukseklik = %.2f m\n", *(g_isimleri + i), hmax);
    }
}

void agirlikDeneyi(double *p) {
    double m, G;
    printf("Kutle (kg): "); scanf("%lf", &m);
    m = (m < 0) ? -m : m;
    for (int i = 0; i < 8; i++) {
        G = m * (*(p + i));
        printf("%s: Agirlik = %.2f Newton\n", *(g_isimleri + i), G);
    }
}

void potansiyelEnerji(double *p) {
    double m, h, Ep;
    printf("Kutle (kg): "); scanf("%lf", &m);
    printf("Yukseklik (m): "); scanf("%lf", &h);
    m = (m < 0) ? -m : m; h = (h < 0) ? -h : h;
    for (int i = 0; i < 8; i++) {
        Ep = m * (*(p + i)) * h;
        printf("%s: Enerji = %.2f Joule\n", *(g_isimleri + i), Ep);
    }
}

void hidrostatikBasinc(double *p) {
    double rho, h, P;
    printf("Sivi Yogunlugu (kg/m3): "); scanf("%lf", &rho);
    printf("Derinlik (m): "); scanf("%lf", &h);
    rho = (rho < 0) ? -rho : rho; h = (h < 0) ? -h : h;
    for (int i = 0; i < 8; i++) {
        P = rho * (*(p + i)) * h;
        printf("%s: Basinc = %.2f Pascal\n", *(g_isimleri + i), P);
    }
}

void arsimetKaldirma(double *p) {
    double rho, V, Fk;
    printf("Sivi Yogunlugu (kg/m3): "); scanf("%lf", &rho);
    printf("Batan Hacim (m3): "); scanf("%lf", &V);
    rho = (rho < 0) ? -rho : rho; V = (V < 0) ? -V : V;
    for (int i = 0; i < 8; i++) {
        Fk = rho * (*(p + i)) * V;
        printf("%s: Kaldýrma Kuvveti = %.2f Newton\n", *(g_isimleri + i), Fk);
    }
}

void basitSarkac(double *p) {
    double L, T;
    printf("Sarkac Uzunlugu (m): "); scanf("%lf", &L);
    L = (L < 0) ? -L : L;
    for (int i = 0; i < 8; i++) {
        T = 2 * PI * sqrt(L / (*(p + i)));
        printf("%s: Periyot = %.2f saniye\n", *(g_isimleri + i), T);
    }
}

void ipGerilmesi(double *p) {
    double m, T;
    printf("Kutle (kg): "); scanf("%lf", &m);
    m = (m < 0) ? -m : m;
    for (int i = 0; i < 8; i++) {
        T = m * (*(p + i));
        printf("%s: Ip Gerilmesi = %.2f Newton\n", *(g_isimleri + i), T);
    }
}

void asansorDeneyi(double *p) {
    double m, a, N;
    int durum;
    printf("Kutle (kg): "); scanf("%lf", &m);
    printf("Asansor Ivmesi (m/s2): "); scanf("%lf", &a);
    printf("Durum (1: Hizlanan Yukari, 2: Hizlanan Asagi): "); scanf("%d", &durum);
    m = (m < 0) ? -m : m; a = (a < 0) ? -a : a;
    for (int i = 0; i < 8; i++) {
        N = (durum == 1) ? m * ((*(p + i)) + a) : m * ((*(p + i)) - a);
        printf("%s: Etkin Agirlik = %.2f Newton\n", *(g_isimleri + i), N);
    }
}
