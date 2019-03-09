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


%(i) Average Speedup Per Process Count
ySpeedup = [1, 1.836, 3.653, 7.299, 14.323, 24.071];
xSpeedup = [1, 2, 4, 8, 16, 28];
figure;
plot(xSpeedup, ySpeedup, 'o-', 'LineWidth', 2, 'MarkerSize', 8);
ylim([1, 25]);
xlim([1, 25]);
ylabel('Average Speedup');
xlabel('Process Count');
title('Average Speedup Per Process Count');
%--------------------------------------------------------------------------


%(ii) 3D Surf Plot
z = [4.74, 35.21, 758.476, 2351.925, 6540.080;
    2.73, 22.85, 389.79, 1182.18, 3321.46;
    1.37, 11.27, 193.15, 585.77, 1748.61;
    0.72, 5.896, 99.952, 276.86, 833.002;
    0.34, 2.993, 50.96, 142.23, 451.17;
    0.21, 1.79, 29.94, 81.21, 274.78;
y = [1000, 2000, 5000, 7000, 10000;
    1000, 2000, 5000, 7000, 10000;
    1000, 2000, 5000, 7000, 10000;
    1000, 2000, 5000, 7000, 10000;
    1000, 2000, 5000, 7000, 10000];
x = [1, 1, 1, 1, 1;
    2, 2, 2, 2, 2;
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
xlabel('Process Count');
title('Time with Varying Matrix Size & Process Quantities');
%--------------------------------------------------------------------------


%(iii) 1 Process
y1 = [4.74, 35.21, 758.476, 2351.925, 6540.080];
x1 = [1000, 2000, 5000, 7000, 10000];
figure;
bar(x1, y1);
ylabel('Execution Time (s)');
xlabel('Matrix Size');
title('Execution Time vs. Matrix Size for 1 Process');
%--------------------------------------------------------------------------


%(iv) 2 Processes
y2 = [2.73, 22.85, 389.79, 1182.18, 3321.46];
x2 = [1000, 2000, 5000, 7000, 10000];
figure;
bar(x2, y2);
ylabel('Execution Time (s)');
xlabel('Matrix Size');
title('Execution Time vs. Matrix Size for 2 Processes');
%--------------------------------------------------------------------------


%(v) 4 Processes
y4 = [1.37, 11.27, 193.15, 585.77, 1748.61];
x4 = [1000, 2000, 5000, 7000, 10000];
figure;
bar(x4, y4);
ylabel('Execution Time (s)');
xlabel('Matrix Size');
title('Execution Time vs. Matrix Size for 4 Processes');
%--------------------------------------------------------------------------


%(vi) 8 Processes
y8 = [0.72, 5.896, 99.952, 276.86, 833.002];
x8 = [1000, 2000, 5000, 7000, 10000];
figure;
bar(x8, y8);
ylabel('Execution Time (s)');
xlabel('Matrix Size');
title('Execution Time vs. Matrix Size for 8 Processes');
%--------------------------------------------------------------------------


%(vii) 16 Processes
y16 = [0.34, 2.993, 50.96, 142.23, 451.17];
x16 = [1000, 2000, 5000, 7000, 10000];
figure;
bar(x16, y16);
ylabel('Execution Time (s)');
xlabel('Matrix Size');
title('Execution Time vs. Matrix Size for 16 Processes');
%--------------------------------------------------------------------------


%(viii) 28 Processes
y28 = [0.21, 1.79, 29.94, 81.21, 274.78];
x28 = [1000, 2000, 5000, 7000, 10000];
figure;
bar(x28, y28);
ylabel('Execution Time (s)');
xlabel('Matrix Size');
title('Execution Time vs. Matrix Size for 28 Processes');
%--------------------------------------------------------------------------

