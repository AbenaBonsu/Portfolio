/*
 * Name: Abena Bonsu
 * PID: A12367273
 * Date: 05/03/2017
 * Description: This file is used to test the implementations
 * of the 3 ADT structures that we created. It tests 
 * DictionaryBST, DictionaryHashtable and DictionaryTrie.
 */
#include<iostream>
#include<vector>
#include <fstream>
#include<string>
#include<algorithm>
#include<set>
#include<cstdlib>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#define LETTERS 26
using namespace std;

/*
 * Used for testing the implementation of the 3
 * Dictionary ADT structures.
 */
int main(int argc, char** argv)
{

	//Initialize words
	vector<std::string> words;
	vector<string>::iterator wit;
	vector<string>::iterator wen;
	//initialize nonwords
	set<string> nope;
	set<string>::iterator nit;
	set<string>::iterator nen;

	//Initialize data structures
	DictionaryBST d_bst;
	DictionaryHashtable d_ht;
	DictionaryTrie dt;
	int t_bst, t_ht, tt;

	// words.push_back("harry");
	// words.push_back("sriram");
	// words.push_back("cse");
	words.push_back("crucio");
	words.push_back("cse");
	words.push_back("crux");
	// words.push_back("autocomplete");


	cout << "Inserting into Dictionaries..." << endl;

	wit = words.begin();
	wen = words.end();
	for(; wit != wen; ++wit)
	{
		cout << "Inserting: \"" << *wit << "\"... ";
		t_bst = d_bst.insert(*wit);
		t_ht = d_ht.insert(*wit);
		tt = dt.insert(*wit, 1);
		//cout << t_bst << " " << t_ht << " "<< tt << "... ";
		if(!t_bst)
		{
			cout << "failed for DictionaryBST... ";
		}
		if(!t_ht)
		{
			cout << "failed for DictionaryHashset... ";
		}
		if(!tt)
		{
			cout << "failed for DictionaryTrie... ";
		}
		if(t_bst && t_ht && tt)
		{
			cout << "PASSED! :D ";
		}
		cout << endl;
	}
	//dt.print();
	cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

	wit = words.begin();
	wen = words.end();
	for(; wit != wen; ++wit)
	{
		cout << "Inserting: \"" << *wit << "\"... ";
		t_bst = d_bst.insert(*wit);
		t_ht = d_ht.insert(*wit);
		tt = dt.insert(*wit, 0);
		if(t_bst)
		{
			cout << "failed for DictionaryBST... ";
		}
		if(t_ht)
		{
			cout << "failed for DictionaryHashset... ";
		}
		if(tt)
		{
			cout << "failed for DictionaryTrie... ";
		}
		if(!t_bst && !t_ht && !tt)
		{
			cout << "PASSED! :D ";
		}
		cout << endl;
	}

	//dt.print();
	cout << endl;


	/*You are supposed to add more test cases in this file */
	DictionaryTrie newDict;
	newDict.insert("basketball", 1);
	newDict.insert("asterisk", 1);
	newDict.insert("application", 10);
	newDict.insert("a", 1);
	newDict.insert("app", 1);
	newDict.insert("gugglebee", 1);
	newDict.insert("waldos", 1);
	newDict.insert("are you not entertained", 1);
	newDict.insert("never gonna give you up", 1);


	cout << "reinserting" << endl;

	newDict.insert("basketball", 2);
	newDict.insert("asterisk", 1);
	newDict.insert("application", 9);
	newDict.insert("a", 2);
	newDict.insert("app", 2);
	newDict.insert("gugglebee", 2);
	newDict.insert("waldos", 2);
	newDict.insert("are you not entertained", 2);
	newDict.insert("never gonna give you up", 2);
	// bool flag = newDict.insert("A", 20);
	//cout << "flag is " << flag << endl;
	//  newDict.print(); 
	//newDict.printFreq();
	//  char c = (char)123;  
	//  cout << "char c is " << c << endl;

	DictionaryTrie hello;
	//std::ifstream ifs ("dictionary2.txt", std::ifstream::in);
	//Utils::load_dict(hello, ifs);
	hello.insert("step", 510);
	hello.insert("step up", 500);
	hello.insert("steward", 200);
	hello.insert("steer", 100);
	hello.insert("stealth", 150);
	hello.insert("stroke", 1000);
	hello.insert("stealers", 5000);
	hello.insert("stelly", 5000);
	hello.insert("ste", 10000);
	int size1 = hello.size();
	cout << "size of tree is " << size1 << endl;
	vector<std::string> hi;
	hi  = hello.predictCompletions("ste", 4);
	int size = hi.size();

	cout << "ABOUT TO PRINT OUT WORDS" << endl;
	for (int i = 0; i <(signed) size; i++) {
		cout << hi[i] << endl;
	}
	//ifs.close();

	DictionaryTrie bye;

	bye.insert("a", 10788425);
	bye.insert("a aaa", 275);
	bye.insert("a aa", 3100);
	bye.insert("a all", 29);
	bye.insert("a an", 45);
	bye.insert("a and", 192);
	bye.insert("a another", 39);
	bye.insert("a at", 25);
	bye.insert("a b", 82);
	bye.insert("a ba", 66);
	vector <std::string> mmbye = bye.predictCompletions("a a", 3);
	for (int i = 0; i < (signed) mmbye.size(); i++) {
		cout << mmbye[i] << endl;
	}

	DictionaryTrie j;
	vector<std::string> okie = j.predictCompletions("", 10);
	j.insert("a", 1000);
	vector<std::string> oki = j.predictCompletions("A", 10);

	return 0;
}

