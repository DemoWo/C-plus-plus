#include <iostream>
#include <vector>

int check_masFirst (int index, int res, std::vector<int> vec) {
    int end = 0;
    for (int i = index; i < vec.size() - 1; ++i) {
        res = vec[i] + vec[i + 1];
        if (res > end) {
            index = i;
            end = res;
        }
    }
    return index;
}

int check_masSecond (int index, int res, std::vector<int> vec) {
    int end = 0;
    for (int i = index + 1; i < vec.size() - 1; ++i) {
        if (res > end) {
            index = i + 1;
            end = res;
        } else {
            res = vec[i] + vec[i + 1];
        }
    }
    return index;
}

int main() {
    std::vector <int> vec {-2,1,-3,4,-1,2,1,-5,4};
    // -2,-1,-3,4,-9,2,7,-5,9   5.8  -2,1,-3,4,-1,2,1,-5,4  3.6
    int indFirst = 0;
    int indSecond;
    int start = 0;
    int end = 0;

    indFirst = check_masFirst(indFirst,start, vec);
    indSecond = check_masSecond(indFirst,end, vec);

    std::cout << "First index: " << indFirst << std::endl;
    std::cout << "Second index: " << indSecond << std::endl;

    return 0;
}