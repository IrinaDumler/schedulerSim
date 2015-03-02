#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "job.h"
#include "resource.h"

#include <utility>

class Scheduler
{
 private:
  JobPool      jobPool;
  ResourcePool resourcePool;
  
 public:

  /**
   * Creates a scheduler with a job pool and a resource pool
   *
   * TODO The pools should not be copied. 
   * The client (simulator) should be able to adjust the content of the pools.
   */
  Scheduler( JobPool jobs, ResourcePool resources )
    : jobPool( jobs )
    , resourcePool ( resources )
  {}

  virtual std::pair<JobDescription, NodeId> placeJob() = 0;
};

class FIFOScheduler: public Scheduler
{
 public:

  FIFOScheduler( JobPool jobs, ResourcePool resources )
    : Scheduler( jobs, resources )
    {}

  std::pair<JobDescription, NodeId> placeJob() override;
};

#endif /* SCHEDULER_H */
