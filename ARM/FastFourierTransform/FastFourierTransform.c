#include <math.h>
#include <stdlib.h>
#include <complex.h>

#define TAM 10
#define PI 3.1415926535897932384

typedef double complex cplx;
 
void _fft(cplx buf[], cplx out[], int n, int step)
{
	if (step < n) {
		_fft(out, buf, n, step * 2);
		_fft(out + step, buf + step, n, step * 2);
 
		for (int i = 0; i < n; i += 2 * step) {
			cplx t = cexp(-I * PI * i / n) * out[i + step];
			buf[i / 2]     = out[i] + t;
			buf[(i + n)/2] = out[i] - t;
		}
	}
}
 
void fft(cplx buf[], int n)
{
	cplx out[n];
	for (int i = 0; i < n; i++) out[i] = buf[i];
 
	_fft(buf, out, n, 1);
}
 
int main()
{
	cplx buf[TAM] = { 39, 341.32, 257.79, 487.96, 371.93, 118.68, 31.86, 452.4, 174.38, 52.63 };
	
	fft(buf, TAM);
 
	return 0;
}
