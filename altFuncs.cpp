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

/*
alt main function
can reuse this after huffMap is stored in a text file
int main(int argc, char** argv){
    // string para = string("linus benedict torvalds is a finnish software engineer who is the creator and, historically, the lead developer of the linux kernel, used by linux distributions and other operating systems such as android. he also created the distributed version control system git");

    // if there are insufficient parameters
    if(argc != 3){
        cout<<"usage:"<<endl;
        cout<<"./main -parameter \"text that will be compressed\""<<endl;
        cout<<"parameters:\n\t-e : encode given text string\n\t-d : decode given bin string"<<endl;
        return 1;
    }
    // if there are sufficient parameters
    else{
        string input = argv[2];
    
        if(!(argv[1] == "-e")){
            map<char, int> freqTable = charFreq(input);
            node* huffRoot = BuildHuffTree(freqTable);

            cout<<"\nhuffman tree mapping:"<<endl;
            unordered_map<char,string> huffMap;
            buildCharToBinaryMapping(huffRoot,"",huffMap);

            printSummary(input.length(),huffMap,input);

            string encoded =  createEncodedString(input,huffMap);
            cout<<endl<<"encoded string:"<<encoded<<endl;
        }
        else if(!(argv[1] == "-d")){
            // unordered_map<char,string> huffMap;
            // buildCharToBinaryMapping(huffRoot,"",huffMap);
            // string decoded = decodeEncodedString(input,huffMap);
            // cout<<endl<<"decoded string:"<<decoded<<endl;
        
        }
    }
    return 0;
}
*/