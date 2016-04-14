#include <stdio.h>   // for printf()
#include <stdlib.h>  // for atoi()

#include "procs.h"
#include "procheap.h"

// DO NOT CHANGE THESE TWO CONSTANTS !
#define INTER_ARRIVAL_TIME 3   // mean poisson dist
#define SERVICE_TIME       5   // mean poisson dist

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

  /*
  if ((procs = procs_read("book_example.txt", &numprocs)) == NULL) {
    fprintf(stderr, "Error reading procs array\n");
    return 2;
  }
  */

  printf("procs array:\n");
  printf("(arrival time, service time)\n");
  procs_print(procs, numprocs);

  /* Either call your implemented functions for performing FCFS, SPN,
     and HRRN, or insert your code here to perform these algorithms.
     My recommendation is to write one or more functions for these
     algorithms in order for your main to be more readable and
     manageable.
  */

  double fcfs_value_function(*proc_t proc){
    return proc->arrival_time;
  }

  double spn_value_function(*proc_t proc){
    return proc->service_time;
  }

  double hrrn_value_function(*proc_t proc){
    double ratio = (proc->wait_time / proc->service_time) + 1;
    return ratio;
  }

  void update_heap(*proc_t heap){
    int i;

    for (i = 1;  i < num_procs+1; i++) {
      if (i == 1) {
        heap[i]->service_time--;
        if (heap[i]->service_time <= 0){
          heap = heap_deletemin();
        }
      }
      else {
        heap[i]->wait_time--;
      }
    }
  }


 //  *updat
 //  void upadte_heap(heap){
 // if heap[0].servicetime ==0
 // 	delete min heap...
 // (do this only for hrrn)
 // for i in heap:
 // 	if heap[i].waittime ==0
 // 		servicetime--
 // 	else
 // 		heap[i] waittime --
 //  }
 //
 //  update_proc_t(*proc_t){
 // if proc_t[0].servicetime ==0
 // 	&proc_t += sizeof(proc)
 //  }
 //
 //  init heap... // init proc
 // for (i=0; i < simiutaion duration; i++){ // while (num_procs != 0..
 // hrrn(heap, proc_t);
 // updateheap(heap)
 //  }
 //
 // for (i=0; i< simulation_duration; i++){
 // other function(proc_t);
 // updateproc_t()
 // }


  free(procs);   // procs array was dynamically allocated, so free up

  return 0;
}
