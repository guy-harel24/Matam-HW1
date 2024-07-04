//
// Created by guyha on 02/07/2024.
//
#include "BlockChain.h"
#include <iostream>  // Include for cout
#include <string>
using namespace std;

enum execute{
    starting, op, source, target
};

int main(int argc, char ** argv)
{
    if (argc != 4){
        cout << "Usage: ./mtm_blockchain <op> <source> <target>" << endl;
        return 0;
    }

    BlockChain blockchain;
    ifstream source(argv[::source]);
    blockchain = BlockChainLoad(source);
    string format = "format", hash = "hash", compress = "compress",
    verify = "verify";

    if (argv[op] == format){
        ofstream target(argv[::target]);
        BlockChainDump(blockchain, target);
    } else if (argv[op] == hash) {
        ofstream target(argv[::target]);
        BlockChainDumpHashed(blockchain, target);
    } else if (argv[op] == compress) {
        ofstream target(argv[::target]);
        BlockChainCompress(blockchain);
        BlockChainDump(blockchain, target);
    } else if (argv[op] == verify){
        ifstream target(argv[::target]);
        if (BlockChainVerifyFile(blockchain, target)){
            cout << "Verification passed" << endl;
        } else {
            cout << "Verification failed" << endl;
        }

    } else {
        cout << "Usage: ./mtm_blockchain <op> <source> <target>" << endl;
        return 0;
    }
    BlockChainDelete(blockchain);

    return 0;
}
