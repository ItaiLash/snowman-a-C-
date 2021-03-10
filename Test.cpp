/**
 * snowman Unit tests.
 *
 * AUTHORS: <Itai.Lashover>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;


string removeSpaces(string str)  
{ 
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
    return str; 
} 

/*
Hats:
-1:"      \n _===_"
-2:"  ___ \n ....."
-3:"   _  \n  /_\\ "
-4:" ___ \n (_*_)\n"

Noses:
-1:"X(L,R)Y"
-2:"XL.R)Y"
-3:"X(L_R)Y"
-4:"X(L R)Y"

Eyes:
-1:"X(.N.)Y"
-2:"X(oNo)Y"
-3:"X(0N0)Y"
-4:"X(-N-)Y"

Arms:
-1:" (LNR) \n<(TTT)>"
-2:"\LNR)/\n (TTT) "
-3:" (LNR) \n/(TTT)\"
-4:" (LNR) \n (TTT) "

Torsos:
-1:"X( : )Y"
-2:"X(] [)Y"
-3:"X(> <)Y"
-4:"X(   )Y"

Base:
-1:" ( : ) "
-2:" (" ") "
-3:" (___) "
-4:" (   ) "
*/


TEST_CASE("Good snowman code")
{
    //All types of hats
    CHECK(snowman(11111111) == string("      \n _===_\n (.,.) \n<( : )>\n ( : )"));
    CHECK(snowman(22222222) == string("  ___ \n .....\n\\(o.o)/ \n (] [) \n (\" \")"));
    CHECK(snowman(33333333) == string("   _  \n  /_\\ \n (O_O) \n/(> <)\\\n (___)"));
    CHECK(snowman(44444444) == string("  ___ \n (_*_)\n (- -) \n (   ) \n (   ) "));
    
    //All types of Noses
    CHECK(snowman(31313131) == string("   _  \n  /_\\ \n (O,.) \n/(> <)>\n ( : )"));
    CHECK(snowman(12121212) == string("      \n _===_\n (..o)/\n<( : ) \n (\" \")"));
    CHECK(snowman(43242312) == string("  ___ \n (_*_)\n\\(o_-) \n ( : )\\\n (\" \")"));
    CHECK(snowman(44241342) == string("  ___ \n (_*_)\n (o -) \n<(   )\\\n (\" \")"));

    //All types of Left Eyes
    CHECK(snowman(11114111) == string("      \n _===_\n (.,.) \n ( : )>\n ( : )"));
    CHECK(snowman(43242312) == string("  ___ \n (_*_)\n\\(o_-) \n ( : )\\\n (\" \")"));
    CHECK(snowman(33333433) == string("   _  \n  /_\\ \n (O_O) \n/(> <) \n (___)"));
    CHECK(snowman(42424222) == string("  ___ \n (_*_)\n (-.o)/\n (] [) \n (\" \")"));

    //All types of Right Eyes
    CHECK(snowman(12311111) == string("      \n _===_\n (O..) \n<( : )>\n ( : )"));
    CHECK(snowman(11223344) == string("      \n _===_\n (o,o) \n/(   )\\\n (   )"));
    CHECK(snowman(44332211) == string("  ___ \n (_*_)\n\\(O O)/\n ( : ) \n ( : )"));
    CHECK(snowman(12341424) == string("      \n _===_\n (O.-) \n<(] [) \n (   )"));

    //All types of Left Arms(X)
    CHECK(snowman(31421322) == string("   _  \n  /_\\ \n (-,o) \n<(] [)\\\n (\" \")"));
    CHECK(snowman(34332212) == string("   _  \n  /_\\ \n\\(O O)/\n ( : ) \n (\" \")"));
    CHECK(snowman(31313131) == string("   _  \n  /_\\ \n (O,.) \n/(> <)>\n ( : )"));
    CHECK(snowman(31114411) == string("   _  \n  /_\\ \n (.,.) \n ( : ) \n ( : )"));

    //All types of Right Arms(Y)
    CHECK(snowman(12341111) == string("      \n _===_\n (O.-) \n<( : )>\n ( : )"));
    CHECK(snowman(12121212) == string("      \n _===_\n (..o)/\n<( : ) \n (\" \")"));
    CHECK(snowman(31421312) == string("   _  \n  /_\\ \n (-,o) \n<( : )\\\n (\" \")"));
    CHECK(snowman(33333433) == string("   _  \n  /_\\ \n (O_O) \n/(> <) \n (___)"));

    //All types of Tosss
    CHECK(snowman(12121212) == string("      \n _===_\n (..o)/ \n<( : ) \n (\" \")"));
    CHECK(snowman(43312222) == string("  ___ \n (_*_)\n\\(O_.)/\n (] [) \n (\" \")"));
    CHECK(snowman(31313131) == string("   _  \n  /_\\ \n (O,.) \n/(> <)>\n ( : )"));
    CHECK(snowman(14322341) == string("      \n _===_\n\\(O o) \n (   )\\\n ( : )"));

    //All types of Bases 
    CHECK(snowman(11114411) == string("      \n _===_\n (.,.) \n ( : ) \n ( : )"));
    CHECK(snowman(42424222) == string("  ___ \n (_*_)\n (-.o)/\n (] [) \n (\" \")"));
    CHECK(snowman(33333443) == string("   _  \n  /_\\ \n (O_O) \n/(   ) \n (___)"));
    CHECK(snowman(12341424) == string("      \n _===_\n (O.-) \n<(] [) \n (   )"));
}
  
TEST_CASE("Bad snowman code - Invalid input: less then 8 characters")
{
    CHECK_THROWS(snowman(1));                  // 1 character
    CHECK_THROWS(snowman(12));                 // 2 character
    CHECK_THROWS(snowman(123));                // 3 character
    CHECK_THROWS(snowman(1234));               // 4 character
    CHECK_THROWS(snowman(12341));              // 5 character
    CHECK_THROWS(snowman(123412));             // 6 character
    CHECK_THROWS(snowman(1234123));            // 7 character
}

TEST_CASE("Bad snowman code - Invalid input: more then 8 characters")
{
    CHECK_THROWS(snowman(111111111));          // 9 character
    CHECK_THROWS(snowman(2222222222));         // 10 character
    CHECK_THROWS(snowman(33333333333));        // 11 character
    CHECK_THROWS(snowman(123412341234));       // 12 character
}

TEST_CASE("Bad snowman code - Invalid input: one or more characters different from 1,2,3,4")
{
    CHECK_THROWS(snowman(51111111));
    CHECK_THROWS(snowman(16111111));
    CHECK_THROWS(snowman(11711111));
    CHECK_THROWS(snowman(11181111));
    CHECK_THROWS(snowman(11119111));
    CHECK_THROWS(snowman(11111-11));
    CHECK_THROWS(snowman(111111*1));
    CHECK_THROWS(snowman(11111110));
}