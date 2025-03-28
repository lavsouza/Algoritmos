/*
 * subseqmax.cpp
 *
 *  Created on: 15 de dez de 2017
 *      Author: ramide
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <vector>

unsigned long long count_ssm = 0;

using namespace std;

/* Pr�tica 12 - For�a Bruta -----------------*/

// start e finish: in�cio e final sendo testado agora;
// ini e end: onde s�o retornados o in�cio e final da melhor sequ�ncia
// retorno � a soma da maior sequ�ncia
int subseqMaxBF(const vector<int> &array, int &ini, int &end) {
	int soma_max = INT_MIN;
	int n = array.size();
	ini = end = -1;

	for (int i = 0; i < n; i++) {
		int soma_atual = 0;
		for (int j = i; j < n; j++) {
			soma_atual += array[j];

			if (soma_atual > soma_max) {
				soma_max = soma_atual;
				ini = i;
				end = j;
			}
		}
	}

	// Caso todos os números sejam negativos, retorna 0 (sequência vazia)
	if (soma_max < 0) {
		ini = end = -1;
		return 0;
	}

	return soma_max;
}

/* Pr�tica 13 - Dividir e Conquistar ----------------- */

int subseqMaxMiddle(const vector<int> &array, int start, int middle, int finish, int & ini, int & end) {
	// GIVEN
	int maxL = 0, maxR = 0;
	int sumL = 0, sumR = 0;

	ini = end = middle;

	for (int i = middle - 1; i >= start; i--) {
		count_ssm ++;
		sumL += array[i];
		if (sumL > maxL) {
			maxL = sumL;
			ini = i;
		}
	}

	for (int i = middle + 1; i <= finish; i++) {
		count_ssm ++;
		sumR += array[i];
		if (sumR > maxR) {
			maxR = sumR;
			end = i;
		}
	}

	return maxL + maxR + array[middle];
}

int subseqMaxDC_Rec(const vector<int> &array, int start, int finish, int &ini, int &end) {
	if (start == finish) {
		ini = end = start;
		return array[start];
	}

	int middle = (start + finish) / 2;
	int leftIni, leftEnd, rightIni, rightEnd, midIni, midEnd;

	int leftMax = subseqMaxDC_Rec(array, start, middle, leftIni, leftEnd);
	int rightMax = subseqMaxDC_Rec(array, middle + 1, finish, rightIni, rightEnd);
	int midMax = subseqMaxMiddle(array, start, middle, finish, midIni, midEnd);

	if (leftMax >= rightMax && leftMax >= midMax) {
		ini = leftIni;
		end = leftEnd;
		return leftMax;
	} else if (rightMax >= leftMax && rightMax >= midMax) {
		ini = rightIni;
		end = rightEnd;
		return rightMax;
	} else {
		ini = midIni;
		end = midEnd;
		return midMax;
	}
}

int subseqMaxDC(const vector<int> &array, int & ini, int & end) {
	// GIVEN
	int len = (int)array.size();
	return subseqMaxDC_Rec(array, 0, len - 1, ini, end);
}

/* Pr�tica 14 - Rercusiva ----------------- */

int seqMax(const vector<int> &array, int pos, int & ini) {
	// GIVEN
	if (pos < 0) return 0;
	int sum, iniPrev;

	count_ssm ++;
	int x = array[pos];
	int sumPrev = x + seqMax(array, pos - 1, iniPrev);

	if ( x >= sumPrev) {		// come�a nova sequencia
		sum = array[pos];
		ini = pos;
	} else {				// continua sequencia anterior
		sum = sumPrev;
		ini = iniPrev;
	}

	return sum;
}

int subseqMaxRec(const vector<int> &array, int & ini, int & end) {
	// GIVEN
	int sum = 0;
	int len = (int)array.size();
	ini = end = -1;

	count_ssm = 0;

	for (int i = 0; i < len; i++) {
		int _ini, _sum;
		_sum = seqMax(array, i, _ini);

		if (_sum > sum) {
			sum = _sum;
			ini = _ini;
			end = i;
		}
	}

	return sum;
}

/* Pr�tica 14 - Memoization ----------------- */

int seqMaxMemo(const vector<int> &array, int pos, int &ini, int *SUM, int *INI) {
	if (SUM[pos] != -1) {
		ini = INI[pos];
		return SUM[pos];
	}

	if (pos < 0) return 0;

	int sum, iniPrev;
	int x = array[pos];
	int sumPrev = x + seqMaxMemo(array, pos - 1, iniPrev, SUM, INI);

	if (x >= sumPrev) {
		sum = array[pos];
		ini = pos;
	} else {
		sum = sumPrev;
		ini = iniPrev;
	}

	SUM[pos] = sum;
	INI[pos] = ini;
	return sum;
}

int subseqMaxMemo(const vector<int> &array, int &ini, int &end) {
	int len = (int)array.size();
	int sum = 0;

	int *SUM = new int[len];
	int *INI = new int[len];

	fill(SUM, SUM + len, -1);
	fill(INI, INI + len, -1);

	count_ssm = 0;


	for (int i = 0; i < len; i++) {
		int _ini;
		int _sum = seqMaxMemo(array, i, _ini, SUM, INI);

		if (_sum > sum) {
			sum = _sum;
			ini = _ini;
			end = i;
		}
	}

	delete[] SUM;
	delete[] INI;

	return sum;
}

/* Pr�tica 14 - Programa��o Din�mica ----------------- */

int subseqMaxPD(const vector<int> &array, int & ini, int & end) {
	// TODO
	
}

/* -------------------------------------- */

void runSubseqMax(const char * name, int subseqmax(const vector<int> &, int&, int&), const vector<int> & array, bool printSeq) {
	using namespace std::chrono;

	count_ssm = 0;

	int ini = 0, end = 0;

	auto start = high_resolution_clock::now();

	int max = subseqmax(array, ini, end);

	auto finish = high_resolution_clock::now();
	long elapsed = duration_cast<nanoseconds>(finish-start).count() / 1000;

	cout << name << ": " << max << " ";


	cout << "[time: "<< setw(6) << setfill(' ') << elapsed << "us] ";
	cout << "[count: " << setw(6) << setfill(' ') << count_ssm << "] ";

	if (printSeq) {
		cout << "[ ";
		for (int i = ini; i <= end; i++) cout << array[i] << " ";
		cout << "] ";
	}

	cout << endl;
}

//int main_SUBSEQMAX() {
int main() {
	bool printSeq = true;
	int size = 20;

	srand(12345);

	vector<int> array(size);

	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < size; j++) {
			array[j] = (rand() % (3 * size)) - (rand() % (4 * size));
		}

		cout <<"Test " << i << ": ";

		for (auto v : array) cout << v << " ";
		cout << endl;

		runSubseqMax("Bruteforce     ", subseqMaxBF, array, printSeq);
		runSubseqMax("Divide&Conquer ", subseqMaxDC, array, printSeq);
		runSubseqMax("Recursive      ", subseqMaxRec, array, printSeq);
		runSubseqMax("Memoization    ", subseqMaxMemo, array, printSeq);
		runSubseqMax("Dynamic Prog.  ", subseqMaxPD, array, printSeq);
	}

	return 0;
}






