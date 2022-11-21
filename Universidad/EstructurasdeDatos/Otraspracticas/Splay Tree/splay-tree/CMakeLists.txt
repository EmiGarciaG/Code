cmake_minimum_required (VERSION 3.1)
project (splay_tree)

enable_language(CXX)
set(CMAKE_CXX_STANDARD 11)

add_executable(test_splaytree test_splaytree.cpp splaytree.hpp)

