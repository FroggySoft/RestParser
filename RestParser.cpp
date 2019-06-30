//============================================================================
// Name        : RestParser.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "MainMachine.h"
using namespace std;

const std::string cTestRest = "{ \"hello\" : \"world\", \"t\" : true , \"f\" : false, \"n\": null, \"i\":123, \"pi\": 3.1416, \"a\":[1, 2, 3, 4] , "//
		                      "\"sub\": {\"item1\":\"eerste\" , \"item2\":\"tweede\", \"item3\":\"derde\" }}";

int main()
{
	cout << "Test RestParser" << endl;

	MainMachine machine;
	machine.Initialise(cTestRest);

	cout << "Result:" << endl << machine.GetRest() << endl;
	cout << "Result:" << endl << machine.GetRest() << endl;
	cout << "Result:" << endl << machine.GetRest() << endl;
	cout << "Result:" << endl << machine.GetRest() << endl;
	cout << "Result:" << endl << machine.GetRest() << endl;
	return 0;
}
