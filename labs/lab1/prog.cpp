#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "./mult_div.h"

using namespace std;
int main(int argc, char **argv){
	int m = -1, n = -1,o = -1;
	string restart, tempr, tempc;
	do{
		if(o == -1){
			if(argc == 3 && is_valid_dimensions(argv[1], argv[2])) {
				m = atoi(argv[1]);
				n = atoi(argv[2]);
			} else {
				cout << "Invalid dimensions! Enter new dimensions: ";
				get_dimension(tempr, tempc);
				m = atoi(tempr.c_str());
				n = atoi(tempc.c_str());
			}
			o++;
		}
		mult_div_values **table = create_table(m, n);
		set_mult_values(table, m, n);
		set_div_values(table, m, n);
		print(table, m, n);
		delete_table(table, m);
		cout << "Do you want to do it again? ('y' for yes, 'n' for no)" << endl;
		cin >> restart;
		if(restart == "y"){
			get_dimension(tempr, tempc);
			m = atoi(tempr.c_str());
			n = atoi(tempc.c_str());
		}
	}while(restart == "y");
}