#include <stdio.h>
#include <math.h>

// Fungsi turunan suhu dT/dt sesuai hukum pendinginan Newton
double coolingRate(double T, double T_env, double k) {
    return -k * (T - T_env);
}

// Fungsi solusi eksak (analitik)
double exactSolution(double T0, double T_env, double k, double t) {
    return T_env + (T0 - T_env) * exp(-k * t);
}

int main() {
    // Parameter awal
    double T0 = 90.0;         // Suhu awal (°C)
    double T_env = 25.0;      // Suhu lingkungan (°C)
    double k = 0.1;           // Konstanta pendinginan (/detik)
    double dt = 10.0;         // Langkah waktu (detik)
    double t_max = 100.0;     // Simulasi sampai 100 detik

    // Inisialisasi nilai awal
    double T = T0;
    double t = 0.0;

    // Buka file output CSV
    FILE *fp = fopen("output_pendinginan_full.csv", "w");
    if (fp == NULL) {
        printf("Gagal membuat file CSV.\n");
        return 1;
    }

    // Tulis header CSV
    fprintf(fp, "Waktu (detik),T_Euler,T_Exact,Error_Absolut\n");

    // Tampilkan header ke CMD
    printf("=======================================================\n");
    printf("  t (s) |  T_Euler (°C) |  T_Exact (°C) |  Error Absolut\n");
    printf("=======================================================\n");

    // Simulasi Euler
    while (t <= t_max + 0.01) {
        double T_exact = exactSolution(T0, T_env, k, t);
        double error = fabs(T - T_exact);

        // Tampilkan ke terminal
        printf(" %6.0f |     %8.2f   |    %8.2f   |     %8.4f\n", t, T, T_exact, error);

        // Simpan ke CSV
        fprintf(fp, "%.0f,%.4f,%.4f,%.4f\n", t, T, T_exact, error);

        // Update nilai suhu dengan Euler
        T = T + dt * coolingRate(T, T_env, k);
        t += dt;
    }

    fclose(fp);
    printf("=======================================================\n");
    printf("Simulasi selesai. Data disimpan di 'output_pendinginan_full.csv'.\n");

    return 0;
}
