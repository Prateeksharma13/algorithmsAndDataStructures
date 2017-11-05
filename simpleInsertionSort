#include <iostream>

using namespace std;

int main()
{
    int a[5] = { 13, 21, 3, 5, 4 };
    
    for(int j = 1; j < 5; j++) {
        int temp = a[j];
        int i = j - 1;            
        while(i > -1 && a[i] > temp){
            a[j] = a[i];
            a[i] = temp;
            i = i - 1;
            j = j -1;
        }
     }
    
    for(int i =0; i <5; i++) {
        cout << a[i] <<endl;
    }
    
}



