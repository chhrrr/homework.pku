/*
 * * @Author: 成贺睿, 1201220667
 * * @Description: 将input文件中的单词按出现次数由低到高输出
 * *
 */
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main (void) {
    //<单词，次数>map
    map<string, int> word_count;
    map<int, string> count_word;
    string word;
    //该排除的标点
    string punctuation ("-,.?~!*&^%#@");
    ifstream input;

    input.open("./input");
    if(!input) {
        cerr << "This file doesn't exist!" << endl;
        return -1;
    }

    //将单词排除标点后，统计次数
    while(input >> word) {
        string::size_type found = word.find_last_not_of(punctuation);
        if (found != string::npos) {
            word.erase(found+1);
        }
        ++word_count[word];
    }

    map<string, int>::iterator one = word_count.begin();
    while(one != word_count.end()) {
        string te = count_word[one->second];
        if(te != "") {
            count_word[one->second] = count_word[one->second].append(",");
            count_word[one->second] = count_word[one->second].append(one->first);
        } else {
            count_word[one->second] = one->first;
        }
        ++one;
    }

    cout << "COUNT\tWORD" << endl;

    map<int, string>::iterator two = count_word.begin();
    while(two != count_word.end()) {
        cout << two->first << "\t" << two->second << endl;
        ++two;
    }

    return 0;
}
