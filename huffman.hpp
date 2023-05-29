#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP
#include <string>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

//Defining Huffman Tree Node
struct TreeNode {
    char data;
    unsigned freq;
    string code;
    TreeNode *left, *right;

    TreeNode() {
        left = right = NULL;
    }
};

class huffman {
    private:
        vector <TreeNode*> arr;

        fstream inputFile, outputFile;

        string inputFileName, outputFileName;
        
        TreeNode *root;
        
        class Compare {
            public:
                bool operator() (TreeNode* l, TreeNode* r)
                {
                    return l->freq > r->freq;
                }
        };

        priority_queue <TreeNode*, vector<TreeNode*>, Compare> minHeap;
        
        //Initializing a vector of tree nodes representing character's ascii value and initializing its frequency with 0
        void buildArray();
        
        //Traversing the constructed tree to generate huffman codes of each present character
        void traverse(TreeNode*, string);
        
        //Function to convert binary string to its equivalent decimal value
        int binToDec(string);
        
        //Function to convert a decimal number to its equivalent binary string
        string decToBin(int);
        
        //Reconstructing the Huffman tree while Decoding the file
        void buildTree(char, string&);

        //Creating Min Heap of Nodes by frequency of characters in the input file
        void createMinHeap();
        
        //Constructing the Huffman tree
        void createTree();
        
        //Generating Huffman codes
        void createCodes();
        
        //Saving Huffman Encoded File
        void saveEncodedFile();
        
        //Saving Decoded File to obtain the original File
        void saveDecodedFile();
        
        //Reading the file to reconstruct the Huffman tree
        void getTree();

    public:
        //Constructor
        huffman(string inputFileName, string outputFileName)
        {
            this->inputFileName = inputFileName;
            this->outputFileName = outputFileName;
            buildArray();
        }
        //Compressing input file
        void compress();
        //Decrompressing input file
        void decompress();
};
#endif