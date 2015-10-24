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
#include "ofMain.h"

class DeJong{
public:
    DeJong();
    void seed();
    void populate();
    void reseed();
    void plot();
};

#endif /* DeJong_hpp */
