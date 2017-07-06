// #ifndef ... #def ...   #endif
// ���ڷ��ñ�ͷ�ļ����ظ�����
#ifndef DrawingParticle_hpp
#define DrawingParticle_hpp

#include <stdio.h>
#include "ofMain.h" // �õ�OF�Ĺ��ܣ����������ͷ�ļ�

class DrawingParticle
	// ���������������������ɫ���������ڵ�ʸ�����ƶ����������ƶ������У��򻭲�����
{
public:

	// ���캯��
	DrawingParticle(
		float radius = 10.0f,
		ofColor cr = ofColor::green,
		ofVec2f pos = ofVec2f(0, 0),
		float spd = 100.0f);

	// ���ݾ�����ʱ��dt����ʸ����VecField�������λ�õ�ʸ��������
	// ��Ϊ��ǰ���ٶȣ��ƶ�����λ��
	bool updatePosition(float dt, ofFloatColor vv, bool touch, ofFloatPixels& VecField, int difficulty);

	// ���Լ���λ��/��ɫ/�ߴ续һ��Բ��
	void draw();

	// ��������Ϣ
	void drawVisualAids();


private:
	float _radius; // �뾶
	ofColor _color;// ��ɫ
	ofVec2f _pos;// λ��
	float _speed; // �ٶ�
};
#endif /* DrawingParticle_hpp */
