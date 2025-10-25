#include <iostream> 
#include <cstdlib>
#include <ctime>

void print(int* S, int n) {
	for (int i = 0; i < n; i++) {
		std::cout << S[i] << " ";
	}
	std::cout << std::endl;
}

int linearSearch1(int* S, int n, int x) {
	for (int i = 0; i < n; i++) {
		if (S[i] == x) {
			return i;
		}
	}

	return -1;
}

int binarySearch1(int* S, int n, int x) {
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (S[mid] == x) return mid;
		else if (S[mid] > x) right = mid - 1;
		else left = mid + 1;
	}

	return -1;
}

int linearSearch2(int* S, int n, int x) {
	int steps = 0;

	for (int i = 0; i < n; i++) {
		steps++;

		if (S[i] == x) {
			break;
		}
	}

	return steps;;
}

int binarySearch2(int* S, int n, int x) {
	int steps = 0;
	int left = 0;
	int right = n - 1;

	while (left <= right) {
		steps++;
		int mid = (left + right) / 2;

		if (S[mid] == x) break;
		else if (S[mid] > x) right = mid - 1;
		else left = mid + 1;
	}

	return steps;
}

void initSorted(int* S, int n) {
	S[0] = rand() % n;
	for (int i = 1; i < n; i++)
		S[i] = S[i - 1] + rand() % n;
}

int getRandomIndex(int n) {
	int randIndex = rand() % n;
	return randIndex;
}

void testSearch() {
	for (int size = 10; size <= 100000; size *= 10) {
		int linearSum = 0;
		int binarySum = 0;
		int repeats = 0;
		float linearAvg = 0;
		float binaryAvg = 0;

		std::cout << std::endl << size << std::endl;

		for (int i = 0; i < 100; i++) {
			int* S = new int[size];
			initSorted(S, size);
			int tempIndex = getRandomIndex(size);
			linearSum += linearSearch2(S, size, S[tempIndex]);
			binarySum += binarySearch2(S, size, S[tempIndex]);

			repeats++;
		}

		linearAvg = linearSum / repeats;
		binaryAvg = binarySum / repeats;

		std::cout << linearAvg << std::endl;
		std::cout << binaryAvg << std::endl;
	}
}

int main()
{
	srand(time(NULL));
	std::cout << "Zadanie 1 - test\n";
	int n = 20;
	int* S = new int[n] {1, 3, 5, 8, 9, 13, 17, 20, 25, 27, 29, 30, 33, 34, 36, 37, 40, 42, 43, 45};
	int x = 8;

	print(S, n);
	std::cout << linearSearch1(S, n, x) << std::endl;
	std::cout << binarySearch1(S, n, x) << std::endl;

	std::cout << linearSearch2(S, n, x) << std::endl;
	std::cout << binarySearch2(S, n, x) << std::endl;

	testSearch();

	return 0;
}
