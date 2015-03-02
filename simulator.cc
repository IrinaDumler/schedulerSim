#include "job.h"
#include "resource.h"
#include "scheduler.h"

#include <iostream>

int main()
{
  std::cout << "Welcome to the simulator" << std::endl;

  // -create JobPool and ResourcePool
  JobPool jobPool;

  // TODO fill from some sort of an input stream
  jobPool.addJob( JobDescription(1/*id*/, 3/*resources*/, 4/*time*/) );
  jobPool.addJob( JobDescription(2/*id*/, 1/*resources*/, 4/*time*/) );
  jobPool.addJob( JobDescription(3/*id*/, 4/*resources*/, 7/*time*/) );

  ResourcePool resourcePool;

  // TODO fill from some sort of an input stream
  resourcePool.updateResource( NodeId(2), 3/*resources*/);
  resourcePool.updateResource( NodeId(7), 1/*resources*/);
  resourcePool.updateResource( NodeId(1), 23/*resources*/);

  // -create scheduler and bind it with the jobPool and ResourcePool
  FIFOScheduler fifo( jobPool, resourcePool);

  // -create a sumulator and bind it with the scheduler
  // -start a simulator

  // What scheduler shoud do:
  // find the next job to place and the node for it

  // What simulator should do:
  // count time steps
  // calculate max and avg job waiting time (metrics)
  // calculate avg idle time of used resources (metrics)
  //
  // simulator' "main" routine:
  // as long as there are jobs
  //   let scheduler find a job and a node
  //   update resourcePool and jobPool
  //   update time and metrics

  return 0;
}
