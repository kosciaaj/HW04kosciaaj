#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Resources.h"
#include "kosciaajStarbucks.h"
#include "Starbucks.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HW04App : public AppBasic {
  public:
	int count;
    Entry* buildArray();
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

};


void HW04App::setup()
{ 
	count = 0;
    Entry* first = buildArray();
    int n = count;
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
	
}

void HW04App::update()
{
	
}

void HW04App::draw()
{	
	
}

CINDER_APP_BASIC( HW04App, RendererGl )