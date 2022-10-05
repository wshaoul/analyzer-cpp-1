#include "StringData.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;


int linearSearch(const vector<string> &container, const string &element) {
	auto startTime = systemTimeNanoseconds();

	for (int i = 0; i < container.size(); ++i) {
		if (container[i] == element) {
			auto endTime = systemTimeNanoseconds();
			auto diff = endTime - startTime;
			cout << "\tLinear Search: " << (float) diff / 10e9 << " sec" << endl;

			return i;
		}
	}

	auto endTime = systemTimeNanoseconds();
	auto diff = endTime - startTime;
	cout << "\tLinear Search: " << (float) diff / 10e9 << " sec" << endl;
	return -1;
}

int binarySearch(const vector<string> &container, const string &element) {
	auto startTime = systemTimeNanoseconds();

	int minInd = 0,
			maxInd = container.size() - 1;
	while (minInd < maxInd) {
		auto midInd = (minInd + maxInd) / 2;
		auto midElem = container[midInd];
		if (midElem.compare(element) < 0)
			minInd = midInd + 1;
		else if (midElem.compare(element) > 0)
			maxInd = midInd - 1;
		else
			minInd = maxInd = midInd;
	}

	auto endTime = systemTimeNanoseconds();
	cout << "\tBinary Search: " << (float) (endTime - startTime) / 10e9 << " sec" << endl;

	if (minInd == maxInd)
		return minInd;
	return -1;

}


int main() {
	cout << "Generating container... ";
	const auto stringData = getStringData();
	cout << "DONE\n\tSize = " << stringData.size() << "\n" << endl;

	string searchWords[] = {"not_here", "mzzzz", "aaaaa"};
	for (auto &word: searchWords) {
		cout << "Searching for... '" << word << "'" << endl;

		auto linear_ind = linearSearch(stringData, word);
		cout << "\tIndex = " << linear_ind << endl;
		cout << endl;

		auto binary_ind = binarySearch(stringData, word);
		cout << "\tIndex = " << binary_ind << endl;


		cout << endl;
	}
}
