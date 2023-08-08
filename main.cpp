#include <iostream>
#include <map>
#include <queue>

/*
    Todo:
        get char freq - done
        build huff tree
        write encode function
*/

using namespace std;

class node{
    public:
    char ch;
    int freq;
    node* left;
    node* right;

    node(char c, int f, node* l, node* r){
        this->ch = c;
        this->freq = f;
        this->left = l;
        this->right = r;
    }
};

// function to find char freq using map
map<char, int> charFreq(string str){
    // populating freqTable map
    map<char, int> freqTable;
    for(char i : str)
        freqTable[i]++;

    // printing the freqTable map
    // this code should be remove afterwards
    map<char, int>:: iterator it = freqTable.begin();;
    while (it != freqTable.end()){
        cout << "Key: " << it->first << " Value: " << it->second << std::endl;
        ++it;
    }
    
    return freqTable;
}

// object to compare frequency of two nodes
// used in priority queue
class comp{
    public:
    bool operator()(node* a, node* b){
        return a->freq > b->freq;
    }
};

// function to build huffman tree
node* BuildHuffTree(map<char, int> freqTable){
    // creating a priority queue
    priority_queue<node*, vector<node*>, comp> pq;
    // wtf is auto??
    for(auto pair: freqTable){
        pq.push(new node(pair.first, pair.second, NULL, NULL));
    }

    // creating the nodes
    while(pq.size() != 1){
        node* l = pq.top();
        pq.pop();
        node* r = pq.top();
        pq.pop();

        int sum = l->freq + r->freq;
        pq.push(new node('\0', sum, l, r));
    }

    node* root = pq.top();
    return root;
}

int main(){
    // string para = string("linus benedict torvalds is a finnish software engineer who is the creator and, historically, the lead developer of the linux kernel, used by linux distributions and other operating systems such as android. he also created the distributed version control system git");

    string para = string("aaaaabbbcc");
    map<char, int> freqTable = charFreq(para);

    node* huffRoot = BuildHuffTree(freqTable);

    // a bug in tree that needs to be solved
}