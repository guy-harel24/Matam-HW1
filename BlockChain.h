#pragma once

#include <string>
#include <fstream>
#include "Transaction.h"

#define STARTING_SIZE 0

using std::string;
using std::ifstream;
using std::ofstream;
using std::ostream;
using std::istream;

typedef unsigned int (*updateFunction)(unsigned int);

/**
 *
 * @struct Block - Defining a struct for the chain of blocks
 * @note - Added struct
 * @author - Eden
 */
struct Block {
    Transaction memTransaction;
    string memTimestamp;
    Block *memPreviousTransaction;
};

/**
 * @struct BlockChain - Defining the new BlockChain Type
 * @note Make sure to use BlockChainDelete when the block chain is no longer
 * in order to release allocated space.
*/
struct BlockChain {
    Block *memHead = nullptr;
    int memSize = STARTING_SIZE;
};

/**
 * BlockChainGetSize - returns the number of Blocks in the BlockChain
 *
 * @param blockChain - BlockChain to measure
 *
 * @return Number of Blocks in the BlockChain
 * @editor Eden
*/
int BlockChainGetSize(const BlockChain &blockChain);


/**
 * BlockChainPersonalBalance - returns the balance of a given person, relative to a given BlockChain
 *
 * @param blockChain - BlockChain to calculate the balance from
 * @param name - Name of the person to calculate the balance for
 *
 * @return Balance of the person
 * @editor Eden
*/
int BlockChainPersonalBalance(const BlockChain &blockChain, const string &name);


/**
 * BlockChainAppendTransaction - creates and appends a new memTransaction to the BlockChain
 *
 * @param blockChain BlockChain to append the memTransaction to
 * @param value Value of the memTransaction
 * @param sender Name of the sender
 * @param receiver Name of the receiver
 * @param timestamp String that holds the time the memTransaction was made
 * @editor Eden
*/
void BlockChainAppendTransaction(
        BlockChain &blockChain,
        unsigned int value,
        const string &sender,
        const string &receiver,
        const string &timestamp
);


/**
 * BlockChainAppendTransaction - appends a copy of a given memTransaction to the BlockChain
 *
 * @param blockChain BlockChain to append the memTransaction to
 * @param transaction Transaction we want to append
 * @param timestamp String that holds the time the memTransaction was made
 * @editor Eden
*/
void BlockChainAppendTransaction(
        BlockChain &blockChain,
        const Transaction &transaction,
        const string &timestamp
);


/**
 * BlockChainLoad - Reads data from a file and creates a new block chain
 *
 * @param file Data file to read from
 *
 * @return BlockChain created from the file
 *
*/
BlockChain BlockChainLoad(ifstream &file);


/**
 * BlockChainDump - Prints the data of all transactions in the BlockChain to a given file
 *
 * Data will be printed in the following format:
 *
 * BlockChain info:
 * <n>.
 * Sender Name: <name>
 * Receiver Name: <name>
 * Transaction Value: <value>
 * Transaction Timestamp: <time>
 *
 * @param blockChain BlockChain to print
 * @param file File to print to
 *
*/
void BlockChainDump(const BlockChain &blockChain, ostream &file);


/**
 * BlockChainDumpHashed - Prints the *hashed data* of all transactions in the BlockChain to a given file
 *
 * Data will be printed in the following format:
 * <hashed message>
 * <hashed message>
 * ...
 * <hashed message>
 *
 * @param blockChain BlockChain to print
 * @param file File to print to
 *
*/
void BlockChainDumpHashed(const BlockChain &blockChain, ostream &file);


/**
 * BlockChainVerifyFile - verifies that the file contains correct hashed messages of the given BlockChain
 *
 * Input file is expected to contain data in the following format:
 * <hashed message>
 * <hashed message>
 * ...
 * <hashed message>
 *
 * @param blockChain BlockChain to verify
 * @param file File to read from
 *
 * @return true if the file is valid, false otherwise
*/
bool BlockChainVerifyFile(const BlockChain &blockChain, istream &file);


/**
 * BlockChainCompress - Compresses the given block chain based on the memTransaction's data.
 * All consecutive blocks with the same sender and receiver will be compressed to one Block.
 *
 * @param blockChain BlockChain to compress
*/
void BlockChainCompress(BlockChain &blockChain);


/**
 * BlockChainTransform - Update the values of each memTransaction in the BlockChain
 *
 * @param blockChain BlockChain to update
 * @param operation a pointer to a transform function
*/
void BlockChainTransform(BlockChain &blockChain,
                         updateFunction function);
/**
 * BlockChainDelete - Deletes the chain's blocks (due to dynamic memory
 * allocation used in BlockChainAppendTransaction).
 *
 * @param blockChain BlockChain to delete variables from
 * @note - Added function
 * @author Eden
*/

void BlockChainDelete(BlockChain &blockChain);