//
// Created by Eden on 30/06/2024.
//

#include <iostream>
#include "Transaction.h"
#include "Utilities.h"

using namespace std;

void TransactionDumpInfo(const Transaction &transaction, ofstream &file) {
    file << "Sender Name: " << transaction.sender << endl;
    file << "Receiver Name: " << transaction.receiver << endl;
    file << "Transaction Value: " << transaction.value << endl;
}

/**
 * TransactionHashMessage - Hashs the message of the memTransaction
 *
 * @param transaction Transaction to hash
 *
 * @return The hashed message
*/
string TransactionHashedMessage(const Transaction &transaction) {
    return ::hash(transaction.value, transaction.sender,
                  transaction.receiver);
}


/**
 * TransactionVerifyHashedMessage - Verifies that a given memTransaction suits a given hashed message
 *
 * @param transaction Given memTransaction
 * @param hashedMessage Hashed message to verify
 *
 * @return true if the message given is suitable to this memTransaction, false otherwise
 *
*/
bool TransactionVerifyHashedMessage(const Transaction &transaction,
                                    string hashedMessage) {
    return hashedMessage == TransactionHashedMessage(transaction);

}