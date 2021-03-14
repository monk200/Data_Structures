# lab_intro
This lab was the first lab of the course and useful for guidance setting up your programming environment and making sure everything works before diving into more complex code.
The instructions for this lab can be found at https://courses.engr.illinois.edu/cs225/fa2018/labs/intro-2/  

## Edited Files
I created the cs225 namespace in HSLAPixel.h and HSLAPixel.cpp accoring to the doxygen for HSLAPixel
(https://courses.engr.illinois.edu/cs225/fa2018//doxygen/lab_intro/classcs225_1_1HSLAPixel.html)
and the createSpotlight, illinify, and watermark functions in lab_intro.cpp. The other files, functions, and tests were provided for me by the course.

## Running and Testing
Compile the code by typing <code>make</code> into the linux terminal while in the lab_intro directory.
This builds the execuatable <code>lab_intro</code>, which can be used to run the <code>main</code> function by typing <code>./lab_intro</code> into the terminal.
Once this runs, the files <code>out-grayscale.png</code>, <code>out-illinify.png</code>, <code>out-spotlight.png</code>, and <code>out-watermark.png</code>
 will apply transformations to <code>alma.png</code>.
The provided test cases can be run by typing <code>make test</code> and then <code>./test</code> into the terminal.
Keep in mind that some test cases may produce different results on different computers.

## Output
TBD
