CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(demo)

find_package(Eigen3)
find_package(OsqpEigen)

INCLUDE_DIRECTORIES(
  ${Eigen3_INCLUDE_DIRS}
  ${OsqpEigen_INCLUDE_DIRS}
)

ADD_EXECUTABLE(demo osqp_solver.cpp)

target_link_libraries(demo PUBLIC
  Eigen3::Eigen
  OsqpEigen::OsqpEigen
)