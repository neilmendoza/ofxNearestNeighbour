#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
    const unsigned numPoints = 10000;
    ofBackground(0);
    points.reserve(numPoints);
    for (unsigned i = 0; i < numPoints; ++i)
    {
        points.push_back(ofVec2f(ofRandom(50, ofGetWidth() - 50), ofRandom(50, ofGetHeight() - 50)));
    }
    nn.buildIndex(points);
}

//--------------------------------------------------------------
void testApp::update()
{
    ofSetWindowTitle(ofToString(ofGetFrameRate(), 2));
    ofVec2f mouse(ofGetMouseX(), ofGetMouseY());
    nn.findPointsWithinRadius(mouse, 50, indices);
}

//--------------------------------------------------------------
void testApp::draw()
{
    ofSetColor(255, 0, 0);
    for (unsigned i = 0; i < points.size(); ++i)
    {
        ofCircle(points[i], 2);
    }
    ofSetColor(0, 255, 0);
    for (unsigned i = 0; i < indices.size(); ++i)
    {
        ofCircle(points[indices[i].first], 2);
    }
    ofSetColor(255);
    ofDrawBitmapString("Move mouse to find nearest neighbours", 10, 20);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

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
