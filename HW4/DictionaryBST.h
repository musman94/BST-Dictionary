//
//  DictionaryBST.h
//  HW4
//
//  Created by Muhammad Usman on 4/18/16.
//  Copyright © 2016 Muhammad Usman. All rights reserved.
//

#include <string>
#include <iostream>
using namespace std;
#ifndef DictionaryBST_h
#define DictionaryBST_h
struct BSTnode
{
    string word;
    int key;
    BSTnode *left;
    BSTnode *right;
    
};

//Binary search tree implementation for the dictionary
class DictionaryBST
{
public:
    //Constructor that constructs the dictionary from the input file
    DictionaryBST( string dictionaryFile );
    //Destructor
   // ~DictionaryBST();
    //Inserts the given word into the dictionary
    void insert( string word );
    //Searches the given word in the dictionary, and returns the number //of comparisons made and whether the word is found or not
    void search( string word, int& numComparisons, bool& found );
    //Searches all words in the query file in the dictionary, and //summarizes the results in the output file
    void search( string queryFile, string outputFile );
    void add(BSTnode *&rootptr, BSTnode *item);
    void display(BSTnode *curptr);
    void find(BSTnode* rootptr, string query_word,int key, int & numComaprisions, int& check);
    BSTnode* getroot();
    BSTnode* createNode(string word, int key);
    string getword(BSTnode *rootptr);
    
private:
    BSTnode *rootptr;
    int query_size;
    int max_comp;
    int total_comp;
    int numcomparisions;
    int check;
    double avg_comp;
    bool found;
    string outfile;
};

#endif /* DictionaryBST_h */
