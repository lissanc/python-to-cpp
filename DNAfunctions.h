#include <iostream>
#include <string>

// Function accepts a string and verifies if it contains only the characters A,
// T, C and G

bool check_string_char(std::string user_string) {
  bool check = true;

  if (user_string.empty()) {
    check = false;
  } else {
    for (char i : user_string) {
      if (i != 'A' && i != 'T' && i != 'C' && i != 'G') {
        check = false;
        break;
      }
    }
  }

  return check;
}

// Takes a sequence to be edited and places a "-" in the given indeX

std::string add_indel(std::string string, int index) {
  std::string edited_string = string;
  edited_string[index] = '-';
  return edited_string;
}

// Takes a sequence to be edited and removes the "-" in the given index
std::string delete_indel(std::string string, int index) {
  std::string edited_string = string;
  edited_string.erase(index, 1);
  return edited_string;
}

// Attaches the smaller sequence and attaches indels to the end until it is the
// same length as the other sequence
std::string padding(std::string small_string, int fill_num) {
  std::string edited_string = small_string;
  edited_string.append(fill_num, '-');
  return edited_string;
}

// Returns the amount of mismatches between string1 and string2
int mismatches(std::string string1, std::string string2) {
  int mismatch = 0;
  int counter = 0;
  for (char i : string1) {
    if (i != string2.at(counter) || i == '-') {
      mismatch += 1;
    }
    counter += 1;
  }
  return mismatch;
}

// Returns the amount of matches between string1 and string2
int matches(std::string string1, std::string string2) {
  int match = 0;
  int counter = 0;
  for (char i : string1) {
    if (i == string2.at(counter) && i != '-') {
      match += 1;
    }
    counter += 1;
  }
  return match;
}

// Takes the two sequences and turns any matches into lowercase letters
void score_format(std::string string1, std::string string2) {
  std::string edited_string1 = string1;
  std::string edited_string2 = string2;
  int counter = 0;

  for (char i : string1) {
    if (i == string2.at(counter) && i != '-') {
      edited_string1.at(counter) = tolower(edited_string1.at(counter));
      edited_string2.at(counter) = tolower(edited_string2.at(counter));
    }
    counter += 1;
  }
  std::cout << "Strings compared (Lowercase indicates a match):" << std::endl
            << "String one: " << edited_string1 << std::endl
            << "String two: " << edited_string2 << std::endl;
}

// checks if the string is made up of integers and returns true if it is and
// false if it isnt
bool is_digit(std::string s) {
  for (char c : s) {
    if (isdigit(c) == false) {
      return false;
    } else {
      return true;
    }
  }
}