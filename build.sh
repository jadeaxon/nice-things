#!/usr/bin/env bash

set -e

cd src >& /dev/null

S=$(basename $0)

lib=nicethings
fpic='-fPIC' # Arg to generate position independent code.
if [ "$CYGWIN" ]; then
	echo "$S: Building for Cygwin."	
	libfile=lib${lib}.dll.a
	fpic='' # All Windows code is position independent.
else
	echo "$S: Building for Linux."
	libfile=lib${lib}.so
fi

b=../build
rm -rf $b
mkdir -p $b

# Build and deploy the library itself.
# Deployment path for the library.
dlibpath=$HOME/lib
gcc -c $fpic nt_*.c
gcc -shared -o $b/$libfile nt_*.o
if [ ! -d $dlibpath ]; then
	echo "$S: ERROR: $dlibpath is not a directory!" 1>&2
	exit 1
fi
# Deploy the lib.
cp $b/$libfile $dlibpath
cp $b/$libfile /usr/local/lib/
rm *.o

# The rpath mechanism allows program to find lib in non-standard location without
# setting LD_LIBRARY_PATH.
rpath="-Wl,-rpath,$dlibpath"

# Build the test scripts.
# TO DO: For each loop.
gcc test_nt_string.c $rpath -L$b -l$lib -I. -o $b/test_nt_string
gcc test_nt_crypt.c $rpath -L$b -l$lib -I. -o $b/test_nt_crypt
gcc test_nt_error.c $rpath -L$b -l$lib -I. -o $b/test_nt_error
gcc test_nt_signal.c $rpath -L$b -l$lib -I. -o $b/test_nt_signal

# Deploy the headers.
cp *.h /usr/local/include/

ls -la $b
cd - >& /dev/null


