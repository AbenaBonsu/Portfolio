/*
 * Name: Abena Bonsu
 * PID: A12367273
 * Date: 05/03/17
 * Description: This is a class for testing the average
 * amount of time it takes a DictionaryBST, DictionaryHashtable
 * and a DictionaryTrie to find objects that don't exist
 * within its structure. It computes the average time
 * based on the number of words put into the tree
 * and computes this.
 */
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#include "DictionaryTrie.h"
#include "util.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#define ITERATIONS 20
using std::string;
using namespace std;
/*
 * Main function used for testing the implementation
 * of benchdict
 */
int main(int argc, char* argv[]) {

	// If number of arguments is incorrect
	if (argc != 5) {
		cout << "Invalid number of arguments. Terminating." << endl;
		return -1;
	}

	// Initialize variables to hold the different arguments passed in
	int min_size = std::stoi(argv[1]);
	int step_size = std::stoi(argv[2]);
	int num_iterations = std::stoi(argv[3]);
	std::string dictfile = argv[4];

	// Indicate which class you are benchmarking
	cout << "Currently benchmarking DictionaryBST. " <<
			"Get ready for some BST fun." << endl;
	
	long long avgTimeTaken = 0;
	for (int i = 0; i < num_iterations; i++) {
		// create new BST and stream
		DictionaryBST* bstFun = new DictionaryBST();
		ifstream loadIn;
		
		// Load min_size + i*step_size words from the dictionary file
		loadIn.open(dictfile, std::ios::binary);
		Utils::load_dict(*bstFun, loadIn, min_size + i*step_size);

		//Read the next 100 words from the dictionary file
		vector<std::string> next100;
		Utils::load_vector(next100, loadIn, 100);
	
		// Repeat the find process many times   
		for (int i = 0; i < ITERATIONS; i++) {	
			// Time the amount of time taken to look for words
			Timer time;
			time.begin_timer();
			//for (int i = 0; i < (int) next100.size(); i++) { 
			for (auto&word : next100)
				bstFun->find(word);	
		//	}
			// take the average time of all the runs
			avgTimeTaken += time.end_timer()/ITERATIONS;
		}

		// Print the stats and delete structure
		cout << "Dictsize: " << min_size + i*step_size <<
			 " | Average Time: " << avgTimeTaken << endl;

		delete bstFun;
	}	
	
	//Indicate which class you are benchmarking
	cout << endl << "Currently benchmarking DictionaryHashTable. " <<
			"Get ready for some hash browns." << endl;
        
	// reset the avgerage time taken
        avgTimeTaken = 0;

        for (int i = 0; i < num_iterations; i++) {
		// Create new Hastable and stream
                DictionaryHashtable* hashFun = new DictionaryHashtable();
                ifstream loadIn;
                
		// Load min_size + i*step_size words from the dictionary file
                loadIn.open(dictfile, std::ios::binary);
                Utils::load_dict(*hashFun, loadIn, min_size + i*step_size);
                
		//Read the next 100 words from the dictionary file
                vector<std::string> next100;
                Utils::load_vector(next100, loadIn, 100);

		// Repeat the find process many times   
                for (int i = 0; i < ITERATIONS; i++) {
			// Time the amount of time taken to look for words
                        Timer time;
                        time.begin_timer();
                        for (int i = 0; i < (int) next100.size(); i++) {
                                hashFun->find(next100[i]);
                        }
			// take the average time of all the runs
			avgTimeTaken += time.end_timer()/ITERATIONS;
                }

		// Print the stats and delete structure
		cout << "Dictsize: " << min_size + i*step_size <<
                         " | Average Time: " << avgTimeTaken << endl;
		delete hashFun;
        }

	// Indicate which class you are benchmarking	
	cout << endl << "Currently benchmarking DictionaryTrie. " <<
			"Get ready to be a trie hard." << endl;

	// reset the average time taken
        avgTimeTaken = 0;

        for (int i = 0; i < num_iterations; i++) {
		// Create new Trie and stream
                DictionaryTrie* trieFun = new DictionaryTrie();
                ifstream loadIn;

		// Load min_size + i*step_size words from the dictionary file
                loadIn.open(dictfile, std::ios::binary);
                Utils::load_dict(*trieFun, loadIn, min_size + i*step_size);

		//Read the next 100 words from the dictionary file
                vector<std::string> next100;
                Utils::load_vector(next100, loadIn, 100);

		// Repeat the find process many times   
                for (int i = 0; i < ITERATIONS; i++) {
			// Time the amount of time taken to look for words
                        Timer time;
                        time.begin_timer();
                        for (int i = 0; i < (int) next100.size(); i++) {
                                trieFun->find(next100[i]);
                        }
			// take the average time of all the runs
			avgTimeTaken += time.end_timer()/ITERATIONS;
                }

		// Print the stats and delete structure
		cout << "Dictsize: " << min_size + i*step_size <<
                         " | Average Time: " << avgTimeTaken << endl;
		delete trieFun;
        }
}
