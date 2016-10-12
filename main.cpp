#include <iostream>
#include <vector>

using namespace std;

bool sum_exists_helper(int*, int, int);
bool sum_exists(int*, int, int);

void displaySeq(int* seq, int size) {
	cout << "{";
	for (int i = 0; i < size; i++) {
		cout << seq[i] << " ";
	}
	cout << "}\n";
}

vector<int> solution;

int main() {
	int sequence[] = { 40, 1, 3, 8, 17, 4, 90};
	int size = (sizeof(sequence)) / (sizeof(sequence[0]));
	int num = 25;

	cout << "In sequence :\n";
	displaySeq(sequence, size);
	cout << "We are looking for a number: " << num << endl;
	//start function
	if (sum_exists(sequence, size, num)){
		cout << "Subsequence does exists\n";
	}
	else {
		cout << "Subsequence does not exist\n";
	}
	//Display solution vector in reversed order
	for (int i = solution.size()-1; i > 0; i--) {
		cout << solution[i] << " ";
	}
	cin.get();
	return 0;
}

bool sum_exists(int *seq, int n, int sum) {
	//for all possible beginnings
	for (int i = 0; i < n; i++) {
		//Apply actual recursive function here
		if (sum_exists_helper(seq + i, n - i, sum)) {
			//if it's true, save solution's element to vector and return true
			solution.push_back(seq[i]);
			return true;
		}
	}
	return false;
}

//Actual recursive function used by sum_exists()
bool sum_exists_helper(int *seq, int n, int sum) {
	//if there is no array left, return false
	if (n == 0) { return false; }
	//If difference between first number of sequence and sum so far is smaller than 0 return false
	int diff = sum - seq[0];
	if (diff < 0) {
		return false;
	}//if first number equaled remaining sum, return true and save solution element to vector
	else if (diff == 0) {
		solution.push_back(seq[0]);
		return true;
	}//otherwise, start new function with smaller array as an argument
	else{
		for (int i = 1; i < n; i++) {
			//call function starting with any subsequence of current sequence
			if (sum_exists_helper(seq + i, n - i, diff)) {
				//if it's true, save solution's element to vector and return true
				solution.push_back(seq[i]);
				return true;
			}
		}
		//if, after checking all subsequences there is no match, return false;
		return false;
	}
}