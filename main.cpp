//
//  main.cpp
//  Gallegos_Michael_Lab3
//
//  Created by Michael Gallegos on 9/5/18.
//  Copyright © 2018 Michael Gallegos. All rights reserved.
//
/*
 
 Create a class Point which has a template parameter of the type of internal data, T,
 and a template parameter for the dimension of the vector, n.
 
 Store a statically allocated, internal array of type T with dimension n.
 
 Create a template function which computes the Euclidean distance between 2 points.
 
 Instantiate two Point<double, 3> and compute their distance.
 
 Instantiate two Point<int, 2> and compute their distance.

*/
#include <iostream>
#include <cmath>
using namespace std;

template <class T, int numCount>
class Point {
private:
    T v[numCount];
public:
    Point() {}
    Point(T vInput[numCount]){
        for (int i = 0; i < numCount; i++){ // Go through each part of the array, 1-3
            v[i] = vInput[i];
        }
    }
    T& operator[](int i){return v[i];}
};

template <class T, int n>
double getDistance(Point<T, n> first, Point<T, n> second){
    double dist = 0;
    for (int i = 0; i < n; i++){
        dist = dist + pow(second[i] - first[i],2); // add to what's under the square root sign
    }
    return sqrt(dist); // return the square root, this is the distance formula
}

int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
    double vector1[] = {1,2,3};
    double vector2[] = {8,9,10}; // make the actual points to go into the Point class
    Point<double, 3> pointOne(vector1); // it's a type double with 3 dimensions
    Point<double, 3> pointTwo(vector2);
    cout << getDistance(pointOne, pointTwo) << endl; // get the distance between the two
    
    int vector3[] = {2,4}; // make the other vector
    int vector4[] = {10,10};
    Point<int, 2> pointThree(vector3); // int with 2 dimensions
    Point<int, 2> pointFour(vector4);
    cout << getDistance(pointThree, pointFour) << endl;
    
    return 0;
}
