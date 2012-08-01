//
//  ofxStumpflDMX.h
//  example-Stumpfl
//
//  Created by game over on 1/08/12.
//  Copyright (c) 2012 trace media. All rights reserved.
//

#ifndef __H_OFXSTUMPFLDMX
#define __H_OFXSTUMPFLDMX

#include "ofMain.h"
#include "ofxNetwork.h"

class ofxStumpflDMX {

public:
    
	ofxStumpflDMX();
    ~ofxStumpflDMX();
    
    bool connect(string ip, int port);
    void disconnect();
    bool isConnected();
    
    void update();
    
    void setLevel(unsigned int channel, unsigned char level);
    unsigned char getLevel(unsigned int channel);
    
    void clear();
    
protected:
	
    ofxUDPManager udpConnection;
    unsigned char levels[513];
    unsigned char keepAlive[2];
    
    bool dmxDirty;
    bool connected;
    
private:
	
};

#endif
