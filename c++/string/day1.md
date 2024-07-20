https: // cplusplus.com/reference/string/string/string/

default (1)
string();
copy (2)
string (const string& str);
substring (3)
string (const string& str, size_t pos, size_t len = npos);
from c-string (4)
string (const char* s);
from buffer (5)
string (const char* s, size_t n);
fill (6)
string (size_t n, char c);
range (7)
template <class InputIterator> string (InputIterator first, InputIterator last);
initializer list (8)
string (initializer_list<char> il);
move (9)
string (string&& str) noexcept;

Construct string object
Constructs a string object, initializing its value depending on the constructor version used:

(1) empty string constructor (default constructor)
Constructs an empty string, with a length of zero characters.
(2) copy constructor
Constructs a copy of str.
(3) substring constructor
Copies the portion of str that begins at the character position pos and spans len characters (or until the end of str, if either str is too short or if len is string::npos).
(4) from c-string
Copies the null-terminated character sequence (C-string) pointed by s.
(5) from buffer
Copies the first n characters from the array of characters pointed by s.
(6) fill constructor
Fills the string with n consecutive copies of character c.
(7) range constructor
Copies the sequence of characters in the range [first,last), in the same order.
(8) initializer list
Copies each of the characters in il, in the same order.
(9) move constructor
Acquires the contents of str.
str is left in an unspecified but valid state.

All constructors above support an object of member type allocator_type as additional optional argument at the end, which for string is not relevant (not shown above, see basic_string's constructor for full signatures).
