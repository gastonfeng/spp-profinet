/**
 * @file
 * @brief The sender abstract class.
 *
 * The basic Sender abstraction. Every implementation of a Sender will "derive"
 * from this Sender abstract class.
 *
 */

#include <stdlib.h>

#include "dbg.h"

#include "Sender.h"
#include "Sender-int.h"

struct Sender;
typedef struct Sender Sender_t;


Sender_t * Sender_new(const struct Sender_ops *ops) {

	Sender_t *sender = malloc(sizeof(Sender_t));
	check_mem(sender);

	sender->ops = ops;

	return sender;

error:
	return NULL;
}

int Sender_free(Sender_t *sender) {

	free(sender);

	// TODO anything else to be freed? any Error checking?

	return 0;
}
