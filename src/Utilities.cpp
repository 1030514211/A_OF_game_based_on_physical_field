#include <stdio.h>
#include "Utilities.h"
#include "ofApp.h"


ofVec2f utils::floatColor2Vec2f(
	ofFloatColor cr, float offset, float scale)
{
	ofVec2f v(cr.r - offset, cr.g - offset);
	v *= scale;
	return v;
}

void utils::drawVecField1(ofFloatPixels& VField, ofRectangle R, int res, float arrowSize, int difficulty, ofFloatColor vv1, bool touch)
{
	int w, h;
	w = VField.getWidth();
	h = VField.getHeight();
	//bool touch = false;
	int rw, rh;
	rw = R.width;
	rh = R.height;

	float sx, sy;
	sx = (float)rw / (float)w;
	sy = (float)rh / (float)h;

	ofStyle S = ofGetStyle();
	ofFloatColor CrS = S.color;

	ofPushMatrix();
	ofTranslate(R.x, R.y, 0.0f);
	ofScale(sx, sy, 1.0f);

	for (int row = 0; row < w - 200; row += res)
	{
		for (int col = 0; col < h; col += res)
		{
			ofVec2f pos1(row, col);
			ofFloatColor cr;
			//()
			if (col > 415 && col < 462) {
				cr = 0.0f;
			}
			else {
				ofRectangle R1(0, 500, 220, 150);//大Home ofSetColor(100, 255, 0);
				ofRectangle R4(290, 300, 300, 80);//自旋场
				ofRectangle R5(685, 540, 100, 100);//小home
				if (touch)
				{
					if (!R4.inside(pos1) && !R5.inside(pos1))
						cr = VField.getColor(row, col) + vv1;
					else
						cr = VField.getColor(row, col);
				}
				else
				{
					if (difficulty == 2)
					{
						if (!R1.inside(pos1) && !R4.inside(pos1) && !R5.inside(pos1))
							cr = VField.getColor(row, col) + vv1;
						else
						{
							if (R4.inside(pos1) || R5.inside(pos1))
								cr = VField.getColor(row, col);
							else if (R1.inside(pos1))
							{
								cr = (0.5,0);
								VField.setColor(row,col,cr);
							}
						}
					}
					else
					{
						if ( !R5.inside(pos1))
							cr = VField.getColor(row, col) + vv1;
						else
						{
							cr = VField.getColor(row, col);
						}
					}
				}
			}
			ofFloatColor c(CrS);

			c.a *= cr.a;
			ofSetColor(c);
			ofVec2f v =
				utils::floatColor2Vec2f(cr, 0.5f, res*0.4f);
			ofVec2f pos(row, col);
			ofVec2f S = pos - v;
			ofVec2f E = pos + v;

			if ((col > 415 && col < 462) || (col > 144 && row > 77 && row < 244 && col < 248))
			{}
			
				else {
					if (row > 290 && col > 290 && row < 590 && col < 380)
					{
						if (difficulty == 2)
							ofSetColor(100, 255, 0);//自旋场
						else
						{
						}
					}
					 if (row > 0 && col > 500 && row < 220 && col < 650)
					{
						if (difficulty == 2)
						ofSetColor(204,102,0);//大Home
						else
						{
						}
					}
					else if (row > 685 && col > 525 && row < 784 && col < 640)
					{
						ofSetColor(255, 0,0);//小Home
					}
					if (difficulty == 2 && row > 680 && row < 770 && col>80 && col < 170)
					{
					}
					else 
					{
						ofDrawArrow(S, E, arrowSize);
					}
				}
		}
	}
	ofPopMatrix();
}
