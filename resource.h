#ifndef RESOURCE_H
#define RESOURCE_H

#include <map>
#include <stdexcept>

class ResourcePool; // forward declaration

/**
 * Structure to identifiy a node.
 * Can describe a valid node or a "None" node.
 */
class NodeId {
  friend class ResourcePool; // TODO correct ResourcePool to use NodeId as a key in the map

 private:
  bool none;
  int id;

 public:

  /**
   * Constructs a "None" node
   */
  NodeId()
    : none( true )
    {}

  /**
   * Construct a valid node id
   */
   NodeId( int nodeId )
     : none( false )
     , id( nodeId )
  {}

  bool isNone() const
  {
    return none;
  }

};

/**                                                                                                           
 * Structure to describe a resource pool.
 *
 * TODO could support resource locking.
 * TODO should notife a scheduler on new resources.
 */
class ResourcePool {

 private:
  // structure to describe available resources
  std::map< int, int > resourcesPerNode;

 public:
  
  /**
   * Creates a new empty resource pool
   */
  ResourcePool() {};

  /**
   * Add resources to the pool, if the node is new.
   * Update resources in the pool, if the node is already known.
   */
  void updateResource( NodeId nodeId, int resources );

  /**
   * Finds a node with resources availbale at least as given. 
   */
  NodeId findNodeWithSufficientResources( int resources ) const;

  int getResourcesForNode( NodeId nodeId ) const;
};

#endif /* RESOURCE_H */ 
