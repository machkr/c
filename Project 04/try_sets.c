# Author: Jing Wang, for Program Design
# try_sets is a Unix shell script that will be used to test project 4.
# To use the script, copy it into the same directory as your scource file
# Set execute permission for the file by issuing the command:
# chmod +x try_sets
# Compile your program, producing a.out as the executable
# To run the script, type 
# ./try_sets
# The user input from the script will not be shown on the screen.
# Compare the results from your program with the expected results on the test cases.
echo '===================================================='
#
./a.out <<-EndOfInput
10 9 23 -1
21 8 9 87  -1
EndOfInput
echo '----------------------------------------------------'
echo 'Expected:'
echo 'Set A: {10, 9, 23}'
echo 'Set B: {21, 8, 9, 87}'
echo 'Union of A and B: {10, 9, 23, 21, 8, 87}'
echo 'Intersection of A and B: {9}'
echo 'Deleting 5 from set A: {10, 9, 23}'
echo 'Set difference of A and B: {10, 23}'
echo 'Symmetric difference of A and B: {10, 23, 21, 8, 87}'
#
echo '===================================================='
#
./a.out <<-EndOfInput
10 9 23 24 5 -1
21 8 9 87 5 19 4 -1
EndOfInput
echo '----------------------------------------------------'
echo 'Expected:'
echo 'Set A: {10, 9, 23, 24, 5}'
echo 'Set B: {21, 8, 9, 87, 5, 19, 4}'
echo 'Union of A and B: {10, 9, 23, 24, 5, 21, 8, 87, 19, 4}'
echo 'Intersection of A and B: {9, 5}'
echo 'Deleting 5 from set A: {10, 9, 23, 24}'
echo 'Set difference of A and B: {10, 23, 24}'
echo 'Symmetric difference of A and B: {10, 23, 24, 21, 8, 87, 5, 19, 4}'
#
echo '===================================================='
#
