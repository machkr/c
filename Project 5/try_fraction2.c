# Author: Jing Wang, for Program Design
# try_fraction2 is a Unix shell script that will be used to test project 5.
# To use the script, copy it into the same directory as your scource file
# Set execute permission for the file by issuing the command:
# chmod +x try_fraction2
# Compile your program, producing a.out as the executable
# To run the script, type 
# ./try_fraction2
# The user input from the script will not be shown on the screen.
# Compare the results from your program with the expected results on the test cases.
echo '===================================================='
#

./a.out <<-EndOfInput
2/3 + 1/8
EndOfInput
echo '----------------------------------------------------'
echo 'Expected:'
echo 'Enter two fraction separated by a +, -. *. or / sign: 2/3 + 1/8'
echo 'The sum is 19/24'
#
echo '===================================================='
#

./a.out <<-EndOfInput
3/4 - 1/6
EndOfInput
echo '----------------------------------------------------'
echo 'Expected:'
echo 'Enter two fraction separated by a +, -. *. or / sign: 3/4 - 1/6'
echo 'The difference is 7/12'
#
echo '===================================================='
#
./a.out <<-EndOfInput
1/3 * 3/8
EndOfInput
echo '----------------------------------------------------'
echo 'Expected:'
echo 'Enter two fraction separated by a +, -. *. or / sign: 1/3 * 3/8'
echo 'The product is 1/8'
#
echo '===================================================='
#
./a.out <<-EndOfInput
5/21 / 4/7
EndOfInput
echo '----------------------------------------------------'
echo 'Expected:'
echo 'Enter two fraction separated by a +, -. *. or / sign: 5/21 / 4/7'
echo 'The quotient is 5/12'
#
echo '===================================================='
#
./a.out <<-EndOfInput
2/3   +   1/8
EndOfInput
echo '----------------------------------------------------'
echo 'Expected:'
echo 'Enter two fraction separated by a +, -. *. or / sign: 2/3   +   1/8'
echo 'The sum is 19/24'
#
echo '===================================================='
#
./a.out <<-EndOfInput
2/3 & 1/8
EndOfInput
echo '----------------------------------------------------'
echo 'Expected:'
echo 'Unrecognized operator: &'
#
echo '===================================================='
#
