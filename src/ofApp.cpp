#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetBackgroundAuto(false);
    end = false;
    steps = 0;
    start = 0;
    limit = 200;
    
    stopped = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    if (!end) {
        if (stopped){
            dejong.reseed();
        }
        steps += 1;
        dejong.plot(5);
        if (steps > limit){
    //        stop loop
            end = true;
        }
    }
}

//--------------------------------------------------------------
void ofApp::pause(){
    stopped = true;
    draw();
}

void ofApp::record(){

}

void ofApp::resume(){
    stopped = false;
    steps = 0;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    ofBackground(0);
    steps = 0;
    end = false;
    dejong.reseed();
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
