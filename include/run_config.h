#ifndef RUN_CONFIG_H
#define RUN_CONFIG_H

#include "litmus.h"
//#include "internal.h"

typedef struct node{
	int 		id;
	lt_t		rate_a;
	lt_t		rate_b;
	int		level;
	struct node 	*parent;
	struct node 	*l_c;
	struct node 	*r_s; 
} node_t;

inline void init(node_t *n) {
	n->id = -1;
	n->parent = NULL;
	n->l_c = NULL;
	n->r_s = NULL;
}

#endif
