#include <chrono> 
#include <string>
#include <iostream>
#include <fstream>
#include <random>
#include <map>
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include <ctime>
#include <stdio.h>
using namespace std;



void generateFile(string filename, int size, int min, int max) {
	ofstream out(filename);
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(min, max);
	for (int i = 0; i < size; i++) {
		int x = distribution(generator);
		out << x << endl;
	}

}
vector<int> getData(string filename,int nr) {
	vector<int> v{};
	//int x = rand() % 20 + 10;
	generateFile(filename, nr, -10, 30);


	ifstream f(filename);
	int c;
	while (!f.eof()) {
		f >> c;
		v.push_back(c);
	}
	f.close();
	return v;
}

vector<int> copy(vector<int> list, int pos1, int pos2) {
	vector<int> rez{};
	for (int i = pos1; i < pos2; i++) {
		rez.push_back(list[i]);
	}
	return rez;
}

vector<int> merge(vector<int> a, vector<int> b) {
	int k = 0;
	vector<int> merged{};
	int i = 0, j = 0;
	while (i != a.size() && j != b.size()) {
		if (a[i] <= b[j]){
			merged.push_back(a[i]);
			i++;
		}else {
			merged.push_back(b[j]);
			j++;
		}
	}
	if (i != a.size()) {
		for (int ii = i; ii < a.size(); ii++) {
			merged.push_back(a[ii]);
		}
	}
	if (j != b.size()) {
		for (int jj = j; jj < b.size(); jj++) {
			merged.push_back(b[jj]);
		}
	}
	return merged;
}
vector<int> mergeSortSecv(vector<int>list) {
	if (list.size() == 1) {
		return list;
	}
	else {
		int m = list.size() / 2;
		vector<int> a = copy(list, 0, m);
		vector<int> b = copy(list, m, list.size());
		vector<int> aSorted = mergeSortSecv(a);
		vector<int> bSorted = mergeSortSecv(b);
		return merge(aSorted, bSorted);
	}

}

using namespace std::chrono;


int main() {
	vector<int> a = getData("C:\\Users\\Patcas\\source\\repos\\Lab3PPCpp\\Lab3PPCpp\\data.txt", 25);
	vector<int> rez = mergeSortSecv(a);
	ofstream f("C:\\Users\\Patcas\\source\\repos\\Lab3PPCpp\\Lab3PPCpp\\rez.txt");
	
	for (int i = 0; i < rez.size(); i++) {
		f<< rez[i] << " ";
	}
	f.close();
	return 0;
}