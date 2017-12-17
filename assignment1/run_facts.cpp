/*********************************************************************
** Program Filename: run_facts.cpp
** Author: Tsewei Peng
** Date: 04/13/2016
** Description: This program reads information of states and counties from a text file, and print out the stats of the states and counties
** Input: command line: -s # -f filename. Input for restarting reading, and if yes, re-input number of states read and the file to be read.
** Output: The information of states and counties. After that, print the stats of the stats of the states and counties
*********************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include "./facts.h"
using namespace std;

int main(int argc, char *argv[]){
	int state_num;
	string filename, state_nums;
	bool restart = true, check_arg = false;
	do{
		if(!check_arg){
			if(!is_valid_arguments(argv, argc)){
				cout << "usage: -s # -f filename" << endl;
				return 0;
			}else{
				state_nums = argv[2];
				filename = argv[4];
				if(!check_num(state_nums)){
					state_num = get_num();
				}else{
					state_num = atoi(state_nums.c_str());
				}
				if(!check_file(filename)){
					filename = get_file();
				}
			}
			check_arg = true;
		} else {
			filename = get_file();
			state_num = get_num();
		}
		check_arg++;
		cout << endl;
		get_info(state_num, filename);
		restart_prompt(restart);
	}while(restart == true);
}
