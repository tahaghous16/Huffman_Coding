# 📦 Huffman Coding - Text Compression in C++

This project demonstrates the **implementation of Huffman Coding**, a well-known algorithm for data compression. Huffman Coding works by assigning shorter binary codes to more frequent characters, thereby reducing the size of the text.

---

## 🚀 Features

- Calculate character frequencies
- Build a Huffman Tree using a min-heap
- Generate Huffman binary codes
- Encode the input text
- Display original vs. compressed size
- C++ implementation using only standard libraries
  
---

## 📖 About

This project was developed as part of the **Discrete Structures** course. It provides a practical demonstration of compression techniques using **binary trees**, **priority queues**, and **maps** in C++.

> “The more a character appears, the shorter its binary code.”

---

## 🔧 How It Works

1. **User Input**: User enters a string to compress
2. **Frequency Calculation**: Map counts how often each character appears
3. **Min-Heap**: Priority queue arranges characters by frequency
4. **Huffman Tree**: Merge smallest frequencies into a binary tree
5. **Generate Codes**: Traverse the tree to assign binary codes
6. **Encode Text**: Convert text to compressed binary format
7. **Size Comparison**: Show original vs. compressed bit size

---

## ✅ Conclusion

Through this project, I'm not only implemented Huffman Coding successfully but also deepened  understanding of how theoretical computer science concepts can solve real-world problems like data compression. It challenged  to think algorithmically, collaborate effectively, and write clean, modular C++ code.
What started as a course project turned into a meaningful learning experience — showing how a few lines of binary can make a big difference in storage and performance. This project has motivated to continue exploring algorithms that power modern technology and to keep building solutions that are both efficient and elegant.

“Great things are done by a series of small things brought together.” — Vincent Van Gogh

---

## 🖨️ Sample Output

```cpp
===== HUFFMAN CODING - TEXT COMPRESSION =====
Enter the text to compress: assassination

--- Character Frequencies ---
'a' : 3
's' : 3
'i' : 2
'n' : 2
't' : 1
'o' : 1

--- Huffman Codes ---
't' : 000
'o' : 001
'a' : 01
's' : 10
'i' : 110
'n' : 111

--- Encoded Binary String ---
0110100110101101110100011000111

--- Compression Summary ---
Original Size   : 104 bits
Compressed Size : 31 bits
Compression Ratio: 29.81%

