
#pragma once

#include <string>
#include <fstream>

using std::string;
using std::ofstream;


/**
*
 * Transaction - Defining the new Transaction Type
 *
*/
struct Transaction {
    unsigned int value;
    string sender;
    string receiver;
};


/**
 * TransactionDumpInfo - Prints the data of the memTransaction to a given file
 *
 * The data is printed in the following format:
 * Sender Name: <name>
 * Receiver Name: <name>
 * Transaction Value: <value>
 *
 * @param transaction Transaction to print
*/
void TransactionDumpInfo(const Transaction &transaction, ofstream &file);


/**
 * TransactionHashMessage - Hashs the message of the memTransaction
 *
 * @param transaction Transaction to hash
 *
 * @return The hashed message
*/
string TransactionHashedMessage(const Transaction &transaction);


/**
 * TransactionVerifyHashedMessage - Verifies that a given memTransaction suits a given hashed message
 *
 * @param transaction Given memTransaction
 * @param hashedMessage Hashed message to verify
 *
 * @return true if the message given is suitable to this memTransaction, false otherwise
 *
*/
bool TransactionVerifyHashedMessage(
        const Transaction &transaction,
        string hashedMessage
);
