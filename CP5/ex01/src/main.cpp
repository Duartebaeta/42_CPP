#include "../incl/Bureaucrat.hpp"
#include "../incl/Form.hpp"

int main() {
    // Test 1: Create a default Form
    std::cout << "Test 1: Creating a default Form" << std::endl;
    Form f1;
    std::cout << f1 << std::endl;

    // Test 2: Attempt to create Form with invalid grades
    std::cout << "Test 2: Creating Form with invalid grades" << std::endl;
    try {
        Form f2("InvalidForm", 0, 151);
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl << std::endl;
    }

    // Test 3: Create a Bureaucrat
    std::cout << "Test 3: Creating a Bureaucrat" << std::endl;
    Bureaucrat b1(100, "Master");
    std::cout << b1 << std::endl;

    // Test 4: Try to sign Form with Bureaucrat
    std::cout << "Test 4: Signing Form with Bureaucrat" << std::endl;
    Form f3("Form3", 100, 100);
    try {
        f3.beSigned(b1);
        std::cout << f3 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Test 5: Try to sign Form with insufficient Bureaucrat grade
    std::cout << "Test 5: Signing Form with insufficient Bureaucrat grade" << std::endl;
    Form f4("Form4", 50, 50);
    try {
        f4.beSigned(b1);
        std::cout << f4 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}