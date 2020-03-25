# TSP-c2mips
This repo contains a solution of TSP in C and MIPS. I firstly solved the problem in C with dynamic programming, then manually compiled the C code to MIPS code. This project was a team project with [Hera Koo](https://github.com/khr0407) and me, [Subin Jeon](https://github.com/bsjn16sw). I made the C code then Hera made initial version of MIPS code. I debugged and wrapped up that MIPS code finally.

## Description
The goal of this project is finding a shortest tour starting from City-1 and finally returning to it, while visiting other cities only once. That is, we have to find the shortest distance and corresponding sequence of the cities visited. The number of cities and coordinates of them are hard-coded in the codes but changing them will very easy to do. Meanwhile, this problem is TSP which is also known as Travelling Salesman Problem and it is one of the most famous example of NP-hard. Plus, 'IC' which means 'Instruction Count' was also counted with `$s0` in MIPS code so check it in the code!

## Practice
You will be able to compile and execute the C code in any compiler. For MIPS code, I worked with Qt-SPIM simulator. You can download Qt-SPIM in [here](http://spimsimulator.sourceforge.net/). You can debug the MIPS code by setting breakpoints in Qt-SPIM and finally check the result of the MIPS code. If you open and simulate the MIPS code, a console will be generated like below:  
<p align="center">
<img src="/img/qtspim_console.png" alt="qtspim_console" height="60%" width="60%" align="middle">
</p>