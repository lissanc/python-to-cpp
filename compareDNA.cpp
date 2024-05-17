#include "DNAfunctions.h"
#include <iostream>
#include <string>

int main() {
  bool flag1 = true;
  std::string string1;
  std::string string2;
  std::string string_choice;
  std::string string_edit;
  std::string index_choice;
  int index;

  while (flag1) {
    std::cout << "                     Welcome to a DNA PROJECT!" << std::endl;
    std::cout << "-------------------------------------------------------------"
                 "--------"
              << std::endl;
    std::cout << "Please enter two strings of DNA (Valid characters are A, T, "
                 "C, and G)"
              << std::endl;

    // check this first while loop
    flag1 = false;

    bool flag2 = true;
    while (flag2 == true) {
      std::cout << "String one: ";
      //   std::string string1;
      //   std::string string2;
      getline(std::cin, string1);
      std::cout << "String two: ";
      getline(std::cin, string2);

      bool check1 = check_string_char(string1);
      bool check2 = check_string_char(string2);
      std::cout << "";

      if ((check1 == false) || (check2 == false)) {
        std::cout << "INVALID STRING(S): Valid characters are A, T, C, or G"
                  << std::endl;
      } else if (check1 == true && check2 == true) {
        flag2 = false;
      }
    }

    bool flag3 = true;
    while (flag3 == true) {
      std::cout << "-----------------------------------------------------------"
                   "----------"
                << std::endl;
      std::cout << "What would you like to do?" << std::endl
                << "a) Add an indel" << std::endl
                << "b) Delete an indel" << std::endl
                << "c) Score Match" << std::endl
                << "d) Restart Program" << std::endl
                << "e) Quit Program" << std::endl;

      std::string input;
      std::cin >> input;
      std::string menu_choice = input;
      std::cout << "" << std::endl;

      // ADDING an indel
      if (menu_choice == "a" || menu_choice == "A") {
        bool flag4 = true;
        // Asking for which string to edit
        while (flag4 == true) {
          std::cout << "Add indel for string one or two: ";
          // declared in main outside a loop: std::string string_choice;
          std::cin >> string_choice;
          if (string_choice == "one" || string_choice == "ONE") {
            // std::string string_edit = string1;
            string_edit = string1;
            std::cout << "Current string one: " << string1 << std::endl;
            flag4 = false;
          } else if (string_choice == "two" || string_choice == "TWO") {
            // std::string string_edit = string2;
            string_edit = string2;
            std::cout << "Current string two: " << string2 << std::endl;
            flag4 = false;
          } else {
            std::cout << "INVALID INPUT: Options are \"one\" or \"two\""
                      << std::endl;
            continue;
          }
        }
        // Asking for index to edit
        bool flag7 = true;
        while (flag7 == true) {
          std::string index_choice;
          std::cout << "New indel position (Begins from 0): ";
          std::cin >> index_choice;
          if (is_digit(index_choice) == true) {
            index = std::stoi(index_choice);
            flag7 = false;

          } else {
            std::cout << "INVALID INPUT: Out of range" << std::endl;
            std::cout << "";
          }
        }
        // Editing and printing added indel
        if (string_choice == "one" || string_choice == "ONE") {
          string1 = add_indel(string_edit, index);
          std::cout << "";
          std::cout << "The new sequence is " << string1 << "." << std::endl;

        } else if (string_choice == "two" || string_choice == "TWO") {
          string2 = add_indel(string_edit, index);
          std::cout << "";
          std::cout << "The new sequence is " << string1 << "." << std::endl;
        }
        // DELETING an indel

      } else if (menu_choice == "b" || menu_choice == "B") {
        bool flag5 = true;
        // Asking for which string to edit
        while (flag5 == true) {
          std::cout << "Delete indel from string one or two: ";
          std::cin >> string_choice;

          if (string_choice == "one" || string_choice == "ONE") {
            string_edit = string1;
            std::cout << "Current string one: " << string1 << std::endl;
            flag5 = false;
          } else if (string_choice == "two" || string_choice == "TWO") {
            string_edit = string2;
            std::cout << "Current string two: " << string2 << std::endl;
            flag5 = false;
          } else {
            std::cout << "INVALID INPUT: Options are \"one\" or \"two\""
                      << std::endl;
            std::cout << "";
            continue;
          }
        }
        // Asking for index to edit
        bool flag6 = true;
        while (flag6 == true) {
          std::cout << "New indel position (Begins from 0) or type \"back\" to "
                       "return to menu: ";
          std::cin >> index_choice;

          // To avoid a softlock if there is no indels
          if (index_choice == "back" || index_choice == "BACK") {
            std::cout << "";
            flag6 = false;
            break;
          }

          // Collecting index
          if (is_digit(index_choice) == true) {
            index = std::stoi(index_choice);
          } else {
            std::cout << "INVALID INDEX: Out of range." << std::endl;
            continue;
          }
          if (index >= 0 && index <= string_edit.size()) {
            char s = string_edit.at(index);
            if (s == '-') {
              flag6 = false;
            } else {
              std::cout
                  << "INVALID INDEX: Only indexes with \"-\" can be edited."
                  << std::endl;
            }
          } else {
            std::cout << "INVALID INDEX: Out of range." << std::endl;
          }

          // # Editing and printing added indel
        }
        if (index_choice == "back" || index_choice == "BACK") {
          continue;
        } else if (string_choice == "one" || string_choice == "ONE") {
          string1 = delete_indel(string_edit, index);
          std::cout << "The new sequence is " << string1 << std::endl;
        } else if (string_choice == "two" || string_choice == "TWO") {
          string2 = delete_indel(string_edit, index);
          std::cout << "The new sequence is " << string2 << std::endl;
        }

        // SCORE Match
      } else if (menu_choice == "c" || menu_choice == "C") {
        std::string sstring1 = string1;
        std::string sstring2 = string2;

        // Padding smaller string
        int fill_num;
        if (sstring1.size() != sstring2.size()) {
          if (sstring1.size() < sstring2.size()) {
            fill_num = sstring2.size() - sstring1.size();
            sstring1 = padding(sstring1, fill_num);
          } else if (sstring1.size() > sstring2.size()) {
            fill_num = sstring1.size() - sstring2.size();
            sstring2 = padding(sstring2, fill_num);
          }
        }
        // Printing matches and mismatches
        int mismatched = mismatches(sstring1, sstring2);
        int match = matches(sstring1, sstring2);
        std::cout << "Number of matched characters: " << match << std::endl
                  << "Number of mismatched characters: " << mismatched
                  << std::endl;
        score_format(sstring1, sstring2);

        // RESTART PrograM
      } else if (menu_choice == "d" || menu_choice == "D") {
        flag3 = true;
        // break;

      } else if (menu_choice == "e" || menu_choice == "E") {
        std::cout << "---------------------------------------------------------"
                     "------------"
                  << std::endl
                  << "                            PROGRAM END" << std::endl;

        flag1 = false;
        flag3 = false;

      } else {

        std::cout << "INVALID INPUT";
      }
    }
  }
  return 0;
}
