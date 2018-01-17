/*
 * Name: Abena Bonsu
 * PID: A1236273
 * Date: 05/03/2017
 * Description: This is a class for a BST 
 * ADT. This BST inserts nodes that are of
 * larger value to the right subtree, and 
 * nodes that are of smaller value to the
 * left subtree
 */
#include "util.h"
#include "DictionaryBST.h"
#include <set>
#include <iostream>
#include <string>
using std::set;
using std::string;

set<string> dict;

/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){
	set<string> dict;
}

/* Insert a word into the dictionary. */
bool DictionaryBST::insert(std::string word) {
        auto add = dict.insert(word);	
	if (add.second)
		return true;
	return false;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const {
	bool found = (dict.find(word) != dict.end());
	return found;
}

/* Destructor */
DictionaryBST::~DictionaryBST(){
	dict.clear();
}
