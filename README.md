# GIICIS ![logo](./GIICIS.png "GIICIS Logo") 
Main repository for GIICIS

## Prerequisites
- ParadisEO-2.0. 
    
    The best way to make it work is [downloading sources](http://paradiseo.gforge.inria.fr/index.php?n=Download.Download), compiling and installing (Doxygen and lcov required). 
    
    Follow instructions in INSTALL file (cmake, make, make install).
    
    In some cases cmake doesn't find doxygen. Commenting `include(FindDoxygen OPTIONAL)` must do the magic.
     
- Boost.Test
    
    In Debian-derived distros `sudo apt install libboost-test-dev` 