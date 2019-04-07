# AI_Miss_Cann

Parameterized solver of Missionaries and Cannibals Problem using Breadth First Search implemented in C++.

## Getting Started

Clone the repository, compile and run it.

### Clone

```
git clone https://github.com/EduardoCulau/AI_Miss_Cann.git
```

### Compile

Enter the project directory and run the make command below.
The parameter PRINT define if the program must to print the execution or not.

```
make -j 5 -C src/ PRINT=0

or

make -j 5 -C src/ PRINT=1
```

### Run

The executable has 4 parameters as following in the below table:

  Parameter   |         Meaning
------------- | -----------------------
-m            | Number of Missionaries
-m            | Number of Cannibals
-bc           | Boat Capacity
-h            | Help

One example is:

```
./bin/miss_cann -m 2 -c 2 -bc 2
```

For a fast test, is possible to run with the make command as follow below but only with m = 3, c = 3 and bc = 2.

```
make run332 -C src/
```
