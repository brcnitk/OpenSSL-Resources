## OpenSSL Errors

``Error 1:``
```
$ openssl servsion
Error: openssl: error while loading shared libraries: libssl.so.1.1: cannot open shared object file: No such file or directory
```
Solution:

Check for the existence of libssl.so file
```
$ which openssl                             # To check the local of openssl if it is installed
$ ldd /usr/local/bin/openssl                # Shows missing libraries
$ ls /usr/local/lib                         # To check the presence of openssl
$ export LD_LIBRARY_PATH = /usr/local/lib   # Adding the location of openssl
$ sudo ldconfig # Executing the changes
```
