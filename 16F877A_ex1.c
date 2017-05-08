#include "16F877A.h"
/*This will simply output low and high, should read all 0, and all 1.  Will catch bad chips by their output*/

void main()
{
	output_D(0);  //set all output to low
	output_D(255);//set all output to high
}