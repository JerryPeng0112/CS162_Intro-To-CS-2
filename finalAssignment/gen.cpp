#include <iostream>
#include <cstdlib>
using namespace std;
void shuffle(int arr[], int num){
    int temp;
    for(int i = 0; i < 5; i++){
        for(int j = num - 1; j > 0; j--){
            int b = rand() % j;
            temp = arr[b];
            arr[b] = arr[j];
            arr[j] = temp;
        }
    }
}

void a(int num){
    for(int i = 1; i <= num; i++){
        cout << i << " ";
    }
    cout << endl;
}

void d(int num){
    for(int i = num; i > 0; i--){
        cout << i << " ";
    }
    cout << endl;
}

void r(int num){
    int arr[num];
    for(int i = 0; i < num; i++){
        arr[i] = i + 1;
    }
    shuffle(arr, num);
    for(int i = 0; i < num; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void rr(int num){
    int arr[num];
    for(int i = 0; i < num/2; i++){
        arr[i * 2] = i + 1;
        arr[i * 2 + 1] = i + 1;
    }
    shuffle(arr, num);
    for(int i = 0; i < num; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(){
    srand(time(NULL));
    a(1000);
    d(1000);
    //r(1000);
    //rr(1000);
}
