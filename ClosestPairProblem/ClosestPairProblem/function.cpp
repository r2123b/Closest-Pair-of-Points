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
#include <float.h>

using namespace std;

void printPointSet(const vector<Point> &pointSet) {
    printf("The number of PointSet is %d.\n", (int)pointSet.size());
    for (int i=0; i<pointSet.size(); i++) {
        printf("(%2d,%2d) \n", pointSet[i].x, pointSet[i].y);
    }
}

bool readFile(vector<Point> &pointSet)
{
    // the file is supposed to put in the same direction with .out
    ifstream infile("testData2.txt", ifstream::in); // input file stream
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


int compareX(const void* a, const void* b)
{
    Point *p1 = (Point *)a,  *p2 = (Point *)b;
    return (p1->x - p2->x);
}

int compareY(const void* a, const void* b)
{
    Point *p1 = (Point *)a,   *p2 = (Point *)b;
    return (p1->y - p2->y);
}

// A utility function to find the distance between two points
float dist(const Point &p1, const Point &p2)
{
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +
                 (p1.y - p2.y)*(p1.y - p2.y) );
}

// A Brute Force method to return the smallest distance between two points
// in P[] of size n
float bruteForce( const vector<Point> &P, int n )
{
    float min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            if (dist(P[i], P[j]) < min)
                min = dist(P[i], P[j]);
    return min;
}

// A utility function to find minimum of two float values
float min(float x, float y)
{
    return (x < y)? x : y;
}


// A utility function to find the distance beween the closest points of
// strip of given size. All points in strip[] are sorted accordint to
// y coordinate. They all have an upper bound on minimum distance as d.
// Note that this method seems to be a O(n^2) method, but it's a O(n)
// method as the inner loop runs at most 6 times
float stripClosest(vector<Point> &strip, int size, float d)
{
    float min = d;  // Initialize the minimum distance as d
    
    qsort(&strip[0], size, sizeof(Point), compareY);
    
    // Pick all points one by one and try the next points till the difference
    // between y coordinates is smaller than d.
    // This is a proven fact that this loop runs at most 6 times
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
            if (dist(strip[i],strip[j]) < min)
                min = dist(strip[i], strip[j]);
    
    return min;
}

// A recursive function to find the smallest distance. The array P contains
// all points sorted according to x coordinate
float closestUtil(vector<Point> &P, int n)
{
    // If there are 2 or 3 points, then use brute force
    if (n <= 3)
        return bruteForce(P, n);
    
    // Find the middle point
    int mid = n/2;
    Point midPoint = P[mid];
    
    // I want to do: P_prime = P[mid ~ end]
    vector<Point>::iterator it = P.begin() + mid;
    vector<Point> P_prime;
    P_prime.assign(it, P.end());
    
    
    float dl = closestUtil(P, mid);
    float dr = closestUtil(P_prime, n-mid);
    
    // Find the smaller of two distances
    float d = min(dl, dr);
    
    // Build an array strip[] that contains points close (closer than d)
    // to the line passing through the middle point
    vector<Point> strip;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d) {
            strip.push_back(P[i]);
        }
    
    // Find the closest points in strip.  Return the minimum of d and closest
    // distance is strip[]
    return min( d, stripClosest(strip, (int)strip.size(), d) );
}


float closestPair(vector<Point> &P, int n)
{
    // qsort's fisrt parameter has to put the memory location
    qsort(&P[0], P.size(), sizeof(Point), compareX);

    return closestUtil(P, n);
}
