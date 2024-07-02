//
// Created by Eden on 30/06/2024.
//

#include <iostream>
#include <string>
# include <cassert>
#include "BlockChain.h"

#define VARIABLES_IN_TRANS 4
#define INITIAL_INDEX 0

using namespace std;

// enums for indexes used in BlockChainLoad function in the variables array.
enum ParamIndexes {
    Sender = 0,
    Receiver = 1,
    Value = 2,
    Timestamp = 3
};

// implemented by - Eden
int BlockChainGetSize(const BlockChain &blockChain) {
    return blockChain.memSize;
}


// implemented by - Eden
int
BlockChainPersonalBalance(const BlockChain &blockChain, const string &name) {
    int sumRecieved = 0, sumSent = 0;
    Block *temp = blockChain.memHead;
    while (temp != nullptr) {
        if (temp->memTransaction.receiver == name) {
            sumRecieved += temp->memTransaction.value;
        } else if (temp->memTransaction.sender == name) {
            sumSent += temp->memTransaction.value;
        }
        temp = temp->memPreviousTransaction;
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
    Block *newBlock = new Block{transaction, timestamp, blockChain.memHead};
    blockChain.memHead = newBlock;
    blockChain.memSize++;
}


// implemented by - Eden
void BlockChainAppendTransaction(
        BlockChain &blockChain,
        const Transaction &transaction,
        const string &timestamp
) {
    Block *newBlock = new Block{transaction, timestamp, blockChain.memHead};
    blockChain.memHead = newBlock;
    blockChain.memSize++;
}

// implemented by - Eden
BlockChain BlockChainLoad(ifstream &file) {

    BlockChain chain;
    string line;

    while (getline(file, line)) {
        string variables[VARIABLES_IN_TRANS];
        int variableIndex = INITIAL_INDEX;

        while (line[0] != '\0') {
            variables[variableIndex].push_back(line[0]);
            line = &line[1];
            if (line[0] == ' ') {
                variableIndex++;
                line = &line[1];
            }
        }

        // Value is saved as string in the array, casts to unsigned int.
        // Using the namespace of ParamsIndexes for: Value, Sender, Receiver,
        // Timestamp.
        unsigned int value = stoi(variables[Value]);
        Transaction transaction = {value, variables[Sender],
                                   variables[Receiver]};
        BlockChainAppendTransaction(chain, transaction, variables[Timestamp]);
    }

    return chain;
}


// needs implementation
void BlockChainDump(const BlockChain &blockChain, ofstream &file)
{
    file << "BlockChain Info:" << endl;
    int i = 1;
    Block* block = blockChain.memHead;
    while (block != nullptr)
    {
        Transaction& trans = block->memTransaction;
        file << i << "." << endl;
        file << "Sender Name: " << trans.sender << endl;
        file << "Receiver Name: " << trans.receiver << endl;
        file << "Transaction Value: " << trans.value << endl;
        file << "Transaction timestamp: " << block->memTimestamp << endl;
        i++;
        block = block->memPreviousTransaction;
    }
}


// needs implementation
void BlockChainDumpHashed(const BlockChain &blockChain, ofstream &file)
{
    Block* block = blockChain.memHead;

    while (true)
    {
        Transaction& trans = block->memTransaction;
        file << TransactionHashedMessage(trans);
        block = block->memPreviousTransaction;
        if (block != nullptr){
            file << endl;
        } else {
            break;
        }
    }
}

// needs implementation
bool BlockChainVerifyFile(const BlockChain &blockChain, std::ifstream &file)
{
    Block* block = blockChain.memHead;
    bool verify = true;
    string hash;
    while (!file.eof() && block != nullptr && verify)
    {
        Transaction& trans= block->memTransaction;
        getline(file, hash);
        verify = TransactionVerifyHashedMessage(trans,
                                                hash);
    }
    assert(file.eof() && block == nullptr);
    return verify;
}


// needs implementation
void BlockChainCompress(BlockChain &blockChain);


// needs implementation
void BlockChainTransform(BlockChain &blockChain, updateFunction function);

// implemented by - Eden
void BlockChainDelete(BlockChain &blockChain) {
    while (blockChain.memHead != nullptr) {
        Block *temp = blockChain.memHead;
        blockChain.memHead = blockChain.memHead->memPreviousTransaction;
        delete temp;
    }
}