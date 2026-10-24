#include <iostream>
#include <vector>
#include <cmath>

double predict(double x, double weight, double bias) {
  return weight * x + bias;
}

int main() {
  // Iputs and expected outputs
  std::vector<double> inputs = {1, 2, 3, 4, 5};
  std::vector<double> expected = {3, 5, 7, 9, 11};

  // weights and biases
  double weight = 0.0;
  double bias = 0.0;

  // learning rate
  double learning_rate = 0.01;

  int epoch = 1;

  std::cout << "Weight: " << weight << std::endl;
  std::cout << "Bias: " << bias << std::endl;

  for (int i = 0; i < inputs.size(); i++) {
    double x = inputs[i];
    double target = expected[i];

    std::cout << "current input: " << x << std::endl;
    std::cout << "\n";

    double predicted = predict(x, weight, bias);

    std::cout << "Prediction: " << predicted << std::endl;
    std::cout << "\n";

    std::cout << "Expected prediction: " << target << std::endl;
    std::cout << "\n";

    double loss = pow((predicted - target), 2);
    std::cout << "Loss: " << loss << std::endl;
    std::cout << "\n";

    double gradw = 2 * (predicted - target) * x;
    double gradb = 2 * (predicted - target);

    std::cout << "Gradients: " << std::endl;

    std::cout << "Gradient weight: " << gradw << std::endl;
    std::cout << "Gradient bias: " << gradb << std::endl;

    weight = weight - learning_rate * gradw;
    bias = bias - learning_rate * gradb;

    std::cout << "\n";

    std::cout << "New weight: " << weight << std::endl;
    std::cout << "New bias: " << bias << std::endl;

    std::cout << "\n";

    std::cout << "Press ENTER to continue: ";
    std::cin.get();
    std::cout << "\n";
  }

  return 0;
}
