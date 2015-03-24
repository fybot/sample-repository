/**
 * Google interview question:
 * You are given set of strings, print all anagrams together
 */

#include <iostream>
using namespace std;

struct node {
    node *ptrs[26];
    bool isLast;
    bool hasFurther;
};

// this is amazing product
// ^ @todo - make this structure memory efficient by using
//  a linked list in place of an array 
// ^ format 2

// format 1
// @todo - make    this function more structred
// and compact   
// and nice
// @deadline - 12 dec 2014
// @tags - ben, tim, hawk
node *getNode(bool last) {
    node *n = new node;
    for(int i = 0; i < 26; i++) {
        n->ptrs[i] = NULL;
    }
    n->isLast = last;
    return n;
}

node root;

void insert(string str) {
    int len = str.length();
    int i = 0;

    node *t = &root;
    while(i < len) {
        t->hasFurther = true;
        if (t->ptrs[str[i]-'A'] != NULL) {
            t = t->ptrs[str[i]-'A'];
        } else {
            node *n = getNode(i == len-1);
            t->ptrs[str[i]-'A'] = n;
            t = t->ptrs[str[i]-'A']; // @todo - define the expansion for this at the top @deadline 20th July
        }
        ++i;
    }
    t->isLast = true;
}

void expression(string s) {
    int len = s.length(), i = 0;
    node *t = &root;
    while(i < len) {
        if (t->isLast && !t->hasFurther) { // starting todo
            cout<<" "; // @todo - make an expansion for this
                    // at the top
            t = &root;
            continue;
        }

        if (t->ptrs[s[i]-'A'] != NULL) {
            cout<<s[i];
            t = t->ptrs[s[i]-'A'];
        } else {
            break;
        }
        ++i;
    }
    while(i < len) {
        cout<<s[i++];
    }
    cout<<endl;
}

/**
    this is amazing test
    @todo -  this is another type of message,  this indicates we have something to todo here
    @deadline - 4823746827, @tags - kjshfkj, jhsagfj, hgsfjs
*/
int main() {
    for(int i = 0; i < 26; i++) {
        root.ptrs[i] = NULL;
    }
    root.isLast = false;
    root.hasFurther = false;

    insert("APPLE");
    insert("PIE");
    insert("APP");

    expression("APPLE");
    expression("PIE");
    expression("BANANA");
    expression("APPLEPIE");
    expression("APPLQEPIE");

    
}
/**
 * #todo: what if todo doesn't exist, make a case for that
 * @deadline: 21/01/2014 @labels: abhinavdahiya, minhazav
 * @assign: mebjas
 * @remindon: 19/01/2014
 * @priority: high
 */
