#include "partofV.h"
#include "Utilities.h"
partofV::partofV(float x, float y, float w, float h)
{
		ofSetColor(100);
		ofNoFill();
		ofSetLineWidth(1.0f);
}

void partofV::update(float x, float y, float w, float h, float dt,float rec,ofFloatPixels& VF,ofFbo& Field)
{   
	_img.allocate(w, h, OF_IMAGE_COLOR_ALPHA);
	int col(0), row(0);
	col = 0;
	for (int i = x;i<=x+w;i++)
	{
		row = 0;
		for (int j = y;j<=y+h;j++)
		{
			ofFloatColor cr = VF.getColor(i, j);
			ofVec2f v = utils::floatColor2Vec2f(cr, 0.5, 1.0f);
			v.rotate(5);
			v.limit(600);
			float distToCtr; 
			distToCtr = ofClamp(v.length(), 0, 1);
			float decay = ofMap(distToCtr, 0, 1, 1, 0);
			float alpha = decay * 50;
			ofFloatColor cr2(v.x + 0.5f, v.y + 0.5f, 0.0f, alpha);
			_img.setColor(col, row, cr2);
			row++;
		}
		col++;
	}
	Field.begin();
	_img.update();   
    
    ofPushMatrix();
    ofPushStyle();
    _img.draw(x,y,w,h);
    ofPopStyle();
    ofPopMatrix();
    Field.end();
}

