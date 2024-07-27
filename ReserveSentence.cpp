#include <iostream>
#include <algorithm>
using namespace std;
int main() {
//initalize variables, get sentence
string sentence;
string reversed;
string word;
cout << "Enter your sentence:" << endl;
getline(cin, sentence);
//remove dot from sentence
sentence.erase(remove(sentence.begin(), sentence.end(), '.'), sentence.end());
//iterate through the sentence, separate words, and reverse them
for (int i = sentence.length() - 1; i >= 0; i--) {
if (sentence[i] != ' ') {
word = sentence[i] + word;
} else {
reversed.append(word + ' ');
word = "";
}
}
//add the last word
reversed.append(word);
//print sentence, add dot back
cout << "Your sentence with reversed words is: " << reversed << "."<< endl;
return 0;
}
