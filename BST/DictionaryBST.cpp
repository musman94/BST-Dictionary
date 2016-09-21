//
//  DictionaryBST.cpp
//  HW4
//
//  Created by Muhammad Usman on 4/18/16.
//  Copyright © 2016 Muhammad Usman. All rights reserved.
//

#include "DictionaryBST.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
DictionaryBST::DictionaryBST( string dictionaryFile )
{
    string first_word;
    string word;
    ifstream file(dictionaryFile, ios::in);
    if(!file)
        exit(EXIT_FAILURE);
    rootptr = NULL;
    while(file >> word)
        insert(word);
        
}

void DictionaryBST::insert( string word )
{
    char first =  word[0];
    int position = first;
    BSTnode *item = createNode(word,position);
    add(rootptr,item);
    
}


void DictionaryBST::search( string word, int& numComparisons, bool& found )
{

    char temp = word[0];
    int key = temp;
    check = 0;
    find(rootptr,word,key ,numcomparisions,check);
    if(max_comp < numcomparisions)
        max_comp = numcomparisions;
    total_comp = total_comp + numcomparisions;
    ofstream output;
    output.open(outfile,ios::app);
    output << word << " " << check << " " << numcomparisions << endl;
    numcomparisions = 0;
    check = 0;
    output.close();
}

void DictionaryBST::search( string queryFile, string outputFile )
{
    outfile = outputFile;
    query_size = 0;
    numcomparisions = 0;
    found = 0;
    max_comp = 0;
    total_comp = 0;
    avg_comp = 0;
    string query_word;
    ifstream query(queryFile,ios::in);
    if(!query)
        exit(EXIT_FAILURE);
    while(query >> query_word)
    {
        query_size++;
        search(query_word,numcomparisions,found);
    }
    
    avg_comp = (double)total_comp/(double)query_size;
    ofstream output2;
    output2.open(outfile,ios::app);
    output2 << "# of queries: " << query_size << endl;
    output2 << "Maximum # of comparisons: " << max_comp << endl;
    output2 << "Average # of comparisons: " << avg_comp << endl;
    output2.close();
}

void DictionaryBST::find(BSTnode* rootptr, string query_word, int key, int & numComaprisions, int &check)
{
    if(rootptr != NULL)
    {
        numcomparisions++;
        if(rootptr != NULL)
        {
            if(key == rootptr -> key)
            {
                if(query_word == rootptr -> word)
                    check = 1;
                else if(query_word != rootptr -> word)
                    find(rootptr -> right, query_word, key, numcomparisions,check);
                else
                    check = 0;
            }
            else if(key < rootptr -> key)
                find(rootptr -> left, query_word, key, numcomparisions,check);
            else
                find(rootptr -> right, query_word, key, numcomparisions,check);
        }
    }
}

void DictionaryBST::add(BSTnode *& rootptr, BSTnode* item)
{
    if(rootptr == NULL)
        rootptr = item;
    else if(item -> key < rootptr -> key)
        add(rootptr -> left, item);
    else
        add(rootptr -> right, item);
}

void DictionaryBST::display(BSTnode *rootptr)
{
    if(rootptr != NULL)
    {
        display(rootptr -> left);
        cout << rootptr -> word << endl;
        display(rootptr -> right);
    }
}

BSTnode* DictionaryBST::getroot()
{
    return rootptr;
}

string DictionaryBST::getword(BSTnode *rootptr)
{
    return rootptr -> word;
    
}



BSTnode* DictionaryBST::createNode(string word, int key)
{
    BSTnode *node = new BSTnode();
    node -> word = word;
    node -> key = key;
    node -> left = NULL;
    node -> right = NULL;
    return node;
    

}





