//
//  ofxStumpflDMX.cpp
//  example-Stumpfl
//
//  Created by game over on 1/08/12.
//  Copyright (c) 2012 trace media. All rights reserved.
//

#include "ofxStumpflDMX.h"

//--------------------------------------------------------------
ofxStumpflDMX::ofxStumpflDMX(){
    connected = false;
    keepAlive[0] = keepAlive[1] = 'A'; // set keep alive to nonsense!
    dmxDirty = false; // default to not send anything on startup?
}

//--------------------------------------------------------------
ofxStumpflDMX::~ofxStumpflDMX(){
    udpConnection.Close();
}

//--------------------------------------------------------------
bool ofxStumpflDMX::connect(string ip, int port){
    
    // conect to the box via provided ip address and port
    udpConnection.Create();
	connected = udpConnection.Connect(ip.c_str(), port);
    if(!connected){
        // error let us know
        ofLogError() << "Could not connect to Stumpfl box on: " << ip << ":" << port;
        return false;
    }else{
        udpConnection.SetNonBlocking(true);
        
        // set everything to zero
        for (int i = 0; i < 513; i++) {
            levels[i] = 0;
        }
        
        // let us know
        ofLogNotice() << "Connected to Stumpfl box on: " << ip << ":" << port;
        return true;
    }
	
}

//--------------------------------------------------------------
void ofxStumpflDMX::disconnect() {
	udpConnection.Close();
}

//--------------------------------------------------------------
bool ofxStumpflDMX::isConnected(){
    return connected;
}

//--------------------------------------------------------------
void ofxStumpflDMX::update(){
    
    int sent = 0;
    levels[0] = 0xa0; // always set this bit to 0xa0?
    
    if(dmxDirty){
        // send all 512 channels at once - is there another way?
        sent = udpConnection.Send((const char*)levels, 513);
        dmxDirty = false;
    }else{
        // send keep alive packet
        sent = udpConnection.Send((const char*)keepAlive, 2);
    }
    
}

//--------------------------------------------------------------
void ofxStumpflDMX::setLevel(unsigned int channel, unsigned char level){
    if(channel > 0 && channel < 513){ // make sure channel is valid
        // should we clamp/check level is between 0 and 255?
        levels[channel] = level;
        dmxDirty = true;
    }else{
        ofLogError() << "Invalid channel: " << channel;
    }
}

//--------------------------------------------------------------
unsigned char ofxStumpflDMX::getLevel(unsigned int channel){
	return levels[channel];
}

//--------------------------------------------------------------
void ofxStumpflDMX::clear() {
	for(int i = 1; i < 513; i++){
		levels[i] = 0;
	}
}