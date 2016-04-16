#ifndef PROCHEAP_H
#define PROCHEAP_H

#include "procs.h"

void    heap_init(int size, double (*value_func)(proc_t *));
void    heap_free();
int     heap_insert(proc_t *elem);
proc_t *heap_deletemin();
proc_t *heap_top();
double  hrrn_value_function(proc_t *elem);
double  fcfs_value_function(proc_t *elem);
double  spn_value_function(proc_t *elem);
void    update_heap();
int     heap_size();
void    heap_age(double amount);   // used by HRRN
void    print_heap();

#endif /* PROCHEAP_H */
