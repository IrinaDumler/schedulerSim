#ifndef JOB_H
#define JOB_H

#include <vector>
#include <stdexcept>

/**
 * Structure to describe a job.
 * Can describe a valid job or a "None" job.
 */
class JobDescription {

 private:
  bool none;  
  int id; // some unique job id
  int resourceNeed; // number of resource units needed
  int timeNeed; // number of time units needed

 public:

  /**
   * Constructs a "None" job
   */
 JobDescription()
   : none(true)
  {}

  /**
   * Constructs a job description with given resource and time needs
   *
   * TODO ensure both resource and time needs are > 0.
   */
 JobDescription( int jobId, int resource, int time )
   : none ( false )
   , id ( jobId )
   , resourceNeed( resource )
   , timeNeed( time )
  {}

  bool isNone() const
  {
    return none;
  }

  int getId() const
  {
    if( isNone() )
      throw std::logic_error("not available for none job");
    
    return id;
  }

  int getResourceNeed() const
  {
    if( isNone() )
      throw std::logic_error("not available for none job");

    return resourceNeed;
  }

  int getTimeNeed() const
  {
    if( isNone() )
      throw std::logic_error("not available for none job");

    return timeNeed;
  }

};

/**
 * Structure to hold jobs that are to be scheduled.
 * There are no job priorities.
 * The order of job placements is known.
 * 
 * TODO should notife a scheduler on new jobs (job arrivals).
 * TODO limit on jobs (number, cumulative resources, cumulative time)?
 */
class JobPool {

 private:
  // Holding all outstanding jobs in the order of incoming.
  // TODO optimize for access per jobId.
  std::vector<JobDescription> pool;

 public:

  /**
   * Contruct an empty job pool
   */
  JobPool(){}

  /**
   * Gives the description of the job, which was placed first (of all present jobs) 
   */
  JobDescription getJob() const;

  /**
   * Gives the escription of the first job, which has a resource need less than given.
   *
   * Idea: instead of specific functions there should be a general getJob method, which takes a 
   * decision/selection function as an argument.  
   */
  JobDescription getJobFirstForResources( int res ) const;

  /**
   * Remove a job from the pool (if it can be scheduled)
   */
  void removeJob( int jobId );

  /**
   * Adds job to a pool. 
   */
  void addJob( const JobDescription& job );

  /**
   * Tells if the pool is empty.
   */
  bool isEmpty() const;
};

#endif /* JOB_H */
