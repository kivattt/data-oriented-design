#include <iostream>
#include <immintrin.h>
#include <stdlib.h>
#include <chrono>
#include <vector>

using std::vector;

int main() {
	const int nThings = 400000000 / 32; // Approximately 3.2 GB memory usage
	vector<__m256i> numbers(nThings);
	for (int i = 0; i < nThings; i++) {
		numbers[i] = 69;
	}

	//unsigned long long *newNumbers = posix_memalign(numbers, 16, (unsigned long long)nThings*8);

	auto start = std::chrono::high_resolution_clock::now();
	unsigned long long sum = 0;
	for (int i = 0; i < nThings; i++) {
		sum += numbers[i];
		//sum += newNumbers[i];
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto durationMs = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << sum << std::endl;
	std::cout << "Took " << durationMs.count() << "ms" << std::endl;
}
