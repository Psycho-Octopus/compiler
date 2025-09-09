## QUBE compiler
compiler...

Little side project, i might come back to it.

## Example
``` go
var x = 2;
return x;
```

## Build
Must have clang++, nasm and qbe installed.

``` bash
# or pacman, dnf, yum, apk ...
sudo apt update
sudo apt install clang nasm
```

For qbe:
``` bash
git clone git://c9x.me/qbe.git
cd qbe
make
sudo make install
```

then run build.sh
``` bash
bash build.sh
```
