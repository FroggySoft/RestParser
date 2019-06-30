/*
 * MyRestHandler.h
 *
 *  Created on: 26 jun. 2019
 *      Author: rvandenbroeck
 */

#pragma once

#include <string>
#include <vector>

#include "SubMachine.h"
#include "rapidjson\document.h"

class MainMachine
{
public:
	MainMachine();
	virtual ~MainMachine();

	virtual void Initialise(std::string aRest);
	virtual std::string GetRest();

private:
	std::string mString;
	bool mBool;
	int  mInt;
	std::vector<int> mArray;
	std::vector<std::string> mSubStrings;

	rapidjson::Document mDocument;

	SubMachine mSubMachine;
};
