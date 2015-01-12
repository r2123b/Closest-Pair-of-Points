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

void printPointSet(const vector<Point> &pointSet) {
    printf("Point number is %d.\n", (int)pointSet.size());
    for (int i=0; i<pointSet.size(); i++) {
        printf("(%2d,%2d) \n", pointSet[i].x, pointSet[i].y);
    }
}

bool readFile(vector<Point> &pointSet) {
    // the file is supposed to put in the same direction with .out
    ifstream infile("testData.txt", ifstream::in); // input file stream
    //    ofstream outfile("outData.txt"); // output file stream
    
    if (!infile) {
        cout<<"file doesn't open!!\n";
        return false;
    }
    
    string line;
    getline(infile, line);
    
    char charLine[line.size()];
    strcpy(charLine, line.c_str());
    
    char *token = strtok(charLine, "(, )"); //first token has to put the string name, charLine
    Point tempPoint;
    for (int i=0; token != NULL; i++) {
        
        if (i%2 == 0)
            tempPoint.x = atoi(token);
        else {
            tempPoint.y = atoi(token);
            pointSet.push_back(tempPoint);
        }
        token = strtok(NULL, "(, )");
    }
    
//    printPointSet(pointSet);
    
    infile.close();
    return true;
}

float twoPointDist(const Point &p1, const Point &p2) {
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y) );
}