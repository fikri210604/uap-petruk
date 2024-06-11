#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

std::vector<int> readDataFromFile(const std::string& filename) {
  std::ifstream file(filename);
  std::vector<int> data;
  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) {
        data.push_back(std::stoi(line));
    }
    file.close();
  } else {
    std::cerr << "Error opening file: " << filename << std::endl;
  }
  return data;
}

std::vector<int> merge(const std::vector<int>& left, const std::vector<int>& right) {
    std::vector<int> merged;
    int i = 0, j = 0;
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            merged.push_back(left[i++]);
        } else {
            merged.push_back(right[j++]);
        }
    }
    while(i < left.size()) {
        merged.push_back(left[i]);
        i++;
    }
    while(j < right.size()) {
        merged.push_back(right[j]);
        j++;
    }
    return merged;
}

std::vector<int> divide(std::vector<int>& data) {
    if (data.size() == 1) {
        return data;
    }
    int mid = data.size() / 2;
    std::vector<int> left(data.begin(), data.begin() + mid);
    std::vector<int> right(data.begin() + mid, data.end());
    left = divide(left);
    right = divide(right);
    return merge(left, right);
}

int main() {
    std::string filename = "./Function/Data/HasilParkir.txt"; // Replace with your text file name
    std::vector<int> data = readDataFromFile(filename);

    std::cout << "Unsorted data: ";
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    data = divide(data);

    std::cout << "Sorted data: ";
    std::stack<int> stack;
    for (int num : data) {
        stack.push(num);
    }
    while (!stack.empty()) {
        std::cout << stack.top() << " ";
        stack.pop();
    }
    std::cout << std::endl;

    return 0;
}
