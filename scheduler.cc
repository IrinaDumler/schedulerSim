#include "scheduler.h"

using namespace std;

std::pair<JobDescription, NodeId> 
FIFOScheduler::placeJob()
{
  // TODO
  // just take the first job and find a node to place it

  return make_pair( JobDescription(), NodeId() );
}
