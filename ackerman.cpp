#include <iostream>
using namespace std;

int ack(int m, int n){
    if(m == 0){
        return n + 1;
    }
    else if((m > 0) && (n == 0)){
        return ack(m-1, 1);
    }
    else if((m > 0) && (n > 0)){
        return ack(m - 1, ack(m, n - 1));
    }
    return -1;
}

int main(){
    int result;
    result = ack(1, 2);
    cout << "Result is: " << result << endl;
    return 0;
}