/*
 * This file contains code from "C++ Primer, Fourth Edition", by Stanley B.
 * Lippman, Jose Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 * 
 * "Copyright (c) 2005 by Objectwrite, Inc., Jose Lajoie, and Barbara E. Moo."
 * 
 * 
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 * 
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address: 
 * 
 * 	Pearson Education, Inc.
 * 	Rights and Contracts Department
 * 	75 Arlington Street, Suite 300
 * 	Boston, MA 02216
 * 	Fax: (617) 848-7047
*/ 

#include "algs_preamble.h"

int main() {
    vector<int> vec;

    istream_iterator<int> in_iter(cin);  // read ints from cin
    istream_iterator<int> eof;           // istream ``end'' iterator

    // read until end of file, storing what was read in vec
    while (in_iter != eof)
            // increment advances the stream to the next value
            // dereference reads next value from the istream
            vec.push_back(*in_iter++);

    // print what we got
    for (vector<int>::const_iterator it = vec.begin();
                                     it != vec.end(); ++it)
	    cout << *it << " ";
    cout << endl;
}

