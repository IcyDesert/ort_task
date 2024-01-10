cmake_minimum_required(VERSION 3.8)
project(enemy_estimator_task)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Eigen
find_package(Eigen3 3.3 REQUIRED)
set(link Eigen3::Eigen ${link})

find_package(ament_cmake_auto REQUIRED)
find_package(rclcpp REQUIRED) # 手动加入
find_package(task_interfaces REQUIRED)

# find ament_cmake
ament_auto_find_build_dependencies()
# find src
file(GLOB_RECURSE src "src/*.cpp")
ament_auto_add_library(${PROJECT_NAME} SHARED ${src})
target_link_libraries(${PROJECT_NAME} ${link})
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

add_executable(enemy_estimator_task src/enemy_estimator_task.cpp)
ament_target_dependencies(enemy_estimator_task rclcpp task_interfaces)

install(TARGETS enemy_estimator_task
    DESTINATION lib/${PROJECT_NAME}
)

ament_auto_package(
  INSTALL_TO_SHARE
  config
  launch
)
