#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define N 10

void printGrid(int arr[N], int n) {
	int i;
	printf("[");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i] + 1);
	}
	printf("] ");
}

bool safe(int arr[N], int x, int y) {
	int i;
	for (i = 0; i < x; i++) {
		if (arr[i] == y || abs(x - i) == abs(y - arr[i])) {
			return false;
		}
	}
	return true;
}

void solveNQueensUtil(int arr[N], int n, int x, bool *flag) {
	int i;
	if (x == n) {
		printGrid(arr, n);
		*flag = true;
	}
    //checking for each cell in respective rows starting from 0.
	for (i = 0; i < n; i++) {
		if (safe(arr, x, i)) {
			arr[x] = i;
			solveNQueensUtil(arr, n, x + 1, flag);
		}
	}
}

void solveNQueens(int n) {
	int *arr = (int*)malloc(sizeof(int) * n);
	bool flag = false;
    //passig flag by reference so as to use its value in the current funtion 
	solveNQueensUtil(arr, n, 0, &flag);
	if(!flag) {
	    printf("-1\n");
	}
	else {
	    printf("\n");
	}
}

int main() {
	//code
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		solveNQueens(n);
	}
	return 0;
}