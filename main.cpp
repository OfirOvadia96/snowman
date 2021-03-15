#include "snowman.hpp"
using namespace ariel;
/*
program that uses the snowman function
*/

int main(){
    cout << "Wellcome ! in this program you can draw snowman\n";
    int choose = 1;
    int snowman_type;
    while(choose){
        cout << "please choose your type snowman: (insert 8 numbers each number 1-4)\n";
        cin >> snowman_type;
        try{
            cout << snowman(snowman_type) + "\n";
        }
        catch(invalid_argument e){
                cout << " next time insert vaild number\n";
        }
        cout << "to continue insert 1 , to exit insert 0\n";
        cin >> choose;
    }
    return 0;
}