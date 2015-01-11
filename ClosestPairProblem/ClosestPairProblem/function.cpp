//
//  function.cpp
//  ClosestPairProblem
//
//  Created by Lu Kuan-Yin on 1/11/15.
//  Copyright (c) 2015 NTU. All rights reserved.
//

#include "function.h"
#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

bool readFile(vector<Point> &pointSet)
{
    // the file is supposed to put in the same direction with .out
    ifstream infile("testData.txt", ifstream::in); // input file stream
    //    ofstream outfile("outData.txt"); // output file stream
    
    if (!infile) {
        cout<<"file doesn't open!!\n";
        return false;
    }
    
    while (!infile.eof()) {
        
    }
    //    //Test the input:
    //    cout<<"w: ";
    //    for (int i=0; i<values.size(); i++) {
    //        cout<<weights[i] <<" ";}
    
    infile.close();
    return true;
}

float twoPointDist(const Point &p1, const Point &p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y) );
}