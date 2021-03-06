#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <tchar.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

double plsum(const float mass[], int size) {
	int max = mass[0], min = max;
	for (int t = 0; t < size; t++) {
		if (mass[t] > max) max = mass[t];
		if (mass[t] < min) min = mass[t];
	}
	return (max + min) / 2;
}

void normalize(float mass[], int size, int polsum) {
	for (int t = 0; t < size; t++)
		mass[t] /= polsum;
}

int main()
{
	FILE *fin = fopen("aaa.txt", "r"), *fout = fopen("bbb.txt", "w");
	int i;
	char smv;
	float dmass[256], j, polsum;
	do {
		i = 0;
		do {
			fscanf(fin, "%f%c", &j, &smv);
			dmass[i] = j;
			i++;
		} while (smv != '\n');
		if (i <= 1) break;
		polsum = plsum(dmass, i);
		normalize(dmass, i, polsum);
		for (int k = 0; k < i; k++)
		fprintf(fout, "%f ", dmass[k]);
		fprintf(fout, "\n");
	} while (!feof(fin));
	fclose(fin);
	fclose(fout);
	return 0;
}
