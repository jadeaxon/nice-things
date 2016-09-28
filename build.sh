set -e

cd src >& /dev/null

# gcc -c -fpic nt_string.c -o nt_string.o
# gcc -c nt_string.c -o nt_string.o
gcc -c -fPIC nt_*.c
# gcc -shared -o libnicethings.so nt_string.o
gcc -shared -o libnicethings.so nt_*.o
cp libnicethings.so $HOME/lib

gcc test_nt_string.c -Wl,-rpath,$HOME/lib -L. -lnicethings -I. -o test_nt_string


cd - >& /dev/null




