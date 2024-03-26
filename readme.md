# Building C++ library and main file with library dependency

* hpp files of the libray need to be accessible to main source code
* built static library *.a needs to be added to the compiled source code of the main file to create a complete exe file.


## Configuration files

* launch.json - determines debug configuration. Depends on tasks.json tasks to build the application - using preLaunchTask which refers to tasks.json task
* tasks.json - tasks needed to build the application
    * C/C++: g++.exe build main/active file - task used to build main app, assumes the library has been built. Can be referenced by run/debug button because it is cppbuild type task.
    * C/C++: g++.exe build of the dependency library - prepares library output folder and builds the library outtput file in two steps:
        * Compiles source files
        * Create archive of compiled files - library  
        * WARNING - does not copy/prepare library header files
    * Project build process - tasks builds library and then main app in order, used in launch.json as prerequisite task.

## Common problems
* If a "Detected task" is used in Run/Debug action it will fail. Those are tasks predefined by the C++ library that will be automatically added to tasks.json and do not take library dependency into account. Delete those tasks from tasks.json and run task "C/C++: g++.exe build main/active file" - note the "main" part in name; this task uses the library and is predefined in tasks.json.