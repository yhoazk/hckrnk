%% In branch test comment for testing


%% Animate Barker code
%bark = = [1 1 1 1 1 -1 -1 1 1 -1 1 -1 1 1 1 1 1 1 -1 -1 1 1 -1 +1 -1 +1 +1 +1 +1 +1 +1 -1 -1 +1 +1 -1 +1 +1 -1 -1 -1 -1 -1 +1 +1 -1 -1 +1 -1 +1 -1 +1 +1 +1 +1 +1 -1 -1 +1 +1 -1 +1 -1 +1]
bark = [+1 +1 +1 +1 +1 -1 -1 +1 +1 -1 +1 -1 +1 +1 +1 +1 +1 +1 -1 -1 +1 +1 -1 +1 -1 +1 +1 +1 +1 +1 +1 -1 -1 +1 +1 -1 +1 +1 -1 -1 -1 -1 -1 +1 +1 -1 -1 +1 -1 +1 -1 +1 +1 +1 +1 +1 -1 -1 +1 +1 -1 +1 -1 +1]

for j = -0.5*(size(bark)(2)):0.5* (size(bark)(2));
  v(j+33) = corr(bark, circshift(bark,[0,j]));
  %display(v);
endfor
plot(v)
sleep(2)
% Animation example:
t = 0:0.1:10*pi;
r = linspace (0, 1, numel (t));
z = linspace (0, 1, numel (t));

figure
axis([-1 1 -1 1 0 1])
hold on

for ii=1:length(r)
    plot3 (r(ii)*sin(t(ii)), r(ii)*cos(t(ii)), z(ii),'*');
    pause (.001)
end

pause (3)
%% Continuous trajectory
delay = 0.001  % seconds
figure
comet3(r.*sin(t), r.*cos(t), z, delay);
% plot the first point to get started
h = plot3(x(1),y(1),z(1),"b");
axis([min(x), max(x), min(y), max(y), min(z), max(z)]);

% refresh the plot in a loop through the rest of the data
for k = 1:length(z);
   set(h, 'XData', x(1:k));
   set(h, 'YData', y(1:k));
   set(h, 'ZData', z(1:k));
   pause (0.001); % delay in seconds
       % alternatively could provide a velocity function
       % pause(sqrt(vx(k)^2+vy(k)^2+vz(k)^2));  
endfor

