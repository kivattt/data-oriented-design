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
	for (int i = 0; i < nThings / 64; i += 64) {
		sum += numbers[i+0];
		sum += numbers[i+1];
		sum += numbers[i+2];
		sum += numbers[i+3];
		sum += numbers[i+4];
		sum += numbers[i+5];
		sum += numbers[i+6];
		sum += numbers[i+7];
		sum += numbers[i+8];
		sum += numbers[i+9];
		sum += numbers[i+10];
		sum += numbers[i+11];
		sum += numbers[i+12];
		sum += numbers[i+13];
		sum += numbers[i+14];
		sum += numbers[i+15];
		sum += numbers[i+16];
		sum += numbers[i+17];
		sum += numbers[i+18];
		sum += numbers[i+19];
		sum += numbers[i+20];
		sum += numbers[i+21];
		sum += numbers[i+22];
		sum += numbers[i+23];
		sum += numbers[i+24];
		sum += numbers[i+25];
		sum += numbers[i+26];
		sum += numbers[i+27];
		sum += numbers[i+28];
		sum += numbers[i+29];
		sum += numbers[i+30];
		sum += numbers[i+31];

		sum += numbers[i+32];
		sum += numbers[i+33];
		sum += numbers[i+34];
		sum += numbers[i+35];
		sum += numbers[i+36];
		sum += numbers[i+37];
		sum += numbers[i+38];
		sum += numbers[i+39];
		sum += numbers[i+40];
		sum += numbers[i+41];
		sum += numbers[i+42];
		sum += numbers[i+43];
		sum += numbers[i+44];
		sum += numbers[i+45];
		sum += numbers[i+46];
		sum += numbers[i+47];
		sum += numbers[i+48];
		sum += numbers[i+49];
		sum += numbers[i+50];
		sum += numbers[i+51];
		sum += numbers[i+52];
		sum += numbers[i+53];
		sum += numbers[i+54];
		sum += numbers[i+55];
		sum += numbers[i+56];
		sum += numbers[i+57];
		sum += numbers[i+58];
		sum += numbers[i+59];
		sum += numbers[i+60];
		sum += numbers[i+61];
		sum += numbers[i+62];
		sum += numbers[i+63];
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto durationMs = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << sum << std::endl;
	std::cout << "Took " << durationMs.count() << "ms" << std::endl;
}
