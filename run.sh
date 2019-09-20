#!/bin/bash

# Resets Results
rm results/*
touch results/RESULTS.txt

# Echo is Bash for "console.log" or "print" or "cout" or "System.out.println"
echo ""

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
g++ ./compare.cpp -o compare.o

# Counts the number of input files.
shopt -s nullglob
logfiles=(./inputs/*)
numFiles=${#logfiles[@]}

# Variable for progress
done=0

# Runs for every input file.
for file in ./inputs/*
do
    # Finds the number of the input by parsing.
    file_name="${file##*/}"
    num=`echo "$file_name" | sed 's/[^0-9]*//g'`
    # Informs User
    printf "\r ${sp:i++%${#sp}:1} : $done/$numFiles : Running $file_name                 "

    # Runs file through your program and outputs to output.txt
    ./program "$file" output.txt

    for solution in ./solutions/*
    do
        solution_name="${solution##*/}"
        solution_num=`echo "$solution_name" | sed 's/[^0-9]*//g'`
        if [ "$solution_num" -eq "$num" ]
        then
        solution_file="$solution"
        fi
    done
    # Informs user
    printf "\r ${sp:i++%${#sp}:1} : $done/$numFiles : Compairing Output to $solution_name              "
    # Runs output through compare program with solution file, appending output to RESULTS.txt
    touch results/results_input$num.txt
    ./compare.o output.txt "$solution_file" results/RESULTS.txt results/results_input$num.txt $num
    # Adds one to done.
    done=$((done + 1))
done

printf "\r --- Hooray! Test Complete ---                                  \n"
echo ""
echo "     To view comparisons:"
echo "   $ cat results/RESULTS.txt"
echo ""
echo "         Drum roll :)"
echo ""
