#include <iostream>
#include <vector>
#include <sstream>

#define NEW 0
#define OPEN 1
#define CLOSED 2

using namespace std;

// struct Point {

// 	double x;
// 	double y;

// }

// typedef struct Point value;

typedef struct node node;

struct node {
//To be done: map neighbours with cost
	value val;
	std::vector<node*> nb;
	node* back;
	double h;
	double k;
	int STATE;

};

double k(node* T) {
	return T->k;
}

double h(node* T) {
	return T->h;
}

struct tree {

	std::vector<node> New;
	std::vector<node> Open;
	std::vector<node> Closed;

}

typedef struct tree tree;

double process_state(tree Graph, node* target); //implementation done


//to be implemented:
node* min_state(tree Graph);

double c(node* to, node* from);

double get_k_min(tree Graph);

std::vector<node*> neighbours(node* X);

void del(node* X);

void ins(node* Y, double cost);

void modify_cost(node* from, node* to, double c_new);

//implementations:
double process_state(tree Graph, node* target) {
	node* X = min_state(Graph);
	double k_min = get_k_min(Graph);
	if (X == target) return -1;
	del(X);
	std::vector<node*> NEAR = neighbours(X);
	if (h(X) > k_min) {
		for (i = 0; i < NEAR.size(); i++) {
			node* Y = NEAR[i];
			if ((Y->h < k_min) && (h(X) > h(Y) + c(Y,X))) {
				X->back = Y; X->h = h(Y) + c(Y,X);
			}
		} 
	}
	if (h(X) == k_min) {
		for (i = 0; i < NEAR.size(); i++) {
			node* Y = NEAR[i];
			if ((Y->STATE == NEW) || ((Y->back == X) && (h(Y) != h(X)+c(X,Y))) || ((Y->back != X) && (h(Y) > h(X) + c(X,Y)))) {
				Y->back = X; ins(Y,h(X)+c(X,Y));
			}
		}
	}
	else {
		for (i = 0; i < NEAR.size(); i++) {
		if ((Y->STATE == NEW) || (Y->back = X && (h(Y) != h(X) + c(X,Y)))) {
			Y->back = X; ins(Y,h(X)+c(X,Y));
		}
		else if ((Y->back != X) && (h(Y) > h(X) + c(X,Y)))
			ins(X,h(X));
		else ((Y->back != X) && (h(X)>h(Y)+c(Y,X)) && (Y->STATE == NEW) && (h(Y) > k_min))
			ins(Y,h(Y));
	}
	return k_min;
}
