#ifndef __LIST_H__
#define __LIST_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>

struct __list_node {
    int data;
    struct __list_node *next;
	
};

typedef struct {
    struct __list_node *head;
	pthread_mutex_t headlock;
} list_t;


void list_init(list_t *);
void list_clear(list_t *);
void list_add(list_t *, int);
int list_remove(list_t *, int);
void list_print(list_t *, FILE *);

#endif // __LIST_H__
