Linhas executadas para gerar as imagens para fazer os gifs (no cygwin)

```
./fractaparl 256 32

./fractalpar1 256 32 2
./fractalpar1 256 32 4
./fractalpar1 256 32 8

./fractalpar2 256 32 2
./fractalpar2 256 32 4
./fractalpar2 256 32 8
```

Linhas executadas para gerar os gifs (no terminal do Windows). Cada um foi feito 
separadamente, uma execução no cygwin e outra no terminal do Windows.

```
magick -delay 1x10 fractal1*.bmp fractal.gif

magick -delay 1x10 fractal1*.bmp fractalpar12.gif
magick -delay 1x10 fractal1*.bmp fractalpar14.gif
magick -delay 1x10 fractal1*.bmp fractalpar18.gif

magick -delay 1x10 fractal1*.bmp fractalpar22.gif
magick -delay 1x10 fractal1*.bmp fractalpar24.gif
magick -delay 1x10 fractal1*.bmp fractalpar28.gif
```
