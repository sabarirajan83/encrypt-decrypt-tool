# 🔐 Message Encryption & Decryption (C++)

A **C++ program** that allows you to **encrypt and decrypt messages** using a simple **matrix-based cipher algorithm**.  
Perfect for learning basic cryptography concepts and matrix transformations in programming.

---

## 🚀 Features
- 🔒 Encrypt any plain-text message into numeric codes  
- 🔓 Decrypt numeric codes back to the original message  
- 🧹 Input validation for error-free encryption/decryption  
- 🖥 Works on **Windows**, **Linux**, and **macOS**  

---

## 📦 Installation & Setup

### 1. Clone this repository
```bash
git clone https://github.com/sabarirajan83/encrypt-decrypt-tool.git
cd encrypt-decrypt-tool

```

### 2.Compile the program
```bash
g++ encrypt_decrypt.cpp -o encrypt_decrypt

```

### 3.Run the program
```bash
./encrypt_decrypt

```

## 🧠 How It Works

This program uses a 2x2 matrix cipher to transform your message:

Encoding matrix

[2 3]
[1 2]

Decoding matrix

[ 2 -3]
[-1  2]

Encoding: Each pair of characters is converted to ASCII codes, then multiplied with the encoding matrix to generate numeric codes.

Decoding: Uses the decoding matrix to reverse the process and reconstruct the original message.

---

Crafted in C++ by CõpperCõre