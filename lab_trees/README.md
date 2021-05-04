# lab_trees
This lab worked with binary trees and expored templates and iterators. The different functions created worked with iteratively and recursively traversing through trees and manipulating the pointers between nodes. The instructions for this lab can be found at https://courses.engr.illinois.edu/cs225/sp2021/labs/trees/

## Edited Files
I created the mirror, isOrderedIterative, and isOrderedRecursive functions in binarytree.h and binarytree.cpp as well as InorderTraversal and add functions in TreeTraversals\InorderTraversal.h. The other functions and files were provided for me by the course.

## Running and Testing
Compile the code by typing <code>make</code> into the linux terminal while in the lab_trees directory.
This builds the execuatable <code>treefun</code>, which can be used to run the <code>main</code> function by typing <code>./treefun</code> into the terminal.
Adding <code>color</code> as a modifier after the executable colors the branches of the tree green if they are correct or red if they are wrong.
This mode might cause unexpected issues when debugging so be cautious.
The provided test cases can be run by typing <code>make test</code> and then <code>./test</code> into the terminal.
Keep in mind that some test cases may produce different results on different computers.

## Output
At the moment, isOrderedRecursive() is still not completed so the code passes 3/4 test cases and 25/26 assertions. The output from running <code>./treefun color</code> is shown below:  

![Output.png](https://github.com/monk200/Data_Structures/blob/main/lab_trees/Output.PNG)
