#include <iostream>
#include <map>
#include <queue>
#include<unordered_map>

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
        //adding nodes to priority queue in increasing order of frequency
        pq.push(new node(pair.first, pair.second, NULL, NULL));
    }

    // creating the nodes
    while(pq.size() != 1){
        //left node 
        node* l = pq.top();
        pq.pop();
        //right node
        node* r = pq.top();
        pq.pop();

        int sum = l->freq + r->freq;
        //pushing null character containing the sum of the left and right nodes and having the left and right nodes
        //as its children
        pq.push(new node('\0', sum, l, r));
    }

    node* root = pq.top();
    return root;
}

void inorderTraversal(node* root){
     if(root==NULL)return;
     inorderTraversal(root->left);
     cout<<root->ch<<" ";
     inorderTraversal(root->right);

}

void printSummary(int stringLength,unordered_map<char,string> &huffMap,string para){
    int decodedLength = stringLength * 8;
    int encodedLength = 0;
    for(auto ch:para){
        encodedLength+=huffMap[ch].length();//huffMap[ch] will give corresponding huffman binary string whose len we will add to encoded data

    }
    int mapSize = 0;
    for(auto pair:huffMap){
       //adding 8 for every iteration since ascii represn of every char takes 8 bits
        mapSize +=   8+pair.second.length();;
    }
    
    cout<<endl;
    cout<<"initial length:"<<decodedLength<<endl;
    cout<<"encoded length:"<<encodedLength<<endl;
    float ratio = float(encodedLength+mapSize)/float(decodedLength);
    cout<<"map size:"<<mapSize<<endl;
    cout<<"size reduced to :"<<ratio*100<<"%"<<endl;
    cout<<"bits saved:"<<decodedLength-(mapSize+encodedLength)<<endl;

}

void buildCharToBinaryMapping(node* root, string bin,unordered_map<char,string> &huffMap) {
    if (root == NULL) return;
  
    buildCharToBinaryMapping(root->left, bin + "0",huffMap);
    //jar current node cha character not equal to MrRightNa, then add it to the map along with its huffman bin reprsn
    if(root->ch!='\0'){

    cout << root->ch << " : " << bin << endl;
    huffMap[root->ch] = bin;

    }
    buildCharToBinaryMapping(root->right, bin + "1",huffMap);
}

string createEncodedString(string para, unordered_map<char,string>&HuffMap){
    string encoded = "";
    for(auto ch: para){
        encoded +=HuffMap[ch];
    }
    
    return encoded;


}

string decodeEncodedString(string encodedStr,unordered_map<char,string>&HuffMap){
    string currentHuffStr = "";
    string decoded = "";
    for(auto ch:encodedStr){
        currentHuffStr+=ch;
        //check presence of given value to find the key in HuffMap by iterating over the map;
        for(auto pair:HuffMap){
            if(pair.second == currentHuffStr){
                decoded +=pair.first;
                currentHuffStr = "";//reset currentHuffString karan key sapadli
            }
        }
    }
    return decoded;

}


int main(){
    // string para = string("linus benedict torvalds is a finnish software engineer who is the creator and, historically, the lead developer of the linux kernel, used by linux distributions and other operating systems such as android. he also created the distributed version control system git");

    string para ;
    cout<<"Enter the string you want to encode and decode"<<endl;
    cin>>para;
    map<char, int> freqTable = charFreq(para);

    node* huffRoot = BuildHuffTree(freqTable);
   
    unordered_map<char,string> huffMap;
    //huffMap will store the mapping of character to its corresponding huffman code;
    cout<<"\nhuffman tree mapping:"<<endl;
    buildCharToBinaryMapping(huffRoot,"",huffMap);

    printSummary(para.length(),huffMap,para);




   string encoded =  createEncodedString(para,huffMap);
   cout<<endl<<"encoded string:"<<encoded<<endl;
   string decoded = decodeEncodedString(encoded,huffMap);
   cout<<endl<<"decoded string:"<<decoded<<endl;
}