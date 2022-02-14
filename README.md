# title

... creates executable scripts for games using proton. Simply pass the path to game into the program and it will generate an executable script that will run the game through proton with some commonly used flags.

Note that some games will not work out of the box and will require some tinkering.

## Configuration

All configuration is done through the config.h file. All the macros have the same name as the variable they are setting making it easy to look up what each one does.

## Building 

Simply run
```console
make install
```

## Notes

This is just a template generator. Most games I've tested have worked out of the box but there are edge cases! 
