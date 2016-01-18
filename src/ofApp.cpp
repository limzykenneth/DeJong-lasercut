#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    end = false;
    steps = 0;
    start = 0;
    limit = 200;
    stopped = false;
	
	saveID = 0;
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
			end = true;
			ofSetBackgroundAuto(false);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 's') {
		string filename;
		filename = "screen-"+ ofToString(saveID) + ".png";
		ofSaveScreen(filename);
		saveID++;
		
		mouseReleased(0, 0, 0);
	}
	
	if (key == 'q'){
		mouseReleased(0, 0, 0);
	}
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
    ofBackground(255);
	ofSetBackgroundAuto(true);
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
