ofxStumpflDMX
=====================================

Introduction
------------
Drop in replacement for ofxDMX when using a Stumpfl ethernet - DMX controller. Tested with a Stumpfl SC LAN DMX512-I/O.

Instead of using (eg) dmx.connect("tty.usbserial-EN098903", 512) use (eg)dmx.connect("192.168.5.199", 9813) where the IP and port are set on your Stumpfl box.

You'll need Iseo 2 to set these values - go to Extras->Iseo Device Manager->SC LAN. Make sure the Stumpfl box is disconnected. Hold down the Setup button, whilst plugging in the ethernet cable. Release the setup button, when the blue light goes solid. You should now be able to reset the IP Properties with the software.

Download: http://europe.avstumpfl.com/en/service/downloads/software/iseo_2

With thanks to the Ars Electronica Futurelab - especially Ali & Otto who worked out how to Stumpfl!

Licence
-------
ofxStumpflDMX is distributed under the [MIT License](https://en.wikipedia.org/wiki/MIT_License). See license.md distributed with this repository.

Installation
------------
Just drop the ofxStumpflDMX folder into the `openFrameworks/addons/` folder.

Add both ofxStumpflDMX and ofxNetwork to your project or use the Project Generator.

Dependencies
------------
ofxNetwork

Compatibility
------------
Tested with of071

Known issues
------------
None

Version history
------------

### Version 0.1 01/08/12:
* Initial commit.