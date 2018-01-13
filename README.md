# Zip Decoder

Zipdecoder is a library for converting zip codes to their state. The code here also contains a full CLI tool that can read an input text file containing zip codes and produce a file converting each of these zip codes to their given state. This is helpful for those evaluating visitors to museums or other institutions from all over the United States for demographic information. The code here is cross platform.

## Getting Started

Download all source files and directories and type make on the command line. Code is confirmed to run on Windows, built with MinGW. The makefile here supposes GNU/Linux, though. Let me know if someone wants a Windows or Mac binary or something.

## Prerequisites

There are no prerequisites. The library is self-contained. It does use a portion of the bstrings library, though this is already included. 

## Installing

Here's what you can do to get it running:
1. Download all files and folders here into a folder on your computer
2. Navigate to that folder on the command line (open a terminal window, type cd [folder])
3. Type make
4. Copy the binary produced (found in the bin/ folder) into your app path (e.g., usr/local/bin). You could also not do that and just run it wherever you copy the binary file.
5. Run zipdecode by typing ./zipdecode in the folder and it will give you specifics on command line options.

I didn't write any unit tests. 

## Deployment

See the notes above for installation. Deployment is no different than any other CLI application.

### Built With
C

## Contributing

Let me know if you have a pull request or something else: jake.kartchner@gmail.com

## Versioning

I'm not too concerned with versioning.
Authors

    Jake Kartchner

License

This project is licensed under a modified MIT License - see the LICENSE.md file for details
Acknowledgments

    Hat tip to Zed Shaw's debug macros and books
    Inspiration - my wife really wanted something to make this less tedious for her

