
 #include <stdio.h>
 #include "minunit.h"
#include "util.h"
 int tests_run = 0;

 static char * test1() {
     mu_assert("test failed", strcmp("network unreachable",icmpcode_v4(0))==0);
     return 0;
 }

 static char * test2() {
     mu_assert("test failed", strcmp("host unreachable",icmpcode_v4(1))==0);
     return 0;
 }

 static char * all_tests() {
     mu_run_test(test1);
     mu_run_test(test2);
     return 0;
 }

 int main(int argc, char **argv) {
     char *result = all_tests();
     if (result != 0) {
         printf("%s\n", result);
     }
     else {
         printf("ALL TESTS PASSED\n");
     }

     return 0;
 }
