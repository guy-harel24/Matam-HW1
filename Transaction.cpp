//
// Created by Eden Avidan on 30/06/2024.
//

#include <iostream>
#include "Transaction.h"
#include "Utilities.h"

using namespace std;

void TransactionDumpInfo(const Transaction& transaction, ofstream& file)
{
    file << "Sender Name: " << transaction.mem_sender << endl;
    file << "Receiver Name: " << transaction.mem_receiver << endl;
    file << "Transaction Value: " << transaction.mem_value << endl;
}
/**
 * TransactionHashMessage - Hashs the message of the transaction
 *
 * @param transaction Transaction to hash
 *
 * @return The hashed message
*/
string TransactionHashedMessage(const Transaction &transaction) {
    return ::hash(transaction.mem_value, transaction.mem_sender, transaction.mem_receiver);
}


/**
 * TransactionVerifyHashedMessage - Verifies that a given transaction suits a given hashed message
 *
 * @param transaction Given transaction
 * @param hashedMessage Hashed message to verify
 *
 * @return true if the message given is suitable to this transaction, false otherwise
 *
*/
bool TransactionVerifyHashedMessage(const Transaction &transaction,
                                    string hashedMessage) {
    return hashedMessage == TransactionHashedMessage(transaction);

}