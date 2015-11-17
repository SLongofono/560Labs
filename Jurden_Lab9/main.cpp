//start timer
//build leftist heap
//stop timer

//start timer
//build skew heap
//stop timer

//duration for leftist heap
//duration for skew heap
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "Timer.cpp"
#include "Leftist.h"
#include "Skew.h"


using namespace std;

int main(){
  int sizes[] = {50000, 100000, 200000, 400000};

	//create file to write results into
	ofstream out("results.csv", ofstream::out);
	ofstream lef("seeds.csv", ofstream::out);
	ofstream ske("sseeds.csv", ofstream::out);

	out << "Num, Left, Skew" << endl;
	lef << "Num, 1, 6, 11, 16, 21, 26" << endl;
	ske << "Num, 1, 6, 11, 16, 21, 26" << endl;

	ofstream outID("idavg.csv", ofstream::out);
	ofstream lefID("idlef.csv", ofstream::out);
	ofstream skeID("idske.csv", ofstream::out);
	outID << "Num, Left, Skew" << endl;
	lefID << "Num, 1, 6, 11, 16, 21, 26" << endl;
	skeID << "Num, 1, 6, 11, 16, 21, 26" << endl;
	//timer
	Timer t;

	//creat arrays to store info for build timing
	double leftB[4][5];
	double skewB[4][5];
	double skewBAVG[4];
	double leftBAVG[4];

	//create arrays to store info for insert/delete timing
	double leftI[4][5];
	double skewI[4][5];
	double skewIAVG[4];
	double leftIAVG[4];
	//for loop to increment the n value, while
	for(int num = 0; num < 4; num++)
	{
		cout << sizes[num];
		lef << sizes[num] << ',';
		ske << sizes[num] << ',';
		lefID << sizes[num] << ',';
		skeID << sizes[num] << ',';
		//for loop to increment the seed (by 5)
		for(int sd = 1; sd <=26; sd += 5)
		{
			cout << sd << endl;
			//create heaps
			Skew* skew = new Skew();
			Leftist* left = new Leftist();
			int rlim = sizes[num] * 4;
			//keep track of index for recording each seed time
			int seed = floor(sd/5);
			//increment load factor as appropriate
			//populate left
			int count = 0;
			int val = 0;
			srand(sd);
			t.start();
			while(count <= sizes[num])
			{
				val = rand() % rlim;
				left->insert(val, left->root);
				count++;
			}
			double left_time = t.stop();
			count = 0;
			srand(sd);
			t.start();
			while(count <= sizes[num])
			{
				val = rand() % rlim;
				skew->insert(val, skew->root);
				count++;
			}
			double skew_time = t.stop();
			skewBAVG[num] += skew_time;
			leftBAVG[num] += left_time;
			leftB[num][seed] = left_time;
			skewB[num][seed] = skew_time;
			ske << skew_time << ',';
			lef << left_time << ',';


			//now do insert/delete operations
			double r;
			int lim = sizes[num] * .1;
			count = 0;
			srand(sd);
			t.start();
			while(count < lim)
			{
				r = ((double) rand() / (RAND_MAX)) + 1;
				if(0 <= r <.5)
				{
					left->deleteMin(left);
				}
				if(0.5 <= r <1)
				{
					val = rand() % rlim;
					left->insert(val, left->root);
				}
				count++;
			}
			double left_tID = t.stop();

			count = 0;
			srand(sd);
			t.start();
			while(count < lim)
			{
				r = ((double) rand() / (RAND_MAX)) + 1;
				if(0 <= r <.5)
				{
					skew->deleteMin(skew);
				}
				if(0.5 <= r <1)
				{
					val = rand() % rlim;
					skew->insert(val, skew->root);
				}
				count++;
			}
			double skew_tID = t.stop();
			skewIAVG[num] += skew_tID;
			leftIAVG[num] += left_tID;
			leftI[num][seed] = left_tID;
			skewI[num][seed] = skew_tID;
			skeID << skew_tID << ',';
			lefID << left_tID << ',';
		}
		ske << '\n';
		lef << '\n';
		skeID << '\n';
		lefID << '\n';
		double savg = skewBAVG[num] / 4.0;
		double lavg = leftBAVG[num] / 4.0;
		double sidavg = skewIAVG[num] / 4.0;
		double lidavg = leftIAVG[num] / 4.0;
		out << sizes[num] << ',' << lavg << ',' << savg << endl;
		outID << sizes[num] << ',' << lidavg << ',' << sidavg << endl;
	}
	out.close();
	lef.close();
	ske.close();
	outID.close();
	lefID.close();
	skeID.close();
};
