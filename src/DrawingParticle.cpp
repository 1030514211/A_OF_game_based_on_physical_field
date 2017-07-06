#include "DrawingParticle.hpp" // �����ͷ�ļ�
#include "Utilities.h" // ���ߺ������������ͷ�ļ���

int times=0; 
float _runtime = 0;
bool in = false;
int electricity1 = 1;//�糡��ʼ������
int electricity2 = 0;//С���ʼ������
float _PlayTime = 0.0f;

bool DrawingParticle::updatePosition(float dt, ofFloatColor vv,bool touch,ofFloatPixels& VecField, int difficulty)
{
	ofVec2f vec;
	ofVec2f move;
	ofVec2f distance1,distance2,distance11, distance22;
	float length1,length2, length11, length22;
	ofVec2f dis;

	// ��ʸ����VecField��õ�ǰλ��pos����ɫ
	ofFloatColor vecCr =
		VecField.getColor(_pos.x, _pos.y)+vv;
	// ����ɫת��Ϊһ��ʸ������Ϊ�ٶ�vecʹ��

	distance1.x = 700 - _pos.x;
	distance1.y = 446 - _pos.y;
	length1 = distance1.length();

	distance2.x = 100 - _pos.x;
	distance2.y = 446 - _pos.y;
	length2 = distance2.length();

	ofRectangle R1(77, 144, 167, 104);

	if (R1.inside(_pos))
	{
		in= true;
	}

	//���Ͻ�touch
	ofRectangle T(700, 100,60,60);
	if (T.inside(_pos))
	{
		touch = true;
	}

	int time1 = times;
	if (in && (!R1.inside(_pos)))
	{
		times += 1;
		in = false;
	}

	//ofRectangle RR1(50, 570, 100, 80);
	//ofRectangle RR2(716, 570, 50, 40);
	if (_pos.x > 50 && _pos.y > 570 && _pos.x < 150 && _pos.y < 650 && difficulty == 2&& electricity2==1)
	{
		_runtime += 0;
		_pos.x = 100;
		_pos.y = 610;
	} 
	else if(_pos.x > 716 && _pos.y > 570 && _pos.x < 766 && _pos.y < 610 && electricity2 == 1)
	{
		_runtime += 0;
		_pos.x = 740;
		_pos.y = 590;
	}
	else
	{
		_runtime += ofGetLastFrameTime();
	}

	if ((int)_runtime % 15 < 5)//�糡������
	{
		electricity1 = 1;
	}
	else if (((int)_runtime % 15 >= 5) && ((int)_runtime % 15 < 10))//�糡������
	{
		electricity1 = 0;
	}
	else if ((int)_runtime % 15 >= 10)//�糡������
	{
		electricity1 = -1;
	}

	if (R1.inside(_pos))
		{
			if ((electricity1+ electricity2 )<= -1)//����
			{
				electricity2 = -1;
				ofPushStyle();
				ofSetColor(0, 0, 0, 255);
				ofDrawLine(_pos.x - 10.0f, _pos.y, _pos.x + 10.0f, _pos.y);
				ofPopStyle();
				
			}
			else if ((electricity1 + electricity2 )==0)//������
			{
				electricity2 = 0;
			}
			else if ((electricity1 + electricity2) >=1)//����
			{
				electricity2 = 1;
				ofPushStyle();
				ofSetColor(0, 0, 0, 255); 
				ofDrawLine(_pos.x, _pos.y - 10.0f, _pos.x, _pos.y + 10.0f);
				ofDrawLine(_pos.x - 10.0f, _pos.y, _pos.x + 10.0f, _pos.y);
				ofPopStyle();	
			}	
		}
	else if (!R1.inside(_pos))
		{
			if (electricity2 == -1)//����
			{
				ofPushStyle();
				ofSetColor(0, 0, 0, 255);
				ofDrawLine(_pos.x - 10.0f, _pos.y, _pos.x + 10.0f, _pos.y);
				ofPopStyle();
				electricity2 = -1;
			}
			else if (electricity2 == 0)//������
			{
				electricity2 = 0;
			}
			else if (electricity2 == 1)//����
			{
				ofPushStyle();
				ofSetColor(0, 0, 0, 255);
				ofDrawLine(_pos.x, _pos.y - 10.0f, _pos.x, _pos.y + 10.0f);
				ofDrawLine(_pos.x - 10.0f, _pos.y, _pos.x + 10.0f, _pos.y);
				ofPopStyle();
				electricity2 = 1;
			}
		}

	ofTrueTypeFont _Font2;
	_Font2.load("vag.ttf", 15);
	ofPushStyle();
	ofSetColor(0, 255, 0);
	_Font2.drawString("TIME", 820, 500);
	_Font2.drawString(ofToString(times), 900, 500);
	ofTrueTypeFont _Font1;
	_Font1.load("vag.ttf", 30);
	int score;
	if (_runtime > 30)
		score = 100 - _runtime*0.5 - times * 10;
	else
		score = 100 - times * 10;

	string TotalTime = ofToString(_runtime);
	float txtWidth2 = _Font1.stringWidth(TotalTime);
	_Font2.drawString("Score", 800, 550);
	ofSetColor(ofColor::red);
	_Font1.drawString(ofToString(score), 900,550);
	ofPopStyle();

	//��(100,446)��(700,446)�ֱ��������ų�
	if (_pos.y >= 415 && _pos.y <= 446) {
		
		//�����ұߵĴų������������ұ�
		if (length1 <= length2) {
			if (distance1.x > 0)
				dis.x = 5;
			else
				dis.x = -5; 
			dis.y = dis.x*distance1.y / distance1.x;
			vec = utils::floatColor2Vec2f(vecCr, 0.5f, 0);
			// ���ٶ�vec�ƶ���move
			move = dt * vec / (0.01f*10.0f*10.0f);
			move += dis;

			distance11.x = 700 - _pos.x;
			distance11.y = 446 - _pos.y;
			length11 = distance11.length();

			if (length11 <= 5) {
				//ofSleepMillis(3000);
				//pause = true;
			}	
		}
	if (length2 < length1) {
		if (distance2.x > 0)
			dis.x = 5; 
		else
			dis.x = -5;
		dis.y = dis.x*distance2.y / distance2.x;
		vec = utils::floatColor2Vec2f(vecCr, 0.5f, 0);
		// ���ٶ�vec�ƶ���move
		move = dt * vec / (0.01f*10.0f*10.0f);
		move += dis;
		distance22.x = 100 - _pos.x;
		distance22.y = 446 - _pos.y;
		length22 = distance22.length();

		if (length22 <= 5) {
		//	ofSleepMillis(3000); //pause = true;
		}
	}
}	
	else if (_pos.y > 444 && _pos.y <= 487) {
		dis.x =0;
		dis.y = ofRandom(2, 7)*0.8;
		vec = utils::floatColor2Vec2f(vecCr, 0.5f, 0);
		move = dt * vec / (0.01f*10.0f*10.0f);
		move += dis/2;
	}
	else {
		vec = utils::floatColor2Vec2f(vecCr, 0.5f, _speed);
		// ���ٶ�vec�ƶ���move
		move = dt * vec / (0.01f*10.0f*10.0f);
	}

	// ����Լ���ɫ��ɫ��Hue
	float hue = 360.0f*(float)_color.getHue() / 255.0f;

	//˲���ƶ���
	if (difficulty == 1)
	{
		ofRectangle Sent(150, 500, 80, 60);
		ofFloatImage _sent;
		_sent.load("sent.jpg");
		_sent.draw(150, 500, 80, 60);
		if (Sent.inside(_pos))
		{
			float t;
			t = _pos.y;
			_pos.y = _pos.x;
			_pos.x = t;
		}
	}
	else if (difficulty == 2&&!touch)
	{
		float _W = ofWrap(_PlayTime * 10, 0, 125);
		ofRectangle Sent1(125 - _W, 500, 80, 60);
		ofFloatImage _sent1;
		_sent1.load("sent.jpg");
		_sent1.draw(125 - _W, 500, 80, 60);
		ofRectangle Sent2(_W + 125, 500, 80, 60);
		ofFloatImage _sent2;
		_sent2.load("sent.jpg");
		_sent2.draw(_W + 125, 500, 80, 60);
		if (Sent1.inside(_pos) || Sent2.inside(_pos))
		{
			float t;
			t = _pos.y+50;
			_pos.y = _pos.x-80-50;
			_pos.x  = t+80+50;
		}
	}
	else {}
	ofRectangle RR1(50, 570, 100, 80);
	ofRectangle RR2(716, 570, 50, 40);
	if ((RR1.inside(_pos) && difficulty == 2 && electricity2 == 1) || (RR2.inside(_pos) && electricity2 == 1))
	{
		float totalTime;
		totalTime = _runtime;
		if (RR1.inside(_pos) && difficulty == 2 && electricity2 == 1)
		{
			_pos.x = 100;
			_pos.y = 610;
			score += 5;
		}
		else if ((RR2.inside(_pos) && electricity2 == 1))
		{
			_pos.x = 741;
			_pos.y = 590;
			score += 10;
		}
		else {}
		ofClear(255, 255, 255);
		ofPushStyle();
		ofSetColor(ofColor::black);	
		string GameOverString = "Game Over";
		string TotalTime = ofToString(totalTime);
		ofTrueTypeFont _Font1;
		ofTrueTypeFont _Font2;
		_Font1.load("vag.ttf", 30);
		_Font2.load("vag.ttf", 20);
		float txtWidth1 = _Font1.stringWidth(GameOverString);
		float txtWidth2 = _Font1.stringWidth(TotalTime);
		_Font1.drawString(GameOverString, ofGetWidth() / 2.0f - txtWidth1 / 2.0f, ofGetHeight() / 2.0f-100);
		_Font2.drawString("TotalTime:", ofGetWidth() / 2.0f - txtWidth2 / 2.0f-50, (ofGetHeight() ) / 2.0f-30);
		_Font2.drawString(TotalTime, ofGetWidth() / 2.0f - txtWidth2 / 2.0f+100, (ofGetHeight() ) / 2.0f -30);
		_Font2.drawString("Score:", ofGetWidth() / 2.0f - txtWidth2 / 2.0f - 20, (ofGetHeight()) / 2.0f + 50);
		ofSetColor(ofColor::red);
		_Font1.drawString(ofToString(score), ofGetWidth() / 2.0f - txtWidth2 / 2.0f + 100, (ofGetHeight()) / 2.0f + 50);
		ofPopStyle();
	}
	else 
	{}
	// �ƶ�����תһ���Ƕȣ���ɫ��hue
	move.rotate(hue);

	// �ƶ�����λ��
	_pos += move;

	_PlayTime += dt;

	// ��������Ļ��Χ������ת����Ļ��һ��
	ofRectangle R(0, 0, ofGetWidth()-220, ofGetHeight());
	if (!R.inside(_pos))
	{
		_pos.x = ofWrap(_pos.x, 0, ofGetWidth()-220);
		_pos.y = 0;
	}
	return touch;
}

void DrawingParticle::draw()
{
	// ����Բ��
	ofPushStyle();
	ofSetColor(_color);
	ofDrawCircle(_pos, 10.0f);
	ofPopStyle();
}

void DrawingParticle::drawVisualAids()
{
	// ������Ķ�������ɫ����
	ofPushStyle();
	ofNoFill();
	ofSetColor(0, 0, 0, 255);
	ofDrawCircle(_pos, 10.0f);
	ofPopStyle();
}

// ���캯������ʼ������
DrawingParticle::DrawingParticle(
	float radius,
	ofColor cr,
	ofVec2f pos,
	float spd):
	_radius(radius),
	_color(cr),
	_pos(pos),
	_speed(spd)
{}

