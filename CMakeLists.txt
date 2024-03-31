cmake_minimum_required(VERSION 3.25)
project(linver LANGUAGES C)
add_executable(${PROJECT_NAME} "main.c")

if(MSVC)
  target_compile_options(${PROJECT_NAME}} PRIVATE /W4 /WX)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
  
if (UNIX)
#add_subdirectory("linux_methods") 
target_sources(${PROJECT_NAME} PUBLIC "linux_methods/linuxver.c" "linux_methods/firmware_ver.c")
endif (UNIX)

if (WIN32)
    
endif (WIN32)
