#include <catch2/catch.hpp>
#include "includes/test-000.hpp"

char* convertArray()
{
    std::string data[1];
    std::string currentStr;
    char* charArray;
    
    data[0] = "test";
    currentStr = data[0];
    charArray = &currentStr[0];

    return charArray;
}

TEST_CASE( "string array converts to char", "[convertArray]" ) 
{
    char charArray[4] = {'t', 'e', 's', 't'};
    REQUIRE( strcmp(convertArray(), "test") == 0 );
}
