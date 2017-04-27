# cb-pepperspot
This is my personnal version of pepperspot

## Installing

Clone the repository

```
git clone git@github.com:borellyc/cb-pepperspot.git
cd cb-pepperspot
```

Then use autotools and automake to build the program:

```
autoreconf -vfi
./configure
make
sudo make install
```

You may enable verbose build with:

```
...
make V=1
```
