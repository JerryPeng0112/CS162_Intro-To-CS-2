#include <iostream>
#include <fstream>
#include <string>
#include "./letters.h"

using namespace std;

void count_letters(ifstream &file, int* alphaarray);
void output_letters(ofstream &outfile, int* alphaarray);

int main(){
	string filename;
	ifstream file;
	while(1){
		cout << "Enter filename you wish to read: ";
		cin >> filename;
		file.open(filename.c_str());
		if(file.fail()){
			cout << "Invalid filename!" << endl;
		} else {
			break;
		}
	}
	int alphaarray[26];
	count_letters(file, alphaarray);
	
	return 0;
}

