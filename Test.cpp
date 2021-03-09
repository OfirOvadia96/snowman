#include "doctest.h"
#include "snowman.hpp"
#include <stdlib.h>
#include <limits>
using namespace ariel;

#define array_length 6;

//checks invalid inputs:

TEST_CASE("Bad input >> to_short to_long"){
int short_random = rand()%11111111; //0 to 11111110
int long_random = rand()% INTMAX_MAX + 44444445; //44444445 to max_int
CHECK_THROWS(snowman(short_random));
CHECK_THROWS(snowman(long_random));
}

TEST_CASE("Bad inputs >> negetive number"){
    int negative = ((-1) * rand() % INTMAX_MAX);
    CHECK_THROWS(snowman(negative));
}

//checks all the 48 cases >> (8 - digit) * (6 - out_of_range_numbers)
TEST_CASE("Bad input >> contains number not in the range 1-4"){
    //first digit
    int arr[6] = {-1, 4, 5, 6, 7, 8};
    int number = 11111111;
    for(int i=0; i<array_length i++){
        CHECK_THROWS(snowman((number+arr[i])));
    }

    //second digit
    for(int i=0; i<array_length i++){
        CHECK_THROWS(snowman((number+(arr[i]*10))));
    }

    //third digit
    for(int i=0; i<array_length i++){
        CHECK_THROWS(snowman((number+(arr[i]*100))));
    }

    //fourth digit
    for(int i=0; i<array_length i++){
        CHECK_THROWS(snowman((number+(arr[i]*1000))));
    }

    //fifth digit
    for(int i=0; i<array_length i++){
        CHECK_THROWS(snowman((number+(arr[i]*10000))));
    }

    //sixth digit
    for(int i=0; i<array_length i++){
        CHECK_THROWS(snowman((number+(arr[i]*100000))));
    }

    //seventh digit
    for(int i=0; i<array_length i++){
        CHECK_THROWS(snowman((number+(arr[i]*1000000))));
    }

    //eighth digit
    for(int i=0; i<array_length i++){
        CHECK_THROWS(snowman((number+(arr[i]*10000000))));
    }
}

//check snowman function with valid input >> checks the outputs:

TEST_CASE("Good input >> check snowman body parts"){
    CHECK(snowman(11111111) == string("_===_\n(.,.)\n<( : )>/\n( : )"));
    CHECK(snowman(22222222) == string(" ---\n.....\n(o.o)\n\\(] [)/\n(" ")"));
    CHECK(snowman(33333333) == string(" _ \n/_\\n(O_O)\n/(> <)\\n(___)"));
    CHECK(snowman(44444444) == string(" ___\n[_*_]\n(- -)\n(   )\n(   )"));
}

TEST_CASE("Good inputs >> randomal snowmans"){
    CHECK(snowman(11111111) == string("_===_\n(.,.)\n<( : )>\n( : )"));

    CHECK(snowman(31112214) == string("_/_\\\n\\(.,.)/\n]( : )[\n(   )")) ;
    
    CHECK (snowman(41112214) ==string("___ \n(_*_)\n\\(.,.)/\n]( : )[\n(   )"));

    CHECK(snowman(44112214) == string("___ \n(_*_)\n\\(. .)/\n]( : )[\n(   )")); 

    CHECK(snowman(44442214) ==string( "___ \n(_*_)\n\\(- -)/\n]( : )[\n(   )"));

    CHECK(snowman(42442214) ==string( "___ \n(_*_)\n\\(-.-)/\n]( : )[\n(   )"));

    CHECK(snowman(11114411) == string("_===_\n(.,.)\n( : )\n( : )"));

    CHECK(snowman(41111112) == string("___ \n(_*_)\n(.,.)\n<( : )>\n(" ")"));

    CHECK(snowman(11112211) == string("_===_\n\\(.,.)/\n( : )\n( : )"));

    CHECK(snowman(11112213) == string("_===_\n\\(.,.)/\n( : )\n( ___ )"));

    CHECK(snowman(21112213) == string("___\n.....\n\\(.,.)/\n( : )\n( ___ )"));

    CHECK(snowman(11111213) == string("_===_\n(.,.)/\n<( : )\n( ___ )"));

    CHECK(snowman(11331213) == string("_===_\n(O,O)/\n<( : )\n( ___ )"));

    CHECK(snowman(32331213) == string("_ \n/_\\\n(O.O)/\n<( : )\n( ___ )"));

    CHECK(snowman(11331113) == string("_===_\n(O,O)\n<( : )>\n( ___ )"));

    CHECK(snowman(11331133) == string("_===_\n(O,O)\n<(> <)>\n( ___ )"));

    CHECK(snowman(11331233) == string("_===_\n(O,O)/\n<(> <)\n( ___ )"));

    CHECK(snowman(11321222) == string("_===_\n(O,o)/\n<(] [)\n(" ") "));

    CHECK(snowman(12222212) == string("_===_\n(o.o)\n\\( : )/\n(" ")"));
    
    CHECK(snowman(32443333) == string("_/_\\\n\\(-.-)/\n(> <)\n(___)"));

}