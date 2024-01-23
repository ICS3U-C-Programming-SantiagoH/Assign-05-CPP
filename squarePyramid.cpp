// Copyright (c) 2023 Santiago Hewett All rights reserved.
// Created by: Santiago Hewett
// Date: Dec 11, 2023
// This program will ask for the base edge
// and height of a square-based pyramid
// then it will calculate the surface area
// and ask if they want to run it again

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

// Function to get positive float input from the user
double get_positive_float(const std::string &prompt) {
    double input;
    std::string userInputStr;
    bool validInput = false;

    while (!validInput) {
        // Display the prompt and get user input
        std::cout << prompt;
        std::cin >> userInputStr;

        // Use a stringstream to convert string to double
        std::stringstream ss(userInputStr);
        ss >> input;

        // Validate the input
        if (std::cin.fail() || input <= 0) {
            std::cout << "Invalid input. Please enter a positive decimal";
            std::cout << "number.\n ";

            // Clear the input buffer to handle invalid input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            validInput = true;
        }
    }

    return input;
}

// Function to calculate the surface area of a square pyramid
double calc_surface_area(double base_edge, double height) {
    // Calculate the surface area of the square pyramid
    double calc_surface_area = std::pow(base_edge, 2) + base_edge * 2 *
    std::sqrt(std::pow(base_edge, 2) / 4 + std::pow(height, 2));
    return calc_surface_area;
}

int main() {
    // Declare variables
    double userBaseEdgeDouble, userHeightDouble, surface_area;
    std::string userDecision;

    // Loop to continue if the user wants
    do {
        // Get valid input for base edge and height
        userBaseEdgeDouble = get_positive_float("Enter the base edge of the square pyramid: ");
        userHeightDouble = get_positive_float("Enter the height of the square pyramid: ");

        // Call the function to calculate surface area
        surface_area = calc_surface_area(userBaseEdgeDouble, userHeightDouble);

        // Display the calculated surface area
        std::cout << "\nThe surface area of the square pyramid is: " 
        << std::fixed << std::setprecision(2) << surface_area << std::endl;

        // Ask if the user wants to continue
        std::cout << "\nDo you want to calculate for another square based pyramid? (y/n): ";
        std::cin >> userDecision;

    } while (userDecision == "y" || userDecision == "Y");

    return 0;
}
