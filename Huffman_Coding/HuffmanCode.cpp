#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

// ------------------- Common Structures -------------------
struct Node {
    char ch;
    int freq;
    Node* left, * right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// -------------------  Frequency Counter -------------------
unordered_map<char, int> getFrequency(const string& text) {
    unordered_map<char, int> freqMap;
    for (char ch : text) {
        freqMap[ch]++;
    }
    return freqMap;
}

// ------------------- Build Huffman Tree -------------------
Node* buildHuffmanTree(const unordered_map<char, int>& freqMap) {
    priority_queue<Node*, vector<Node*>, compare> minHeap;
    for (auto& entry : freqMap) {
        minHeap.push(new Node(entry.first, entry.second));
    }

    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        minHeap.push(newNode);
    }

    return minHeap.top();
}

// ------------------- Generate Huffman Codes -------------------
void generateCodes(Node* root, string code, unordered_map<char, string>& codeMap) {
    if (!root) return;

    if (root->ch != '$') {
        codeMap[root->ch] = code;
    }

    generateCodes(root->left, code + "0", codeMap);
    generateCodes(root->right, code + "1", codeMap);
}

// -------------------Encode Text -------------------
string encodeString(const string& text, const unordered_map<char, string>& huffmanCodes) {
    string encoded = "";
    for (char ch : text) {
        encoded += huffmanCodes.at(ch);
    }
    return encoded;
}

// ------------------- Main Function -------------------
int main() {
    string text;
    cout << "===== HUFFMAN CODING - TEXT COMPRESSION =====\n";
    cout << "Enter the text to compress: ";
    getline(cin, text);

    // Step 1: Frequency Count
    unordered_map<char, int> freqMap = getFrequency(text);

    // Step 2: Build Huffman Tree
    Node* root = buildHuffmanTree(freqMap);

    // Step 3: Generate Codes
    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    // Step 4: Encode the String
    string encodedText = encodeString(text, huffmanCodes);

    // ----- Display Results -----
    cout << "\n--- Character Frequencies ---\n";
    for (auto& entry : freqMap)
        cout << "'" << entry.first << "' : " << entry.second << endl;

    cout << "\n--- Huffman Codes ---\n";
    for (auto& entry : huffmanCodes)
        cout << "'" << entry.first << "' : " << entry.second << endl;

    cout << "\n--- Encoded Binary String ---\n";
    cout << encodedText << "\n";

    // Size Comparison
    int originalBits = text.length() * 8;  // 1 char = 8 bits
    int compressedBits = encodedText.length();

    cout << "\n--- Compression Summary ---\n";
    cout << "Original Size   : " << originalBits << " bits\n";
    cout << "Compressed Size : " << compressedBits << " bits\n";
    cout << "Compression Ratio: " << (100.0 * compressedBits / originalBits) << "%\n";

    return 0;
}