#include <iostream>
#include <chrono>
#include <vector>

using std::vector;

int main() {
	const int nThings = 400000000; // Approximately 3.2 GB memory usage
	vector<unsigned long long> numbers(nThings);
	for (int i = 0; i < nThings; i++) {
		numbers[i] = 69;
	}

	auto start = std::chrono::high_resolution_clock::now();
	unsigned long long sum = 0;

	for (unsigned long long &e : numbers) {
		sum += e;
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto durationMs = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << sum << std::endl;
	std::cout << "Took " << durationMs.count() << "ms" << std::endl;
}
