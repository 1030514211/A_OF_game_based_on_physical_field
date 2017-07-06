#include <stdio.h>
#include "ofMain.h"
#pragma once
class partofV
{
public:
	partofV(float x, float y, float w,float h);
   	void update(float x, float y, float w, float h,float dt,float rec,ofFloatPixels& VF,
		ofFbo& Field);
private:
	ofFloatImage _img;
};