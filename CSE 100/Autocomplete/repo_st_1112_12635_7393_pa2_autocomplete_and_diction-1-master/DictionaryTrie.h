/**
 *  CSE 100 PA3 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado
 */

/*
 * Name: Abena Bonsu
 * PID: A12367273
 * Date: 05/03/2017
 * Description: The class for a dictionary ADT
 * implemented as a Trie. Contains an inner Node
 * class, as well as a CompareNode class used
 * for comparing the frequencies of two nodes
 */
#ifndef DICTIONARY_TRIE_H
#define DICTIONARY_TRIE_H

#include <vector>
#include <string>
using namespace std;
class DictNode;

/**
 *  The class for a dictionary ADT, implemented as a trie
 *  You may implement this class as either a mulit-way trie
 *  or a ternary search trie, but you must use one or the other.
 *
 */
class DictionaryTrie
{

	/*
 	 * Inner node class used to store nodes within the 
 	 * Trie ADT
 	 */
	class DictNode {

		public:
			bool word;
			int freq;
			int maxFreq;
			// Array that will hold pointers of other DictNodes
			vector<DictNode*> childrenNodes; 
			string fullWord;
			DictNode(); 
	};

	/*
 	 * Inner class used to compare the freq of
 	 * nodes. Returns the larger of the two and
 	 * adds to the priority queue dependent on this
 	 */
	class CompareNode {
		public:
			bool operator() (DictNode*firstNode,
					 DictNode* secondNode) const {
				return firstNode->maxFreq < secondNode->maxFreq;
			}

	};

	public:

	/* Create a new Dictionary that uses a Trie back end */
	DictionaryTrie();

	int size();
	/* Insert a word with its frequency into the dictionary.
	 * Return true if the word was inserted, and false if it
	 * was not (i.e. it was already in the dictionary or it was
	 * invalid (empty string) */
	bool insert(std::string word, unsigned int freq);

	/* Return true if word is in the dictionary, and false otherwise */
	bool find(std::string word) const;

	/* Return up to num_completions of the most frequent completions
	 * of the prefix, such that the completions are words in the dictionary.
	 * These completions should be listed from most frequent to least.
	 * If there are fewer than num_completions legal completions, this
	 * function returns a vector with as many completions as possible.
	 * If no completions exist, then the function returns a vector of size 0.
	 * The prefix itself might be included in the returned words if the prefix
	 * is a word (and is among the num_completions most frequent completions
	 * of the prefix)
	 */
	std::vector<std::string>
		predictCompletions(std::string prefix, unsigned int num_completions);

	/* Destructor */
	~DictionaryTrie();

	//prints words inside Trie
	void print();

	// Keep track of total nodes in Trie
	int nodes = 0;

	private:
	// Add your own data members and methods here
	void printAll(DictNode*root);

	DictNode* root;// = new DictNode();
	void deleteAll(DictNode *root);
};

#endif // DICTIONARY_TRIE_H
