//
//  function.h
//  ClosestPairProblem
//
//  Created by Lu Kuan-Yin on 1/11/15.
//  Copyright (c) 2015 NTU. All rights reserved.
//

#ifndef __ClosestPairProblem__function__
#define __ClosestPairProblem__function__

#include <stdio.h>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};
void printPointSet(const vector<Point> &pointSet);
bool readFile(vector<Point> &pointSet);
float closestPair(vector<Point> &P, int n);

#endif /* defined(__ClosestPairProblem__function__) */
