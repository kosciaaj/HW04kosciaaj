#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Resources.h"
#include "kosciaajStarbucks.h"
#include "Starbucks.h"
#include "cinder/Font.h"
#include "cinder/ImageIo.h"
#include "cinder/gl/Texture.h"
#include <iostream>
#include <fstream>
#include <time.h>

using namespace ci;
using namespace ci::app;
using namespace std;

class HW04App : public AppBasic {
  public:
	int count;
    Entry* buildArray();
	void setup();
	void mouseDown( MouseEvent event );	
	void HW04App::keyDown(KeyEvent event);
	void update();
	void draw();
	void placeCircle(uint8_t* pixels,int x, int y);
	void prepareSettings(Settings *settings);
	Entry* first;
	int n;
	int dataSize;

	double closx;
    double closy;
	bool display;
	static const int radius = 5;
	static const int kTextureSize=1024;
	static const int kAppWidth=800;
	static const int kAppHeight=600;

	gl::Texture USMap;
	Surface* mySurface;
};


void HW04App::prepareSettings(Settings *settings){
	settings->setWindowSize(kAppWidth, kAppHeight);
	settings->setFrameRate(60.0f);
	settings->setResizable(false);
	settings->setFullScreen(false);
	display = true;
}

void HW04App::setup()
{ 
	USMap = gl::Texture(loadImage( "../resources/USMap.jpg"));
	mySurface = new Surface(kTextureSize,kTextureSize,false);
	count = 0;
    Entry* first = buildArray();
    int n = count;
	dataSize = count;
    kosciaajStarbucks* find = new kosciaajStarbucks();
    find->build(first, n);
    Entry* nearest = find->getNearest(.1, .9);
	console() << nearest->identifier << "(" << nearest->x << ", " << nearest->y << ")" << endl;
}

Entry* HW04App::buildArray(){
	string name;
    double cordX, cordY;
    ifstream input("../resources/Starbucks_2006.csv");
    while(input.good()){
        getline(input, name, ',');
        input >> cordX;
        input.get();
        input >> cordY;
        input.get();
        count++;
    }
    input.clear();
    input.seekg(0);
    
    Entry* locations  = new Entry[count];
    count = 0;
    
    while(input.good()){
        getline(input, name, ',');
        input >> cordX;
        input.get();
        input >> cordY;
        input.get();
        (locations+count)->identifier = name;
        (locations+count)->x = cordX;
        (locations+count)->y = cordY;
        
        count++;
    }
    input.close();
    
    return locations;
}


void HW04App::mouseDown( MouseEvent event )
{	
	uint8_t* dataArray = (*mySurface).getData();
	int x = event.getX();
	int y = event.getY();

	placeCircle(dataArray,x,y);
}

void HW04App::placeCircle(uint8_t* pixels, int x, int y){
for (int j = x; j <= 2*radius && j < kTextureSize; j++){
	for(int i = x; i <= radius*2; i++){
			double dist_from_center = sqrt((double) (i - radius)*(i-radius)+(j-radius)*(j-radius));
			if (dist_from_center == radius){
				int current_point = 3*(i + j*kTextureSize);
				pixels[current_point] = 0;
				pixels[current_point+1] = 0;
				pixels[current_point+2] = 0;
		}
	}
	}
}

void HW04App::keyDown(KeyEvent event)
{
	display = !display;
}

void HW04App::update()
{
}

void HW04App::draw()
{	
	uint8_t* dataArray = (*mySurface).getData();
	if ( display){
		gl::draw(USMap, getWindowBounds());
	}
	else if (!display) {
        gl::clear(Color(0,0,0));
	}
	for (int i=0; i < dataSize; i++) {
		gl::color(ColorA(0.0,0.5,0.0,0.5f));
		gl::drawSolidCircle(Vec2f(first[i].x*getWindowSize().x,(1-first[i].y)*getWindowSize().y),1);
	}
}

CINDER_APP_BASIC( HW04App, RendererGl )