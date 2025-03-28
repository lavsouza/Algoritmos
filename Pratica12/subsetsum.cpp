/*
 * subsetsum.cpp
 *
 *  Created on: 14 de dez de 2017
 *      Author: ramide
 */

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

unsigned long long count_ssk = 0;

/* Pr�tica 12 - For�a Bruta ------------------*/

bool subsetSumBF(const vector<int> &array, int K, vector<bool> &subset) {
	int n = array.size();
	subset.resize(n, false);

	for (long long mask = 0; mask < (1LL << n); mask++) {
		int soma_atual = 0;

		for (int i = 0; i < n; i++) {
			if (mask & (1LL << i)) {
				soma_atual += array[i];
			}
		}

		if (soma_atual == K) {
			for (int i = 0; i < n; i++) {
				subset[i] = (mask & (1LL << i)) != 0;
			}
			return true;
		}
	}

	return false;
}

/* Pr�tica 13 - Backtracking ------------------- */

bool subsetSumBTRec(const vector<int> &array, int n, int k, vector<bool> &subset) {
	if (k == 0) {
		return true;
	}
	if (n < 0 || k < 0) {
		return false;
	}

	// Otimização: se a soma total dos elementos for menor que k, não há solução
	int total_sum = std::accumulate(array.begin(), array.end(), 0);
	if (k > total_sum) {
		return false;
	}

	if (subsetSumBTRec(array, n - 1, k, subset)) {
		return true;
	}

	subset[n] = true;
	if (subsetSumBTRec(array, n - 1, k - array[n], subset)) {
		return true;
	}

	subset[n] = false;
	return false;
}

// Função de interface para chamar a recursão corretamente
bool subsetSumBT(const vector<int> &array, int k, vector<bool> &subset) {
	int n = array.size();
	subset.resize(n, false);

	int total_sum = std::accumulate(array.begin(), array.end(), 0);
	if (k > total_sum) {
		return false;
	}

	return subsetSumBTRec(array, n - 1, k, subset);
}

/* Pr�tica 14 - Programa��o Din�mica ------------------ */

bool subsetSumRecMemo(const vector<int> &array, int n, int k, vector<bool> &subset, vector<vector<int>> &memo) {
	if (k == 0) {
		return true;
	}
	if (n < 0 || k < 0) {
		return false;
	}

	if (memo[n][k] != -1) {
		return memo[n][k];
	}

	int total_sum = accumulate(array.begin(), array.end(), 0);
	if (k > total_sum) {
		return false;
	}

	if (subsetSumRecMemo(array, n - 1, k, subset, memo)) {
		return memo[n][k] = true;
	}

	subset[n] = true;
	if (subsetSumRecMemo(array, n - 1, k - array[n], subset, memo)) {
		return memo[n][k] = true;
	}

	subset[n] = false;
	return memo[n][k] = false;
}

bool subsetSumMemo(const vector<int> &array, int k, vector<bool> &subset) {
	vector<vector<int>> memo(array.size() + 1, vector<int>(k + 1,  -1));
	return subsetSumRecMemo(array, (int)array.size(), k, subset, memo);
}

bool subsetSumDP(const vector<int> &array, int k, vector<bool> &subset) {
	// TODO
   
}

/* Pr�tica 14 - Greedy ------------------ */

bool subsetSumGreedy(const vector<int> &array, int k, vector<bool> &subset) {
	// TODO

	
}

/* -------------------------------------- */

bool check_sum(const vector<int> &array, int sum, const vector<bool> &subset) {
	int cur_sum = 0;

	for (int i = 0; i < (int)array.size(); i++) {
		if (subset[i]) cur_sum += array[i];
	}

	return (cur_sum == sum);
}

void runSubsetSum(const char *name, bool subsetSum(const vector<int> &, int, vector<bool> &), const vector<int> &array, int sum) {
	using namespace std::chrono;

    count_ssk = 0;

	vector<bool> subset(array.size(), false);

	auto start = high_resolution_clock::now();

	bool found = subsetSum(array, sum, subset);

	auto finish = high_resolution_clock::now();
	long elapsed = duration_cast<nanoseconds>(finish - start).count() / 1000;

	bool valid = found && check_sum(array, sum, subset);

	cout << name << ": " << (found ? ( valid ? "YES " : "ERR " ): " NO ");

	cout << "[time: " << elapsed << "us] ";
	cout << "[count: " << count_ssk << "] ";
	if (found) {
		cout << "[ ";
		for (unsigned i = 0; i < array.size(); i++) {
			if (subset[i])
				cout << array[i] << " ";
		}
		cout << "] ";
	}
	cout << endl;

}

//int main_SUBSETSUM() {
int main() {
	int size = 20;

	vector<int> array(size);

//	srand(333);
	srand(12345);

	for (int i = 0; i < size; i++) {
		cout << (array[i] = 1 + rand() % (size * 5)) << " ";
	}
	cout << endl;

	int value = 0;
	for (int i = 0; i < 20; i++) {
		value += (rand() % (size * 6));
		cout << i << ": Trying " << value << " ..." << endl;

		runSubsetSum("Bruteforce   ", subsetSumBF, array, value);
		runSubsetSum("Backtracking ", subsetSumBT, array, value);
		runSubsetSum("Memoization  ", subsetSumMemo, array, value);
		runSubsetSum("Dynamic Prog.", subsetSumDP, array, value);
		runSubsetSum("Greedy       ", subsetSumGreedy, array, value);
	}


	return 0;
}

