//
//  DeJong.cpp
//  DeJong
//
//  Created by Kenneth Lim on 24/10/2015.
//
//

#include "DeJong.hpp"
#include <algorithm>

vector< vector<double> > density;

DeJong::DeJong(){
    intensity = 2;
    N = 1400;
    iterations = 8000;
    density.resize(N, vector<double> (N));
    reseed();
}

void DeJong::clear(){
    vector< vector<double> > results;
    vector<double> results1(N, 0);
    for (int i = 0; i < N; i++) {
        results.push_back(results1);
    }
    density = results;
    maxDensity = 0;
}

void DeJong::seed(){
    ofSeedRandom();
    xSeed = (ofRandom(1000) * 2 / N - 1) * 0.02;
    ySeed = (ofRandom(1000) * 2 / N - 1) * 0.02;
    x = N/2;
    y = N/2;
}

void DeJong::populate(int samples){
    double _x;
    double _y;
    for (int i = 0; i < samples * iterations; i++){
        _x = ((sin(xSeed * y) - cos(ySeed * x)) * N * 0.2) + N/2;
        _y = ((sin(-xSeed * x) - cos(-ySeed * y)) * N * 0.2) + N/2;
        
        density[round(_x)][round(_y)] += intensity;
        x = _x;
        y = _y;
    }
    
    vector<double> results;
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
    ofImage screen;
    double dens;
    ofColor white;
    populate(samples);
    
    screen.grabScreen(0, 0, N, N);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dens = density[i][j];
            
            if (dens <= 0){
                continue;
            }
            
            double light = (log(dens) / maxDensity) * 255;
            
            double v = 300-light;
            if (v > 255){
                v = 255;
            }
            
            white.r = v;
            white.g = v;
            white.b = v;
            
            screen.setColor(i, j, white);
        }
    }
    screen.update();
    screen.draw(0,0);
}