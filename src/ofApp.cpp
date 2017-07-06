#include "ofApp.h"
#include "utilities.h"
#include "DrawingParticle.hpp"
#include "partofV.h"
#include "sent.h"
//--------------------------------------------------------------
bool touch = false;
int difficulty;
float dt;

void ofApp::setup() {
	difficulty = 1;
	difficulty1 = false;
	// 限制帧率最大60帧/秒
	ofSetFrameRate(60.0f);
	_Font1.load("vag.ttf", 20);
	_Font2.load("vag.ttf", 15);

	// 设定矢量场的初始状态
	ofFloatImage I1;
	I1.load("15.jpg");
	_Background1.load("1.jpg");
	_Background2.load("10.jpg");
	_home1.load("home.png");
	_home2.load("home.png");
	Touch.load("touch.jpg");


	_VField.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F);
	_VField.begin();
	ofClear(0, 0, 0, 0);
	I1.draw(0, 0, _VField.getWidth(), _VField.getHeight());
	_VField.end();

	// 彩色画布初始化
	_Canvas.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
	_Canvas.begin();
	ofClear(255, 255, 255, 255);
	_Canvas.end();

	// 移动粒子相关内容初始化
	_AddParticle.set("AddingParticles", false);
	_ParticleControl.setName("Particles");
	_ParticleControl.add(_AddParticle);

	// 难度系数初始化
	_Difficulty1.set("Difficulty1", false);
	_Difficulty2.set("Difficulty2", false);
	_DifficultyControl.setName("Difficulty");
	_DifficultyControl.add(_Difficulty1);
	_DifficultyControl.add(_Difficulty2);

	// 全局矢量场初始化
	_DisplayControl.setName("Display");
	_BrRotation1.set("AllRotation",
		ofFloatColor(0, 0, 0, 0.4f),
		ofFloatColor(0, 0, 0, 0),
		ofFloatColor(1, 1, 1, 1));
	_DisplayControl.add(_BrRotation1);

	// 图形界面初始化
	GUI.setup();
	GUI.setName("Control Panel");
	GUI.setSize(200, 400);
	GUI.setPosition(ofGetWidth() - 200, 0);
	GUI.add(_ParticleControl);
	GUI.add(_DisplayControl);
	GUI.add(_DifficultyControl);
	bDrawGUI = true;

	screenw = ofGetWidth();
	screenh = ofGetHeight();
	bool in = false;
}

//--------------------------------------------------------------
void ofApp::update() {
	
	// 将矢量场_VField的内容逐个像素的读取到_VFPx中
	_VField.getTexture().readToPixels(_VFPx);
	// after edit pixels in ofImage/ofFloatImage, we call update() to make it visible
}

//--------------------------------------------------------------
void ofApp::draw() {
	dt = ofGetLastFrameTime();
	_Canvas.draw(0, 0, ofGetWidth(), ofGetHeight());
	_Background1.draw(50, 412, 51, 62);
	_Background2.draw(700, 412, 52, 62);
	
	_home2.draw(716,570,50,40);
	if (difficulty == 2)
	{
		Touch.draw(700, 100, 60, 60);
		_home1.draw(50, 570, 100, 80);

	//	ofRectangle R1(0, 500, 220, 150);//大Home ofSetColor(100, 255, 0);
	/*	ofPushStyle();
		ofSetColor(255, 255, 0);
		ofDrawRectangle(0, 500, 220, 150);
		ofPopStyle();*/
	
	}

	//开始
	ofPushStyle();
	ofSetColor(255, 255,0);
	ofDrawRectangle(850, 400, 80, 60);
	ofPopStyle();

	ofPushStyle();
	ofSetColor(0);

	//自旋场
	partofV P1(290, 300, 300, 80);
	ofPopStyle();
	
	ofPushStyle();
	ofSetColor(0, 255, 0);
	_Font2.drawString("Begin", 860, 437);
	ofPopStyle();
	// 显示粒子
	drawParticles(true);

	// 显示界面
	if (bDrawGUI)
		GUI.draw();

	// 粒子移动
	//float 

	if (difficulty==2)
	{
		//part自旋场
		P1.update(290, 300, 300, 80, dt, 0.5, _VFPx, _VField);
		
	}

	ofFloatImage I2;
	I2.load("14.jpg");
	sent S1(735, 590, 0, 50,I2);

	if ((_PlayTime <= 64&& difficulty == 2)|| difficulty == 1)
	{
		if ((int)(_PlayTime / 5) % 2 == 1)
		{
			S1.update(-(int)(_PlayTime) % 5, 0.5, _VFPx, _VField);
		}
		else
		{
			S1.update((int)(_PlayTime) % 5, 0.5, _VFPx, _VField);
		}
	}

	if(touch==false&&difficulty==2)
	{
		ofPushStyle();
		ofSetColor(0, 255, 0);
		ofNoFill();
		ofDrawRectangle(10,500,200,150);
		ofPopStyle();
	}
	drawVField(touch);
	//drawElapseTime();
	ofVec2f _pos1, _pos2, _pos3;
	_pos1.x = 87; _pos1.y = 238;_pos2.x = 117; _pos2.y = 238;_pos3.x = 147; _pos3.y = 238;
	ofPushStyle();
	ofSetColor(255, 255, 0);
	ofDrawCircle(_pos1, 10.0f);ofDrawCircle(_pos2, 10.0f);ofDrawCircle(_pos3, 10.0f);
	ofPopStyle();

	ofPushStyle();
	ofNoFill();
	ofSetColor(0, 0, 0, 255);
	ofDrawCircle(_pos1, 10.0f);ofDrawCircle(_pos2, 10.0f);ofDrawCircle(_pos3, 10.0f);
	ofPopStyle();
	if ((int)_PlayTime % 15<5)//正电
	{
		//ofClear(255, 255, 0);
		ofPushStyle();
		ofSetColor(0, 0, 0, 255); //draw(); drawVisualAids();
		ofDrawLine(_pos1.x, _pos1.y - 10.0f, _pos1.x, _pos1.y + 10.0f);
		ofDrawLine(_pos1.x - 10.0f, _pos1.y, _pos1.x + 10.0f, _pos1.y);
		ofDrawLine(_pos2.x, _pos2.y - 10.0f, _pos2.x, _pos2.y + 10.0f);
		ofDrawLine(_pos2.x - 10.0f, _pos2.y, _pos2.x + 10.0f, _pos2.y);
		ofDrawLine(_pos3.x, _pos3.y - 10.0f, _pos3.x, _pos3.y + 10.0f);
		ofDrawLine(_pos3.x - 10.0f, _pos3.y, _pos3.x + 10.0f, _pos3.y);
		ofPopStyle();
	}
	if (((int)_PlayTime % 15 >= 5) && ((int)_PlayTime % 15 < 10))//不带电
	{	
	}
	if ((int)_PlayTime % 15 >= 10)//负电
	{
		ofPushStyle();
		ofSetColor(0, 0, 0, 255); //draw(); drawVisualAids();
		ofDrawLine(_pos1.x - 10.0f, _pos1.y, _pos1.x + 10.0f, _pos1.y);
		ofDrawLine(_pos2.x - 10.0f, _pos2.y, _pos2.x + 10.0f, _pos2.y);
		ofDrawLine(_pos3.x - 10.0f, _pos3.y, _pos3.x + 10.0f, _pos3.y);
		ofPopStyle();
	}

	for (int i = 0; i<_Particles.size(); i++)
	{
		touch = _Particles[i]->updatePosition(dt, _BrRotation1, touch, _VFPx, difficulty);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	if (x > 850 && x < 930 && y>400 && y < 460) {
		// 添加粒子或矢量场动态化处理源
		if (_AddParticle)
		{
			dt = ofGetLastFrameTime();
			if (_Difficulty1&&!_Difficulty2)
				difficulty = 1;
			else if (!_Difficulty1 && _Difficulty2)
				difficulty = 2;
			begin = true;
			ofPtr<DrawingParticle> newPt;
			newPt.reset(new DrawingParticle(10.0f, ofColor(255, 0, 0, 100), ofVec2f(ofRandom(130,200), 10), 100.0f));
			_Particles.push_back(newPt);			
		}

		if (_Difficulty1&&!_Difficulty2)
		{
			difficulty1 = true;
			difficulty2 = false;
		}		
		else if (!_Difficulty1 &&_Difficulty2)
		{
			difficulty1 = false;
			difficulty2 = true;
		}		
	}
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {
	ofSetWindowShape(screenw, screenh);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

void ofApp::drawElapseTime()
{
	if(begin){
	ofPushStyle();
	ofSetColor(ofColor::black);
	_Font1.drawString("Time:", 810.0f, 380.0f);
	_Font1.drawString(ofToString(_PlayTime), 890.0f, 380.0f);
	ofPopStyle();
	}
}

// 显示所有粒子
void ofApp::drawParticles(bool bVisualAid)
{
	for (int i = 0; i<_Particles.size(); i++)
	{
		ofPtr<DrawingParticle> ptrPt = _Particles[i];
		ptrPt->draw();
		if (bVisualAid)
		{
			//if()
			ptrPt->drawVisualAids();
			float deltaTime = ofGetLastFrameTime();
			_PlayTime += deltaTime;
			drawElapseTime();
		}
	}	
}

// 画出矢量场
void ofApp::drawVField(bool touch)
{
	ofPushStyle();
	ofSetColor(55,146,155);//初始场的颜色
	//ofSetColor(0,0,0);
	utils::drawVecField1(_VFPx,
		ofRectangle(0, 0, ofGetWidth(), ofGetHeight()),20, 2.5f, difficulty,_BrRotation1,touch);
	ofPopStyle();
}

