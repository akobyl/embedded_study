#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

typedef struct cb_t cb_handle;

cb_handle *cb_create(uint16_t capacity);
void cb_destroy(cb_handle *cb);
void cb_reset(cb_handle *cb);
bool cb_full(cb_handle *cb);
void cb_write(cb_handle *cb, uint8_t value);
bool cb_read(cb_handle *cb, uint8_t *value);

#ifdef __cplusplus
}
#endif

#endif // CIRCULAR_BUFFER_H
