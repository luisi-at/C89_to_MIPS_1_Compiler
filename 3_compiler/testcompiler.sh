#!/bin/bash

mkdir -p working

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

for i in test/programs/*; do
    b=$(basename ${i});
    mkdir -p working/$b

    echo "==========================="
    echo ""
    echo "Input file : ${i}"
    echo "Testing $b"

    #compile to actual mips assembly:
    mips-linux-gnu-gcc -c -S -x c $i/in.code.c -o working/$b/mips_gnu.ref.s
    #now compile to mips binary:
    mips-linux-gnu-gcc -static working/$b/mips_gnu.ref.s -o working/$b/mips_gnu.output
    # single hyphen gives stdin/stdout
    #compile now to an object file and then run in qemu and get result
    #output result to file
    qemu-mips working/$b/mips_gnu.output

    REF_RESULT=$?;
    echo "${REF_RESULT}" > $i/ref.result.txt

    cat $i/in.code.c | bin/c_compiler > working/$b/compiled.s


    #compile own assembly to binary
    #mips-linux-gnu-gcc -static working/$b/c_compiled.s -o working/$b/c_compiled
    #run own assembly on qemu
    #qemu-mips working/$b/c_compiled
    #get result
    #GOT_RESULT=$?;
    #echo result to text file
    #echo "${GOT_RESULT}" > $i/got.result.txt

    #OK=0;

    #REF_RESULT=$(head -n 1 $i/ref.result.txt | ${DOS2UNIX} );

    #if [[ "${GOT_RESULT}" -ne "${REF_RESULT}" ]]; then
        echo "  got result : ${GOT_RESULT}"
        echo "  ref result : ${REF_RESULT}"
        echo "  FAIL!";
        OK=1;
    #fi

    #if [[ "$OK" -eq "0" ]]; then
        PASSED=$(( ${PASSED}+1 ));
    #fi

    #CHECKED=$(( ${CHECKED}+1 ));

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
