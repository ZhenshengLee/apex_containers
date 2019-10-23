cmake_minimum_required(VERSION 3.5)

project(containers)

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

include_directories(include)

set(containers_sources
    include/containers/memory/common.hpp
    include/containers/forward_list.hpp
    include/containers/list.hpp
    include/containers/map.hpp
    include/containers/set.hpp
    include/containers/static_vector.hpp
    include/containers/string.hpp
    include/containers/unordered_map.hpp
    include/containers/unordered_set.hpp
    include/containers/visibility_control.hpp
    src/string/to_string.cpp)

set_source_files_properties(${containers_sources} PROPERTIES language "CXX")
add_library(${PROJECT_NAME} SHARED ${containers_sources})
apex_set_compile_options(${PROJECT_NAME})

ament_target_dependencies(${PROJECT_NAME}
    apexutils
    foonathan_memory)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  find_package(ament_cmake_pclint REQUIRED)
  find_package(apex_test_tools REQUIRED)
  ament_lint_auto_find_test_dependencies()

  apex_test_tools_add_gtest(test_containers
      test/test_main.cpp
      test/containers/test_shared_ptr.cpp
      test/containers/test_static_allocators_vectors.cpp
      test/containers/test_static_allocators_basic.cpp
      test/containers/test_static_vector_snippets.cpp
      test/string/test_string.cpp
      test/string/test_string_strict.cpp
      test/string/test_to_string.cpp)
  target_link_libraries(test_containers ${PROJECT_NAME})
  ament_target_dependencies(test_containers)

endif()

list(APPEND ${PROJECT_NAME}_LIBRARIES
  "${PROJECT_NAME}"
)

ament_auto_package()
