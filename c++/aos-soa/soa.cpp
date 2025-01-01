#include <iostream>
#include <vector>
#include <chrono>
#include <string>

using std::string;
using std::vector;

struct Vec3 {
	float x;
	float y;
	float z;
};

struct Cold {
	int stuff[800];
	string name;
	int id;
	unsigned flags;
	float a;
	float b;
};

struct Things {
	vector<Vec3> positions;
	vector<Cold> cold;
};

Things getThings() {
	Cold cold;
	cold.id = 69;
	cold.flags = 0;
	cold.name = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	int bigThing[800];
	for (int i = 0; i < 800; i++) {
		bigThing[i] = 69;
	}
	//cold.stuff = bigThing;
	std::copy(std::begin(bigThing), std::end(bigThing), std::begin(cold.stuff));
	cold.a = 69.0f;
	cold.b = 69.0f;

	//const int nThings = 1600000; // Uses ~5 GB memory
	const int nThings = 1000000;
	Things things;
	things.positions.resize(nThings);
	things.cold.resize(nThings);
	for (int i = 0; i < nThings; i++) {
		things.positions[i] = Vec3{69,69,69};
		things.cold[i] = cold;
	}

	return things;
}

int main() {
	Things things = getThings();

	auto start = std::chrono::high_resolution_clock::now();
	unsigned long long sum = 0;
	for (Vec3 &pos : things.positions) {
		sum += pos.x;
		sum += pos.y;
		sum += pos.z;
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto durationMs = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << "sum : " << sum << std::endl;
	//std::cout << "sum2: " << sum2 << std::endl;
	std::cout << "Took " << durationMs.count() << "ms" << std::endl;
}
