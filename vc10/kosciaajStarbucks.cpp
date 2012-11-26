#include "Resources.h"
#include "kosciaajStarbucks.h"

kosciaajStarbucks::kosciaajStarbucks(){
}
    void kosciaajStarbucks::allBucks(){
		
	}
	//Extremely basic build method
	void kosciaajStarbucks::build(Entry* c, int n){
		unsortedArray = new Entry[n];
	for(int i = 0; i < n; i++){
		unsortedArray[i] = c[i];
	}
	size = n;
	}
	//Extremely basic search method that uses a mathmatic formula. 
	Entry* kosciaajStarbucks::getNearest(double x, double y){
		Entry* close = new Entry();
	    Entry temp = unsortedArray[0];
	    for(int i=0; i < size; i++){
		if(sqrt((unsortedArray[i].x-x)*(unsortedArray[i].x-x)+
			(unsortedArray[i].y-y)*(unsortedArray[i].y-y)) < sqrt((temp.x-x)*(temp.x-x)+(temp.y-y)*(temp.y-y))){
				temp = unsortedArray[i];
		}
	}

	*close = temp;
	return close;
	}