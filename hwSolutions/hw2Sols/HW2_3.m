%%% plot figues %%%%
%%%%     N      Pi
Data = [1000,3.20800000000000;
        10000,3.14200000000000;
        100000,3.14628000000000;
        1000000,3.14114000000000;
        10000000,3.14054500000000;
        100000000,3.14102800000000];
figure(1)
semilogx(Data(:,1),Data(:,2),'bd-','MarkerSize',10, 'LineWidth', 2)
grid on
xlabel('Number of samples N','FontSize',16)
ylabel('Estimate of \pi','FontSize',16)
axis([1e3 1e8 3.1 3.3])
