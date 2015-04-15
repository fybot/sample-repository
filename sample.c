/**
 * #todo - Google interview question:
 * You are given set of strings, print all anagrams together
 */

// Adding a random new line
// Adding another random new line

#include <iostream>
using namespace std;

struct node {
    node *ptrs[26];
    bool isLast;
    bool hasFurther;
    bool nothing;
};


// format 1
// @todo - make    this function more structred
// and compact  modified a todo here
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
            /*
             * #todo - adding a new todo to test integration with todo-ci
             * @deadline - 20 days @remainder - 15 days @assign mebjas
             */
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
        if (t->isLast && !t->hasFurther) { // #todo - modifed and added another todo 
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
    cout<<endl;
}

/**
    this is amazing test
    @todo -  this is another type of message, this indicates we have something to todo here
    @deadline - 4823746827, @tags - test, todo-ci, awsomeness
*/
int main() {
    for(int i = 0; i < 26; i++) {
        root.ptrs[i] = NULL;
    }
    root.isLast = false;
    root.hasFurther = false;

    insert("PIE - 1");
    insert("APP - 2");

    expression("APPLE");
    expression("PIE");
    expression("BANANA");

    
}

/* 
    comment
    // @ToDo - make todo ci very scalable and fast
    and more important sexy
    bla
    ble
     * @deadline: 21/01/2014 bla vla bla @tags: abhinavdahiya, minhazav
     * @assign: mebjas
     * @remindon: 19/01/2014
     @ lebel: googleit, microsd

*/
