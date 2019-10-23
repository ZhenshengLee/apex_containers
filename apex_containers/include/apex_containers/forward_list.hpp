/// \copyright Copyright 2019 Apex.AI, Inc.
/// All rights reserved.
#ifndef APEX_CONTAINERS__FORWARD_LIST_HPP_
#define APEX_CONTAINERS__FORWARD_LIST_HPP_

#include <apex_containers/memory/common.hpp>

#include <forward_list>

namespace apex
{
namespace containers
{
/// Defines a forward_list type that only works with static allocators. Intended for more
/// complicated use cases, such as those involving forward_lists nested in a container
template<typename T, typename Mutex = memory::default_mutex>
using forward_list = std::forward_list<T, node_allocator<T, Mutex>>;
/// Defines forward_list type which can accept multiple allocators which can be applied to
/// different levels of nested data structures
template<typename T, typename Mutex = memory::default_mutex, typename ... InnerAlloc>
using forward_list_scoped_alloc =
  std::forward_list<T, scoped_node_allocator<T, Mutex, InnerAlloc...>>;

namespace memory
{
/// Helper typedef for unordered set node sizes
template<typename T>
using forward_list_node_size = foonathan::memory::forward_list_node_size<T>;
/// These are just pass-through parameters to any std::forward_list
/// Specialization of node sizes for std::forward_list
template<typename T, typename Mutex>
struct NodeSize<forward_list<T, Mutex>>
  : std::integral_constant<std::size_t, forward_list_node_size<T>::value>
{
};
}  // namespace memory
}  // namespace containers
}  // namespace apex
#endif  // APEX_CONTAINERS__FORWARD_LIST_HPP_
