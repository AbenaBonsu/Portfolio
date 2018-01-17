/**
 *  CSE 100 PA3 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado
 */

/*
 * Name: Abena Bonsu
 * PID: A12367273
 * Date: 05/03/2017
 * Description: This is a class for a Dictionary
 * that uses a Hastable to store its words. It
 * has methods such as insert and find.
 */
#ifndef DICTIONARY_HASHTABLE_H
#define DICTIONARY_HASHTABLE_H

#include <string>

/**
 *  The class for a dictionary ADT, implemented as a Hashtable
 * When you implement this class, you MUST use a Hashtable
 * in its implementation.  The C++ unordered_set implements 
 * a Hashtable, so we strongly suggest you use that to store 
 * the dictionary.
 */
class DictionaryHashtable
{
public:

  /* Create a new Dictionary that uses a Hashset back end */
  DictionaryHashtable();

  /* Insert a word into the dictionary. */
  bool insert(std::string word);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* Destructor */
  ~DictionaryHashtable();

private:
  // Add your own data members and methods here
};

#endif // DICTIONARY_HASHTABLE_H
