#pragma once
#include <stdio.h>
#include "ofMain.h"
#pragma once
class sent
{
public:
	sent(float x, float y, float rot, float str, ofFloatPixels VF);
	void update(float dt, float rec, ofFloatPixels& VF, ofFbo& Field);
	ofVec2f _PosA;
	ofFloatImage _AffectSum;
	ofVec2f  _Affects;
private:
	ofFloatImage _img;

};