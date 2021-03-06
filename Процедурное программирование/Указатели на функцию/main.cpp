#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <cmath>

#include "Header.h"

int main()
{
	setlocale(0, "");
	float(*func[3])(float);
	func[1] = function_1;
	func[2] = function_2;
	int  N, numerfunc = -1;
	float x, Xn, Xf, y, dx, Ymax, Xmax;
	void(*maxmin)(float**, int, float&, float&) = NULL;
	maxmin = maxarg;

	while (numerfunc != 0) {
		while (numerfunc < 0 || numerfunc > 2) {
			printf("Выберите одну из функций:\nx*x  -  1\nx-|x|*2  -  2\n");
			scanf("%d", &numerfunc);
		}
		printf("Введите Xнач: ");
		scanf("%f", &Xn);
		printf("Введите Xкон: ");
		scanf("%f", &Xf);
		printf("Введите количество точек: ");
		scanf("%d", &N);
		x = Xn;
		float **mass = new float*[2];
		mass[0] = new float[N];
		mass[1] = new float[N];
		dx = (Xf - Xn) / (N - 1);
		if (numerfunc < 0 || numerfunc > 2) break;
		for (int i = 0; i < N; i++) {
			y = func[numerfunc](x);
			mass[0][i] = y;
			mass[1][i] = x;
			x += dx;
		}
		maxmin(mass, N, Ymax, Xmax);
		printf("Максимальное значение функции: %4.2f[%4.2f]\n\n\n", Ymax, Xmax);
		printf("Закончить работу? 0 - Да   1 - Нет\n");
		scanf("%d", &numerfunc);
	}

	return 0;
}
