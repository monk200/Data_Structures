# Data_Structures
This repository contains code from Data Structures in C++ with Prof. Wade Fagen-Ulmschneider at UIUC. Course content available at https://courses.engr.illinois.edu/cs225/fa2018/  
  
Please do not steal the code if you are currently in the course, there is no guarentee that any of it is correct or up to date as I took the course in 2018. I'm currently redoing some of the labs and MP's from the course to refresh my memory and build a github I feel proud sharing with recruiters.

## Content
Each individual lab or MP will have its own README file with a link to the instructions, more information on how to run it, which files I altered, and the output created. 
  
* [lab_intro](https://github.com/monk200/Data_Structures/tree/main/lab_intro): A simple lab to get comfortable using C++ in your coding environemnt and manipulating images using the HSLAPixel class  
* [lab_trees](https://github.com/monk200/Data_Structures/tree/main/lab_trees): A lab that works with binary trees, traversing them and manipulating them iteratively and recursively. It also utilizes C++ templates and iterators.  
* lab_huffman:  
* MP4:  
* MP6:  
* lab_dict:  
* lab_ml:  

## Setup
1. Install Windows Subsystem for Linux (WSL): https://docs.microsoft.com/en-us/windows/wsl/install-win10  
> I had trouble getting Ubuntu from the Windows store because of an issue with my account, so I downloaded Ubuntu 20.04 from this link: https://docs.microsoft.com/en-us/windows/wsl/install-manual
2. After installing Ubuntu through the Windows store or by running the dowloaded .appx file, set up a username and password for yourself
3. Download the packages needed for the labs and MP's by running the following commands:

> - <code>sudo apt-get update; sudo apt-get install clang-6.0 libc++abi-dev libc++-dev git gdb valgrind graphviz imagemagick gnuplot make</code>  
> - <code>sudo update-alternatives --install /usr/bin/clang clang /usr/bin/clang-6.0 100</code>
> - <code>sudo update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/clang++-6.0 100</code>
> - <code>sudo update-alternatives --install /usr/bin/llvm-symbolizer llvm-symbolizer /usr/bin/llvm-symbolizer-6.0 100</code>  
>   
> If you're using Ubuntu 20.04 or having problems with including things from the standard library, also run this command:
> - <code>sudo apt-get install clang</code>

