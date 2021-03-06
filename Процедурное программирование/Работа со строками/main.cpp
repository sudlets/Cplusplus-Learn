#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <clocale>


int words_count(char **mass, int i) {
	int len, j, k = 0;
	len = strlen(mass[i]);
	for (j = 1; j < len; j++)
		if ((mass[i][j] == ' ') && (mass[i][j + 1] != ' ')) k++;
	if ((mass[i][j] == ' ') && i == len || mass[i][j] != ' ' && i == len) k++;
	return k;
}

void in2_mass(char **mass, int count) {
	char *s; int words;
	for (int i = 0, k = 0; i < count; i++) {
		printf("Ввод строки №%d: ", i + 1); fgets(mass[i], 128, stdin);
		s = strchr(mass[i], '\n'); if (s != NULL) *s = '\0';
		words = words_count(mass, i);
		if (words < 2) {
			printf("Вы ввели слишком мало слов %d :( ", words);
			i--;
		}
	}
}

void out2_mass(char **mass, int count) {
	for (int i = 0; i < count; i++)
		printf("Массив №%d: %s\n", i + 1, mass[i]);
}

void space_delete(char ** mass, int str)
{
	int i, j;
	for (int l = 0; l < str; l++) {
		int len = strlen(mass[l]);
		for (i = 0, j = 0; i < len; i++)
			if (mass[l][i] != ' ' || (mass[l][i] == ' ') && (mass[l][i + 1] != ' '))
				mass[l][j++] = mass[l][i];
		mass[l][j] = '\0';
	}
}

void delete_two_word(char **mass, int count, int minlen) {
	int k, j, i;
	for (int str = 0; str < count; str++) {
		k = 0;
		char *first_word = new char[strlen(mass[str])], *residue = new char[strlen(mass[str])];
		int len = strlen(mass[str]);
		first_word[0] = mass[str][0];
		for (i = 1; i < len; i++) {
			if (mass[str][i] != ' ') first_word[i] = mass[str][i];
			else {
				first_word[i] = '\0';
				i++;
				break;
			}
		}
		for (; i < len; i++) {
			if (mass[str][i] != ' ') k++;
			else break;
		}
		if (k < minlen) {
			for (j = 0; i < len; i++, j++) {
				residue[j] = mass[str][i];
			}
			residue[j] = '\0';
			strcpy(mass[str], first_word);
			strcat(mass[str], residue);
		}
	}
}

int main() {
	setlocale(0, "");
	int str, minlen;
	printf("Введите количество строк (Не больше 20)\n");
	scanf("%d", &str);
	getchar();
	while (str >= 20 || str <= 0) {
		printf("Err0r! Try again!\n");
		scanf("%d", &str);
		getchar();
	}
	printf("Минимальная длина второго слова: ");
	scanf("%d", &minlen);
	getchar();
	char **text = new char*[str];
	for (int i = 0; i < str; i++)
		text[i] = new char[128];
	in2_mass(text, str);
	printf("\n");
	space_delete(text, str);
	delete_two_word(text, str, minlen);
	out2_mass(text, str);
	for (int i = 0; i < str; i++)
		delete[] text[i];
	delete[] text;
	printf("Для продолжения нажмите любую кнопку...\n");
	getchar();
	return 0;
}
