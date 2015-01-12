//
//  main.cpp
//  ClosestPairProblem
//
//  Created by Lu Kuan-Yin on 1/11/15.
//  Copyright (c) 2015 NTU. All rights reserved.
//

#include <iostream>
#include <vector>
#include "function.h"


using namespace std;

int main(int argc, const char * argv[]) {
    vector<Point> pointSet;
    readFile(pointSet);
    
    printPointSet(pointSet);
    
    return 0;
}
