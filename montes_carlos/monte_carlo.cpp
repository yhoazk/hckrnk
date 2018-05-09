/* Implementation of the Monte Carlo methods
  The example will integrate the function
  y = x^2 in [2,8]
*/

#include <iostream>
#include <cmath>
#include <random>

#define N_SAMPLES (500)

std::default_random_engine def_eng;
std::gamma_distribution<double> uniform_dist(0.0, 1.0);

double fnc(double x)
{
  return x*x;
}

double rand_range(double a, double b)
{
  return (uniform_dist(def_eng) * (b - a)) + a;
}
double crude()
{
  double result = {0};

  for (size_t i = 0; i < N_SAMPLES; i++) {
    result += fnc(rand());
  }

  return result;
}

double acceptance_rejection()
{
  double result = {0};
  return result;
}

double stratified()
{
  double result = {0};
  return result;
}

double importance_sampling()
{
  double result = {0};
  return result;
}

double reference()
{
  double result = {0};
  return result;
}
int main(int argc, char const *argv[]) {
  std::cout << "Results: " << crude() << std::endl;
  std::cout << rand_range(1, 5) << std::endl;
  std::cout << rand_range(1, 5) << std::endl;
  std::cout << rand_range(1, 5) << std::endl;
  std::cout << rand_range(1, 5) << std::endl;
  std::cout << rand_range(1, 5) << std::endl;
  std::cout << rand_range(1, 5) << std::endl;
  std::cout << rand_range(1, 5) << std::endl;
  std::cout << rand_range(1, 5) << std::endl;
  std::cout << rand_range(1, 5) << std::endl;
  std::cout << rand_range(1, 5) << std::endl;
  std::cout << rand_range(1, 5) << std::endl;
  std::cout << rand_range(1, 5) << std::endl;
  std::cout << rand_range(1, 5) << std::endl;
  std::cout << rand_range(1, 5) << std::endl;
  std::cout << rand_range(1, 5) << std::endl;
  std::cout << rand_range(1, 5) << std::endl;
  std::cout << rand_range(1, 5) << std::endl;
  std::cout << rand_range(1, 5) << std::endl;
  std::cout << rand_range(1, 5) << std::endl;
  return 0;
}
