# AGasket_Dimension

Compile using:

gcc -o apollonianGasketN2 -O3 -ffast-math -lm apollonianGasketN2.c

Run it on various parameters. An Example:

echo -1 2 2 3 | ./apollonianGasketN2 -b 2 -e 1 -a 1 -b 15

where (-1,2,2,3) are the radii of the four circles (-1 being the largest that encloses the other three).


Returns

n[i] = number of disks smaller than k[i] = (b^e)^i for a <= i <= b.

