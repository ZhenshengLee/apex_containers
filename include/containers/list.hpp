/// \copyright Copyright 2019 Apex.AI, Inc.
/// All rights reserved.
#ifndef CONTAINERS__LIST_HPP_
#define CONTAINERS__LIST_HPP_

#include <containers/memory/common.hpp>

#include <list>

namespace apex
{
namespace containers
{
/// Defines a list type that only works with static allocators. Intended for more
/// complicated use cases, such as those involving lists nested in a container
template<typename T, typename Mutex = memory::default_mutex>
using list = std::list<T, node_allocator<T, Mutex>>;
/// Defines list type which can accept multiple allocators which can be applied to
/// different levels of nested data structures
template<typename T, typename Mutex = memory::default_mutex, typename ... InnerAlloc>
using list_scoped_alloc = std::list<T, scoped_node_allocator<T, Mutex, InnerAlloc...>>;

namespace memory
{
/// Helper typedef for unordered set node sizes
template<typename T>
using list_node_size = foonathan::memory::list_node_size<T>;
/// These are just pass-through parameters to any std::list
/// Specialization of node sizes for std::list
template<typename T, typename Mutex>
struct NodeSize<list<T, Mutex>>: std::integral_constant<std::size_t, list_node_size<T>::value>
{
};
}  // namespace memory
}  // namespace containers
}  // namespace apex
#endif  // CONTAINERS__LIST_HPP_
