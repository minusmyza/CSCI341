#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> array, int startIdx, int endIdx, int val);
int sum(vector<int> array, int startIdx, int endIdx);

int main() {
	vector<int> array;
	int input;
	bool doneFill = false;
	while (!doneFill and array.size() < 10) {
		cout << "Enter a number to add to the array: ";
		cin >> input;
		if (input != 0) {
			array.push_back(input);
		} else {
			doneFill = true;
		}
	}

	int val;
	bool validVal = false;
	while (!validVal) {
		cout << "What value would you like to find?" << endl << "> ";
		cin >> val;
		if (count(array.begin(), array.end(), val)) {
			validVal = true;
		} else {
			cout << "Invalid value" << endl;
		}
	}

	int startIdx = 0;
	int endIdx = array.size() - 1;

	int returnIdx = binarySearch(array, startIdx, endIdx, val);
	cout << "Index: " << returnIdx;
	return 0;
}

int binarySearch(vector<int> array, int startIdx, int endIdx, int val) {
	cout << "Sum: " << sum(array, startIdx, endIdx) << endl;
	int midIdx = (startIdx + endIdx) / 2;
	cout << "Mid Index: " << midIdx << endl;
	if (val > array.at(midIdx)) {
		binarySearch(array,  midIdx + 1, endIdx, val);
	}
	else if (val < array.at(midIdx)) {
		binarySearch(array,  startIdx, midIdx - 1, val);
	}
	else {
		cout << "ACTUAL INDEX: " << midIdx << endl;
		return midIdx;
	}
}

int sum(vector<int> array, int startIdx, int endIdx) {
	int sum = 0;
	for (int i = startIdx; i <= endIdx; i++) {
		sum += array.at(i);
	}
	return sum;
}
