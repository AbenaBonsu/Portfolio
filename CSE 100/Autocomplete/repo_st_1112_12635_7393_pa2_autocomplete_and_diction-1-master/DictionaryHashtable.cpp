/*
 * Name: Abena Bonsu
 * PID: A12362737
 * Date: 05/03/2017
 * Description: This is a class for a 
 * Dictionary that uses a Hashtable
 * as its backing. It contains methods
 * such as insert and find.
 */
#include "util.h"
#include "DictionaryHashtable.h"
#include <iostream>
#include <string>
#include <unordered_set>
using std::string;
using std::unordered_set;

unordered_set<string>hDict;

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){
	unordered_set<string>hDict;
}

/* Insert a word into the hDictionary. */
bool DictionaryHashtable::insert(std::string word){
	auto added = hDict.insert(word);	
	if (added.second) 
		return true;
	return false;
}

/* Return true if word is in the hDictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const {
	bool found = (hDict.find(word) != hDict.end());
	return found;
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable(){
	hDict.clear();
}
