#!/bin/bash
# Echo is Bash for "console.log" or "print" or "cout" or "System.out.println"
echo ""

# Resets Results
rm RESULTS.txt
touch RESULTS.txt

# Variables for the Spinning Animation
i=1
sp="/-\|"
echo -n ' '

# Compiles every .cpp program in the directory above.
# ${sp:i++%${#sp}:1} is how the spinning animation is done, contained by the printf
printf "\r ${sp:i++%${#sp}:1} : Compiling User Program"
g++ -Wall -Werror -std=c++17 -g ../*.cpp -o program

# Informing the user of completion.
printf "\r ${sp:i++%${#sp}:1} : Finished User Program Compilation"

# Compiles the compare program.
printf "\r ${sp:i++%${#sp}:1} : Compiling Compare Program               "
g++ compare.cpp -o compare.o

# Counts the number of input files.
shopt -s nullglob
logfiles=(./inputs/input*.txt)
numFiles=${#logfiles[@]}

# Variable for progress
done=0

# Runs for every input file.
for file in ./inputs/input*.txt
do
    # Informs User
    printf "\r ${sp:i++%${#sp}:1} : $done/$numFiles : Running $file               "
    
    # Finds the number of the input by parsing.
    num=${file:14:$((${#file} - 14 - 4))}
    # Runs file through your program and outputs to output.txt
    ./program "$file" output.txt
    # Informs user
    printf "\r ${sp:i++%${#sp}:1} : $done/$numFiles : Compairing Output to solution$num.txt              "
    # Runs output through compare program with solution file, appending output to RESULTS.txt
    ./compare.o output.txt "./solutions/solution$num.txt" RESULTS.txt $num
    # Adds one to done.
    done=$((done + 1))
done

printf "\r --- Hooray! Test Complete ---                                  \n"
echo ""
echo "     To view comparisons:"
echo "      $ cat RESULTS.txt"
echo ""
echo "         Drum roll :)"
echo ""



