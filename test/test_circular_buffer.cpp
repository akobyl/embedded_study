#include "circular_buffer.h"
#include <gtest/gtest.h>
#include <stddef.h>
#include <sys/types.h>

TEST(CircularBuffer, testCreate) {
  auto cb = cb_create(10);
  ASSERT_TRUE(cb != nullptr);
  ASSERT_FALSE(cb_full(cb));
}

TEST(CircularBuffer, testDestroy) {
  auto cb = cb_create(10);
  ASSERT_TRUE(cb != nullptr);
  cb_destroy(cb);
  // No way to verify that the memory is freed in C
}

TEST(CircularBuffer, testWriteSingle) {
  auto cb = cb_create(10);
  cb_write(cb, 5);
  uint8_t read;
  bool success = cb_read(cb, &read);
  ASSERT_TRUE(success);
  ASSERT_EQ(5, read);

  success = cb_read(cb, &read);
  ASSERT_FALSE(success);
}

TEST(CircularBuffer, testWriteDouble) {
  auto cb = cb_create(10);
  cb_write(cb, 5);
  cb_write(cb, 6);
  uint8_t read;
  bool success = cb_read(cb, &read);
  ASSERT_TRUE(success);
  ASSERT_EQ(5, read);

  success = cb_read(cb, &read);
  ASSERT_TRUE(success);
  ASSERT_EQ(6, read);

  success = cb_read(cb, &read);
  ASSERT_FALSE(success);
}

TEST(CircularBuffer, testWrite) {
  const size_t capacity = 10;
  auto cb = cb_create(10);

  for (auto i = 0; i < 10; i++) {
    ASSERT_FALSE(cb_full(cb));
    cb_write(cb, i);
  }

  ASSERT_TRUE(cb_full(cb));

  for (int i = 0; i < 10; i++) {
    uint8_t read;
    ASSERT_TRUE(cb_read(cb, &read));
    ASSERT_EQ(i, read);
  }
}

TEST(CircularBuffer, testReset) {
  auto cb = cb_create(10);

  cb_write(cb, 5);
  cb_write(cb, 6);
  cb_reset(cb);

  uint8_t read;
  ASSERT_FALSE(cb_read(cb, &read));
  ASSERT_FALSE(cb_read(cb, &read));
}

TEST(CircularBuffer, testOverflow) {
  auto cb = cb_create(3);

  cb_write(cb, 1);
  cb_write(cb, 2);
  cb_write(cb, 3);
  ASSERT_TRUE(cb_full(cb));
  cb_write(cb, 4);
  ASSERT_TRUE(cb_full(cb));

  uint8_t read;
  bool success = cb_read(cb, &read);
  ASSERT_TRUE(success);
  ASSERT_EQ(2, read);

  success = cb_read(cb, &read);
  ASSERT_TRUE(success);
  ASSERT_EQ(3, read);

  success = cb_read(cb, &read);
  ASSERT_TRUE(success);
  ASSERT_EQ(4, read);

  success = cb_read(cb, &read);
  ASSERT_FALSE(success);
}
