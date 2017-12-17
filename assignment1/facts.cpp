/*********************************************************************
** Program Filename: facts.cpp
** Author: Tsewei Peng
** Date: 04/13/2016
** Description: The implementation file for run_facts.cpp
** Input: Same as the run_facts.cpp
** Output: Same as the run_facts.cpp
*********************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include "./facts.h"
using namespace std;

/*********************************************************************
** Function: restart_prompt
** Description: Ask the user if they want to restart the program, will continue to ask for answer until right answer is inputted
** Parameters: bool &restart
** Pre-Conditions: the file is read and the stats outputted
** Post-Conditions: restart is either changed to false, or stay on true
*********************************************************************/
void restart_prompt(bool &restart){
	while(1){
		string input;
		cout << "Would you like to run again? ('y' for yes, 'n' for no) ";
		getline(cin, input);
		if(input.length() == 1){
			if(input == "n"){
				restart = false;
				return;
			}else if(input == "y"){
				break;
			}
		}
		cout << endl << "Please enter 'y' for yes, 'n' for no !" << endl;
	}
}

/*********************************************************************
** Function: is_valid_arguments
** Description: Check if the command line argument is valid or not
** Parameters: char *argv[], int argc
** Pre-Conditions: none
** Post-Conditions: Return if the command line is not satisfying, and will not recover, return true if command line acceptable
*********************************************************************/
bool is_valid_arguments(char *info[], int argc){
	if(argc != 5 || strcmp(info[1], "-s") || strcmp(info[3], "-f")){
		return false;
	}
	return true;
}

/*********************************************************************
** Function: check_num
** Description: Check if a string contain valid number
** Parameters: string check
** Pre-Conditions: a string passed into function
** Post-Conditions: return false if it's empty or contain characters that are not numbers
*********************************************************************/
bool check_num(string check){
	if(check.empty()){
		return false;
	}
	for(int i = 0; i < check.length(); i++){
		if(check[i] < '0' || check[i] > '9'){
			cout << endl << "Invalid number !" << endl;
			return false;
		}
	}
	return true;
}

/*********************************************************************
** Function: check_file
** Description: check if a filename is valid to open
** Parameters: string filename
** Pre-Conditions: a string passed into the function
** Post-Conditions: return false if the file fail to open, and true of the file valid to open
*********************************************************************/
bool check_file(string filename){
	ifstream file;
	file.open(filename.c_str());
	if(file.fail()){
		cout << endl << "Invalid filename !" << endl;
		file.close();
		return false;
	}else{
		file.close();
		return true;
	}
}

/*********************************************************************
** Function: get_num
** Description: get a number from user and return it
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: return a valid positive number
*********************************************************************/
int get_num(){
	string num;
	int numi;
	while(1){
		cout << "Please enter the number of state data to get from file: ";
		getline(cin, num);
		if(num[0] != '0'){
			if(check_num(num)){
				numi = atoi(num.c_str());
				return numi;
			}
		}
	}
}

/*********************************************************************
** Function: get_file
** Description: get a filename and return it if valid
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: return a string as filename when it's checked valid
*********************************************************************/
string get_file(){
	string filename;
	while(1){
		cout << "Please enter a filename: ";
		getline(cin, filename);
		if(check_file(filename)){
			return filename;
		}
	}
}

/*********************************************************************
** Function: get_info
** Description: get the information from the text file
** Parameters: int state_num, string filename
** Pre-Conditions: the valid number of state and filename
** Post-Conditions: all the text file processed
*********************************************************************/
void get_info(int state_num, string filename){
	ifstream file;
	int c = 0;
	file.open(filename.c_str());
	state *states = create_states(state_num);
	cout << "===================== File data =====================" << endl;
	for(int i = 0; i < state_num; i++){
		get_state_data(states, i, file);
		c++;
		if(file.eof()){
			cout << "End Of File Reached !" << endl;
			break;
		}
	}
	cout << endl << endl;
	state_num = c;
	print_stats(states, c);
	delete_info(states, state_num);
}

/*********************************************************************
** Function: state *create_state
** Description: create a dynamic array with size of number of states
** Parameters: int state_nu,
** Pre-Conditions: pass in number of states
** Post-Conditions: return a dynamic array of states
*********************************************************************/
state *create_states(int state_num){
	state *states;
	states = new state[state_num];
	return states;
}

/*********************************************************************
** Function: get_state_data
** Description: get the information of state depending on the index of the value passed in
** Parameters: state *states, int state_num ifstream &file
** Pre-Conditions: the file is opened, and the states array is passed, the integer is passed in
** Post-Conditions: the data is put into specific state
*********************************************************************/
void get_state_data(state *states, int state_num, ifstream &file){
	string line;
	stringstream ss;
	getline(file, line);
	ss << line;
	ss >> states[state_num].name >> states[state_num].population >> states[state_num].counties;
	cout << states[state_num].name << " " << states[state_num].population << " " << states[state_num].counties << " " << endl;
	states[state_num].c = create_counties(states[state_num].counties);
	for(int i = 0; i < states[state_num].counties; i++){
		get_county_data(states[state_num].c, i, file);
	}
}

/*********************************************************************
** Function: county *create_counties
** Description: create a dynamic array of county based on the number of county
** Parameters: int county_num
** Pre-Conditions: the number of county passed into function
** Post-Conditions: return the county pointer
*********************************************************************/
county * create_counties(int county_num){
	county *counties;
	counties = new county[county_num];
	return counties;
}

/*********************************************************************
** Function: get_county_data
** Description: get the data of the county
** Parameters: county *counties, int county_num ifstream &file
** Pre-Conditions: the number of counties is read from previous line
** Post-Conditions: the county information are put into the state.c
*********************************************************************/
void get_county_data(county *counties, int county_num, ifstream &file){
	string line;
	stringstream ss;
	getline(file, line);
	ss << line;
	ss >> counties[county_num].name >> counties[county_num].population >> counties[county_num].avg_income >> counties[county_num].avg_house >> counties[county_num].cities;
	//
	cout << counties[county_num].name << " " << counties[county_num].population << " " << counties[county_num].avg_income << " " << counties[county_num].avg_house << " " << counties[county_num].cities;
	counties[county_num].city = new string [counties[county_num].cities];
	for(int i = 0; i < counties[county_num].cities; i++){
		ss >> counties[county_num].city[i];
	}
	//
	for(int i = 0; i < counties[county_num].cities; i++){
		cout << " " << counties[county_num].city[i];
	}
	cout << endl;
}

/*********************************************************************
** Function: delete_info
** Description: delete all the dynamic arrays
** Parameters: state *states, int state_num
** Pre-Conditions: the files are read, and the stats are printed
** Post-Conditions: all the dynamic array and memories are freed
*********************************************************************/
void delete_info(state *states, int state_num){
	for(int i = 0; i < state_num; i++){
		for(int j = 0; j < states[i].counties; j++){
			delete [] states[i].c[j].city;
		}
		delete [] states[i].c;
	}
	delete[] states;
}

/*********************************************************************
** Function: print_stats
** Description: the main function for printing the stats of the arrays
** Parameters: state *states, int state_num
** Pre-Conditions: the states arrays are created, and the number of states are passed in
** Post-Conditions: All the filed are printed
*********************************************************************/
void print_stats(state *states, int state_num){
	state_pop(states, state_num);
	county_pop(states, state_num);
	county_above_income(states, state_num);
	avg_house_cost(states, state_num);
	sort_state_name(states, state_num);
	sort_state_pop(states, state_num);
	sort_county_pop(states, state_num);
	sort_county_name(states, state_num);
}

/*********************************************************************
** Function: state_pop
** Description: print out the state with most population
** Parameters: state *states, int state_num
** Pre-Conditions: arrays passed in
** Post-Conditions: none
*********************************************************************/
void state_pop(state *states, int num){
	int max = states[0].population, count = 0;
	for(int i = 1; i < num; i++){
		if(states[i].population > max){
			count = i;
			max = states[i].population;
		}
	}
	cout << "1. The state with the largest population: " << endl << states[count].name << ", " << states[count].population << endl << endl;
}

/*********************************************************************
** Function: county_pop
** Description: print the county with most population
** Parameters: state *states, int state_num
** Pre-Conditions: states array passed in
** Post-Conditions: none
*********************************************************************/
void county_pop(state *states, int num){
	int max = states[0].c[0].population, count_state = 0, count_county = 0;
	for(int i = 0; i < num; i++){
		for(int j = 0; j < states[i].counties; j++){
			if(states[i].c[j].population > max){
				count_state = i;
				count_county = j;
				max = states[i].c[j].population;
			}
		}
	}
	cout << "2. The county with the largest population: " << endl << states[count_state].c[count_county].name << ", " << states[count_state].c[count_county].population << endl;
}

/*********************************************************************
** Function: county_above_income
** Description: print out counties with income above user input
** Parameters: state *states, int state_num
** Pre-Conditions: states array passed in
** Post-Conditions: none
*********************************************************************/
void county_above_income(state *states, int num){
	string input;
	int income, count = 0;
	cout << endl;
	while(1){
		cout << "Please enter a income threshold: ";
		getline(cin, input);
		if(input[0] != '0'){
			if(check_num(input)){
				income = atoi(input.c_str());
				break;
			}
		}
	}
	cout << "3. The counties with an income above a specific amount: " << endl;
	for(int i = 0; i < num; i++){
		for(int j = 0; j < states[i].counties; j++){
			if(states[i].c[j].avg_income > income){
				count++;
				cout << states[i].c[j].name << " " << endl;
			}
		}
	}
	if(count == 0){
		cout << "None" << endl;
	}
	cout << endl;
}

/*********************************************************************
** Function: avg_house_cost
** Description: print the average housing cost for all counties in each state
** Parameters: state *states, int state_num
** Pre-Conditions: states array passed in
** Post-Conditions: none
*********************************************************************/
void avg_house_cost(state *states, int num){
	float avg;
	float total;
	cout << "4. The average household cost for all counties in each state: " << endl;
	for(int i = 0; i < num; i++){
		total = 0;
		for(int j = 0; j < states[i].counties; j++){
			total += states[i].c[j].avg_house;
		}
		avg = (total + 0.0)/states[i].counties;
		cout << states[i].name << ": " << avg << " " << endl;
	}
	cout << endl;
}

/*********************************************************************
** Function: sort_state_name
** Description: print out the sorted order by names in each state
** Parameters: state *states, int state_num
** Pre-Conditions: states array passed in
** Post-Conditions: none
*********************************************************************/
void sort_state_name(state *states, int num){
	state temp;
	for(int i = 0; i < num - 1; i++){
		for(int j = 1; j < num; j++){
			if(states[i].name.compare(states[j].name) > 0){
				temp = states[i];
				states[i] = states[j];
				states[j] = temp;
			}
		}
	}
	cout << "5. The states in sorted order by name (alphabetical order): " << endl;
	for(int i = 0; i < num; i++){
		cout << states[i].name << " " << endl;
	}
	cout << endl;
}

/*********************************************************************
** Function: sort_state_pop
** Description: print out the sorted state by population for states
** Parameters: state *states, int state_num
** Pre-Conditions: states array passed in
** Post-Conditions: none
*********************************************************************/
void sort_state_pop(state *states, int num){
	state temp;
	for(int i = 0; i < num - 1; i++){
		for(int j = 1; j < num; j++){
			if(states[i].population < states[j].population){
				temp = states[i];
				states[i] = states[j];
				states[j] = temp;
			}
		}
	}
	cout << "6. The states in sorted order by population (from large to small): " << endl;
	for(int i = 0; i < num; i++){
		cout << states[i].name << " " << endl;
	}
	cout << endl;
}

/*********************************************************************
** Function: sort_county_pop
** Description: print out the sorted counties by population in each states
** Parameters: state *states, int state_num
** Pre-Conditions: states array passed in
** Post-Conditions: none
*********************************************************************/
void sort_county_pop(state *states, int num){
	county temp;
	for(int i = 0; i < num; i++){
		for(int j = 0; j < states[i].counties - 1; j++){
			for(int k = 1; k < states[i].counties; k++){
				if(states[i].c[j].population < states[i].c[k].population){
					temp = states[i].c[j];
					states[i].c[j] = states[i].c[k];
					states[i].c[k] = temp;
				}
			}
		}
	}
	cout << "7. The counties within states sorted by population (from large to small): " << endl;
	for(int i = 0; i < num; i++){
		cout << states[i].name << ": " << endl;
		for(int j = 0; j < states[i].counties; j++){
			cout << "\t" << states[i].c[j].name << " " << endl;
		}
		cout << endl;
	}
}

/*********************************************************************
** Function: sort_county_name
** Description: sort the counties by order of names in each states
** Parameters: state *states, int state_num
** Pre-Conditions: states array passed in
** Post-Conditions: none
*********************************************************************/
void sort_county_name(state *states, int num){
	county temp;
	for(int i = 0; i < num; i++){
		for(int j = 0; j < states[i].counties - 1; j++){
			for(int k = 1; k < states[i].counties; k++){
				if(states[i].c[j].name.compare(states[i].c[k].name) > 0){
					temp = states[i].c[i];
					states[i].c[i] = states[i].c[j];
					states[i].c[j] = temp;
				}
			}
		}
	}
	cout << "8. The counties within states sorted by name (alphabetical order): " << endl;
	for(int i = 0; i < num; i++){
		cout << states[i].name << ": " << endl;
		for(int j = 0; j < states[i].counties; j++){
			cout << "\t" << states[i].c[j].name << " " << endl;
		}
		cout << endl;
	}
}
