#include "../incl/easyfind.hpp"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
    std::list<int> lst(arr, arr + sizeof(arr) / sizeof(int));

    try {
        std::vector<int>::iterator itVec = easyfind(vec, 3);
        std::cout << "Element found in vector: " << *itVec << std::endl;

        std::list<int>::iterator itList = easyfind(lst, 2);
        std::cout << "Element found in list: " << *itList << std::endl;
        
        // This will throw an exception
        std::vector<int>::iterator itVecFail = easyfind(vec, 6);
        std::cout << "Element found in vector: " << *itVecFail << std::endl;
    } catch(const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
