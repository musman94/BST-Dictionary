//
//  main.cpp
//  HW4
//
//  Created by Muhammad Usman on 4/18/16.
//  Copyright © 2016 Muhammad Usman. All rights reserved.
//

#include <iostream>
#include "DictionaryBST.h"
#include <string>
using namespace std;

int main()
{
    DictionaryBST *dic = new DictionaryBST("/Users/Usman/Desktop/CS/CS202/hw4/HW4/HW4/test.txt");
    dic -> search("/Users/Usman/Desktop/CS/CS202/hw4/HW4/HW4/query.txt","/Users/Usman/Desktop/CS/CS202/hw4/HW4/HW4/outputBST.txt");
        return 0;
    
}
