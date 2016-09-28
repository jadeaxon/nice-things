set -e

cd src >& /dev/null

gcc -c -fPIC nt_*.c
gcc -shared -o libnicethings.so nt_*.o
cp libnicethings.so $HOME/lib

gcc test_nt_string.c -Wl,-rpath,$HOME/lib -L. -lnicethings -I. -o test_nt_string
gcc test_nt_crypt.c -Wl,-rpath,$HOME/lib -L. -lnicethings -I. -o test_nt_crypt

cd - >& /dev/null




