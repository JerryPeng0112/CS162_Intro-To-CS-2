#include <iostream>
#include <fstream>
#include <string>
#include "./letters.h"

using namespace std;

void count_letters(ifstream &file, int* alphaarray){
	char newchar;
	ofstream outfile;
	while(1){
		for(int i = 0; i < 26; i++){
			alphaarray[i] = 0;
		}
		while(!file.eof()){
			file.get(newchar);
			if(file.eof()){
				cout << "END" << endl;
			}
			if(newchar >= 'a' && newchar <= 'z'){
				alphaarray[newchar - 'a']++;
			} else if(newchar >= 'A' && newchar <= 'Z'){
				alphaarray[newchar - 'A']++;
			} else if(newchar == '\n'){
				output_letters(outfile, alphaarray);
				break;
			}
		}
		if(file.eof()){
			output_letters(outfile, alphaarray);
			break;
		}
	}
	file.close();
}

void output_letters(ofstream &outfile, int* alphaarray){
	string filename;
	while(1){
		cout << "Enter filename you wish to print to: ";
		cin >> filename;
		outfile.open(filename.c_str(), ios::app);
		if(outfile.fail()){
			cout << "Invalid filename!" << endl;
		} else {
			break;
		}
	}
	char letter;
	for(int i = 0; i < 26; i++){
		letter = 'A' + i;
		outfile << letter << ": " << alphaarray[i] << endl;
	}
	outfile.close();
}