#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include "Timer.cpp"
#include "CHash.h"
#include "LinkedList.h"
#include "Hash.h"


using namespace std;

int main(){
	//set prime for timing
	const double prime = 600011;
	//set base load factor 
	double load = .2;
	//set long int random num max
	const long int rmax = 2147483647;
	long int val;
	//create timer
	Timer t;
	//create both hash tables
	CHash* closed = new CHash(prime);
	Hash* open = new Hash(prime);

	double openAVG[6];
	double closedAVG[6];
	//for loop to increment the load factor
	for(int lincr = 0; lincr < 6; lincr++)
	{
		double lf = load + (lincr / 10.0);
		//for loop to increment the seed (by 5)
		for(int sd = 1; sd <=26; sd += 5)
		{
			for(int i = 0; i< prime; i++)
			{
				closed->table[i] = new CContainer(false, -1);
				open->table[i] = new LinkedList();
			}
			//increment load factor as appropriate
			//calculate the count of random #s to generate
			int num = prime * lf;
			//populate closed hash table
			int count = 0;
			srand(sd);
			t.start();
			while(count <= num)
			{
				val = rand() % rmax;
				closed->Cinsert(val);
				count++;
			}
			double closed_time = t.stop();
			count = 0;
			srand(sd);
			t.start();
			while(count <= num)
			{
				val = rand() % rmax;
				open->insert(val);
				count++;
			}
			double open_time = t.stop(); 
			openAVG[lincr] += open_time;
			closedAVG[lincr] += closed_time;
			cout<<"Load factor: "<<lf<<"\tSeed: "<<sd<<endl;
			cout<<"Closed hashing completed in:\t"<<closed_time<<endl;
			cout<<"Open hashing completed in:\t"<<open_time<<endl;
		}
		double oavg = openAVG[lincr] / 6.0;
		double cavg = closedAVG[lincr] / 6.0;
		cout<<"Average closed hashing time for load factor:\t"<<lf<<":\t"<<cavg<<endl;
		cout<<"Average open hashing time for load factor:\t"<<lf<<":\t"<<oavg<<endl;	
	}

};