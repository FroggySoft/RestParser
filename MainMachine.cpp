/*
 * MyRestHandler.cpp
 *
 *  Created on: 26 jun. 2019
 *      Author: rvandenbroeck
 */

#include "MainMachine.h"
#include "JsonObject.h"

#include "rapidjson\writer.h"
#include <cstdio>

using namespace rapidjson;
using namespace std;

MainMachine::MainMachine():
	 mString(""),
	 mBool(false),
	 mInt(0),
	 mArray(),
	 mSubStrings(),
	 mDocument(),
	 mSubMachine()
{
	Document::AllocatorType& allocator = mDocument.GetAllocator();

	mDocument.SetObject();
	mDocument.AddMember("hello","",allocator);
	mDocument.AddMember("t",false,allocator);
	mDocument.AddMember("i",0,allocator);

	rapidjson::Value array(kArrayType);
	mDocument.AddMember("a",array,allocator);

	rapidjson::Value subValue(kObjectType);
	JsonObject sub(subValue,allocator);
	mSubMachine.Initialise(sub);

	mDocument.AddMember("sub",subValue,allocator);
}

MainMachine::~MainMachine()
{
}

void MainMachine::Initialise(std::string aRest)
{
	Document d;
	d.Parse(aRest.c_str());
	if (d.HasMember("hello") && d["hello"].IsString())
		mString = d["hello"].GetString();

	if (d.HasMember("t") && d["t"].IsBool()) mBool = d["t"].GetBool();
	if (d.HasMember("i") && d["i"].IsInt())  mInt = d["i"].GetInt();

	if (d.HasMember("a") && d["a"].IsArray())
	{
		const Value& a = d["a"];
		for (SizeType i=0; i<a.Size(); i++)
		{
			mArray.push_back(a[i].GetInt());
		}
	}

	if (d.HasMember("sub"))
	{
		mSubMachine.ReadJson(d["sub"]);
	}
}

std::string MainMachine::GetRest()
{
	Document::AllocatorType& allocator = mDocument.GetAllocator();

	// TODO? check if items exist (created in constructor)
	mDocument["hello"].SetString( mString.c_str(), allocator );
	mDocument["t"] = mBool;
	mDocument["i"] = mInt;

	Value& array = mDocument["a"];
	array.Clear();
	for(auto x: mArray)
	{
		array.PushBack(x,allocator);
	}

	JsonObject sub(mDocument["sub"],allocator);
	mSubMachine.GetRest(sub);

    StringBuffer sb;
    Writer<StringBuffer> writer(sb);
    mDocument.Accept(writer);    // Accept() traverses the DOM and generates Handler events.
    return sb.GetString();
}
