//
// Created by guyha on 02/07/2024.
//
#include "BlockChain.h"

int main(int argc, char ** argv)
{
    BlockChain blockchain;

    // Create transactions
    Transaction transaction1 = {100, "Alice", "Bob"};
    Transaction transaction2 = {200, "Bob", "Charlie"};
    Transaction transaction3 = {300, "Charlie", "David"};

    BlockChainAppendTransaction(blockchain, transaction1, "13:30");
    BlockChainAppendTransaction(blockchain, transaction2, "13:31");
    BlockChainAppendTransaction(blockchain, transaction3, "13:32");
    ofstream out_file(argv[1]);
    BlockChainDump(blockchain, out_file);

    return 0;
}
