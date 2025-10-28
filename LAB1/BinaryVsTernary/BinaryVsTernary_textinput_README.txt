Binary Vs Ternary Program takes input.txt as input

BinaryVsTernary_textinput.exe < input.txt

This BinaryVsTernary_textinput.exe after getting input generates output.dat

This output.dat contains the n(no of elements of array),comparison2(no of comparisons using Binary Search),comparison3(no of comparisons using Ternary Search)

Plot.gp contains the commands

set title "Binary vs Ternary Search Comparisons"
set xlabel "Array Size (n)"
set ylabel "No. of Comparisons"
set grid
set key left top
plot "output.dat" using 1:2 with linespoints title "Binary Search", \
     "output.dat" using 1:3 with linespoints title "Ternary Search"



Run Terminal and run command gnuplot -p plot.gp to plot graph between n and No. of Binary and Ternary Comparisons.

Algorithm Design:
Binary Search:
Repeatedly divide the list into two halves.
Compare the middle element with the target.
Discard half the list each iteration.
Runs in O(log₂ n) time.
Needs only 1 comparison per step.

Ternary Search:
Divide the list into three nearly equal parts.
Compare the target with both midpoints (mid1 and mid2).
Based on the result, search in one of the three intervals.
Runs in O(log₃ n) time.
Needs 2 comparisons per step.

Conclusion:
Binary Search is better than Ternary Search.
Even though ternary search reduces the range faster, the extra comparisons at each step make it less efficient.
The growth of comparisons, as shown in the table and graph, clearly demonstrates that binary search requires fewer operations than ternary search for large inputs.