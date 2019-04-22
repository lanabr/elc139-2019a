#!/bin/bash
for i in {0..10};
do
./fractal 1024 32 >> fractal102432.txt
./fractal 1024 64 >> fractal102464.txt
./fractal 512 64 >> fractal51264.txt


./fractal1 1024 32 2 >> fractal11024322.txt
./fractal1 1024 64 2 >> fractal11024642.txt
./fractal1 512 64 2 >> fractal1512642.txt

./fractal1 1024 32 4 >> fractal11024324.txt
./fractal1 1024 64 4 >> fractal11024644.txt
./fractal1 512 64 4 >> fractal1512644.txt

./fractal1 1024 32 8 >> fractal11024328.txt
./fractal1 1024 64 8 >> fractal11024648.txt
./fractal1 512 64 8 >> fractal1512648.txt


./fractal2 1024 32 2 >> fractal21024322.txt
./fractal2 1024 64 2 >> fractal21024642.txt
./fractal2 512 64 2 >> fractal2512642.txt

./fractal2 1024 32 4 >> fractal21024324.txt
./fractal2 1024 64 4 >> fractal21024644.txt
./fractal2 512 64 4 >> fractal2512644.txt

./fractal2 1024 32 8 >> fractal21024328.txt
./fractal2 1024 64 8 >> fractal21024648.txt
./fractal2 512 64 8 >> fractal2512648.txt
done
