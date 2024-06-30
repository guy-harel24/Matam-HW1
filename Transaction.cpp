//
// Created by Eden Avidan on 30/06/2024.
//

#include <iostream>
#include "Transaction.h"
#include "Utilities.h"

using namespace std;

/**
 * TransactionHashMessage - Hashs the message of the transaction
 *
 * @param transaction Transaction to hash
 *
 * @return The hashed message
*/
string TransactionHashedMessage(const Transaction &transaction) {
    return ::hash(transaction.value, transaction.sender, transaction.receiver);
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