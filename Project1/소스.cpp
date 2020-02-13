#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// �ش� �࿡ ���� �����°�?
bool X[12];
// ���� �밢�� ���� ���� ���� x + y�� x - y�� ����.
bool XplusY[23]; // x + y�� ������ 0 ~ 22.
bool XminusY_o[23];
bool* XminusY = XminusY_o + 11; // x - y�� ������ -11 ~ 11.

int putQueen(int n, int y) { // y��° �ٿ� queen�� ���´�.
	static int operating_cnt = 0;
	operating_cnt++;
	printf("input = %d, operating : %d\n", n, operating_cnt);
	if (n == y) return 1; // n - 1��°���� ��� �������� �Ϸ�.
	int answer = 0;
	bool success = false;
	for (int x = 0; x < n; x++)
		if (!(X[x] || XplusY[x + y] || XminusY[x - y])) { // ���� �� ������
			X[x] = XplusY[x + y] = XminusY[x - y] = success = true; // ����
			answer += putQueen(n, y + 1); // ���� �ٿ� ������ ����.
			X[x] = XplusY[x + y] = XminusY[x - y] = false;
		}
	return success ? answer : 0;
}

int main() {
	int n; scanf("%d", &n);
	printf("result = %d", putQueen(n, 0));

	return 0;
}