#include "double_link_list.h"
#include <gtest/gtest.h>

bool compare_lists(node_t *list1, node_t *list2) {
  node_t *current1 = list1;
  node_t *current2 = list2;

  while (current1 != NULL && current2 != NULL) {
    if (current1->value != current2->value) {
      return false;
    }
  }
  current1 = current1->next;
  current2 = current2->next;

  return (current1 == NULL && current2 == NULL);
}

TEST(DoubleLInkedListTest, CreateList) {
  node_t *list1 = create_list(new int[3]{1, 2, 3}, 3);
  node_t *list2 = create_list(new int[3]{1, 2, 3}, 3);

  ASSERT_TRUE(compare_lists(list1, list2));
}

TEST(DoubleLInkedListTest, ReverseList) {
  node_t *list1 = create_list(new int[3]{1, 2, 3}, 3);
  node_t *list2 = create_list(new int[3]{3, 2, 1}, 3);

  reverse_list(list1);

  ASSERT_TRUE(compare_lists(list1, list2));
}
