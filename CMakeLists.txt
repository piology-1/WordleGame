cmake_minimum_required(VERSION 3.10)
project(WordleGame)

# Set the C++ standard to C++11 or higher
set(CMAKE_CXX_STANDARD 11)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")

# Find all header and source files using GLOB
file(GLOB HEADER_FILES "include/*.h")
file(GLOB SOURCE_FILES "src/*.cpp")

# Add executable
add_executable(WordleGame ${SOURCE_FILES} main.cpp)
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


# Include directories for the target
target_include_directories(WordleGame PUBLIC include)



### /// cURL library \\\ ###

# Set the path to the library directory
# link_directories(C:/msys64/mingw64/lib)

# # Include the directory with the header files
# include_directories(C:/msys64/mingw64/include)

# # Link your project to libcurl
# target_link_libraries(WordleGame PRIVATE curl)

# Include cURL
# find_package(CURL REQUIRED)
# include_directories(${CURL_INCLUDE_DIRS})
# # target_link_libraries(WordleGame ${CURL_LIBRARIES})
# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/external_dependencies/curl/include)
# target_link_libraries(WordleGame PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/external_dependencies/curl/lib/libcurl.a)
# target_link_libraries(WordleGame PRIVATE curl)


# Set the paths to CURL library and include directories
# set(CURL_LIBRARY "C:/msys64/mingw64/lib/libcurl.dll.a")
# set(CURL_INCLUDE_DIR "C:/msys64/mingw64/include/curl")

# # # Find and link the CURL library
# find_package(CURL REQUIRED)
# target_link_libraries(WordleGame PRIVATE CURL::libcurl)

# # # Include cURL headers
# target_include_directories(WordleGame PRIVATE ${CURL_INCLUDE_DIR})

# # Optional: If you have unit tests, add them here
# enable_testing()
# add_subdirectory(tests)
# add_test(NAME MyTest COMMAND MyTest)

# Install the executable to a specified directory
install(TARGETS WordleGame DESTINATION bin)
