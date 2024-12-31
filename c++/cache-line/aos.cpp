#include <iostream>
#include <chrono>
#include <vector>

using std::vector;

struct Thing {
	unsigned long long i1;
	unsigned long long i2;
	unsigned long long i3;
	unsigned long long i4;
	unsigned long long i5;
	unsigned long long i6;
	unsigned long long i7;
	unsigned long long i8;
	unsigned long long i9;
	unsigned long long i10;
};

vector <Thing> getThings() {
	const int nThings = 50000000;
	std::vector <Thing> ret(nThings);

	Thing thing;
	thing.i1 = 69;
	thing.i2 = 69;
	thing.i3 = 69;
	thing.i4 = 69;
	thing.i5 = 69;
	thing.i6 = 69;
	thing.i7 = 69;
	thing.i8 = 69;
	thing.i9 = 69;
	thing.i10 = 69;

	for (int i = 0; i < nThings; i++) {
		ret[i] = thing;
	}
	return ret;
}

int main() {
	vector<Thing> things = getThings();

	auto start = std::chrono::high_resolution_clock::now();
	unsigned long long sum = 0;
	for (Thing &thing : things) {
		sum += thing.i1;
		sum += thing.i2;
		sum += thing.i3;
		sum += thing.i4;
		sum += thing.i5;
		sum += thing.i6;
		sum += thing.i7;
		sum += thing.i8;
		sum += thing.i9;
		sum += thing.i10;
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto durationMs = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << sum << std::endl;
	std::cout << "Took " << durationMs.count() << "ms" << std::endl;
}
