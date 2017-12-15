#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either stmt. We wouldn't
//be able to compare our vector template to the Standard
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
    vector<int> v;   //Our vector class
    std::vector<int> stdv; //Standard vector
    //Compare operation of our vector to std
    v.push_back(23);
    stdv.push_back(23);
    cout << "size of v: " << v.size() << endl;
    cout << "size of stdv: " << stdv.size() << endl;
    vector<int> new_v = v;
    cout << "size of new_v, copy constructed: " << new_v.size() << endl;
    cout << "new_v[0]: " << new_v[0] << endl;
    cout << "new_v[1]: " << new_v[1] << endl;
    cout << "new_v.at(0): " << new_v.at(0) << endl;
    cout << "new_v.at(1): " << new_v.at(1) << endl;
    return 0;
}
