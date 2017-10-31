#!/bin/bash

if [[ -z "$1" ]]; then
    COMPILER=3_compiler/bin/c_compiler
else
    COMPILER=$1
fi

mkdir -p 3_compiler/working

for DRIVER in 3_compiler/test_deliverable/testcases/*_driver.c ; do
    NAME=$(basename $DRIVER _driver.c)
    TESTCODE=3_compiler/test_deliverable/testcases/$NAME.c

    >&2 echo "Test case $NAME"

    # Compile driver with normal GCC
    mips-linux-gnu-gcc -c $DRIVER -o 3_compiler/working/${NAME}_driver.o 2> 3_compiler/working/${NAME}_driver.compile.stderr
    if [[ $? -ne 0 ]]; then
        >&2 echo "ERROR : Couldn't compile driver program using GCC."
        continue
    fi

    # Compile test function with compiler under test to assembly
    cat $TESTCODE | $COMPILER > 3_compiler/working/$NAME.s  2> 3_compiler/working/${NAME}.compile.stderr
    if [[ $? -ne 0 ]]; then
        >&2 echo "ERROR : Compiler returned error message."
        continue
    fi

    # Link driver object and assembly into executable
    mips-linux-gnu-gcc -static 3_compiler/working/${NAME}.s 3_compiler/working/${NAME}_driver.o -o 3_compiler/working/${NAME}.elf 2> 3_compiler/working/${NAME}.link.stderr
    if [[ $? -ne 0 ]]; then
        >&2 echo "ERROR : Linker returned error message."
        continue
    fi

    # Run the actual executable
    qemu-mips 3_compiler/working/${NAME}.elf
    if [[ $? -ne 0 ]]; then
        >&2 echo "ERROR : Testcase returned $?, but expected 0."
    fi

    echo "pass"
done
