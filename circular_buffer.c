#include "circular_buffer.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

struct cb_t {
  uint16_t head; // head is is
  uint16_t tail;
  size_t capacity;
  bool full;
  uint8_t *buffer;
};

cb_handle *cb_create(uint16_t capacity) {

  cb_handle *cb = (cb_handle *)malloc(sizeof(struct cb_t));
  uint8_t *buffer = malloc(capacity);

  assert(cb && buffer);

  cb->head = 0;
  cb->tail = 0;
  cb->full = false;
  cb->capacity = capacity;
  cb->buffer = buffer;

  return cb;
}

void cb_destroy(cb_handle *cb) {
  assert(cb);
  free(cb);
}

void cb_reset(cb_handle *cb) {
  assert(cb);
  cb->head = 0;
  cb->tail = 0;
  cb->full = false;
}

bool cb_full(cb_handle *cb) {
  assert(cb);
  return cb->full;
}

void cb_write(cb_handle *cb, uint8_t value) {

  // write to tail
  cb->buffer[cb->head] = value;

  if (cb->full) {
    cb->tail = (cb->tail + 1) % cb->capacity;
  }

  cb->head = (cb->head + 1) % cb->capacity;

  if (cb->tail == cb->head) {
    cb->full = true;
  }
}

bool cb_read(cb_handle *cb, uint8_t *read) {
  assert(cb);
  assert(read);

  // cb is empty!
  if (cb->head == cb->tail && !cb->full) {
    return false;
  }

  cb->full = false;
  *read = cb->buffer[cb->tail];
  cb->tail++;

  if (cb->tail == cb->capacity) {
    cb->tail = 0;
  }

  return true;
}
