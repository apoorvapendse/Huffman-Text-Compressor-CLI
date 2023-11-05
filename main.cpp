#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <fstream>

#define VERSION 3.0.0

using namespace std;

class node
{
public:
    char ch;
    int freq;
    node *left;
    node *right;

    node(char c, int f, node *l, node *r)
    {
        this->ch = c;
        this->freq = f;
        this->left = l;
        this->right = r;
    }
};

// function to find char freq using map
map<char, int> charFreq(string str)
{
    // populating freqTable map
    map<char, int> freqTable;
    for (char i : str)
        freqTable[i]++;

    return freqTable;
}

// overloaded function which creates freqTable with file
map<char, int> charFreq(ifstream &text)
{
    map<char, int> freqTable;
    char ch;
    while (text.get(ch))
    {
        freqTable[ch]++;
    }

    // printing the freqTable map
    // this code should be remove afterwards
    map<char, int>::iterator it = freqTable.begin();
    ;
    while (it != freqTable.end())
    {
        cout << "Key: " << it->first << " Value: " << it->second << endl;
        ++it;
    }
    return freqTable;
}

// object to compare frequency of two nodes
// used in priority queue
class comp
{
public:
    bool operator()(node *a, node *b)
    {
        return a->freq > b->freq;
    }
};

// function to build huffman tree
node *BuildHuffTree(map<char, int> freqTable)
{
    // creating a priority queue
    priority_queue<node *, vector<node *>, comp> pq;
    for (auto pair : freqTable)
    {
        // adding nodes to priority queue in increasing order of frequency
        pq.push(new node(pair.first, pair.second, NULL, NULL));
    }

    // creating the nodes
    while (pq.size() != 1)
    {
        // left node
        node *l = pq.top();
        pq.pop();
        // right node
        node *r = pq.top();
        pq.pop();

        int sum = l->freq + r->freq;
        // pushing null character containing the sum of the left and right nodes and having the left and right nodes
        // as its children
        pq.push(new node('\0', sum, l, r));
    }

    node *root = pq.top();
    return root;
}

void inorderTraversal(node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->ch << " ";
    inorderTraversal(root->right);
}

void printSummary(int stringLength, unordered_map<char, string> &huffMap, string para)
{
    int decodedLength = stringLength * 8;
    int encodedLength = 0;
    for (auto ch : para)
    {
        encodedLength += huffMap[ch].length(); // huffMap[ch] will give corresponding huffman binary string whose len we will add to encoded data
    }
    int mapSize = 0;
    for (auto pair : huffMap)
    {
        // adding 8 for every iteration since ascii represent of every char takes 8 bits
        mapSize += 8 + pair.second.length();
        ;
    }

    cout << endl;
    cout << "Compression Performance" << endl;
    cout << "Initial length: " << decodedLength << endl;
    cout << "Encoded length: " << encodedLength << endl;
    float ratio = float(encodedLength + mapSize) / float(decodedLength);
    cout << "Map size:" << mapSize << endl;
    cout << "Size reduced to :" << ratio * 100 << "% of initial size" << endl;
    cout << "Bits saved: " << decodedLength - (mapSize + encodedLength) << endl;
}

void buildCharToBinaryMapping(node *root, string bin, unordered_map<char, string> &huffMap)
{
    if (root == NULL)
        return;

    buildCharToBinaryMapping(root->left, bin + "0", huffMap);
    if (root->ch != '\0')
    {
        cout << root->ch << " : " << bin << endl;
        huffMap[root->ch] = bin;
    }
    buildCharToBinaryMapping(root->right, bin + "1", huffMap);
}

string createEncodedString(string para, unordered_map<char, string> &HuffMap)
{
    string encoded = "";
    for (auto ch : para)
    {
        encoded += HuffMap[ch];
    }
    return encoded;
}

string createEncodedString(ifstream &text, unordered_map<char, string> &HuffMap)
{
    string encoded = "";
    char ch;
    while (text.get(ch))
    {
        encoded += HuffMap[ch];
    }
    return encoded;
}

string decodeEncodedString(string encodedStr, unordered_map<char, string> &HuffMap)
{
    string currentHuffStr = "";
    string decoded = "";
    for (auto ch : encodedStr)
    {
        currentHuffStr += ch;
        // check presence of given value to find the key in HuffMap by iterating over the map;
        for (auto pair : HuffMap)
        {
            if (pair.second == currentHuffStr)
            {
                decoded += pair.first;
                currentHuffStr = "";
            }
        }
    }
    return decoded;
}

// takes text and huffMap as input and outputs the bin string
string encode(string para, unordered_map<char, string> huffMap)
{
    // evaluating the length of compressed string;
    int encodedLength;
    for (auto ch : para)
    {
        encodedLength += huffMap[ch].length();
    }
    // making char array of required length
    string output;
    output.reserve(encodedLength);
    for (auto ch : para)
    {
        output.append(huffMap[ch]);
    }
    return output;
}

// decode takes the bin string, huffman tree and converts it to text
vector<char> decode(node *root, string bin)
{
    node *rootCopy = root;
    int binItr = 0;
    vector<char> decodedText;
    while (binItr < bin.size())
    {
        if (root->ch == '\0' && bin[binItr] == '0')
        {
            root = root->left;
            binItr++;
        }
        else if (root->ch == '\0' && bin[binItr] == '1')
        {
            root = root->right;
            binItr++;
        }
        else if (root->ch != '\0')
        {
            decodedText.push_back(root->ch);
            root = rootCopy;
        }
    }
    decodedText.push_back(root->ch);
    return decodedText;
}

// function to print binary tree on terminal
void printBT(const string& prefix, const node* ptr, bool isLeft)
{
    if(ptr != nullptr )
    {
        cout << prefix;

        cout << (isLeft ? "|--" : "L--" );

        // print the value of the ptr
        if(ptr->ch == '\0')
            cout << "\\0" << endl;
        else
            cout << ptr->ch << " " << ptr->freq << endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "|  " : "    "), ptr->left, true);
        printBT( prefix + (isLeft ? "|  " : "    "), ptr->right, false);
    }
}

void printBT(const node* node)
{
    printBT("", node, false);
}

int main(int argc, char **argv){
    // if there are insufficient parameters

    if(argc != 2){
        cout<<"usage:"<<endl;
        cout<<"./main \"file that will be compressed\""<<endl;
        return 1;
    }
    // if there are sufficient parameters

    // following block for file handling
    ifstream text;
    text.open(argv[1]);
    if (!text.is_open())
    {
        cout << "File not found." << endl;
        return 1; // Return a non-zero value to indicate an error
    }

    // creating char frequencey map and huffman tree
    map<char, int> freqTable = charFreq(text);
    node *huffRoot = BuildHuffTree(freqTable);
    cout << endl << "The generated Huffman Tree: " << endl;
    printBT(huffRoot);

    // creating huffMap from huffman tree
    cout << "Char to Bin Mapping" << endl;
    unordered_map<char, string> huffMap;
    buildCharToBinaryMapping(huffRoot, "", huffMap);
    text.close();

    text.open(argv[1]);
    string encoded = createEncodedString(text, huffMap);
    text.close();
    cout << "encoded string:\n" << encoded << endl;

    // decoding the input string
    string decoded = decodeEncodedString(encoded, huffMap);
    cout<<endl<<"Decoded string:\n"<<decoded<<endl;

    text.open(argv[1]);
    string fileContents;
    string line;
    
    while (getline(text, line)) {
        fileContents += line + '\n';
    }
    text.close();

    printSummary(fileContents.length(), huffMap, fileContents);

    return 0;

}