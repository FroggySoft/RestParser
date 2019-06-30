/*
 * MyRestHandler.h
 *
 *  Created on: 26 jun. 2019
 *      Author: rvandenbroeck
 */

#pragma once

#include <string>
#include <vector>

#include "rapidjson\document.h"
#include "JsonObject.h"

class SubMachine
{
public:
	SubMachine();
	virtual ~SubMachine();

	virtual void Initialise(JsonObject& aObject);
	virtual void ReadJson(rapidjson::Value& aValue);
	virtual void GetRest(JsonObject& aObject);

private:
	int mCounter;
	std::vector<std::string> mItems;
};
