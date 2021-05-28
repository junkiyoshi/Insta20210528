#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);

	ofSetCircleResolution(60);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	auto noise_seed = glm::vec2(ofRandom(1000), ofRandom(1000));

	ofSetLineWidth(3);

	ofBeginShape();
	for (int x = 120; x <= 340; x += 1) {

		auto y = sin((x + 340 + ofGetFrameNum()) * 0.05) * 100;

		ofVertex(x, y);
	}
	ofEndShape();

	ofBeginShape();
	for (int x = -120; x >= -340; x -= 1) {

		auto y = sin((x + 240 + 340 + ofGetFrameNum()) * 0.05) * 100;

		ofVertex(x, y);
	}
	ofEndShape();

	ofBeginShape();
	for (int y = 120; y <= 340; y += 1) {

		auto x = cos((y + 340 + ofGetFrameNum()) * 0.05) * 100;

		ofVertex(x, y);
	}
	ofEndShape();

	ofBeginShape();
	for (int y = -120; y >= -340; y -= 1) {

		auto x = cos((y + 240 + 340 + ofGetFrameNum()) * 0.05) * 100;

		ofVertex(x, y);
	}
	ofEndShape();

	ofSetLineWidth(1.5);
	ofDrawCircle(0, 0, 93);
	ofDrawCircle(0, 0, 107);

	ofFill();
	auto location = glm::vec2(100 * cos((460 + ofGetFrameNum()) * 0.05), 100 * sin((460 + ofGetFrameNum()) * 0.05));
	ofDrawCircle(location.x, location.y, 6);

	for (int i = 1; i < 10; i++) {

		ofSetColor(ofMap(i, 1, 10, 39, 200));
		auto log = glm::vec2(100 * cos((460 + ofGetFrameNum() - i * 3) * 0.05), 100 * sin((460 + ofGetFrameNum() - i * 3) * 0.05));
		ofDrawCircle(log.x, log.y , 6);
	}

	ofNoFill();
	ofSetColor(39);

	ofDrawLine(glm::vec2(location.x, -120), glm::vec2(location.x, 120));
	ofDrawLine(glm::vec2(120, location.y), glm::vec2(-120, location.y));

	ofDrawLine(glm::vec2(-100, -120), glm::vec2(100, -120));
	ofDrawLine(glm::vec2(-100, 120), glm::vec2(100, 120));

	ofDrawLine(glm::vec2(120, -100), glm::vec2(120, 100));
	ofDrawLine(glm::vec2(-120, -100), glm::vec2(-120, 100));

	ofDrawLine(glm::vec2(-100, -340), glm::vec2(100, -340));
	ofDrawLine(glm::vec2(-100, 340), glm::vec2(100, 340));

	ofDrawLine(glm::vec2(340, -100), glm::vec2(340, 100));
	ofDrawLine(glm::vec2(-340, -100), glm::vec2(-340, 100));

}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}