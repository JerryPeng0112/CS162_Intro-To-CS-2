#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "./mult_div.h"

using namespace std;

void get_dimension(string &a, string &b){
	bool quit;
	do{
		quit = false;
		cout << "row: ";
		cin >> a;
		cout << "column: ";
		cin >> b;
		for(int i = 0; i < a.length(); i++){
			if(a.at(i) < '0' || a.at(i) > '9'){
				quit = true;
				break;
			}
		}
		for(int i = 0; i < b.length(); i++){
			if(b.at(i) < '0' || b.at(i) > '9'){
				quit = true;
				break;
			}
		}
	}while(quit);
}
bool is_valid_dimensions(char *m, char *n){
	for(int i = 0; i < strlen(m); i++)
		if(m[i] < '0' || m[i] > '9')
			return false;
	for(int i = 0; i < strlen(n); i++)
		if(n[i] < '0' || n[i] > '9')
			return false;
	if(m[0] != '0' && n[0] != '0'){
		return true;
	} else {
		return false;
	}
}

mult_div_values** create_table(int m, int n){
	mult_div_values **table = new mult_div_values*[m];
	for(int i = 0; i < m; i++){
		table[i] = new mult_div_values[n];
	}
	return table;
}
void set_mult_values(mult_div_values **table, int m, int n){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			table[i][j].mult = (i + 1)*(j + 1);
		}
	}
}
void set_div_values(mult_div_values **table, int m, int n){
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			table[i][j].div = (i + 1.0)/(j + 1.0);
		}
	}
}
void print(mult_div_values **table, int m, int n){
	cout << " Multiplication Table: " << endl;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout << " " << table[i][j].mult;
		}
		cout << endl;
	}	
	cout << " Division Table: " << endl;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout << " " << table[i][j].div;
		}
		cout << endl;
	}	
}
void delete_table(mult_div_values **table, int m){
	for(int i = 0; i < m; i++){
		delete[] table[i];
	}
	delete[] table;
}
