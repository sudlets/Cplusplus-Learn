#pragma once


void ChoiceSort(int *m, int dlina) {
	int buff, min;
	for (int i = 0; i < dlina; i++) {
		min = i;
		for (int j = i + 1; j < dlina; j++)
			if (m[j] < m[min])
				min = j;
		buff = m[i];
		m[i] = m[min];
		m[min] = buff;
	}
}
void q_sort(int *arr, int j) {
	int size = j;
	int k = 0;
	int c = arr[(int)(size / 2)];
	int tmp;
	do {
		while (arr[k] < c)k++;
		while (arr[j] > c)j--;
		if (k <= j) {
			tmp = arr[k];
			arr[k] = arr[j];
			arr[j] = tmp;
			k++;
			j--;
		}
	} while (k <= j);
	if (j > 0) q_sort(arr, j);
	if (size > k) q_sort(&arr[k], size - k);
}
void siftDown(int *numbers, int root, int bottom)
{
	int maxChild;
	int done = 0;
	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)
			maxChild = root * 2;
		else if (numbers[root * 2] > numbers[root * 2 + 1])
			maxChild = root * 2;
		else
			maxChild = root * 2 + 1;
		if (numbers[root] < numbers[maxChild])
		{
			int temp = numbers[root];
			numbers[root] = numbers[maxChild];
			numbers[maxChild] = temp;
			root = maxChild;
		}
		else
			done = 1;
	}
} //для пирамидальной сортировки (построение дерева) 
void heapSort(int *numbers, int array_size)
{
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		siftDown(numbers, i, array_size);
	for (int i = array_size - 1; i >= 1; i--)
	{
		int temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		siftDown(numbers, 0, i - 1);
	}
}
void insertSort(int *m, int dlina) {
	int buff, j;
	for (int i = 0; i < dlina; i++) {
		buff = m[i];
		for (j = i; j > 0; j--) {
			if (buff < m[j - 1])
				m[j] = m[j - 1];
			else
				break;
		}
		m[j] = buff;
	}
}
void BubbleSort(int *m, int dlina) {
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
void ShellSort(int *m, int len) {
	int j, tmp;
	for (int k = len / 2; k > 0; k /= 2)
		for (int i = k; i < len; i++) {
			tmp = m[i];
			for (j = i; j >= k; j -= k) {
				if (tmp < m[j - k])
					m[j] = m[j - k];
				else
					break;
			}
			m[j] = tmp;
		}
}
void in_mas(int *arr, int j) {
	for (int i = 0; i < j; i++)
		arr[i] = rand();
}
void out_mas(int *arr, int j) {
	for (int i = 0; i < j; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void sd(int *m, int dlin, int pr) {
	int buff, min;
	int dlina = (dlin - dlin/100.*pr);
	for (int i = 0; i < dlina; i++) {
		min = i;
		for (int j = i + 1; j < dlina; j++)
			if (m[j] > m[min])
				min = j;
		buff = m[i];
		m[i] = m[min];
		m[min] = buff;
	}

}
void sort_prot(int *m, int dlina, int pr) {
	int buff, min;
	for (int i = 0; i < dlina; i++) {
		min = i;
		for (int j = i + 1; j < dlina; j++)
			if (m[j] < m[min])
				min = j;
		buff = m[i];
		m[i] = m[min];
		m[min] = buff;
	}
	sd(m, dlina, pr);
}
