HUFFMAN ENCODING USING GREEDY ALGORITHM IN C

INTRODUCTION

This program implements Huffman Encoding, a lossless data compression technique based on the Greedy algorithm.
It reads input data from a text file, calculates the frequency of each character, builds a Huffman Tree, and generates variable-length binary codes for each character.

Huffman coding ensures that characters with higher frequency get shorter codes, resulting in efficient compression.

OBJECTIVES

• Implement Huffman Encoding using C
• Apply greedy strategy for optimal prefix codes
• Read input from a file
• Generate Huffman codes for characters
• Store encoded output in a file

ALGORITHM DESCRIPTION

Step 1: Read Input
• Read characters from input.txt
• Count frequency of each character

Step 2: Build Min Heap
• Create a min heap of nodes based on character frequencies
• Each node represents a character and its frequency

Step 3: Build Huffman Tree
• Extract two nodes with minimum frequency
• Create a new internal node with combined frequency
• Insert it back into the min heap
• Repeat until only one node remains

Step 4: Generate Huffman Codes
• Traverse the Huffman Tree
• Assign 0 for left edges and 1 for right edges
• Generate prefix-free binary codes

Step 5: Output
• Display Huffman codes on the console
• Write the same codes to encoded_output.txt

PROGRAM STRUCTURE

Function Name Description

newNode() Creates a new Huffman tree node
createMinHeap() Initializes a min heap
minHeapify() Maintains heap property
extractMin() Removes node with minimum frequency
insertMinHeap() Inserts node into heap
buildHuffmanTree() Constructs Huffman Tree
printCodes() Prints Huffman codes
HuffmanCodes() Main driver for encoding
main() Reads input file and executes program

INPUT SPECIFICATION

• Input file name: input.txt
• File contains text data
• Supports all ASCII characters

Example input (input.txt):
HELLO WORLD

OUTPUT SPECIFICATION

• Output file name: encoded_output.txt
• Displays each character with its Huffman code

Example output:
H: 110
E: 101
L: 00
O: 111
(space): 010

COMPILATION AND EXECUTION

Compilation:
gcc huffman.c -o huffman

Execution:
./huffman

ERROR HANDLING

• If input.txt cannot be opened, program displays error
• If input file is empty, program terminates gracefully

TIME AND SPACE COMPLEXITY

Time Complexity : O(n log n)
Space Complexity : O(n)

Where n is the number of unique characters.

LIMITATIONS

• Only generates Huffman codes, does not compress full file
• Fixed ASCII character set (256 characters)
• Decoding functionality not implemented

APPLICATIONS

• Data compression
• File compression utilities
• Multimedia encoding
• Network data transmission