#include <stdlib.h>
#include <stdexcept>
template <class T>
class vector {
private:
    T *v;
    int s;
public:
    vector(){
        s=0;
        v=NULL;
    }
    int size(){
     return s;
    }
    void push_back(T ele) {
        T *temp;
        temp = new T[++s];
        for(int i=0; i<s-1; i++)
        temp[i]=v[i];
        delete [] v;
        v=temp;
        v[s-1]=ele;
    }
    T operator[](int i){ //Only perform address arithmetic
        return v[i];
    }
    T at(int i){ //Check to make sure not out of bounds
        if(i < s)
        return v[i];
        else
        throw std::out_of_range("out of my vector bounds");
    }

    vector(const vector &obj){
        s = obj.s;
        v = new T [s];
        for(int i = 0; i < s; i++){
            v[i] = obj.v[i];
        }
    }
    void operator =(const vector &obj){
        if(v != NULL) delete [] v;
        s = obj.s;
        v = new T [s];
        for(int i = 0; i < s; i++){
            v[i] = obj.v[i];
        }
    }
    ~vector(){
         delete [] v;
    }
};
