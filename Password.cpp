#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  int repetition = 0;
  int index = 0;
  if (phrase.length() > 0){ //if there are any characters in the string, then there is at least one leading character
    repetition++;
  }
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

/*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
*/

bool Password::has_mixed_case(string phrase) {
  bool has_upper = false;
  bool has_lower = false;
  for(int i = 0; i < phrase.length(); i++){
    if(phrase[i] >= 'A' && phrase[i] <= 'Z'){
      has_upper = true;
    }
    if(phrase[i] >= 'a' && phrase[i] <= 'z'){
      has_lower = true;
    }
  }
  return has_upper && has_lower;
}

/*
  constructor sets the default password to "ChicoCA-95929"
  */
Password::Password(){
  pass_history.push_back("ChicoCA-95929");
}

/*
  receives a password and sets the latest in pass_history to it if and only
  if it meets all criteria:
    1. The password is at least 8 letters long, but no longer than 20
    2. It has no more than 3 of the same leading characters
    3. It has mixed case (at least one upper case and at least one lower case)
    4. It was not a previous password in the history
  */
void Password::set(string new_pass){

  if ((new_pass.length() >= 8 && new_pass.length() <= 20) && count_leading_characters(new_pass) <= 3 && has_mixed_case(new_pass)){
    //check if new_pass was not a previous password in pass_history
    for (int i = 0; i < pass_history.size(); i++){
      if (new_pass == pass_history[i]){
        pass_history.pop_back();
        return;
      }
    }
    pass_history.push_back(new_pass);
    return;
  }
}

/*
  receives a string and authenticates it against the latest password in the
  pass_history, returning true for an exact match or false when it does not match
  or if a password has not been set.
  */
bool Password::authenticate(string pass){
  return false;
}

