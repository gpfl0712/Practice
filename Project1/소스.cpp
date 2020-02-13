#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 해당 행에 블럭이 놓였는가?
bool X[12];
// 같은 대각선 위에 놓인 점은 x + y나 x - y가 같다.
bool XplusY[23]; // x + y의 범위는 0 ~ 22.
bool XminusY_o[23];
bool* XminusY = XminusY_o + 11; // x - y의 범위는 -11 ~ 11.

int putQueen(int n, int y) { // y번째 줄에 queen을 놓는다.
	static int operating_cnt = 0;
	operating_cnt++;
	printf("input = %d, operating : %d\n", n, operating_cnt);
	if (n == y) return 1; // n - 1번째까지 모두 놓았으면 완료.
	int answer = 0;
	bool success = false;
	for (int x = 0; x < n; x++)
		if (!(X[x] || XplusY[x + y] || XminusY[x - y])) { // 놓을 수 있으면
			X[x] = XplusY[x + y] = XminusY[x - y] = success = true; // 놓고
			answer += putQueen(n, y + 1); // 다음 줄에 놓으러 가자.
			X[x] = XplusY[x + y] = XminusY[x - y] = false;
		}
	return success ? answer : 0;
}

int main() {
	int n; scanf("%d", &n);
	printf("result = %d", putQueen(n, 0));

	return 0;
}