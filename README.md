# ToyMFE

### v1
* This is the original version of the program

### mod2
* Memory allocation reduced from `N^2` to `2N`
* Memory macro modified so that `T(i,j)` maps to `T[(i)%2][j]`

### Nmem
* Memory allocation reduced from `2N` to `N`
* Memory macro modified so that `T(i,j)` maps to `T[-(i)+j]`

### tile
* Tiles the main computation loops
