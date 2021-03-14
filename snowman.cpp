#include "snowman.hpp"
using namespace std;

/*function that draw snowman
get int - for type
return string - draw of snowman
*/

namespace ariel{

    string snowman(int type){
        string input = to_string(type);

         //Check the input length
         const int Length = 8;
         if(input.length() != Length){
             throw invalid_argument("Invalid input ! ! ! too shot/long");
         }
         
         //Check the input range numbers 1-4
         for(int i=0; i<Length; i++){
             if(input[i] < '1' || input[i] > '4'){
                 throw invalid_argument("Invalid input ! ! ! out of range 1-4 ");
             }
         }
        
        //arrays of all body parts
        const array<string,4> base {" : ","\" \"","___","   "};
        const array<string,4> torso {" : ","] [","> <","   "};
        const array<string,4> rightArm {">","/","\\",""};
        const array<string,4> leftArm {"<","\\","/",""};
        const array<string,4> eye {".","o","O","-"}; // for both eyes
        const array<string,4> nose {",",".","_"," "};
        const array<string,4> hat {"_===_"," ___\n.....","  _\n /_\\"," ___\n(_*_)"};

        string snowman_draw;
        /*
        snowman model:
          HHHHH
          HHHHH
         X(LNR)Y
         X(TTT)Y
          (BBB)
        */
        const int B = 7; //base
        const int T = 6; //torso
        const int Y = 5; //right arm
        const int X = 4; //left arm
        const int R = 3; //right eye
        const int L = 2; //left eye
        const int N = 1; //nose
        const int H = 0; //hat
        const int a = 49; //char to int(ASCI)

        //Checks if the snowman with left arm
        if (input[X] != '4'){
            snowman_draw += " " + hat.at(input[H] - a) + "\n";
            const int six = 6;
            const int five = 5;
            if (input[H] == '4' || input[H] == '2'){
                snowman_draw.insert(six, " ");
            }
            else if (input[H] == '3'){
                snowman_draw.insert(five, " ");
            }
        }
        else{
            snowman_draw += hat.at(input[H] - a) + "\n";
        }
         //three big parts:

        //head
        if (input[X] == '2') { //If left hand up
            snowman_draw += '\\';
        }
        else if (input[X] != '4') { //If have left arm
            snowman_draw += " ";
        }
        snowman_draw += "(" + eye.at(input[L] - a) + nose.at(input[N] - a) + eye.at(input[R] - a) + ")";
        if (input[Y] == '2') { //If right hand up
            snowman_draw += '/';
        }
        snowman_draw += '\n';

        //chest
        if (input[X] == '2') { //If left hand up = put space in the chest
            snowman_draw += " ";
        }
        else{
            snowman_draw += leftArm.at(input[X] - a);
        }
        snowman_draw += "(" + torso.at(input[T] - a) + ")";
        if (input[Y] != '2') { //If the right hand is not up = put by number[Y]
            snowman_draw += rightArm.at(input[Y] - a);
        }
        snowman_draw += '\n';

        //bottom part
        if (input[X] != '4') { //If there is a left arm
            snowman_draw += " ";
        }
        snowman_draw += "(" + base.at(input[B] - a) + ")";

        return snowman_draw;
    }
}