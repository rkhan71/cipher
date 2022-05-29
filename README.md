# cipher
All the code I wrote to implement a cipher in C. The cipher encrypts and decrypts messages using UTF-8 encoding.

The program takes 3 command line arguments:
1. a letter (e / d) to determine whether text should be encrypted or decrypted
2. a file containing text to encrypt or hexadecimal digits to decrypt
3. a name for a file to write the encrypted/decrpyted text to

The program takes the text from the file and encrypt/decrypts it. Then it writes that message to an outfile and prints it out as well.

The key I use for this cipher is imported from this website: https://medium.com/analytics-vidhya/build-your-encryption-program-in-python-in-8-min-with-this-mini-project-code-snippets-dacdf53ee581
I don't use the full key because for some of the characters the csv file was not being read properly. This code will work for a different key as long as the format
remains the same and the size is the same or smaller. For a differently sized key all that would have to change is the constant KEYSIZE in definitions.h. A key which has
hexadicimal digits which are longer or written differently would require a small change to the code but could easily be implemented.
