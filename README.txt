Compiling Instructions:

Please compile the program MSS on the flip server using the following command:

gcc algorithms.c MSS.c -o MSS


Once compiled the program MSS can be run using the following command:

MSS {<filename> | <size_of_array>} <1…4>

1.) if the input array(s) come from a file, enter the filename as the first parameter.

2.) If the size n of the array to be tested is to be run 10 times (if the array is to be randomly generated), use the integer size of array as the first parameter.

3.) The second parameter signifies which algorithm to run: algorithm 1, 2, 3, or 4.

If it takes file input, the program will return each array itself, followed by the calculated value of the maximum sum sub array and time it took to compute. This will all be written to the output file.

If the array is to be randomly generated, the program will compute the entered algorithm for 10 different randomly generated arrays of size n, writing only the values and times to compute to the output file.

So, for a file input computation using algorithm 2, the command line command would look like:

./MSS MSS_Problems.txt 2

and what would get written to the output file MSS_TestResults.txt (by default) should be:

[1, 4, -9, 8, 1, 3, 3, 1, -1, -4, -6, 2, 8, 19, -10, -11] 
[8, 1, 3, 3, 1, -1, -4, -6, 2, 8, 19]
34

[2, 9, 8, 6, 5, -11, 9, -11, 7, 5, -1, -8, -3, 7 -2]
[2, 9, 8, 6, 5]
30

[10, -11, -1, -9, 33, -45, 23, 24, -1, -7 -8, 19] 
[23,24, -1, -7, -8, 19]
50

[31,-41, 59, 26, -53, 58, 97, -93, -23, 84] 
[59, 26, -53, 58, 97]
187

[3, 2, 1, 1, -8, 1, 1, 2, 3]
[3, 2, 1, 1]
7

[12, 99, 99, -99, -27, 0, 0, 0, -3, 10] 
[12, 99, 99]
210

[-2, 1, -3, 4, -1, 2, 1, -5, 4] 
[4, -1, 2, 1]
6

For 10 randomly generated arrays of size 1000, using algorithm 4, the command would be:

./MSS 1000 4

And the output would be (sums and times are made up as an example):

       Sum        Time (s)

45            0.004
25            0.003
118          0.004
45            0.004
98            0.004
79            0.005
54            0.006
39            0.004
40            0.003
88            0.004
Average Time (s): 0.0042