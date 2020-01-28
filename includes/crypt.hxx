#pragma once

#include <iostream>
#include <fstream>

using std::cin, std::cout, std::endl;
using std::ifstream, std::ofstream, std::fstream;

void crypt(ifstream& source, ifstream& key, ofstream& dest);