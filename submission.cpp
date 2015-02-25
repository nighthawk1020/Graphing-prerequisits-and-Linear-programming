#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
struct Node{
	vector<Node> children;
	int numChildren = 0;
	int value;
};
int main(int argc, char* argv[]){
	//Graph programming part. My implementation is
	//essentially an adjacency list.
	vector<Node> Graph;
	Graph.resize(16);
	Node cs1;
	cs1.value = 1;
	Node cs2;
	cs2.value = 2;
	Node cs3;
	cs3.value = 3;
	Node cs4;
	cs4.value = 4;
	Node cs5;
	cs5.value = 5;
	Node cs6;
	cs6.value = 6;
	Node cs7;
	cs7.value = 7;
	Node cs8;
	cs8.value = 8;
	Node cs9;
	cs9.value = 9;
	Node cs10;
	cs10.value = 10;
	Node cs11;
	cs11.value = 11;
	Node cs12;
	cs12.value = 12;
	Node cs13;
	cs13.value = 13;
	Node cs14;
	cs14.value = 14;
	Node cs15;
	cs15.value = 15;
	cs8.children.push_back(cs11);
	cs8.numChildren++;
	cs9.children.push_back(cs10);
	cs9.numChildren++;
	cs5.children.push_back(cs8);
	cs5.numChildren++;
	cs7.children.push_back(cs9);
	cs7.numChildren++;
	cs14.children.push_back(cs15);
	cs14.numChildren++;
	cs4.children.push_back(cs5);
	cs4.children.push_back(cs7);
	cs4.children.push_back(cs14);
	cs4.numChildren = 3;
	cs6.children.push_back(cs14);
	cs6.children.push_back(cs13);
	cs6.children.push_back(cs8);
	cs6.numChildren = 3;
	cs1.children.push_back(cs6);
	cs1.numChildren++;
	cs2.children.push_back(cs4);
	cs2.numChildren++;
	cs3.children.push_back(cs12);
	cs3.numChildren++;
	int semesters = 1;
	queue<Node> q;
	q.push(cs1);
	q.push(cs2);
	q.push(cs3);
	bool visited[16];
	for(int i = 0; i < 17; i++){
		visited[i] = false;
	}
	int distance[16];
	distance[1] = 1;
	distance[2] = 1;
	distance[3] = 1;
	//Breadth first search with the queue initialized with the values
	//of 1 2 and 3 because they are all base nodes.
	while(!q.empty()){
		Node current = q.front();
		q.pop();
		visited[current.value] = true;
		for(int i = 0; i < current.numChildren; i++){
			Node child = current.children[i];
			if(!visited[child.value]){
				distance[child.value] = distance[current.value] + 1;
				if(distance[current.value] + 1 > semesters){
					semesters = distance[current.value] + 1;
				}
				q.push(child);
			}
		}
	}cout<<"The number of semesters required to graduate is: "<<semesters<<endl;
	//linear programming part
	float maxCalories = 300;
	float maxVitA = 36;
	float maxVitC = 90;
	float aCalories = 60;
	float aVitA = 12;
	float aVitC = 10;
	float aCost = .12;
	float bCalories = 60;
	float bVitA = 6;
	float bVitC = 30;
	float bCost = .15;
	float min = 1000;
	float xVar = 0;
	float yVar = 0;
	float xPoint = 0;
	float yPoint = 0;
	xVar = (maxCalories * bVitA - maxVitA * bCalories)/(aCalories * bVitA - bCalories * aVitA);
	yVar = (maxCalories - aCalories * xVar)/(bCalories);
	if(min > ((aCost * xVar) + (bCost * yVar))){
		if((aCalories * xVar + bCalories * yVar) >= maxCalories && (aVitA * xVar + bVitA * yVar) >= maxVitA && (aVitC * xVar + bVitC * yVar) >= maxVitC){
			min = (aCost * xVar) + (bCost * yVar);
			xPoint = xVar;
			yPoint = yVar;
		}
	}xVar = (maxVitA * bVitC - maxVitC * bVitA)/(aVitA * bVitC - bVitA * aVitC);
	yVar = (maxVitA - aVitA * xVar)/(bVitA);
	if(min > ((aCost * xVar) + (bCost * yVar))){
		if((aCalories * xVar + bCalories * yVar) >= maxCalories && (aVitA * xVar + bVitA * yVar) >= maxVitA && (aVitC * xVar + bVitC * yVar) >= maxVitC){
			min = (aCost * xVar) + (bCost * yVar);
			xPoint = xVar;
			yPoint = yVar;
		}
	}xVar = (maxCalories * bVitC - maxVitC * bCalories)/(aCalories * bVitC - bCalories * aVitC);
	yVar = (maxCalories - aCalories * xVar)/(bCalories);
	if(min > ((aCost * xVar) + (bCost * yVar))){
		if((aCalories * xVar + bCalories * yVar) >= maxCalories && (aVitA * xVar + bVitA * yVar) >= maxVitA && (aVitC * xVar + bVitC * yVar) >= maxVitC){
			min = (aCost * xVar) + (bCost * yVar);
			xPoint = xVar;
			yPoint = yVar;
		}
	}cout<<"The minimum cost of this problem is: "<<min<<" dollars"<<endl;
	cout<<"The x value of the minimum cost is: "<<xPoint<<endl;
	cout<<"The y value of the minimum cost is: "<<yPoint<<endl;
};
