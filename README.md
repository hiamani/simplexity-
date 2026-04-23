# simplexity~

A 1D simplex noise generator for Max/MSP.

## Build

First clone the repository along with submodules:

```sh
cd /path/to/Max\ 9/Packages/
# HTTP
git clone https://github.com/hiamani/simplexity.git --recursive
# SSH
git clone git@github.com:hiamani/simplexity.git --recursive
```

Then build:

```sh
mkdir build
cd build
cmake ..
cmake --build .
```

If you're on an M-class Mac, you'll need to codesign the simplexity~ external:

```sh
# From the project root
codesign --force --deep -s - externals/simplexity~.mxo
```

## Support

Right now the build is only optimized for MacOS architecture. If you're a
Windows user please open an issue and we can work through building this for
your platform!

## Attributes

```

@seed    <number>: A number that changes the base of the hashing algorithm.
@octaves <number>: The number of octaves; the default is 1. Adding more than
                   one octave enables lacunarity and persistence inputs. Adding
                   more octaves increases CPU load!
@hashfn  <enum>:   Which hashing function to use. Default is 0 (pearson), which
                   is incredibly pseudo-random, but expensive. Pass 1 to use the
                   "Moremur" hash, which is more performant, but less "random".
```

Real documentation (.maxhelp files) coming soon!
