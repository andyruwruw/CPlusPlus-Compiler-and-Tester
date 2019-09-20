# C-Compiler-and-Tester

Compiles and runs your C++ program with given inputs, compares them to solutions and shows differences.

If you have any ways to make this better, feel free to fork the repository!

### Table of Contents
- [Section 1](#Pieces_and_Parts):  Pieces and Parts
- [Section 2](#Requirements):  Requirements
- [Section 3](#How_To_Use):  How To Use
- [License](#License)

---

## Pieces and Parts

**inputs** - Directory for all your `.txt` files, to be run through your program.

**solutions** - Directory for every input's desired output.

**results** - Directory for every comparisons results, along with `RESULTS.txt` as an overview to every comparison made.

**compare.cpp** - Takes in the `output.txt` from your program along with the desired output (`solution.txt `) and goes character by character to compare them. Any differences are appended to files in `results`, one for every comparison. Total number of differences for each file are appended to `RESULTS.txt`.

**run.sh** - Compiles your `.cpp`, runs all your `input.txt` through, and takes the `output.txt` it results in and plugs it through `compare.cpp` with the correct `solution.txt`.

---

## Requirements

All commands are written for a **Unix based system**.

`run.sh` will run your program with the input.txt as the first argument, and output.txt as the second. If you are using `cout` to console for output, change **line 45** of `run.sh` to:

```
./program "$file"  > output.txt
```

---

## How to Use

Clone the repository into the folder with your `.cpp` files.

Make sure to leave everything from this repository inside of its own sub-directory. 

It will be looking to compile your `.cpp` files a **directory up** from where it is run.

```
// Within your lab folder

$ git clone https://github.com/andyruwruw/CPlusPlus-Compiler-and-Tester.git
```

Drop into the directory

```
$ cd CPlusPlus-Compiler-and-Tester
```

Give `run.sh` permission to **execute commands**.

*You're encouraged to read through* **run.sh** *to make sure you're comfortable with all the commands it will be making.*

*Comments are made throughout to help with understanding.*

```
chmod +x run.sh
```

Next you'll need to place all your **inputs** and **solutions** into the folders provided.

**Input Files** need to have a unique number. It doesn't matter if the number is split up in multiple places.
```
# Valid File Names
input1.txt
22input.txt
4.txt
5input1.txt
```

**Solution Files** need to have the same digits as the input they should be compared with. The valid files below will match the inputs above.
```
# Valid File Names
solution1.txt
sol22.txt
4anothersolution.txt
51solution.txt
```

Inputs will be run through your compiled program, and the output will be compared to its correct solution.

After you've given `run.sh` permission, go ahead and run it!

```
./run.sh
```

`run.sh` will **compile your code**, **compile the compare program**, **run each input** through your program, and **compare the output** to the correct **solution**.

The number of differences for each file will be put into `results/RESULTS.txt`.

Detailed line by line comparisons will be in `txt` files custom made for each input file inside of the `results` folder.

These custom files will also include the full output.

All program files will be deleted upon completion, cleaning up the folder.

```
// Optional

cat ./results/RESULTS.txt
```
---

## License

[Available under the MIT license.](./LICENSE.txt)