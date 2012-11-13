#include "Resources.h"
#include "Starbucks.h"
#include "cinder/CinderResources.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/ImageIo.h"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "Resources.h"

class kosciaajStarbucks : public Starbucks {
public : 
 void build(Entry* c, int n);
 void allBucks();
 bool display;
 double closx;
 double closy;
 void placeCircle(uint8_t* pixels,int x, int y);
 Entry* getNearest(double x, double y);
	kosciaajStarbucks();
	Entry* unsortedArray;
	int size;
	string identifier;
	double x;
	double y;
   };