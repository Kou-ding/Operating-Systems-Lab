### Lab 5
#### 1. Memory management in C (5 Marks)

You are asked to implement a vector struct in C, similar to std::vector of C++ [1]. The needed functions, apart from a proper a) destructor and b) constructor are c) vector_push_back(), d) vector_pop() and e) vector_remove().

[1] https://en.cppreference.com/w/cpp/container/vector

#### 2. Resources limit in shell (5 Marks)

Add a shell script called spawner(memoryInKB, timeoutInSec, binaryName) that runs binaryName until timeoutInSec or memoryInKB limit reached. If so, exit gracefully. Make sure to add proper error checking for i) number of arguments passed to spawner(), ii) binary’s existence and iii) exec flag .

The CodeRunner expected non-0 error codes are:

    exit 1; memory limit reached

    exit 2; issue with passed arguments

    exit 3; binaryName doesn't exist

    exit 4; binaryName doesn't have +x flag

    exit 5; timeout

Make sure to exit gracefully upon any of the conditions reached.

#### 3. Makefiles, shared libraries and unit-tests. (2 Marks)

##### Part III - Makefiles, shared libraries and unit-tests. (3 Marks)
You are provided with the following source files: runner.c, test_runner.c and libdummy.c. You can download them from here [1]. On the course's Linux box, create a folder under your home directory named quiz-5, e.g. /home/deadpool/quiz-5 and extract the contects of the file quiz-5-source-tar.gz obtained from [1]. It should include the three mentioned files. You can safely delete the tarbal after extraction. 

##### Your task is to write a Makefile that has three recipes:
- make runner which compiles runner.c to runner.out. 
- make test which compiles test_runner.c and runs test_runner.out Keep in mind that both binaries require libdummy.c during runtime and to be linked.
- make clean which cleans up everything created, i.e. .out and .so, restoring the original state of the folder.

> Make sure you add the appropriate linking and compilation steps needed for libdummy.c to be available as a shared library (.so) and linked to both the other binaries.

##### In order to check your output, you should after running make runner your folder should containing the following files:
- runner.out 
- libdummy.so 
- Makefile
- test_runner.c
- runner.c
- libdummy.c

##### Running the command ldd runner.out should produce the following, i.e. meaning runner.out is linked to the shared library libdummy.co, apart from other system included libraries.
- linux-vdso.so.1 (0x00007fffe4306000)
- libdummy.so => ./libdummy.so (0x00007fe815dcf000)
- libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fe815bd1000)
- /lib64/ld-linux-x86-64.so.2 (0x00007fe815ddb000)
  
##### Running make test should produce the following output on std.out.
- ./test_runner.out
- Hello from the shared but dummy library!
- All tests passed.
 
##### And running ldd test_runner.out
- linux-vdso.so.1 (0x00007fff7bd77000)
- libdummy.so => ./libdummy.so (0x00007f4668dee000)
- libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f4668bf0000)
- /lib64/ld-linux-x86-64.so.2 (0x00007f4668dfa000)
 

##### By running make clean the directory should be restored in its original state, i.e. only the following files contained:
- Makefile
- test_runner.c
- runner.c
- libdummy.c 