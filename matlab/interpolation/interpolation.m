%% Basic methods of interpolation

% Given the picewise interpolation f1 choose the function
% which behaves as cuadratic in (1,2] and as cubic in the
% range (2, 3]
close all;
clear all;
% original interpolation
f1=@(x) x.*(x>1).*(x<=2)+(6-x.^2).*(x>2).*(x<=3)
x0 = 1:0.1:3;
hold on;

opt1=@(x) x.*x.*(x>1).*(x<=2)+(4-x.^3).*(x>2).*(x<=3) 
opt2=@(x) x.*(x>1).*(x<=2)+(6-x.^3).*(x>2).*(x<=3) 
opt3=@(x) x.*x.*(x>1).*(x<=2)+(12-x.^3).*(x>2).*(x<=3)
opt4=@(x) x.*x.*(x>1).*(x<=2)+(6-x.^3).*(x>2).*(x<=3) 
plot(x0, opt1(x0), 'k-*') % This eq has a discontinuity in 2
plot(x0, opt2(x0), 'r--*') % this one does not behaves cuadratically 
plot(x0, opt3(x0), 'b-+') % this is the correct one as is continuous
plot(x0, opt4(x0), 'r-o') % discarded as it is discontinuous
plot(x0, f1(x0), 'b') % also discontinuous


%% Interpolation vs regression
% Regression allows error in the points, interolation passes
% exaclty through the sample points. Both can be picewise defined

% array logical operation

f=@(x) sin(x);
x_bar=0:0.55:2.75;
fs=f(x_bar);
If=@(x) fs(find(x_bar<x,1,'last')); % here the x_bar < x returns the array of bool values which satisfy that condition 
% the function find with this options will return the index of the last
% element which satisfies the condition

%%

h=0.221
x_bar=1.1:h:1.1+5*h;
fs=f(x_bar);
plot(x_bar,f(x_bar),'ro')
If=@(x) interp1(x_bar,fs,x,'previous');
abs(f(1.45)-If(1.45)) 


% When in the picewise-constant, left endpoint interpolation, which has an error O(h)
% this means that the log of interpolation error decreases linerarly with slope of -1
% with respect to log(1/h)

% For picewise-linear the error or O(h^2), which means that the error decreases with a
% slope of -2 with respect to log(1/h)

% For picewise-quadratic the error is O(h^3)
% The quadratic uses the larange basis functions and has the property of being 
% continuous in the first derivative in the joints
%% Larange Basis Functions

% Larange polynomial


%% Slpines



%% Cubic Hermite Basis

% hermite allows to define the values at the point and the value of the 
% derivative there at the begining of the segment and the end too.