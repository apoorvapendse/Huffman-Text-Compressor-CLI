#include <iostream>
#include <map>

using namespace std;

class node{
    public:
    char ch;
    int freq;
    node* left;
    node* right;
};

map<char, int> charFreq(string str){
    map<char, int> freqTable;
    for(char i : str)
        freqTable[i]++;

    map<char, int>:: iterator it = freqTable.begin();;
    while (it != freqTable.end()){
        cout << "Key: " << it->first << " Value: " << it->second << std::endl;
        ++it;
    }
    
    return freqTable;
}

int main(){
    // char para[] = "linus benedict torvalds is a finnish software engineer who is the creator and historically the lead developer of the linux kernel used by linux distributions and other operating systems such as android he also created the distributed version control system git";
    string para = string("linus benedict torvalds is a finnish software engineer who is the creator and, historically, the lead developer of the linux kernel, used by linux distributions and other operating systems such as android. he also created the distributed version control system git");

    map<char, int> freqTable = charFreq(para);

}