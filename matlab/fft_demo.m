fs = 10;
t = 0:1/fs:20; % n time for sample
y = sin(1.8*2*pi*t) + sin(2.1*2*pi*t); % The signal
plot(t,y);
yfft = fft(y);
n = numel(y); % number of elements
f = 0:fs/n:fs*(n-1)/n; % Freq corresponding to values in yfft
plot(f, abs(yfft)) % plot the fourier


% Notice the two spikes on the left side of the plot which correspond to the 
% frequencies of the two sine waves you created earlier. Since the spikes are
% close together, the signal exhibits the beat phenomenon.
% Why are there four spikes? That relates to the Nyquist frequency, which in
% this case is 5 (or fs/2). When the input vector consists of real numbers, the
% fft function always returns data whose magnitude is symmetric about the
% Nyquist frequency. That is, the second half of the plot (after the Nyquist
% frequency) is just a mirror image of the first half.
