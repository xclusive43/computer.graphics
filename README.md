# computer.graphics
befor compilation please do check your compiler is ready with libgraph or not.
!if not then..please do..

steps:
http://download.savannah.nongnu.org/releases/libgraph/libgraph-1.0.2.tar.gz
2. Install build essentials


sudo apt-get install build-essential
3. Install packages to run graphics.h header file

You need to install an entire list of packages which can be executed in a single statement as follows.


sudo apt-get install libsdl-image1.2 libsdl-image1.2-dev guile-1.8 guile-1.8-dev libsdl1.2debian libart-2.0-dev libaudiofile-dev libesd0-dev libdirectfb-dev libdirectfb-extra libfreetype6-dev libxext-dev x11proto-xext-dev libfreetype6 libaa1 libaa1-dev libslang2-dev libasound2 libasound2-dev
4. Extract the libgraph.tar.gz package file

You can extract a file in Linux using two methods:

Right click on the compressed file and extract it in the same folder
Execute a Linux command to untar the libgraph file

tar -xvzf libgraph.tar.gz
5. Copy extracted libgraph folder into USR directory


sudo cp -r libgraph-1.0.2 /usr/local/lib
 
6. Compile a C program with graphics.h header file

The following line of code will help you to understand how to compile graphics.h in Ubuntu 14.04 operating system.


gcc test.c -lgraph
Note: This graphics C program is compiled with GNU GCC compiler on Ubuntu 14.04 operating system. However, these codes are compatible with all other operating systems.

How To Install SDL Library in Linux Ubuntu?
It is very easy to download and install SDL graphics library in your Ubuntu operating system. Please follow the steps below.

Step 1: Start your Linux terminal and type the following command.


sudo apt-get install libsdl2-dev
Step 2: Run your C program with the following statement.


gcc armstrong_number.c -lSDL2

