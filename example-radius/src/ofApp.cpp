#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
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
void ofApp::update()
{
    ofSetWindowTitle(ofToString(ofGetFrameRate(), 2));
    ofVec2f mouse(ofGetMouseX(), ofGetMouseY());
    nn.findPointsWithinRadius(mouse, 50, indices);
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofSetColor(255, 0, 0);
    for (unsigned i = 0; i < points.size(); ++i)
    {
        ofDrawCircle(points[i], 2);
    }
    ofSetColor(0, 255, 0);
    for (unsigned i = 0; i < indices.size(); ++i)
    {
        ofDrawCircle(points[indices[i].first], 2);
    }
    ofSetColor(255);
    ofDrawBitmapString("Move mouse to find nearest neighbours", 10, 20);
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
