#include <iostream>
#include <string>
#include <chrono>
#include <vector>

using std::string;
using std::vector;

struct Thing {
	string a;
	string b;
	string c;
	vector <int> d;
	vector <int> e;
	int f;
};

vector <Thing> getThings() {
	vector <int> vecInt(800);
	for (int i = 0; i < 800; i++) {
		vecInt[i] = 69;
	}

	Thing thing;
	thing.a = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaalkjdslfkjjlksdfklj";
	thing.b = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaalkjdslfkjjlksdfklj";
	thing.c = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaalkjdslfkjjlksdfklj";
	thing.d = vecInt;
	thing.e = vecInt;
	thing.f = 69;

	const int nThings = 300000;
	vector <Thing> things(nThings);
	for (int i = 0; i < nThings; i++) {
		things[i] = thing;
	}

	return things;
}

int main() {
	vector <Thing> things = getThings();

	auto start = std::chrono::high_resolution_clock::now();
	unsigned long long sum = 0;
	for (int i = 0; i < 5; i++) {
	for (Thing &thing : things) {
		/*thing.a.push_back('a');
		thing.b.push_back('a');
		thing.c.push_back('a');

		thing.d.push_back(69);
		thing.e.push_back(69);

		++thing.f;*/

		for (auto &e : thing.a) sum += e;
		for (auto &e : thing.b) sum += e;
		for (auto &e : thing.c) sum += e;
		for (auto &e : thing.d) sum += e;
		for (auto &e : thing.e) sum += e;
		sum += thing.f;
	}
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto durationMs = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << sum << std::endl;
	std::cout << "Took " << durationMs.count() << "ms" << std::endl;
}
