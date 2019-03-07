%JONATHAN ALEXANDER GIBSON
%CSC 6740
%PARALLEL DISTRIBUTED ALGORITHMS
%DR. GHAFOOR
%PROGRAM 4 (MPI MATRIX MULTIPLICATION)


clear %clear all saved variable values
clc %clear the command window
close all %close all figures
format long %long variable format
%--------------------------------------------------------------------------


%(i) Average Speedup Per Thread Count
ySpeedup = [1, 5.661, 10.204, 16.9, 33.4];
xSpeedup = [1, 4, 8, 16, 28];
figure;
plot(xSpeedup, ySpeedup, 'o-', 'LineWidth', 2, 'MarkerSize',8);
ylim([1, 34]);
xlim([1, 34]);
ylabel('Average Speedup');
xlabel('Thread Count');
title('Average Speedup Per Thread Count');
%--------------------------------------------------------------------------


%(ii) 3D Surf Plot
z = [5.26, 67.96, 1467.38, 3114.345, 12619.75;
    1.05, 13.46, 224.21, 641.642, 1846.92;
    0.564, 5.32, 136.97, 361.28, 1316.34;
    0.46, 3.91, 61.5, 225, 698;
    0.266, 1.91, 37.44, 94.43, 318.72];
y = [1000, 2000, 5000, 7000, 10000;
    1000, 2000, 5000, 7000, 10000;
    1000, 2000, 5000, 7000, 10000;
    1000, 2000, 5000, 7000, 10000;
    1000, 2000, 5000, 7000, 10000];
x = [1, 1, 1, 1, 1;
    4, 4, 4, 4, 4;
    8, 8, 8, 8, 8;
    16, 16, 16, 16, 16;
    28, 28, 28, 28, 28];
figure;
surf(x, y, z);
ylim([1000, 10000]);
xlim([1, 28]);
zlabel('Average Execution Time (s)');
ylabel('Matrix Size');
xlabel('Thread Count');
title('Time with Varying Matrix Size & Thread Quantities');
%--------------------------------------------------------------------------

%(iii) 
y1 = [5.26, 67.96, 1467.38, 3114.345, 12619.75];
x1 = [1000, 2000, 5000, 7000, 10000];
figure;
bar(x1, y1);
ylabel('Execution Time (s)');
xlabel('Matrix Size');
title('Execution Time vs. Matrix Size for 1 Thread');
%--------------------------------------------------------------------------


%(iv) 
y4 = [1.05, 13.46, 224.21, 641.642, 1846.92];
x4 = [1000, 2000, 5000, 7000, 10000];
figure;
bar(x4, y4);
ylabel('Execution Time (s)');
xlabel('Matrix Size');
title('Execution Time vs. Matrix Size for 4 Threads');
%--------------------------------------------------------------------------


%(v) 
y8 = [0.564, 5.32, 136.97, 361.28, 1316.34];
x8 = [1000, 2000, 5000, 7000, 10000];
figure;
bar(x8, y8);
ylabel('Execution Time (s)');
xlabel('Matrix Size');
title('Execution Time vs. Matrix Size for 8 Threads');
%--------------------------------------------------------------------------


%(vi) 
y16 = [0.46, 3.91, 61.5, 225, 698];
x16 = [1000, 2000, 5000, 7000, 10000];
figure;
bar(x16, y16);
ylabel('Execution Time (s)');
xlabel('Matrix Size');
title('Execution Time vs. Matrix Size for 16 Threads');
%--------------------------------------------------------------------------


%(vii) 
y28 = [0.266, 1.91, 37.44, 94.43, 318.72];
x28 = [1000, 2000, 5000, 7000, 10000];
figure;
bar(x28, y28);
ylabel('Execution Time (s)');
xlabel('Matrix Size');
title('Execution Time vs. Matrix Size for 28 Threads');
%--------------------------------------------------------------------------

