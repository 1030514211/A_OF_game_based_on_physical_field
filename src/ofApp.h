#pragma once

#include "ofMain.h"
// 要用到图形界面，引用插件ofxGui
#include "ofxGui.h"
// 需要用到下面两个类：
class DrawingParticle;
class partofV;
class sent;
// 主程序的定义
class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	//显示时间
	void drawElapseTime();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	//加载字体
	ofTrueTypeFont _Font1;
	ofTrueTypeFont _Font2;
	//游戏时间
	float _PlayTime = 0.0f;

	//_VField： 矢量场：
	//用ofFbo来定义矢量场
	// 好处：便于对其进行编辑
	// 坏处：不便于访问到各个像素的数值
	ofFbo _VField;
	// _VFPx: 从_VField中逐像素获取数值
	ofFloatPixels _VFPx;
	// _Canvas：色彩场，所有运动粒子绘制的对象
	//ofFloatImage VF;
	ofFbo _Canvas;

	ofFloatImage _Background1;
	ofFloatImage _Background2;
	ofFloatImage Touch;
	ofFloatImage _home1;
	ofFloatImage _home2;

	// 运动粒子：随着矢量场_VField运动，且向画布_Canvas绘制
	// 用容器vector保存数量可变的粒子对象
	// 粒子对象用智能指针来定义
	vector<ofPtr<DrawingParticle> > _Particles;
	// _AddParticle：是否添加粒子，若为真，则点击屏幕就添加一个粒子
	ofParameter<bool> _AddParticle;
	// 上述运动粒子的参数都放在参数组_ParticleControl里
	ofParameterGroup _ParticleControl;

	ofParameter<bool> _Difficulty1;//难度系数1
	ofParameter<bool> _Difficulty2;//难度系数2
	// 上述运动粒子的参数都放在参数组_ParticleControl里
	ofParameterGroup _DifficultyControl;//难度控制


	// 显示所有运动粒子
	void drawParticles(bool bVisualAid = false);

	// 矢量场的显示效果控制
	ofParameter<ofFloatColor> _BrRotation1;
	ofParameterGroup _DisplayControl;
	void drawVField(bool touch);

	bool bDrawGUI;// 是否显示图形界面，用按键f1控制
	ofxPanel GUI; // 图形界面

				  // 窗口尺寸
	int screenw, screenh;
	bool begin;	
	bool difficulty1 ;
	bool difficulty2;
};
