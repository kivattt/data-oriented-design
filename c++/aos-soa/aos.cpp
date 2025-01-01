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

struct Thing {
	int stuff[800];
	Vec3 position;
	string name;
	int id;
	unsigned flags;
	float a;
	float b;
};

vector <Thing> getThings() {
	Thing thing;
	thing.position.x = 69;
	thing.position.y = 69;
	thing.position.z = 69;
	thing.id = 69;
	thing.flags = 0;
	thing.name = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	int bigThing[800];
	for (int i = 0; i < 800; i++) {
		bigThing[i] = 69;
	}
	//thing.stuff = bigThing;
	std::copy(std::begin(bigThing), std::end(bigThing), std::begin(thing.stuff));
	thing.a = 69.0f;
	thing.b = 69.0f;

	//const int nThings = 1600000; // Uses ~5 GB memory
	const int nThings = 1000000;
	vector<Thing> things(nThings);
	for (int i = 0; i < nThings; i++) {
		things[i] = thing;
	}

	return things;
}

int main() {
	vector<Thing> things = getThings();

	auto start = std::chrono::high_resolution_clock::now();
	unsigned long long sum = 0;
	for (int i = 0; i < 100; i++) {
		for (Thing &thing : things) {
			sum += thing.position.x;
			sum += thing.position.y;
			sum += thing.position.z;
		}
	}

	unsigned long long sum2 = 0;
	for (Thing &thing : things) {
		//sum2 += thing.position.x;
		sum2 += thing.id;
		sum2 += thing.flags;
		sum2 += thing.name.size();
		/*for (int i = 0; i < 800; i++) {
			sum2 += thing.stuff[i];
		}*/
		sum2 += thing.a;
		sum2 += thing.b;
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto durationMs = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << "sum : " << sum << std::endl;
	std::cout << "sum2: " << sum2 << std::endl;
	std::cout << "Took " << durationMs.count() << "ms" << std::endl;
}
