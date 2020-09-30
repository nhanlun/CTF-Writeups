#include <iostream>
using namespace std;

unsigned int doSomething(unsigned int i){
    return (unsigned int)(((int)((i << 23) | (i >> 9)) ^ -559038242) + 8224);
}

int main(){
    for (int i = 0; i < 2500; i++){
        unsigned int num = doSomething(i);
        if (num == 808313084 || num == 1202577661 || num == 1613619453 || num == 2871910652u || num == 4230865146u)
            cout << i / 50 << " " << i % 50 << endl;
    }
    return 0;
}