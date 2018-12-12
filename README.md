Next is a Simulation Platform of 6Dof
From version 0.1, it is ported form Rocket Simulation in 6DOF.
The aim is to provide high fidelity of Rocket Launch and In-flight Dynamics.

# Getting Started
## 0. Clone the Repo and sub repo
```
$ git clone --recursive https://github.com/octoberskyTW/Next-simulation.git
```
## 1. Dependencies
 - GCC 5.4 up
 - Python 2.7
 - Boost Serialization
 - cpplint
```
$ sudo apt-get install htop cmake vim tree git-core libopenblas-dev libboost-dev libboost-all-dev bison curl flex python-pip
$ pip install cpplint
```

## 2. Third-Party Installation
 - NASA Trick 17.0.5
   - Official Github [NASA/trick](https://github.com/nasa/trick)
   ```
   $ sudo apt-get install bison curl flex g++ libx11-dev libxml2-dev libxt-dev \
            libmotif-common libmotif-dev make openjdk-8-jdk python2.7-dev swig \
            zlib1g-dev llvm llvm-dev clang libclang-dev libudunits2-dev
   $ cd Next-simulation/third-party/trick
   $ ./configure
   $ make
   $ sudo make install
   ```
 - Armadillo Matrix Library-9.100.6
   - [Official Github Armadillo](http://arma.sourceforge.net/)
   ```
   $ cd Next-simulation/third-party/armadillo
   $ ./configure
   $ make
   $ sudo make install
   ``` 
 - Redis Server Memory Database-5.0.2
   - [Redis Official](https://redis.io/)
   ```
   $ cd Next-simulation/third-party/redis
   $ make
   $ sudo make install
   ``` 
   - [hiredis Official](https://github.com/redis/hiredis )
   ```
   $ cd Next-simulation/third-party/hiredis
   $ make all
   $ sudo make install
   ``` 

## 3. Build and Run a SIL Simulation
```
$ cd Next-simulation/exe/SIL/master
$ ./SIL.sh
```

# Type of Simulation
These simulation as different S_defines resides in exe/ directory.
 - SIL : Software in the loop
 - PIL : Processor in the loop
 - HIL : Hardware in the loop

# Building + Running
## Golden Model
Execuate the SIL Mater+Slave
```
    cd exe/SIL/master
    ./SIL.sh
```

Execuate the PIL Master
```
    cd exe/PIL/master
    ./Deploy_EGSE_PIL.sh
```
Execuate the HIL Master
```
    cd exe/HIL/master
    ./Deploy_EGSE_HIL.sh
```

Deep Clean HIL/PIL/SIL image, object files, .csv, log
```
   ./exe/deep_clean_exe.sh
```
# Install The redis
```
cd third-party/redis
tar -zxvf redis-*.tar.gz -C ./
cd redis-*/src
make && make install
```

# Tests

## Automative testing
A auto-testing is preset and should be run every time change is applied.
To run, at simulation root, issue:
```
    ./SIL.sh
```
which will build, execute and compare against golden data.
Result will be displayed on screen.

The testing is based on average result relative error against golden data < 1E-5


# Support Hardware List
### GNSS 9000 Constellation Simulator (HIL Support)
- [Spirent GSS9000 Official Site](https://www.spirent.com/products/gss9000)

![ ](https://github.com/octoberskyTW/Next-simulation/blob/master/docs/docs_hardware/simgen/simgen_GSS9000.png)

### iXBlue EVO30 Ratetable (HIL Support)
- https://www.ixblue.com/products/evo-30

[![ ](https://github.com/octoberskyTW/Next-simulation/blob/master/docs/docs_hardware/iXblue/EVO30L-3Axis-motion-Simulator.png)](https://www.youtube.com/watch?v=-xfvyl8rP8U)
## Component Diagram
The UML of rocket components is in ./docs/Rocket.mdj
Please use 'StarUML' to view it

## Component Topology
With graphviz installed
```
cd docs
dot topology.dot -Tpng > topology.png
```
Then you can use a typical image viewer to view it.
