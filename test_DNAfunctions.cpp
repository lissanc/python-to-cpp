#include "DNAfunctions.h"
#include <cassert>
#include <iostream>
#include <string>

int main() {

  std::cout << "Testing started" << std::endl;

  // Tests the check_string_char function for diff cases
  // tests for uppercase for valid letters
  assert(check_string_char("ATCG") == true);
  // tests for lowercase valid letters
  assert(check_string_char("atcg") == false);
  assert(check_string_char("") == false);
  assert(check_string_char("AGTX") == false);
  assert(check_string_char("!") == false);

  // tests the add_indel function for diff cases
  assert(add_indel("ATCG", 2) == "AT-G");

  // TESTS the delete_indel for diff cases
  assert(delete_indel("AT-G", 2) == "ATG");

  // TESTS the padding function for diff cases
  assert(padding("ATCG", 3) == "ATCG---");

  // TESTS the mismatches function for diff cases
  assert(mismatches("ATCG", "GCTA") == 4);
  assert(mismatches("ATCG", "ATCG") == 0);
  assert(mismatches("ATCG", "ACTG") == 2);
  assert(mismatches("ATC-", "ATC-") == 1);

  // TESTS the matches function for diff cases
  assert(matches("ATCG", "GCTA") == 0);
  assert(matches("ATCG", "ATCG") == 4);
  assert(matches("ATCG", "ACTG") == 2);
  assert(matches("ATC-", "ATC-") == 3);

  // TESTS the score_format function
  // assert(score_format("ATCG", "GCTA") == "Strings compared (Lowercase
  // indicates a match):\nString one: ATCG\nString two: GTCA\n");

  // TESTS the is_digit function
  assert(is_digit("5") == true);
  assert(is_digit("!") == false);

  std::cout << "All tests passed!" << std::endl;
  return 0;
}