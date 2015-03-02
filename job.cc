#include "job.h"

#include <stdexcept>
#include <algorithm>

using namespace std;

bool
JobPool::isEmpty() const
{
  return pool.empty();
}

JobDescription
JobPool::getJob() const
{
  if( isEmpty() )
    return JobDescription(); // None-job
    
  return pool.front();
}

JobDescription
JobPool::getJobFirstForResources( int res ) const
{
  if( isEmpty() )
    return JobDescription(); //None-job

  auto findRes = std::find_if(std::begin(pool), std::end(pool), 
			   [&](const JobDescription& job) { return job.getResourceNeed() < res ;});
  if( findRes != std::end(pool))
    return *findRes;
  else 
    return JobDescription(); //None-job
}

void
JobPool::removeJob( int jobId )
{
  auto findRes = std::find_if(std::begin(pool), std::end(pool),
                           [&](const JobDescription& job) -> bool { return job.getId() == jobId ;});
  if( findRes != std::end(pool))
    pool.erase( findRes);
}

void
JobPool::addJob( const JobDescription& job )
{
  if( !job.isNone() )
    pool.push_back( job );
}
