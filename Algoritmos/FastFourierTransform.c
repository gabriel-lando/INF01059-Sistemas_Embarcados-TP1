#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

#define TAM 10

void fft(double dat[], int nn, int isign) {
    int n, mmax, m, j, istep, i;
    double wtemp, wr, wpr, wpi, wi, theta;
    double tempr, tempi;

    n = nn << 1;
    j = 1;
    for (i = 1; i < n; i += 2) {
        if (j > i) {
            tempr = dat[j];
            dat[j] = dat[i];
            dat[i] = tempr;
            tempr = dat[j + 1];
            dat[j + 1] = dat[i + 1];
            dat[i + 1] = tempr;
        }
        m = n >> 1;
        while (m >= 2 && j > m) {
            j -= m;
            m >>= 1;
        }
        j += m;
    }
    mmax = 2;
    while (n > mmax) {
        istep = 2 * mmax;
        theta = (2.0 * 3.14) / (isign * mmax);
        wtemp = sin(0.5 * theta);
        wpr = -2.0 * wtemp * wtemp;
        wpi = sin(theta);
        wr = 1.0;
        wi = 0.0;
        for (m = 1; m < mmax; m += 2) {
            for (i = m; i <= n; i += istep) {
                j = i + mmax;
                tempr = wr * dat[j] - wi * dat[j + 1];
                tempi = wr * dat[j + 1] + wi * dat[j];
                dat[j] = dat[i] - tempr;
                dat[j + 1] = dat[i + 1] - tempi;
                dat[i] += tempr;
                dat[i + 1] += tempi;
            }
            wr = (wtemp = wr) * wpr - wi * wpi + wr;
            wi = wi * wpr + wtemp * wpi + wi;
        }
        mmax = istep;
    }
}
 
int main()
{
	double buf[TAM] = { 39, 341.32, 257.79, 487.96, 371.93, 118.68, 31.86, 452.4, 174.38, 52.63 };
	
	fft(buf, TAM, 1);
    fft(buf, TAM, -1);
 
	return 0;
}
