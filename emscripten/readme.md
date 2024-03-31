# Readme
Run docker image using
```
docker-compose -p emscripten -f docker-compose-ubuntu.yml up -d
```

Run with image rebuild
```
docker-compose -p emscripten -f docker-compose-ubuntu.yml up -d --build emscripten
```
Connect to docker container:
```
ssh localhost -l root -p 222
```
To remove old host identification
```
ssh-keygen -R '[hostname]:port' i.e. ssh-keygen -R '[localhost]:222'
```

# Compiling C++ code

https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_wasm


You must start with .c or .cpp and .h source files. Native executables or libraries for any other platform will not work. You cannot take an existing .a library and convert it.

You compile those source files to LLVM bitcode in .o files with emcc or em++.

Optionally you may wish to built multiple .o files into an .a or .bc library with emcc or em++. These will contain LLVM bitcode, which must be built targetting emscripten.

You may then compile the .o, .a, .bc, etc files to .js or .js+.wasm with emcc or em++.

emcc is a compiler tool, wrapping the clang compiler and accepts most clang options as well as emscripten-specific options. See the tutorial https://emscripten.org/docs/getting_started/Tutorial.html for basic setup and links to further documentation.

Use emar in place of ar

## Commands

When positioned in /data (root C++ project folder in container) run

```
em++ ./demo.cpp ./library/addition.cpp ./library/subtraction.cpp -I /data/library/ -o demo.js -sMODULARIZE -sEXPORT_NAME=Demo --closure 1
```
To compile the main program together with the libraries (since native libraries can not be used)

Use -v option to get more detailed output

-o - option can generate js file or html file (generating only wasm is possible but all house keeping has to be done manually https://webassembly.org/getting-started/js-api/)

-sMODULARIZE - enforces using javascript module, requires custom module name using "-sEXPORT_NAME=Demo" when generating .html (can aldo be used with .js). Custom module name requires custom html to account for custom module name so generating default .html is not possible.

--closure 1 - minimises javascript generated code

-c - option forces to produce object files that can be linked with other object files

Compiler reference  
https://emscripten.org/docs/tools_reference/emcc.html#emccdoc


# Calling C++ Functions
https://developer.mozilla.org/en-US/docs/WebAssembly/C_to_wasm#calling_a_custom_function_defined_in_c

https://developer.mozilla.org/en-US/docs/WebAssembly/Using_the_JavaScript_API#streaming_the_webassembly_module