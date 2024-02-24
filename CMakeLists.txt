cmake_minimum_required(VERSION 3.25)
project(linver LANGUAGES C)
add_executable(${PROJECT_NAME} "main.c")

  
if (UNIX)
#add_subdirectory("linux_methods") 
target_sources(${PROJECT_NAME} PUBLIC "linux_methods/linuxver.c" "linux_methods/firmware_ver.c" "linux_methods/netstat.c" "linux_methods/proclist.c")
endif (UNIX)

if (WIN32)
    
endif (WIN32)
