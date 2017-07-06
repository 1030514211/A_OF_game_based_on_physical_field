#include "sent.h"
#include "Utilities.h"

sent::sent(float x, float y, float rot, float str, ofFloatPixels VF)
{

	_PosA = (ofVec2f(x, y));
	_Affects = (ofVec2f(rot, str));
	_AffectSum = VF;
	ofPushStyle();
	//ofSetColor(100);
	ofSetLineWidth(1.0f);
	ofDrawCircle(_PosA, 3);
	ofPopStyle();
}

void sent::update(float dt, float rec, ofFloatPixels& VF, ofFbo& Field)
{
	/*if (_img.getWidth() != w || _img.getHeight() != h)
	{*/
	_img.allocate(_AffectSum.getWidth(), _AffectSum.getHeight(), OF_IMAGE_COLOR_ALPHA);
	//}	
	int col(0), row(0);
	for (int i = _PosA.x - 50;
		i <= _PosA.x - 50 + _AffectSum.getWidth();
		i++)
	{
		row = 0;
		for (int j = _PosA.y - 50;
			j <= _PosA.y - 50 + _AffectSum.getHeight();
			j++)
		{
			ofFloatColor c = _AffectSum.getColor(col, row);
			ofVec2f deltaV(c.r - 0.5f, c.g - 0.5f);

			ofVec2f p[5] = { ofVec2f(col,row),
				ofVec2f(col - 1,row),ofVec2f(col + 1,row),
				ofVec2f(col,row - 1),ofVec2f(col,row + 1) };

			ofVec2f sumVec(0);
			int a = ofRandom(0, 1);

			for (int n = 0; n<5; n++)
			{
				int col = p[n].x;
				int row = p[n].y;
				ofFloatColor c = VF.getColor(col, row);
				ofVec2f vec(c.r - 0.5f, c.g - 0.5f);
				sumVec -= vec*dt/1.5;
			}
			sumVec /= 5.0f;
			ofFloatColor cr(
				sumVec.x + 0.5f,
				sumVec.y + 0.5f,
				0.0f
			);
			_img.setColor(col, row, cr);
			row++;
		}
		col++;
	}

	_img.update();

	Field.begin();
	ofPushMatrix();
	ofPushStyle();
	_img.draw(_PosA.x - 50, _PosA.y - 50, _AffectSum.getWidth(), _AffectSum.getHeight());
	ofPopStyle();
	ofPopMatrix();
	Field.end();
}

