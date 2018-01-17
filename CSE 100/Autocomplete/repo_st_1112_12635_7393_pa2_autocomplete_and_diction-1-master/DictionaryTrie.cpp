/*
 * Name: Abena Bonsu
 * PID: A12367273
 * Date: 05/03/2017
 * Description: This class contains the full
 * implementation of the DictionartyTrie ADT.
 * A Trie ADT contains methods such as insert,
 * find, and predictCompletions. These methods
 * are used to set up autocomplete. 
 */
#include "util.h"
#include "DictionaryTrie.h"
#include "limits.h"
#include <queue>
#include <vector>
#include <algorithm>

/* Create a new DictNode and initialize variables */
DictionaryTrie::DictNode::DictNode() {
	freq = 0;
	maxFreq = 0;
	word = false;
	childrenNodes = vector<DictNode*>(27,0);
}

/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie(){
	root = new DictNode();
	nodes = 0;
}

/*
 * Used to print out all the words contained within
 * the Trie Dictionary ADT
 */
void DictionaryTrie::print() {
	printAll(root);
}

/*
 * Helper method for print() which recursively
 * travels down the Trie and prints all the letters
 * occuring along the way
 */
void DictionaryTrie::printAll(DictNode*root){
	if (!root)
		return;
	for (int i = 0; i < 27; i++) {
		if (root->childrenNodes[i]) {
			char c =  i + 97;
			cout << c;
			printAll(root->childrenNodes[i]);
		}
	}
	cout << endl;
}

/*
 * Returns the size of the Trie tree (how many
 * nodes exist inside)
 */
int DictionaryTrie::size() {
	return nodes;
}

/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */
bool DictionaryTrie::insert(std::string word, unsigned int freq) {
	bool flag = false;
	if (word.length() == 0) 
		return false;
	DictNode *curr = root;        

	if(find(word)) {	
		flag = true;
	}

	// for each character c in word
	for (int i = 0; i < (signed) word.length(); i++) {
		char letter = word[i];
		// check to make sure c is an alphabet or space
		if ((letter < 'a' || letter > 'z'))  
			if (letter != ' ')
				return false;

		//space  needs to be set in the last space of the array
		if ((int)letter == 32)
			letter = (char)123;

		// if curr does not have an outgoing edge labeled by c:
		if (curr->childrenNodes.at(((int) letter)-97) == NULL) {
			// create a new child of curr with the edge labeled by c
			curr->childrenNodes.at(((int) letter)-97) = new DictNode();
		} 
		// curr = child of curr along edge labeled by c
		curr = curr->childrenNodes.at(((char) letter)-97);
	}

	if (flag == true) {	
		curr->maxFreq = std::max((int)freq, curr->maxFreq);
	}

	// if curr is a word-node:
	if (curr->word == true) {
		curr->freq = curr->maxFreq;
		return false;
	} else {
		// if curr is not a word-node, label curr as a word node:
		curr->word = true;
		curr->freq = freq;
		curr->maxFreq = std::max(curr->maxFreq, (int)freq);
		curr->fullWord = word;
		nodes++;
	
	/*	curr = root;
		for (int i = 0; i < (signed)word.length(); i++) {
			//cout << "inside insert fot " << endl;
			char letter = word[i];

			if ((int)letter == 32)
                        	letter = (char)123;

			curr->maxFreq = std::max(curr->maxFreq,(int) freq);
			curr = curr->childrenNodes.at(((char) letter)-97);
		} */

		return true;
	} 
}

/* 
 * Method that checks to see if a particular word exists
 * within the Trie ADT. This method returns true if word
 * is in the dictionary, and false otherwise
 */
bool DictionaryTrie::find(std::string word) const{
	DictNode*curr = root;

	// for each character c in word
	for (int i = 0; i < (signed) word.length(); i++) {
		char letter = word[i];
		if (letter < 'a' || letter > 'z')
			if  (letter != ' ')
				return false;
		//space  needs to be set in the last space of the array
		if ((int)letter == 32)
			letter = (char)123;

		// if curr does not have an outgoing edge labeled by c:
		if (curr->childrenNodes.at(((int) letter)-97) == NULL) {
			return false;
		} else {
			// else curr = child of curr along edge labeled by c
			curr = curr->childrenNodes.at(((int) letter)-97);			
		}
	}
	// if curr is a word-node return true, else false	
	return (curr->word);
}


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
std::vector<std::string> DictionaryTrie::predictCompletions(std::string prefix, unsigned int num_completions)
{
	std::vector<std::string> words;
	
	//check to see that there is a tree
	if (!root)
		return words;
	
	//check if empty string is passed in
	if(prefix.length() == 0) {
		cout<< "Invalid Input. Please retry with correct input"<<endl;
		return words;
	}

	//check if num_completions is impossible number
	if(num_completions <= 0) {
		cout<<"Invalid Input. Please retry with correct input"<<endl;
		return words;
	}

	//Traverse down the Trie to find the subtree where prefix ends
	DictNode*curr = root;
	//for each character c in prefix
	for (int i = 0; i < (signed) prefix.length(); i++) {
                char letter = prefix[i];	
		//check to make sure c is an alphabet or space
		if ((letter < 'a' || letter > 'z')) {
                        if (letter != ' ') {
				cout << "Invalid Input. Please retry" <<
					"  with correct input" << endl;
                                return words;
			}
		}
		//space needs to be set in the last space of the array
		if ((int)letter == 32)
                        letter = (char)123;

		//if curr does not have an outgoing edge labeled by c:
		if (curr->childrenNodes.at(((int) letter)-97) == NULL) {
			cout << "Invalid Input. " <<
				"Please retry with correct input" << endl;
			return words;
		} 
		curr = curr->childrenNodes.at(((char) letter)-97);
	}

	//Create a node that points to the inner root - where prefix ends
	DictNode* innerRoot = curr;

	//Create the queues that will be used in finding all the end words
	queue<DictNode*> search;
	queue<DictNode*> narrowSearch;
	
	//Push all the nodes that exist into both queus			
	search.push(innerRoot);
	narrowSearch.push(innerRoot);
	while(!search.empty()) {
		innerRoot = search.front();
		search.pop();
		
		//check to see if any of the children of the current node exists
		for (int i = 0; i < (int)innerRoot->childrenNodes.size(); i++) {
			if (innerRoot->childrenNodes[i]) {
				search.push(innerRoot->childrenNodes[i]);
				narrowSearch.push(innerRoot->childrenNodes[i]);
			}
		}
	}

	//Create priority queue to store all the nodes in increasing frequency
        priority_queue<DictNode*,std::vector<DictNode*>,CompareNode>breadthFirst;
	DictNode* tempNode;

	// Push all the nodes that are actually a word into the priority queue
	while (!narrowSearch.empty()) {
		DictNode*foundWord = narrowSearch.front();
		narrowSearch.pop();
		if (foundWord->word){
			tempNode = foundWord;
			breadthFirst.push(tempNode);
		}
	}

	// Push all the words into the word vector
	int i = 0;
	while (!breadthFirst.empty()) {
		DictNode*finalWords = breadthFirst.top();
		breadthFirst.pop();
		if (i < (int)num_completions) {
			words.push_back(finalWords->fullWord);
			i++;
		}
	}
	
	return words;
}

/*
 * Recursive method used to help deconstructor
 * recursively delete all the nodes in the Trie ADT
 */
void DictionaryTrie::deleteAll(DictNode *root) {
        if (!root)
                return;
        for (int i = 0; i <(signed) root->childrenNodes.size(); i++) {
                deleteAll( root->childrenNodes[i]);
        }
        delete root;
}

/* Destructor */
DictionaryTrie::~DictionaryTrie(){
	deleteAll(root);
}

