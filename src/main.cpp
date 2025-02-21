#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using std::string;

int main() {
    std::ifstream input("input.txt");

    std::ofstream output;

    output.open("output.txt", std::ofstream::out | std::ofstream::trunc);

    output << "Each sentence length: " << std::endl;

    char ch;
    int len = 0;
    int prev_len = 0;

    int cluster_score = 0;

    string punctuation = "!@#$%^&*()_+-={}[]:\";'<>,?/~`\\|1234567890";

    double sum = 0;
    double count = 0;

    while (input.get(ch)) {
        // std::cout << ch << " ";



        if(punctuation.find(ch) != string::npos) {
            continue;
        }

        if(ch == '.' || ch == '?' || ch == '!') {
            output << len << " ";
            
            cluster_score += abs(len - prev_len);
            
            prev_len = len;
            len = 0;
            count++;
            continue;
        }

        if(ch == ' ' || ch == '\n') {
            len++;
            sum++;
        }
    }

    output << "\n\nSentence statistics:\n" << "Average words per sentence: " << sum / count << "\n";
    output << "Cluster Score: " << cluster_score / count << " (above 10 means longer/shorter sentences arent clustered, below 7 means longer/shorter are clustered)";

}