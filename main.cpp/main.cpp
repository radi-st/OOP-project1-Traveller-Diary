#include "user.h"
#include "string.h"
#include "trip_collection.h"
#include <iostream>
#include <fstream>

int main()
{
    std::ifstream in{ "izhod.txt"};
    User u;
    in >> u;
   std::cout<< u;

}
