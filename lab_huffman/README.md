# lab_huffman
This lab explored Huffman trees, and how they can be used for lossless compression. The instructions for this lab can be found at https://courses.engr.illinois.edu/cs225/fa2018/labs/huffman/

## Edited Files
I created the buildTree, removeSmallest, decode, writeTree, and readTree functions in [huffman_tree.cpp](https://github.com/monk200/Data_Structures/blob/main/lab_huffman/huffman_tree.cpp). The other functions and files were provided for me by the course.

## Running and Testing
Start by typing <code>make data</code> into the console to prepare the text that will be compressed. Compile the code by typing <code>make</code> into the linux terminal while in the lab_huffman directory. This builds the execuatables <code>encoder</code> and <code>decoder</code>, which can be used to run the <code>main</code> function. Typing simply <code>./encoder</code> or <code>./decoder</code> into the terminal will display usage instructions. An example usage could be <code>./encoder data/small.txt output.dat treefile.tree</code> which will encode the data from [./data/small.txt](https://github.com/monk200/Data_Structures/blob/main/lab_huffman/data/small.txt) and output the compressed huffman tree to treefile.tree. Next, typing <code>./decoder output.dat treefile.tree decode_output.dat</code> into the terminal will take the huffman tree and decompress it into [decode_output.dat](https://github.com/monk200/Data_Structures/blob/main/lab_huffman/decode_output.dat). Looking at the original data and the decoded output, or typing <code>diff decode_output.dat data/small.txt</code> into the console, will show that the encoder and decoder worked.  
The other data files provided can be run individually as shown above or the provided test cases can be run by typing <code>make test && ./test</code> into the console. Keep in mind that some test cases may produce different results on different computers.

## Output
Compiling the given test cases passes all 7 assertions in 10 test cases. The output from running <code>./test</code> is shown below:  

![Output.png](https://github.com/monk200/Data_Structures/blob/main/lab_huffman/Output.PNG)
