#include <iostream>
#include <chrono>

int divSum(int n) {
	int sum = 0;

	for (int i = 1; i <= n / 2; i++) {
		if (n % i == 0) {
			sum += i;
		}
	}

	return sum;
}

bool isPerfect(int n) {
	if (n == divSum(n)) {
		return true;
	}

	return false;
}

void allPerfect(int n) {
	for (int i = 1; i < n; i++) {
		if (isPerfect(i)) {
			std::cout << i << std::endl;
		}
	}
}

bool areAmicable(int n, int m) {
	if (divSum(n) == m && divSum(m) == n) {
		return true;
	}

	return false;
}

void allAmicable(int n) {
	for (int i = 1; i <= n; i++) {
		int Si = divSum(i);

		if (Si > i && Si <= n && divSum(Si) == i && i != Si) {
			std::cout << i << " " << Si << std::endl;
		}
	}
}

int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	auto stop = start;

	std::cout << "Zadanie 1 - test\n";
	std::cout << "Suma dzielnikow 15 = " << divSum(15) << std::endl;
	std::cout << "Suma dzielnikow 17 = " << divSum(17) << std::endl;

	std::cout << "Zadanie 2 - test\n";
	std::cout << "Liczba 6: " << isPerfect(6) << std::endl;
	std::cout << "Liczba 12: " << isPerfect(12) << std::endl;
	std::cout << "Liczba 28: " << isPerfect(28) << std::endl;

	std::cout << "Zadanie 3 - test\n";
	std::cout << "Liczby doskonale w zakresie: 1 - 9000\n";
	start = std::chrono::high_resolution_clock::now();
	allPerfect(9000);
	stop = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	std::cout << "Czas dzialania algorytmu wynosi " << duration.count() << " milisekund\n";

	std::cout << "Zadanie 4 - test\n";
	std::cout << "Liczby 220 i 284 " << areAmicable(220, 284) << std::endl;

	std::cout << "Zadanie 5 - test\n";
	std::cout << "Liczby zaprzyjaznione w zakresie: 1 - 3000: \n";
	start = std::chrono::high_resolution_clock::now();
	allAmicable(3000);
	stop = std::chrono::high_resolution_clock::now();

	duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
	std::cout << "Czas dzialania algorytmu wynosi " << duration.count() << " milisekund\n";

	return 0;
}
