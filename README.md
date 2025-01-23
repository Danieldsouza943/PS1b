# PS1b: Image Encryption/Decryption through LFSR
## Contact
Name: Daniel Dsouza
Section: 201
Time to Complete: about 5 and half hours

## Description
The aim of this project is to use FibLFSR to create a program that can encrypt and decrypt images using a bitwise XOR operation. The program reads a source image, encrypts it using the provided binary seed for the LFSR, and displays both the original and encrypted images using the SFML library. It also allows decryption when the same seed is used on an encrypted image.

### Features
For this project I used a string representation as I have prior experience using strings to represent and manipulate numbers, therefore, using a string representation made it way easier for me to implement the functionality needed for this project.

### Issues
Currently the only issues I have faced is when trying to run the program through VSCode, while the program is running VSCode shows a distorted version of both the original and the encrypted image, however, once the images were saved to the disc and opened they are no longer distorted. There is no issue when running the program directly through WSL terminal.

### Tests
I have also implemented a test that checks if the overloaded operator correctly outputs the number to the screen, and another test that checks if the constructor initializes the member data properly. For the second part of the project I included a test that creates a white image and then checks that after using the transform function with a seed of 1011 all the color values for the pixels are no longer 255.

### Extra Credit
Anything special you did. This is required to earn bonus points.

## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.

Youtube.com
StackOverflow.com
