#include "resource.h"

#include <stdexcept>
#include <algorithm>

using namespace std;

void
ResourcePool::updateResource( NodeId nodeId, int resources )
{
  if( !nodeId.isNone() )
    resourcesPerNode[nodeId.id] = resources;
}

NodeId
ResourcePool::findNodeWithSufficientResources( int resources ) const
{
  auto findRes = std::find_if(std::begin(resourcesPerNode), std::end(resourcesPerNode), 
			      [&](const pair<NodeId, int>& nodeResource) { return nodeResource.second < resources ;});
  if( findRes != std::end(resourcesPerNode))
    return findRes->first;
  else 
    return NodeId(); //None-node
}

int
ResourcePool::getResourcesForNode( NodeId nodeId ) const
{
  // TODO prevent exception by checking nodeId and return 0?
  if( !nodeId.isNone() )
    return resourcesPerNode.at( nodeId.id );

  return 0;
}
