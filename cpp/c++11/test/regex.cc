/* 
Regular Expression:  a regular expression is a specific pattern that provides concise and flexible means 
	to "match" strings of text, such as particular characters, words, or patterns of characters. - wikipedia
*/

#include <regex>
using namespace std;

int main() {
   string str;
   while (true) {
      cin >> str;
	  //regex e("abc.", regex_constants::icase);   // .   Any character except newline
	  //regex e("abc?");               // ?       Zero or 1 preceding character
	  //regex e("abc*");               // *       Zero or more preceding character
	  //regex e("abc+");               // +       One of more preceding character
	  //regex e("ab[cd]*");            // [...]   Any character inside the square brackets
	  //regex e("ab[^cd]*");           // [...]   Any character not inside the square brackets
	  //regex e("ab[cd]{3,5}");
	  //regex e("abc|de[\]fg]");         // |       Or
	  //regex  e("(abc)de+\\1");       // \1      First group
	  //regex  e("(ab)c(de+)\\2\\1");
	  //regex e("[[:w:]]+@[[:w:]]+\.com"); // [[:w:]] word character: digit, number, or underscore

	  //regex e("abc.$");                 // $   End of the string
	  regex e("^abc.+", regex_constants::grep);                 // ^   begin of the string
	  

	  //bool match = regex_match(str, e);
	  bool match = regex_search(str, e);

	  cout << (match? "Matched" : "Not matched") << endl << endl;
   }
}





/*

Regular Expression Grammars:

   ECMAScript
   basic
   extended
   awk
   grep 
   egrep

 */








/***************  Deal with subexpression *****************/

/* 
  std::match_results<>  Store the detailed matches
  smatch                Detailed match in string

  smatch m;
  m[0].str()   The entire match (same with m.str(), m.str(0))
  m[1].str()   The substring that matches the first group  (same with m.str(1))
  m[2].str()   The substring that matches the second group
  m.prefix()   Everything before the first matched character
  m.suffix()   Everything after the last matched character
*/

int main() {
   string str;

   while (true) {
      cin >> str;
	  smatch m;        // typedef std::match_results<string>

	  regex e("([[:w:]]+)@([[:w:]]+)\.com");  

	  bool found = regex_search(str, m, e);

      cout << "m.size() " << m.size() << endl;
	  for (int n = 0; n< m.size(); n++) {
		   cout << "m[" << n << "]: str()=" << m[n].str() << endl;
		   cout << "m[" << n << "]: str()=" << m.str(n) << endl;
			cout << "m[" << n << "]: str()=" << *(m.begin()+n) << endl;
	  }
	  cout << "m.prefix().str(): " << m.prefix().str() << endl;
	  cout << "m.suffix().str(): " << m.suffix().str() << endl;
   }
}





/**************** Regex Iterator ******************/
int main() {
	cout << "Hi" << endl;

   string str;

   while (true) {
      cin >> str;

	  regex e("([[:w:]]+)@([[:w:]]+)\.com"); 
	  
	  sregex_iterator pos(str.cbegin(), str.cend(), e);
	  sregex_iterator end;  // Default constructor defines past-the-end iterator
	  for (; pos!=end; pos++) {
		  cout << "Matched:  " << pos->str(0) << endl;
		  cout << "user name: " << pos->str(1) << endl;
		  cout << "Domain: " << pos->str(2) << endl;
		  cout << endl;
	  }
	  cout << "=============================\n\n";
   }
}







/**************** Regex Token Iterator ******************/
int main() {
	cout << "Hi" << endl;

	//string str = "Apple; Orange, {Cherry}; Blueberry";
	string str = "boq@yahoo.com, boqian@gmail.com; bo@hotmail.com";

	//regex e("[[:punct:]]+");  // Printable character that is not space, digit, or letter.
	//regex e("[ [:punct:]]+"); 
	regex e("([[:w:]]+)@([[:w:]]+)\.com");
	  
	sregex_token_iterator pos(str.cbegin(), str.cend(), e, 0);
	sregex_token_iterator end;  // Default constructor defines past-the-end iterator
	for (; pos!=end; pos++) {
		cout << "Matched:  " << *pos << endl;
	}
	cout << "=============================\n\n";
		
	
	cin >> str;
}







/**************** regex_replace ******************/
int main() {
	cout << "Hi" << endl;

	string str = "boq@yahoo.com, boqian@gmail.com; bo@hotmail.com";

	regex e("([[:w:]]+)@([[:w:]]+)\.com");
	regex e("([[:w:]]+)@([[:w:]]+)\.com", regex_constants::grep|regex_constants::icase );
	  
	//cout << regex_replace(str, e, "$1 is on $2");
   cout << regex_replace(str, e, "$1 is on $2", regex_constants::format_no_copy|regex_constants::format_first_only);
	cout << regex_replace(str, e, "$1 is on $2");
		
	
	std::cin >> str;
}






