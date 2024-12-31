#include <iostream>
#include <string>
#include <chrono>
#include <vector>

using std::string;
using std::vector;

struct Things {
	vector <string> a;
	vector <string> b;
	vector <string> c;
	vector <vector<int>> d;
	vector <vector<int>> e;
	vector <int> f;
};

Things getThings() {
	Things things;
	const int nThings = 300000;

	things.a.resize(nThings);
	for (int i = 0; i < nThings; i++) {
		things.a[i] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaalkjdslfkjjlksdfklj";
	}
	things.b.resize(nThings);
	for (int i = 0; i < nThings; i++) {
		things.b[i] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaalkjdslfkjjlksdfklj";
	}
	things.c.resize(nThings);
	for (int i = 0; i < nThings; i++) {
		things.c[i] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaalkjdslfkjjlksdfklj";
	}

	vector <int> vecInt(800);
	for (int i = 0; i < 800; i++) {
		vecInt[i] = 69;
	}

	things.d.resize(nThings);
	for (int i = 0; i < nThings; i++) {
		things.d[i] = vecInt;
	}
	things.e.resize(nThings);
	for (int i = 0; i < nThings; i++) {
		things.e[i] = vecInt;
	}

	things.f.resize(nThings);
	for (int i = 0; i < nThings; i++) {
		things.f[i] = 69;
	}

	return things;
}

int main() {
	Things things = getThings();

	auto start = std::chrono::high_resolution_clock::now();
	unsigned long long sum = 0;

	for (int i = 0; i < 5; i++) {
	for (string &e : things.a) {
		//e.push_back('a');
		for (auto &j : e) sum += j;
	}
	for (string &e : things.b) {
		//e.push_back('a');
		for (auto &j : e) sum += j;
	}
	for (string &e : things.c) {
		//e.push_back('a');
		for (auto &j : e) sum += j;
	}
	for (vector<int> &e : things.d) {
		//e.push_back(69);
		for (auto &j : e) sum += j;
	}
	for (vector<int> &e : things.e) {
		//e.push_back(69);
		for (auto &j : e) sum += j;
	}

	for (int &e : things.f) {
		//++e;
		sum += e;
	}
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto durationMs = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

	std::cout << sum << std::endl;
	std::cout << "Took " << durationMs.count() << "ms" << std::endl;
}
