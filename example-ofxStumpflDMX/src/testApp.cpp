#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE);
    dmx.connect("192.168.5.199", 9813);
    ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void testApp::update(){
    if(dmx.isConnected()){
        dmx.update();
    }   
}

//--------------------------------------------------------------
void testApp::draw(){
    
    // show some info
    stringstream msg;
    for(int i = 1; i < 513; i++){
        char channelInfo[128];
        sprintf(channelInfo, "%03i:%03i ", i, (int)dmx.getLevel(i));
        msg << channelInfo;
        if(i % 15 == 0) msg << endl; // bit of formatting :)
    }
    
    ofSetColor(0, 255, 0);
    ofDrawBitmapString(msg.str(), 20, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case OF_KEY_UP:
            for(int i = 1; i < 513; i++){
                int channelLevel = dmx.getLevel(i) + 1;
                if(channelLevel < 256) dmx.setLevel(i, channelLevel);
            }
            break;
        case OF_KEY_DOWN:
            for(int i = 1; i < 513; i++){
                int channelLevel = dmx.getLevel(i) - 1;
                if(channelLevel > -1) dmx.setLevel(i, channelLevel);
            }
            break;
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}