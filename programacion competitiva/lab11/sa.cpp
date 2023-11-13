#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store the suffix and its corresponding index
struct Suffix {
    int index;
    string suffix;
};

// Comparison function to sort the suffixes
bool compareSuffixes(const Suffix& a, const Suffix& b) {
    return a.suffix < b.suffix;
}

// Function to construct the suffix array
vector<int> constructSuffixArray(const string& text) {
    int n = text.length();
    vector<Suffix> suffixes(n);

    // Create suffixes and their indexes
    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].suffix = text.substr(i);
    }

    // Sort the suffixes using the comparison function
    sort(suffixes.begin(), suffixes.end(), compareSuffixes);

    // Store the indexes of sorted suffixes in the suffix array
    vector<int> suffixArray(n);
    for (int i = 0; i < n; i++) {
        suffixArray[i] = suffixes[i].index;
    }

    return suffixArray;
}

// Function to print the suffix array
void printSuffixArray(const vector<int>& suffixArray) {
    int n = suffixArray.size();
    for (int i = 0; i < n; i++) {
        cout << suffixArray[i] << " ";
    }
    cout << endl;
}

int main() {
    string text = "banana";
    vector<int> suffixArray = constructSuffixArray(text);
    printSuffixArray(suffixArray);

    return 0;
}
