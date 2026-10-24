#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

double predict(double x, double weight, double bias) {
  return weight * x + bias;
}

int main() {
  std::vector<double> inputs = {1, 2, 3, 4, 5};
  std::vector<double> expected = {3, 5, 7, 9, 11};

  double weight = 0.0;
  double bias = 0.0;
  double learning_rate = 0.01;

  int epoch = 1;

  while (true) {
    std::cout << "\n==============================\n";
    std::cout << " STARTING EPOCH " << epoch << "\n";
    std::cout << "Weight: " << weight << " | Bias: " << bias << "\n";
    std::cout << "==============================\n\n";

    for (int i = 0; i < inputs.size(); i++) {
      double x = inputs[i];
      double target = expected[i];

      double predicted = predict(x, weight, bias);
      double loss = pow(predicted - target, 2);

      double gradw = 2 * (predicted - target) * x;
      double gradb = 2 * (predicted - target);

      weight -= learning_rate * gradw;
      bias -= learning_rate * gradb;

      std::cout << "Item " << i + 1
                << " (x=" << x << ") -> Pred: " << predicted
                << " | Target: " << target
                << " | Loss: " << loss << "\n";
    }

    // Calculate MSE using the UPDATED parameters
    double total_loss = 0.0;

    for (int i = 0; i < inputs.size(); i++) {
      double predicted = predict(inputs[i], weight, bias);
      double error = predicted - expected[i];

      total_loss += error * error;
    }

    double mse = total_loss / inputs.size();

    std::cout << "\nEpoch " << epoch << " done!\n";
    std::cout << "Weight: " << weight << " | Bias: " << bias << "\n";
    std::cout << "MSE: " << mse << "\n";

    std::cout << "Press ENTER to run the next epoch "
                 "(or press Ctrl+C to bail): ";

    std::cin.ignore(
        std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();

    epoch++;
  }

  return 0;
}
