//
//  DeJong.hpp
//  DeJong
//
//  Created by Kenneth Lim on 24/10/2015.
//
//

#ifndef DeJong_hpp
#define DeJong_hpp

#include <stdio.h>
#include <vector>
#include "ofMain.h"

class DeJong{
public:
    int intensity;
    int iterations;
//    std::vector< std::vector<double> > density;
    double maxDensity;
    int N;
    double xSeed;
    double ySeed;
    double x;
    double y;
    
    DeJong();
    void clear();
    void seed();
    void populate(int samples);
    void reseed();
    void plot(int samples);
};

#endif /* DeJong_hpp */
