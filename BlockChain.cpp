//
// Created by User on 30/06/2024.
//

#include <iostream>
#include <string>
#include "BlockChain.h"

using namespace std;

// implemented by - Eden
int BlockChainGetSize(const BlockChain &blockChain) {
    return blockChain.size;
}


// implemented by - Eden
int
BlockChainPersonalBalance(const BlockChain &blockChain, const string &name) {
    int sumRecieved = 0, sumSent = 0;
    Block *temp = blockChain.head;
    while (temp != nullptr) {
        if (temp->transaction.receiver == name) {
            sumRecieved += temp->transaction.value;
        } else if (temp->transaction.sender == name) {
            sumSent += temp->transaction.value;
        }
        temp = temp->previousTransaction;
    }
    return sumRecieved - sumSent;
}


// implemented by - Eden
void BlockChainAppendTransaction(
        BlockChain &blockChain,
        unsigned int value,
        const string &sender,
        const string &receiver,
        const string &timestamp
) {
    Transaction transaction = {value, sender, receiver};
    Block *newBlock = new Block{transaction, timestamp, blockChain.head};
    blockChain.head = newBlock;
    blockChain.size++;
}


// implemented by - Eden
void BlockChainAppendTransaction(
        BlockChain &blockChain,
        const Transaction &transaction,
        const string &timestamp
) {
    Block *newBlock = new Block{transaction, timestamp, blockChain.head};
    blockChain.head = newBlock;
    blockChain.size++;
}


// needs implementation
BlockChain BlockChainLoad(ifstream &file);


// needs implementation
void BlockChainDump(const BlockChain &blockChain, ofstream &file);


// needs implementation
void BlockChainDumpHashed(const BlockChain &blockChain, ofstream &file);


// needs implementation
bool BlockChainVerifyFile(const BlockChain &blockChain, std::ifstream &file);


// needs implementation
void BlockChainCompress(BlockChain &blockChain);


// needs implementation
void BlockChainTransform(BlockChain &blockChain, updateFunction function);

// implemented by - Eden
void BlockChainDelete(BlockChain &blockChain) {
    while (blockChain.head != nullptr) {
        Block *temp = blockChain.head;
        blockChain.head = blockChain.head->previousTransaction;
        delete temp;
    }
}