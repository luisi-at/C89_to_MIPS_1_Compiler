#!/bin/bash

mkdir -p test_deliverable/working

# Try to find a portable way of getting rid of
# any stray carriage returns
if which dos2unix ; then
    DOS2UNIX="dos2unix"
elif which fromdos ; then
    DOS2UNIX="fromdos"
else
    # This works on a GNU version of sed. I think this
    # will work in OSX as well, but don't have a machine
    # on which to test that. From reading the OSX docs,
    # it looks compatible.
    # The code \x0D is the ASCII code of carriage-return,
    # so it the regex should delete any CRs at the end of
    # a line (or anywhere in a line)
    DOS2UNIX="sed -e s/\x0D//g -"
    # Tested for combinations of:
    # - Ubuntu
    # - Cygwin
    # and inputs formats:
    # - LF
    # - CRLF
fi

echo "========================================"
echo " Cleaning the temporaries and outputs"
make clean


echo "========================================"
echo " Force building compiler"
make -B bin/c_compiler
if [[ "$?" -ne "0" ]]; then
    echo "Error while building compiler."
    exit 1;
fi

echo "========================================="

PASSED=0
CHECKED=0

for i in test_deliverable/test_cases/*; do
    b=$(basename ${i});
    mkdir -p test_deliverable/working/$b

    echo "==========================="
    echo ""
    echo "Input file : ${i}"
    echo "Testing $b"


    #Get the compiler output
    cat $i/${b}.c | bin/c_compiler > test_deliverable/working/$b/${b}_compiled.s

    #compile the driver to mips
    #mips-linux-gnu-gcc -c -S -x c $i/{$i}_driver.c -o test_deliverable/working/$b/{$b}_driver.s

    #compile and link the driver and test case function
    mips-linux-gnu-gcc -static $i/${b}_driver.c test_deliverable/working/$b/${b}_compiled.s -o test_deliverable/working/$b/${b}_comp_linked.output

    # single hyphen gives stdin/stdout
    #compile now to an object file and then run in qemu and get result
    #output result to file
    qemu-mips test_deliverable/working/$b/${b}_comp_linked.output

    #REF_RESULT=$?;
    #echo "${REF_RESULT}" > $i/ref.result.txt

    #compile own assembly to binary
    #mips-linux-gnu-gcc -static working/$b/c_compiled.s -o working/$b/c_compiled
    #run own assembly on qemu
    #qemu-mips working/$b/c_compiled
    #get result
    GOT_RESULT=$?;
    #echo result to text file
    #echo "${GOT_RESULT}" > test_deliverable/working/$b/got.result.txt

    OK=0;

    #REF_RESULT=$(head -n 1 $i/ref.result.txt | ${DOS2UNIX} );

    if [[ "${GOT_RESULT}" -ne "0" ]]; then
        echo "  got result : ${GOT_RESULT}"
        echo "  FAIL!";
        OK=1;
    fi

    if [[ "$OK" -eq "0" ]]; then
        echo "  got result : ${GOT_RESULT}"
        echo "  TEST PASSED!";
        PASSED=$(( ${PASSED}+1 ));
    fi

    CHECKED=$(( ${CHECKED}+1 ));

    echo ""
done

echo "########################################"
echo "Passed ${PASSED} out of ${CHECKED}".
echo ""

RELEASE=$(lsb_release -d)
if [[ $? -ne 0 ]]; then
    echo ""
    echo "Warning: This appears not to be a Linux environment"
    echo "         Make sure you do a final run on a lab machine or an Ubuntu VM"
else
    grep -q "Ubuntu 16.04" <(echo $RELEASE)
    FOUND=$?

    if [[ $FOUND -ne 0 ]]; then
        echo ""
        echo "Warning: This appears not to be the target environment"
        echo "         Make sure you do a final run on a lab machine or an Ubuntu VM"
    fi
fi
