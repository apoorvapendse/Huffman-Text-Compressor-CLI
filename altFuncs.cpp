
// #include<iostream>
// #include<vector>
// #include<map>
// #include<unordered_map>

// using namespace std;

// // maybe used in future code
// // takes text and huffMap as input and outputs the bin string
// string encode(string para, unordered_map<char, string> huffMap){
//     // evaluating the length of compressed string;
//     int encodedLength;
//     for(auto ch:para){
//         encodedLength+=huffMap[ch].length();
//     }
//     // making char array of required length
//     string output;
//     output.reserve(encodedLength);
//     for(auto ch: para){
//         output.append(huffMap[ch]);
//     }
//     return output;
// }

// // decode takes the bin string, huffman tree and converts it to text
// vector<char> decode(node* root, string bin){
//     node* rootCopy = root;
//     int binItr = 0;
//     vector<char> decodedText;
//     while(binItr < bin.size()){
//         if(root->ch == '\0' && bin[binItr] == '0'){
//             root = root->left;
//             binItr++;
//         }
//         else if(root->ch == '\0' && bin[binItr] == '1'){
//             root = root->right;
//             binItr++;
//         }
//         else if(root->ch != '\0'){
//             decodedText.push_back(root->ch);
//             root = rootCopy;
//         }
//     }
//     decodedText.push_back(root->ch);
//     return decodedText;
// }

