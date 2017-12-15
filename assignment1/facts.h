#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct state{
	string name;	// Name of state
	struct county *c;// Name of counties
	int counties;	// Number of counties in state
	int population; // Total population of state
};
struct county{
	string name;	// Name of county
	string *city;	// Name of cities in county
	int cities;		// Number of cities in county
	int population;	// Total population of county
	float avg_income;// Avg household income
	float avg_house;// Avg household price
};

bool is_valid_arguments(char *[], int);
void restart_prompt(bool &);
bool check_num(string);
bool check_file(string);
int get_num();
string get_file();
void get_info(int, string);
state * create_states(int);
void get_state_data(state *, int, ifstream &);
county * create_counties(int);
void get_county_data(county *, int, ifstream &);
void delete_info(state *, int);
void print_stats(state *, int);
void state_pop(state *, int);
void county_pop(state *, int);
void county_above_income(state *, int);
void avg_house_cost(state *, int);
void sort_state_name(state *, int);
void sort_state_pop(state *, int);
void sort_county_pop(state *, int);
void sort_county_name(state *, int);
