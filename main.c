#include <stdio.h>

void test_dynamic_array();
void test_linked_list();
void test_doubly_linked_list();
int main() {
    printf("=== Data Structures Test Suite ===\n\n");

    test_dynamic_array();
    test_linked_list();
    test_doubly_linked_list();
    
    // Incoming tests:
    // test_stack();
    // test_queue();
    // test_linked_list();

    return 0;
}
