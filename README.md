# presetter

A 1D simplex noise generator for Max/MSP

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
cd build
cmake ..
cmake --build .
```

If you're on an M-class Mac, you'll need to codesign the presetter external:

```sh
# From the project root
codesign --force --deep -s - externals/simplexity~.mxo
```

## Support

Right now the build is only optimized for MacOS architecture. If you're a
Windows user please open an issue and we can work through building this for
your platform!
