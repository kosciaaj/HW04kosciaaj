#include "Resources.h"
#include "Starbucks.h"

class kosciaajStarbucks : public Starbucks {
public : 
 void build(Entry* c, int n);
 Entry* getNearest(double x, double y);
	kosciaajStarbucks();
	Entry* unsortedArray;
	int size;
	string identifier;
	double x;
	double y;
   };