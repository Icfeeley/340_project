#include <stdio.h>   // for printf()
#include <stdlib.h>  // for atoi()

#include "procs.h"
#include "procheap.h"

// DO NOT CHANGE THESE TWO CONSTANTS !
#define INTER_ARRIVAL_TIME 3   // mean poisson dist
#define SERVICE_TIME       5   // mean poisson dist

void fcfs_simulation(proc_t *procs, int numprocs){
  double (*fcfs_value_functionPtr)(proc_t *);
  fcfs_value_functionPtr = &fcfs_value_function;
  heap_init(numprocs, fcfs_value_functionPtr);
  double time_counter = 0;
  double total_wait = 0;
  double total_turnaround_time = 0;
  int procs_started = 0;
  while (heap_size() != 0 || procs_started < numprocs) {
    int i;
    for (i = 0; i < numprocs; i++){
      if (procs[i].arrival_time == time_counter) {
        heap_insert(&procs[i]);
        procs_started++;
      }
    }
    // print_heap();
    heap_age(1);
    if(heap_size() != 0){
        heap_update(&total_wait, &total_turnaround_time);
    }
    time_counter++;
  }

  heap_free();

  float average_wait = (float) total_wait/ numprocs;
  float average_turnaround_time = (float) total_turnaround_time / numprocs;
  printf("FCFS\t%f\t%f\n",average_wait, average_turnaround_time);
}

void spn_simulation(proc_t *procs, int numprocs){
  double (*spn_value_functionPtr)(proc_t *);
  spn_value_functionPtr = &spn_value_function;
  heap_init(numprocs, spn_value_functionPtr);
  double time_counter = 0;
  double total_wait = 0;
  double total_turnaround_time = 0;
  int procs_started = 0;
  while (heap_size() != 0 || procs_started < numprocs) {
    int i;
    for (i = 0; i < numprocs; i++){
      if (procs[i].arrival_time == time_counter) {
        heap_insert(&procs[i]);
        procs_started++;
      }
    }
    // print_heap();
    heap_age(1);
    if(heap_size() != 0){
        heap_update(&total_wait, &total_turnaround_time);
    }
    time_counter++;
  }
  heap_free();
  float average_wait = (float) total_wait/ numprocs;
  float average_turnaround_time = (float) total_turnaround_time / numprocs;
  printf("SPN\t%f\t%f\n",average_wait, average_turnaround_time);
}

void hrrn_simulation(proc_t *procs, int numprocs){
  double (*hrrn_value_functionPtr)(proc_t *);
  hrrn_value_functionPtr = &hrrn_value_function;
  heap_init(numprocs, hrrn_value_functionPtr);
  double time_counter = 0;
  int procs_started = 0;
  double total_wait = 0;
  double total_turnaround_time = 0;
  while (heap_size() != 0 || procs_started < numprocs) {
    int i;
    for (i = 0; i < numprocs; i++){
      // printf("test\n" );
      if (procs[i].arrival_time == time_counter) {
        heap_insert(&procs[i]);
        procs_started++;
      }
    }
    heap_age(1);
    if(heap_size() != 0){
        heap_update(&total_wait, &total_turnaround_time);
    }
    // print_heap();
    time_counter++;
  }
  heap_free();
  // printf("%f\n", total_wait);
  // printf("%f\n", total_turnaround_time);
  float average_wait = (float) total_wait/ numprocs;
  float average_turnaround_time = (float) total_turnaround_time / numprocs;
  printf("HRRN\t%f\t%f\n",average_wait, average_turnaround_time);
}


int main(int argc, char** argv)
{
  int numprocs, seed;
  proc_t *procs;   // array of procs with service time and arrival time

  if (argc < 3) {
    fprintf(stderr, "USAGE: %s numprocs seed\n", argv[0]);
    return 1;
  }

  numprocs = atoi(argv[1]);
  seed = atoi(argv[2]);

  // create an array of numprocs randomly generate (arrival time, service time)
  procs = procs_random_create(numprocs, seed, INTER_ARRIVAL_TIME, SERVICE_TIME);

  // Uncomment the next block of code and comment the line above if
  // you want to read the input from a file instead of generating
  // random values. This can be useful for debugging your code with
  // known inputs.  The file, "book_example.txt", contains an example
  // from the book.

  //
  // if ((procs = procs_read("book_example.txt", &numprocs)) == NULL) {
  //   fprintf(stderr, "Error reading procs array\n");
  //   return 2;
  // }


  printf("procs array:\n");
  printf("(arrival time, service time)\n");
  procs_print(procs, numprocs);

  /* Either call your implemented functions for performing FCFS, SPN,
     and HRRN, or insert your code here to perform these algorithms.
     My recommendation is to write one or more functions for these
     algorithms in order for your main to be more readable and
     manageable.
  */
  printf("type\twait\tturnaround\n");
  // fcfs_simulation(procs, numprocs);
  // spn_simulation(procs, numprocs);
  hrrn_simulation(procs, numprocs);

  free(procs);   // procs array was dynamically allocated, so free up

  return 0;
}
