/*
 * MyRestHandler.cpp
 *
 *  Created on: 26 jun. 2019
 *      Author: rvandenbroeck
 */

#include "MainMachine.h"

#include "rapidjson\writer.h"
#include <cstdio>

using namespace rapidjson;
using namespace std;

//SubMachine::SubMachine(rapidjson::Document::AllocatorType& aAllocator):
//	mCounter(0),
//	mItems(),
//	mJsonValue(kObjectType)

SubMachine::SubMachine():
	mCounter(0),
	mItems()
{
}

SubMachine::~SubMachine()
{
}

void SubMachine::Initialise(JsonObject& aObject)
{
	Value& value = aObject.GetObject();
	rapidjson::Document::AllocatorType& allocator = aObject.GetAllocator();

	value.AddMember("counter",mCounter,allocator);
	value.AddMember("item1",".1.",allocator);
	value.AddMember("item2",".2.",allocator);
	value.AddMember("item3",".3.",allocator);
}

void SubMachine::ReadJson(rapidjson::Value& aValue)
{
	if (aValue.IsObject())
	{
		if (aValue.HasMember("item1") && aValue["item1"].IsString())	mItems.push_back(aValue["item1"].GetString());
		if (aValue.HasMember("item2") && aValue["item2"].IsString())	mItems.push_back(aValue["item2"].GetString());
		if (aValue.HasMember("item3") && aValue["item3"].IsString())	mItems.push_back(aValue["item3"].GetString());
	}
}

void SubMachine::GetRest(JsonObject& aObject)
{
	mCounter++;
	Value& value = aObject.GetObject();
	rapidjson::Document::AllocatorType& allocator = aObject.GetAllocator();

 	if (value.HasMember("counter"))
 		value["counter"] = mCounter;
	if (value.HasMember("item1"))
		value["item1"].SetString(("Was " + mItems[2]).c_str(), allocator);
	if (value.HasMember("item2"))
		value["item2"].SetString(("Was " + mItems[0]).c_str(), allocator);
	if (value.HasMember("item3"))
		value["item3"].SetString(("Was " + mItems[1]).c_str(), allocator);
}
