//
//  DeJong.cpp
//  DeJong
//
//  Created by Kenneth Lim on 24/10/2015.
//
//

#include "DeJong.hpp"
#include <iostream>
#include <algorithm>

DeJong::DeJong(int size){
    intensity = 2;
    N = size;
    iterations = 8000;
    reseed();
}

void DeJong::clear(){
    std::vector< std::vector<double> > results;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            results[i][j] = 0;
        }
    }
    density = results;
    maxDensity = 0;
}

void DeJong::seed(){
    xSeed = ofRandom(-500, 1000) * 2 / N - 1;
    ySeed = ofRandom(-500, 1000) * 2 / N - 1;
    x = N/2;
    y = N/2;
}

void DeJong::populate(int samples){
    int _x;
    int _y;
    for (int i = 0; i < samples * iterations; i++){
        _x = ((sin(xSeed * x)) - (cos(ySeed * y)) * N * 0.2) + N / 2;
        _y = ((sin(-xSeed * x)) - (cos(-ySeed * y)) * N * 0.2) + N / 2;
        
        density[round(_x)][round(_y)] += intensity;
        x = _x;
        y = _y;
    }
    
    std::vector<double> results;
    for (int i = 0; i < density.size(); i++){
        results.push_back(*max_element(density[i].begin(), density[i].end()));
    }
    maxDensity = log(*max_element(results.begin(), results.end()));
}

void DeJong::reseed(){
    clear();
    seed();
    plot(1);
}

void DeJong::plot(int samples){
    double dens;
    int idx;
    populate(samples);
    
    unsigned char * data;
    data = screen.getPixels();
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dens = density[i][j];
            idx = (i * N + j) * 4;
            
            data[idx + 3] = 255;
            
            if (dens <= 0){
                continue;
            }
            
            double light = (log(dens) / maxDensity) * 255;
            
            data[idx] = data[idx+1] = data[idx+2] = light;
        }
    }
    screen.draw(0,0);
}