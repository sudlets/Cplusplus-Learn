#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <tchar.h>
#include <time.h>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

struct Museum {
	char name[32], address[128];
	int YoF, ticket;
};

void inputMuseums(Museum mass[], int count) {
	char *s;
	for (int i = 0; i < count; i++) {
		printf("\nName museum %d: ", i); fgets(mass[i].name, 32, stdin); s = strchr(mass[i].name, '\n'); if (s != NULL) *s = '\0';
		printf("Address museum %d: ", i); fgets(mass[i].address, 128, stdin); s = strchr(mass[i].address, '\n'); if (s != NULL) *s = '\0';
		printf("Date of Foundation of the Museum %d: ", i); cin >> mass[i].YoF;
		printf("Ticket cost of the Museum %d (in rubles): ", i); cin >> mass[i].ticket;
		getchar();

	}
	printf("Function inputMuseums DONE\n\n");
}

void outputMuseums(Museum mass[], int count) {
	for (int i = 0; i < count; i++) {
		cout << "Name museum " << i << ": " << mass[i].name << endl;
		cout << "Address museum" << i << ": " << mass[i].address << endl;
		cout << "Year of Foundation of the Museum "<< i << ": " << mass[i].YoF << endl;
		cout << "Ticket cost of the Museum" << i << ": " << mass[i].ticket << endl << endl;
	}
}

void workMuseums(Museum mass[], int count, int year, int now_year) {
	for (int i = 0; i < count; i++) {
		if (now_year - mass[i].YoF >= year) {
			cout << "Name museum " << i << ": " << mass[i].name << endl;
			cout << "Address museum" << i << ": " << mass[i].address << endl;
			cout << "Year of Foundation of the Museum " << i << ": " << mass[i].YoF << endl;
			cout << "Ticket cost of the Museum" << i << ": " << mass[i].ticket << endl << endl;
		}
	}
}
int main()
{
	setlocale(0, "");
	int year;
	printf("По какой год вести отчет времени работы музея? ");
	scanf("%d", &year);
	getchar();
	Museum p[2];
	inputMuseums(p, 2);
	workMuseums(p, 2, 15, year);
    return 0;
}

/*
void inputMuseums(Museum mass[], int count) {
	for (int i = 0; i < count; i++) {
		printf("Name museum %d: ", i); fgets(mass[i].name, 32, stdin);
		printf("Address museum %d: ", i); fgets(mass[i].address, 128, stdin);
		printf("Date of Foundation of the Museum %d: ", i); getchar(); scanf("%d\n", &mass[i].DoF);
		printf("Ticket cost of the Museum %d (in rubles): ", i); scanf("%d\n\n", &mass[i].ticket);

	}
	printf("Function inputMuseums DONE\n\n");
}
*/