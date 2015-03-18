#include "../calc.h"

int TOTAL_VALUE = 200;
int COINS[] = { 200, 100, 50, 20, 10, 5, 2, 1 };
int COINS_SIZE = sizeof(COINS) / sizeof(int);

bign combinations(int value, int index);

//get all combinations to generate 2£ (200p)
void main() {
	bign result = 0;
	int i;
	for (i = 0; i < COINS_SIZE; i++) {
		result += combinations(TOTAL_VALUE, i);
	}
	printf("%llu combinations found.\n", result);
}

bign combinations(int value, int index) {
	if (index >= COINS_SIZE || value < COINS[index]) {
		return 0;
	} else if (index == COINS_SIZE - 1) {
		if (!(value % COINS[index])) {
			return 1;
		} else {
			return 0;
		}
	}

	int times = value / COINS[index];
	int i;
	bign result = 0;
	for (i = times; i > 0; i--) {
		if (value == i * COINS[index]) {
			result++;
			continue;
		}
		int j;
		for (j = index + 1; j < COINS_SIZE; j++) {
			result += combinations(value - (i * COINS[index]), j);
		}
	}
	return result;
}

