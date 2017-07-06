#pragma once

#include "ofMain.h"
// Ҫ�õ�ͼ�ν��棬���ò��ofxGui
#include "ofxGui.h"
// ��Ҫ�õ����������ࣺ
class DrawingParticle;
class partofV;
class sent;
// ������Ķ���
class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	//��ʾʱ��
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

	//��������
	ofTrueTypeFont _Font1;
	ofTrueTypeFont _Font2;
	//��Ϸʱ��
	float _PlayTime = 0.0f;

	//_VField�� ʸ������
	//��ofFbo������ʸ����
	// �ô������ڶ�����б༭
	// �����������ڷ��ʵ��������ص���ֵ
	ofFbo _VField;
	// _VFPx: ��_VField�������ػ�ȡ��ֵ
	ofFloatPixels _VFPx;
	// _Canvas��ɫ�ʳ��������˶����ӻ��ƵĶ���
	//ofFloatImage VF;
	ofFbo _Canvas;

	ofFloatImage _Background1;
	ofFloatImage _Background2;
	ofFloatImage Touch;
	ofFloatImage _home1;
	ofFloatImage _home2;

	// �˶����ӣ�����ʸ����_VField�˶������򻭲�_Canvas����
	// ������vector���������ɱ�����Ӷ���
	// ���Ӷ���������ָ��������
	vector<ofPtr<DrawingParticle> > _Particles;
	// _AddParticle���Ƿ�������ӣ���Ϊ�棬������Ļ�����һ������
	ofParameter<bool> _AddParticle;
	// �����˶����ӵĲ��������ڲ�����_ParticleControl��
	ofParameterGroup _ParticleControl;

	ofParameter<bool> _Difficulty1;//�Ѷ�ϵ��1
	ofParameter<bool> _Difficulty2;//�Ѷ�ϵ��2
	// �����˶����ӵĲ��������ڲ�����_ParticleControl��
	ofParameterGroup _DifficultyControl;//�Ѷȿ���


	// ��ʾ�����˶�����
	void drawParticles(bool bVisualAid = false);

	// ʸ��������ʾЧ������
	ofParameter<ofFloatColor> _BrRotation1;
	ofParameterGroup _DisplayControl;
	void drawVField(bool touch);

	bool bDrawGUI;// �Ƿ���ʾͼ�ν��棬�ð���f1����
	ofxPanel GUI; // ͼ�ν���

				  // ���ڳߴ�
	int screenw, screenh;
	bool begin;	
	bool difficulty1 ;
	bool difficulty2;
};
