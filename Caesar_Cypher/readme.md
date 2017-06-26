# Caesar Decipher
An application that encrypts/decrypts a message using the Caesar Cypher technique  

### To Compile & Run
* run `make` to compile
* execute `./shift <message_file> <number_of_shifts>` to encrypt
* execute `./crack <encrypted_file>` to decrypt



Ex.

```
$ echo "This file's a test" > test.txt
$ ./shift test.txt 11 > test-enc.txt
$ more test-enc.txt
Estd qtwp'd l epde

$ ./crack test-enc.txt
This file's a test

$ echo "Rhythm & Blues" > rb.txt
$ ./shift rb.txt 10 > rb-enc.txt
$ ./crack rb-enc.txt
Xnezns & Hraky
```