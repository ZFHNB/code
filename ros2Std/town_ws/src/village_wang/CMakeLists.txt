cmake_minimum_required(VERSION 3.8)
project(village_wang)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

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

# ament包配置
ament_package()

# 包含头文件路径
include_directories(
  /opt/ros/humble/include/std_msgs
)

# 添加可执行文件
add_executable(wang2_node src/wang2.cpp)

# 添加编译器依赖
ament_target_dependencies(wang2_node
  rclcpp
  std_msgs  # 添加std_msgs依赖
)

# 安装目标
install(TARGETS
  wang2_node
  DESTINATION lib/${PROJECT_NAME}
)
