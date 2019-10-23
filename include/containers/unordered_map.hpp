/// \copyright Copyright 2019 Apex.AI, Inc.
/// All rights reserved.
#ifndef CONTAINERS__UNORDERED_MAP_HPP_
#define CONTAINERS__UNORDERED_MAP_HPP_

#include <containers/memory/common.hpp>

#include <functional>
#include <unordered_map>
#include <utility>

namespace apex
{
namespace containers
{
/// Defines a unordered_map type that only works with static allocators. Intended for more
/// complicated use cases, such as those involving unordered_maps nested in a container
template<typename Key, typename Value, typename Hash = std::hash<Key>,
  typename KeyEqual = std::equal_to<Key>, typename Mutex = memory::default_mutex>
using unordered_map =
  std::unordered_map<Key, Value, Hash, KeyEqual,
    node_allocator<std::pair<const Key, Value>, Mutex>>;
/// Defines unordered_map type which can accept multiple allocators which can be applied to
/// different levels of nested data structures
template<typename Key, typename Value, typename Hash = std::hash<Key>,
  typename KeyEqual = std::equal_to<Key>, typename Mutex = memory::default_mutex,
  typename ... InnerAlloc>
using unordered_map_scoped_alloc = std::unordered_map<Key, Value, Hash, KeyEqual,
    scoped_node_allocator<std::pair<const Key, Value>, Mutex, InnerAlloc...>>;
/// Defines a unordered_multimap type that only works with static allocators. Intended for more
/// complicated use cases, such as those involving unordered_multimaps nested in a container
template<typename Key, typename Value, typename Hash = std::hash<Key>,
  typename KeyEqual = std::equal_to<Key>, typename Mutex = memory::default_mutex>
using unordered_multimap =
  std::unordered_multimap<Key, Value, Hash, KeyEqual,
    node_allocator<std::pair<const Key, Value>, Mutex>>;
/// Defines unordered_multimap type which can accept multiple allocators which can be applied to
/// different levels of nested data structures
template<typename Key, typename Value, typename Hash = std::hash<Key>,
  typename KeyEqual = std::equal_to<Key>, typename Mutex = memory::default_mutex,
  typename ... InnerAlloc>
using unordered_multimap_scoped_alloc = std::unordered_multimap<Key, Value, Hash, KeyEqual,
    scoped_node_allocator<std::pair<const Key, Value>, Mutex, InnerAlloc...>>;

namespace memory
{
/// Helper typedef for unordered map node sizes
template<typename T>
using unordered_map_node_size = foonathan::memory::unordered_map_node_size<T>;
/// These are just pass-through parameters to any std::unordered_map
/// Specialization of node sizes for std::unordered_map
template<typename Key, typename Value, typename Hash, typename KeyEqual, typename Mutex>
struct NodeSize<unordered_map<Key, Value, Hash, KeyEqual, Mutex>>
  : std::integral_constant<std::size_t, unordered_map_node_size<std::pair<const Key, Value>>::value>
{
};
/// Helper typedef for unordered multimap node sizes
template<typename T>
using unordered_multimap_node_size = foonathan::memory::unordered_multimap_node_size<T>;
/// These are just pass-through parameters to any std::unordered_multimap
/// Specialization of node sizes for std::unordered_multimap
template<typename Key, typename Value, typename Hash, typename KeyEqual, typename Mutex>
struct NodeSize<unordered_multimap<Key, Value, Hash, KeyEqual, Mutex>>
  : std::integral_constant<std::size_t,
    unordered_multimap_node_size<std::pair<const Key, Value>>::value>
{
};
}  // namespace memory
}  // namespace containers
}  // namespace apex
#endif  // CONTAINERS__UNORDERED_MAP_HPP_
