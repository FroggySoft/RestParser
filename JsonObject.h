/*
 * JsonObject.h
 *
 *  Created on: 28 Jun 2019
 *      Author: rob
 */

#pragma once
#include "rapidjson\document.h"

class JsonObject {
public:
	JsonObject(rapidjson::Value& aObject, rapidjson::Document::AllocatorType& aAllocator);
	virtual ~JsonObject();

	rapidjson::Value& GetObject() const;
	rapidjson::Document::AllocatorType& GetAllocator() const;

private:
	rapidjson::Value& mObject;
	rapidjson::Document::AllocatorType& mAllocator;
};
