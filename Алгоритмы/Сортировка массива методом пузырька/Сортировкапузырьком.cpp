#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <cstdlib>
using namespace std;
#define srznach  20

void insertSort(int *m, int dlina) {
	int buff, j;
	for (int i = 0; i < dlina; i++) {
		for (j = i; j > 0; j--) {
			if (m[j] < m[j - 1]) {
				buff = m[j - 1];
				m[j - 1] = m[j];
				m[j] = buff;
			}
		}
	}
}


int main()
{
	int arr[srznach];
	for (int i = 0; i<srznach; i++) {
		arr[i] = rand() % 10 - 5;
		cout << arr[i] << ' ';
	}
	insertSort(arr, srznach);
	cout << endl;
	for (int i = 0; i<srznach; i++)
		cout << arr[i] << ' ';
	return 0;
}