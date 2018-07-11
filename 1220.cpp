#include <cstdio>
#include <stdlib.h>

#define BLOCKS_SIZE 50
#define MAX_COL 140000
#define BLOCKS_COL (MAX_COL / BLOCKS_SIZE)

int all[MAX_COL] = {};
char is_using[BLOCKS_COL] = { 0 };
short prev_block[BLOCKS_COL] = { 0 };
short num_of_block[1000] = { 0 };
short num_of_top_elem[1000] = { 0 };

void push(int s, int val) {
	int i;
	if (num_of_block[s] == -1) {
		for (i = 0; i < BLOCKS_COL; i++) {
			if (is_using[i] == 0) {
				is_using[i] = 1;
				prev_block[i] = -1;
				num_of_top_elem[s] = -1;
				num_of_block[s] = i;
				break;
			}
		}
	}
	if (num_of_top_elem[s] == BLOCKS_SIZE - 1) {
		for (i = 0; i < BLOCKS_COL; i++) {
			if (is_using[i] == 0) {
				is_using[i] = 1;
				prev_block[i] = num_of_block[s];
				num_of_top_elem[s] = -1;
				num_of_block[s] = i;
				break;
			}
		}
	}
	num_of_top_elem[s] = num_of_top_elem[s] + 1;
	all[num_of_block[s] * BLOCKS_SIZE + num_of_top_elem[s]] = val;
}

int pop(int s) {
	int val = all[BLOCKS_SIZE * num_of_block[s] + num_of_top_elem[s]];
	num_of_top_elem[s]--;
	if (num_of_top_elem[s] == -1) {
		is_using[num_of_block[s]] = 0;
		num_of_block[s] = prev_block[num_of_block[s]];
		num_of_top_elem[s] = BLOCKS_SIZE - 1;
	}
	return val;
}

int main() {
	char C[10];
	int N, i, a, b;

	for (i = 0; i < 1000; i++) num_of_block[i] = num_of_top_elem[i] = -1;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%4s", C);
		if (C[1] == 'U') { //push
			scanf(" %d %d", &a, &b);
			push(a - 1, b);
		}
		else {
			scanf("%d", &a);
			printf("%d\n", pop(a - 1));
		}
	}
	return 0;
}