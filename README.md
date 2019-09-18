# C-Compiler-and-Tester

Compiles and runs your C++ program with given inputs, compares them to solutions and shows differences.

## How to Use
Clone the repository into the folder with your `.cpp` files.

Make sure to leave everything in this repository inside of its directory. It will be looking to compile your `.cpp` files a directory `up` from where it is run.

``
// Within your lab folder
$ git clone https://github.com/andyruwruw/CPlusPlus-Compiler-and-Tester.git
``

Drop into the directory

``
$ cd CPlusPlus-Compiler-and-Tester
``

Give `run.sh` permission to **execute commands**.

*You're encouraged to read through `run.sh` to make sure you're comfortable with all the commands it will be making.*

*Comments are made throughout to help with understanding.*

``
chmod +x run.sh
``

Next you'll need to place all your `inputs` and `solutions` into the folders provided.

**Input Files** need to be formated as following.
``
input<number>.txt
``
Replacing `<number>` with a unique digit. Doesn't matter how long.

**Solution Files** need to be formated as following with their number corresponding to their input file.
``
solution<number>.txt
``

After you've given `run.sh` permission, go ahead and run it!

``
./run.sh
``

`run.sh` will `compile your code`, `compile the compare program`, `run each input` through your program, and `compare the output` to the correct `solution`.

All your results will be put into `RESULTS.txt`.

``
// Optional
cat RESULTS.txt
``