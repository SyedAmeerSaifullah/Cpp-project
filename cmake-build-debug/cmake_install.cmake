<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
# Install script for directory: C:/Users/Admin/Documents/GitHub/2024-fall-itulahore-pf-se101t-project-2024-fall-h
=======
<<<<<<< HEAD
# Install script for directory: H:/C++/2024-fall-itulahore-pf-se101t-project-2024-fall-h
>>>>>>> Staff-Management

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/2024_fall_itulahore_pf_se101t_project_2024_fall_h")
<<<<<<< HEAD
=======
=======
# Install script for directory: D:/OneDrive/Documents/GitHub/2024-fall-itulahore-pf-se101t-project-2024-fall-h
=======
# Install script for directory: C:/Users/Admin/Documents/GitHub/2024-fall-itulahore-pf-se101t-project-2024-fall-h
>>>>>>> trains

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/project_final_code")
>>>>>>> trains
>>>>>>> Staff-Management
=======
# Install script for directory: C:/Users/Admin/Documents/GitHub/2024-fall-itulahore-pf-se101t-project-2024-fall-h

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
<<<<<<< HEAD
=======
<<<<<<< HEAD
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/project_final_code")
=======
>>>>>>> passenger
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/PROJECT")
>>>>>>> cargo
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
  set(CMAKE_OBJDUMP "C:/Users/Admin/Downloads/CLion 2024.2.0.1/bin/mingw/bin/objdump.exe")
=======
<<<<<<< HEAD
  set(CMAKE_OBJDUMP "C:/Program Files/JetBrains/CLion 2024.2/bin/mingw/bin/objdump.exe")
=======
  set(CMAKE_OBJDUMP "D:/Cygwin + clion/CLion 2024.2.2/bin/mingw/bin/objdump.exe")
>>>>>>> trains
>>>>>>> Staff-Management
=======
  set(CMAKE_OBJDUMP "C:/Users/Admin/Downloads/CLion 2024.2.0.1/bin/mingw/bin/objdump.exe")
>>>>>>> trains
=======
  set(CMAKE_OBJDUMP "C:/Users/Admin/Downloads/CLion 2024.2.0.1/bin/mingw/bin/objdump.exe")
>>>>>>> cargo
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
file(WRITE "C:/Users/Admin/Documents/GitHub/2024-fall-itulahore-pf-se101t-project-2024-fall-h/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
=======
<<<<<<< HEAD
file(WRITE "H:/C++/2024-fall-itulahore-pf-se101t-project-2024-fall-h/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
=======
file(WRITE "D:/OneDrive/Documents/GitHub/2024-fall-itulahore-pf-se101t-project-2024-fall-h/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> trains
>>>>>>> Staff-Management
=======
file(WRITE "C:/Users/Admin/Documents/GitHub/2024-fall-itulahore-pf-se101t-project-2024-fall-h/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> trains
=======
file(WRITE "C:/Users/Admin/Documents/GitHub/2024-fall-itulahore-pf-se101t-project-2024-fall-h/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}"
>>>>>>> cargo
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
