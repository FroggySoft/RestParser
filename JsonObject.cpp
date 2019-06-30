/*
 * JsonObject.cpp
 *
 *  Created on: 28 Jun 2019
 *      Author: rob
 */

#include "JsonObject.h"

JsonObject::JsonObject(rapidjson::Value& aObject, rapidjson::Document::AllocatorType& aAllocator):
	mObject(aObject),
	mAllocator(aAllocator)
{
}

JsonObject::~JsonObject()
{
}

rapidjson::Value& JsonObject::GetObject() const
{
	return mObject;
}

rapidjson::Document::AllocatorType& JsonObject::GetAllocator() const
{
	return mAllocator;
}
